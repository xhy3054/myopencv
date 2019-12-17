#include <iostream>
#include <fstream>
#include <vector>
#include <unistd.h>
#include <opencv2/core/core.hpp>
#include <opencv2/core/types.hpp>
#include <opencv2/features2d/features2d.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/calib3d/calib3d.hpp>
#include <Eigen/Core>
#include <Eigen/Dense>
#include <Eigen/Geometry>
#include <Eigen/SVD>
#include <g2o/core/base_vertex.h>
#include <g2o/core/base_unary_edge.h>
#include <g2o/core/block_solver.h>
#include <g2o/core/optimization_algorithm_gauss_newton.h>
#include <g2o/core/optimization_algorithm_levenberg.h>
#include <g2o/solvers/dense/linear_solver_dense.h>
#include <chrono>
#include <sophus/se3.h>
#include <pangolin/pangolin.h>
using namespace Sophus;
using namespace std;
using namespace cv;

string input_file = "./compare.txt";

typedef vector<Sophus::SE3, Eigen::aligned_allocator<Sophus::SE3>> TrajectoryType;

void icp_func(const vector<Point3f> &pts1,
              const vector<Point3f> &pts2,
              Eigen::Matrix3d &R, Eigen::Vector3d &t);
void DrawTrajectory(const TrajectoryType &gt, const TrajectoryType &esti);

int main(int argc, char **argv)
{
    //Read data
    TrajectoryType groundtruth, estimated, groundtruth_;
    vector<Point3f> gt_vec, et_vec;
    ifstream fin(input_file);
    if (!fin)
    {
        cerr << "trajectory " << input_file << " not found." << endl;
        return 0;
    }

    double gtime, gtx, gty, gtz, gqx, gqy, gqz, gqw, etime, etx, ety, etz, eqx, eqy, eqz, eqw;
    while (!fin.eof())
    {
        fin >> etime >> etx >> ety >> etz >> eqx >> eqy >> eqz >> eqw >> gtime >> gtx >> gty >> gtz >> gqx >> gqy >> gqz >> gqw;

        et_vec.push_back(Point3f(etx, ety, etz));
        gt_vec.push_back(Point3f(gtx, gty, gtz));

        Sophus::SE3 ep(Eigen::Quaterniond(eqx, eqy, eqz, eqw).normalized(), Eigen::Vector3d(etx, ety, etz));
        Sophus::SE3 gp(Eigen::Quaterniond(gqx, gqy, gqz, gqw).normalized(), Eigen::Vector3d(gtx, gty, gtz));
        estimated.push_back(ep);
        groundtruth.push_back(gp);
    }

    assert(!groundtruth.empty() && !estimated.empty());
    assert(groundtruth.size() == estimated.size());

    //icp
    Eigen::Matrix3d R;
    Eigen::Vector3d t;
    icp_func(et_vec, gt_vec, R, t);

    Sophus::SE3 T_eg(R, t);
    for (auto se3_g : groundtruth)
    {
        auto se3_e = T_eg * se3_g;
        groundtruth_.push_back(se3_e);
    }

    DrawTrajectory(groundtruth_, estimated);
    return 0;
}

void icp_func(const vector<Point3f> &pts1,
              const vector<Point3f> &pts2,
              Eigen::Matrix3d &R, Eigen::Vector3d &t)
{
	// 计算位置的平均值
    Point3f p1, p2; // center of mass
    int N = pts1.size();
    for (int i = 0; i < N; i++)
    {
        p1 += pts1[i];
        p2 += pts2[i];
    }
    p1 = Point3f(Vec3f(p1) / N);
    p2 = Point3f(Vec3f(p2) / N);

	//去均值
    vector<Point3f> q1(N), q2(N); // remove the center
    for (int i = 0; i < N; i++)
    {
        q1[i] = pts1[i] - p1;
        q2[i] = pts2[i] - p2;
    }

    // compute q1*q2^T 计算从q2到q1的变换矩阵的和w
    Eigen::Matrix3d W = Eigen::Matrix3d::Zero();
    for (int i = 0; i < N; i++)
    {
        W += Eigen::Vector3d(q1[i].x, q1[i].y, q1[i].z) * Eigen::Vector3d(q2[i].x, q2[i].y, q2[i].z).transpose();
    }
    cout << "W=" << W << endl;

    // SVD on W 对W进行奇异值分解
    Eigen::JacobiSVD<Eigen::Matrix3d> svd(W, Eigen::ComputeFullU | Eigen::ComputeFullV);
    Eigen::Matrix3d U = svd.matrixU();
    Eigen::Matrix3d V = svd.matrixV();

    cout << "U=" << U << endl;
    cout << "V=" << V << endl;

	// 
    Eigen::Matrix3d R_ = U * (V.transpose());
    if (R_.determinant() < 0)
    {
        R_ = -R_;
    }
    Eigen::Vector3d t_ = Eigen::Vector3d(p1.x, p1.y, p1.z) - R_ * Eigen::Vector3d(p2.x, p2.y, p2.z);

    // convert to cv::Mat
    R << R_(0, 0), R_(0, 1), R_(0, 2),
        R_(1, 0), R_(1, 1), R_(1, 2),
        R_(2, 0), R_(2, 1), R_(2, 2);
    t << t_(0, 0), t_(1, 0), t_(2, 0);
}

void DrawTrajectory(const TrajectoryType &gt, const TrajectoryType &esti)
{
    // create pangolin window and plot the trajectory
    pangolin::CreateWindowAndBind("Trajectory Viewer", 1024, 768);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    pangolin::OpenGlRenderState s_cam(
        pangolin::ProjectionMatrix(1024, 768, 500, 500, 512, 389, 0.1, 1000),
        pangolin::ModelViewLookAt(0, -0.1, -1.8, 0, 0, 0, 0.0, -1.0, 0.0));

    pangolin::View &d_cam = pangolin::CreateDisplay()
                                .SetBounds(0.0, 1.0, pangolin::Attach::Pix(175), 1.0, -1024.0f / 768.0f)
                                .SetHandler(new pangolin::Handler3D(s_cam));

    while (pangolin::ShouldQuit() == false)
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        d_cam.Activate(s_cam);
        glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

        glLineWidth(2);
        for (size_t i = 0; i < gt.size() - 1; i++)
        {
            glColor3f(0.0f, 0.0f, 1.0f); // blue for ground truth
            glBegin(GL_LINES);
            auto p1 = gt[i], p2 = gt[i + 1];
            glVertex3d(p1.translation()[0], p1.translation()[1], p1.translation()[2]);
            glVertex3d(p2.translation()[0], p2.translation()[1], p2.translation()[2]);
            glEnd();
        }

        for (size_t i = 0; i < esti.size() - 1; i++)
        {
            glColor3f(1.0f, 0.0f, 0.0f); // red for estimated
            glBegin(GL_LINES);
            auto p1 = esti[i], p2 = esti[i + 1];
            glVertex3d(p1.translation()[0], p1.translation()[1], p1.translation()[2]);
            glVertex3d(p2.translation()[0], p2.translation()[1], p2.translation()[2]);
            glEnd();
        }
        pangolin::FinishFrame();
        usleep(5000); // sleep 5 ms
    }
}
