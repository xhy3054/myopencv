//
// Created by 高翔 on 2017/12/19.
// 本程序演示如何从Essential矩阵计算R,t
//

#include <Eigen/Core>
#include <Eigen/Dense>
#include <Eigen/Geometry>

using namespace Eigen;

#include <sophus/so3.hpp>

#include <iostream>

using namespace std;

int main(int argc, char **argv) {

    // 给定Essential矩阵
    Matrix3d E;
    E << -0.0203618550523477, -0.4007110038118445, -0.03324074249824097,
            0.3939270778216369, -0.03506401846698079, 0.5857110303721015,
            -0.006788487241438284, -0.5815434272915686, -0.01438258684486258;

    // 待计算的R,t
    Matrix3d R;
    Vector3d t;

    // SVD
    Eigen::JacobiSVD<Eigen::Matrix3d> svd(E, Eigen::ComputeFullU | Eigen::ComputeFullV);
    Eigen::Matrix3d V = svd.matrixV();
    Eigen::Matrix3d U = svd.matrixU();
    Vector3d lambda = svd.singularValues();
    Vector3d l((lambda[0] + lambda[1]) / 2, (lambda[0] + lambda[1]) / 2, 0);
    Matrix3d Sigma = l.asDiagonal();
    cout << "lambda = " << lambda.transpose() << endl;

    AngleAxisd Rz1(M_PI / 2, Vector3d(0, 0, 1)), Rz2(-M_PI / 2, Vector3d(0, 0, 1));

    Matrix3d t_wedge1 = U * Rz1.matrix() * Sigma * U.transpose();
    Matrix3d t_wedge2 = U * Rz2.matrix() * Sigma * U.transpose();

    Matrix3d R1 = U * Rz1.matrix().transpose() * V.transpose();
    Matrix3d R2 = U * Rz2.matrix().transpose() * V.transpose();

    cout << "R1 = " << R1 << endl;
    cout << "R2 = " << R2 << endl;
    cout << "t1 = " << Sophus::SO3d::vee(t_wedge1) << endl;
    cout << "t2 = " << Sophus::SO3d::vee(t_wedge2) << endl;

    Matrix3d tR = t_wedge2 * R1;
    cout << "t^R = " << tR << endl;

    return 0;
}
