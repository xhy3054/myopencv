//
// Created by lixin04 on 19-3-20.
//
#include "GRKLT.hpp"
//#include "tictoc.hpp"
#include <emmintrin.h>
#include <xmmintrin.h>

double GRKLT_SSE(const cv::Mat& last_frame,
               const cv::Mat& input_image,
               const std::vector<cv::Point2f>& feature_locations,
               std::vector<cv::Point2f>& features_out,
               std::vector<unsigned char>& tracked_point_status,
               cv::Size windows,
               int pyramid_levels){
    std::vector<cv::Point2f> tracked_points_new_frame;
    std::vector<int> tracked_point_status_int;
    features_out.clear();
    tracked_point_status.clear();
    int patch_size = (windows.height - 1)/2;
    double K = 1;
    K = trackImagePyramids_SSE(last_frame,
                           input_image,
                           feature_locations,
                           tracked_points_new_frame,
                           tracked_point_status_int,
                           pyramid_levels,
                           patch_size);
    std::vector<int> validity_vector = checkLocationValidity(tracked_points_new_frame,  patch_size, input_image.cols, input_image.rows );

    for(int i = 0;i < feature_locations.size();i++)
    {
        features_out.push_back( tracked_points_new_frame.at(i) );
        tracked_point_status.push_back(validity_vector.at(i) == 0 || tracked_point_status_int.at(i) == 0 ? 0 : 1);
    }
    return K;
}
double trackImagePyramids_SSE(const cv::Mat& frame_1,
                              const cv::Mat& frame_2,
                              const std::vector<cv::Point2f>& pts_1,
                              std::vector<cv::Point2f>& pts_2,
                              std::vector<int>& point_status,
                              int pyramid_levels,
                              int patch_size)
{
    std::vector<int> point_validity;
    for(int i = 0;i < pts_1.size();i++)
    {
        point_validity.push_back(1);
    }

    std::vector<cv::Mat> new_pyramid;
    cv::buildPyramid(frame_2, new_pyramid, pyramid_levels);

    std::vector<cv::Mat> old_pyramid;
    cv::buildPyramid(frame_1, old_pyramid, pyramid_levels);

    std::vector<cv::Point2f> tracking_estimates = pts_1;

    double all_exp_estimates = 0.0;
    int nr_estimates = 0;

    for(int level = (int)new_pyramid.size()-1;level >= 0;level--)
    {
        float power = 1 << level;
        std::vector<cv::Point2f> scaled_tracked_points(pts_1.size());
        std::vector<cv::Point2f> scaled_tracking_estimates(pts_1.size());

        for(auto i = 0;i < pts_1.size();i++)
        {
            cv::Point2f scaled_point;
            scaled_point.x = (pts_1.at(i).x/power);
            scaled_point.y = (pts_1.at(i).y/power);
            scaled_tracked_points.at(i) = scaled_point;

            cv::Point2f scaled_estimate;
            scaled_estimate.x = (tracking_estimates.at(i).x/power);
            scaled_estimate.y = (tracking_estimates.at(i).y/power);
            scaled_tracking_estimates.at(i) = scaled_estimate;
        }

        double exp_estimate = 0;

        double filter_max = 2.0 / power;
        exp_estimate = trackImageExposurePyr_SSE(old_pyramid.at(level),
                                                 new_pyramid.at(level),
                                                 scaled_tracked_points,
                                                 scaled_tracking_estimates,
                                                 point_validity,
                                                 patch_size,
                                                 filter_max);
        all_exp_estimates += exp_estimate;
        nr_estimates++;

        for(auto i = 0; i < scaled_tracking_estimates.size(); i++)
        {
            if (point_validity.at(i) != 0) {

                cv::Point2f scaled_point;
                scaled_point.x =  (scaled_tracking_estimates.at(i).x * power);
                scaled_point.y =  (scaled_tracking_estimates.at(i).y * power);

                tracking_estimates.at(i) = scaled_point;
            }
        }
    }

    pts_2 = tracking_estimates;
    point_status = point_validity;

    double overall_exp_estimate = all_exp_estimates / nr_estimates;
    return overall_exp_estimate;
}


inline __m128 _mm_log_ps(__m128 x)
{
    __m128i I = _mm_castps_si128(x);
    __m128 log_2 = _mm_cvtepi32_ps(_mm_sub_epi32(_mm_and_si128(_mm_srli_epi32(I, 23), _mm_set1_epi32(255)), _mm_set1_epi32(128)));
    I = _mm_and_si128(I, _mm_set1_epi32(-2139095041));        //    255 << 23
    I = _mm_add_epi32(I, _mm_set1_epi32(1065353216));        //    127 << 23
    __m128 F = _mm_castsi128_ps(I);
    __m128 T = _mm_add_ps(_mm_mul_ps(_mm_set1_ps(-0.34484843f), F), _mm_set1_ps(2.02466578f));
    T = _mm_sub_ps(_mm_mul_ps(T, F), _mm_set1_ps(0.67487759f));
    return _mm_mul_ps(_mm_add_ps(log_2, T), _mm_set1_ps(0.69314718f));
}

double trackImageExposurePyr_SSE(const cv::Mat& old_image,
                                 const cv::Mat& new_image,
                                 const std::vector<cv::Point2f>& input_points,
                                 std::vector<cv::Point2f>& output_points,
                                 std::vector<int>& point_validity,
                                 const int patch_size,
                                 const int filter_max)
{
    int nr_points = static_cast<int>(input_points.size());

    if(output_points.empty())
    {
        output_points = input_points;
    }
    else if(output_points.size() != input_points.size())
    {
        std::cout << "ERROR - OUTPUT POINT SIZE != INPUT POINT SIZE!" << std::endl;
        return -1;
    }

    int image_rows = new_image.rows;
    int image_cols = new_image.cols;

    double K_total = 0.0;

    for(int round = 0;round < 1;round++)
    {
        int nr_valid_points = getNrValidPoints(point_validity);

        cv::Mat W(2*nr_valid_points,1,CV_64F,0.0);
        cv::Mat V(2*nr_valid_points,1,CV_64F,0.0);
        cv::Mat V_KLT(2*nr_valid_points,1,CV_64F,0.0);

        cv::Mat U_INV(2*nr_valid_points,2*nr_valid_points,CV_64F,0.0);
        cv::Mat K_all(nr_valid_points, nr_valid_points, CV_64F, 0.0);
        std::vector<cv::Mat> Us(input_points.size());

        double lambda = 0;
        double m = 0;

        int absolute_point_index = -1;

        for(int p = 0;p < input_points.size();p++)
        {
            if(point_validity.at(p) == 0)
            {
                continue;
            }

            absolute_point_index++;

            cv::Mat U(2, 2, CV_64F, 0.0);

            cv::Mat patch_intensities_1;
            cv::Mat patch_intensities_2;
            int absolute_patch_size = ((patch_size + 1) * 2 + 1);
            cv::getRectSubPix(new_image, cv::Size(absolute_patch_size, absolute_patch_size), output_points.at(p),
                              patch_intensities_2, CV_32F);
            cv::getRectSubPix(old_image, cv::Size(absolute_patch_size, absolute_patch_size), input_points.at(p),
                              patch_intensities_1, CV_32F);

            for(int r = 0; r < 2*patch_size+1;r++)
            {
                auto ptr_1  = patch_intensities_1.ptr<float>(r+1);
                auto ptr_1_up = patch_intensities_1.ptr<float>(r+1+1);
                auto ptr_1_dn = patch_intensities_1.ptr<float>(r);

                auto ptr_2  = patch_intensities_2.ptr<float>(r+1);
                auto ptr_2_up = patch_intensities_2.ptr<float>(r+1+1);
                auto ptr_2_dn = patch_intensities_2.ptr<float>(r);


                int c = 0;
                for(; c < 2*patch_size+1 - 4;c = c + 4)
                {
                    float i_frame[5], j_frame[5];

                    i_frame[1] = ptr_1[1+c] < 1?1 : ptr_1[1+c];
                    j_frame[1] = ptr_2[1+c] < 1?1 : ptr_2[1+c];

                    i_frame[2] = ptr_1[2+c] < 1?1 : ptr_1[2+c];
                    j_frame[2] = ptr_2[2+c] < 1?1 : ptr_2[2+c];

                    i_frame[3] = ptr_1[3+c] < 1?1 : ptr_1[3+c];
                    j_frame[3] = ptr_2[3+c] < 1?1 : ptr_2[3+c];

                    i_frame[4] = ptr_1[4+c] < 1?1 : ptr_1[4+c];
                    j_frame[4] = ptr_2[4+c] < 1?1 : ptr_2[4+c];

                    __m128 iframe_beta = _mm_set_ps( ptr_1[1+c], i_frame[2], i_frame[3], i_frame[4] );
                    __m128 iframe_0 = _mm_set_ps( ptr_1[c], ptr_1[1+c], i_frame[2], i_frame[3] );
                    __m128 iframe_1 = _mm_set_ps( i_frame[2], i_frame[3], i_frame[4],ptr_1[5+c] );
                    __m128 iframe_2 = _mm_set_ps( ptr_1_up[1+c], ptr_1_up[2+c], ptr_1_up[3+c], ptr_1_up[4+c] );
                    __m128 iframe_3 = _mm_set_ps( ptr_1_dn[1+c], ptr_1_dn[2+c], ptr_1_dn[3+c], ptr_1_dn[4+c] );
                    __m128 iframe_inv = _mm_set_ps( 1.0, 1.0, 1.0, 1.0 );
                    iframe_inv = _mm_div_ps(iframe_inv, iframe_beta);


                    __m128 jframe_beta = _mm_set_ps( ptr_2[1+c], j_frame[2], j_frame[3], j_frame[4] );
                    __m128 jframe_0 = _mm_set_ps( ptr_2[c], ptr_2[1+c], j_frame[2], j_frame[3] );
                    __m128 jframe_1 = _mm_set_ps( j_frame[2], j_frame[3], j_frame[4], ptr_2[5+c] );
                    __m128 jframe_2 = _mm_set_ps( ptr_2_up[1+c], ptr_2_up[2+c], ptr_2_up[3+c], ptr_2_up[4+c] );
                    __m128 jframe_3 = _mm_set_ps( ptr_2_dn[1+c], ptr_2_dn[2+c], ptr_2_dn[3+c], ptr_2_dn[4+c] );
                    __m128 jframe_inv = _mm_set_ps( 1.0, 1.0, 1.0, 1.0 );
                    jframe_inv = _mm_div_ps(jframe_inv, jframe_beta);



                    __m128 half = _mm_set_ps( 0.5, 0.5, 0.5, 0.5 );
                    __m128 gradix = _mm_sub_ps(iframe_1,iframe_0);
                    __m128 gradiy = _mm_sub_ps(iframe_2,iframe_3);
                    __m128 gradjx = _mm_sub_ps(jframe_1,jframe_0);
                    __m128 gradjy = _mm_sub_ps(jframe_2,jframe_3);
                    gradix = _mm_mul_ps(gradix,half);
                    gradiy = _mm_mul_ps(gradiy,half);
                    gradjx = _mm_mul_ps(gradjx,half);
                    gradjy = _mm_mul_ps(gradjy,half);

                    __m128 a00 = _mm_mul_ps(jframe_inv, gradjx);
                    __m128 a11 = _mm_mul_ps(iframe_inv, gradix);
                    __m128 a = _mm_add_ps(a00, a11);

                    __m128 b00 = _mm_mul_ps(jframe_inv, gradjy);
                    __m128 b11 = _mm_mul_ps(iframe_inv, gradiy);
                    __m128 b = _mm_add_ps(b00, b11);

                    __m128 beta = _mm_log_ps( _mm_div_ps(jframe_beta, iframe_beta) );

                    __m128 u0 = _mm_mul_ps(a,a);
                    __m128 u1 = _mm_mul_ps(a,b);
                    __m128 u2 = _mm_mul_ps(b,b);

                    __m128 v0 = _mm_mul_ps(a, beta);
                    __m128 v1 = _mm_mul_ps(b, beta);

                    float u04[4], u14[4], u24[4];
                    _mm_store_ps(u04, u0);
                    _mm_store_ps(u14, u1);
                    _mm_store_ps(u24, u2);
                    U.at<double>(0,0) += 0.5 *(u04[0] + u04[1] + u04[2] + u04[3]);
                    U.at<double>(0,1) += 0.5 *(u14[0] + u14[1] + u14[2] + u14[3]);
                    U.at<double>(1,0) = U.at<double>(0,1);
                    U.at<double>(1,1) += 0.5 *(u24[0] + u24[1] + u24[2] + u24[3]);

                    float a4[4], b4[4];
                    _mm_store_ps(a4, a);
                    _mm_store_ps(b4, b);
                    W.at<double>(2*absolute_point_index,0)   -= (a4[0] + a4[1] + a4[2] + a4[3]);
                    W.at<double>(2*absolute_point_index+1,0) -= (b4[0] + b4[1] + b4[2] + b4[3]);

                    float v04[4], v14[4];
                    _mm_store_ps(v04, v0);
                    _mm_store_ps(v14, v1);
                    V.at<double>(2*absolute_point_index,0)   -= (v04[0] + v04[1] + v04[2] + v04[3]);
                    V.at<double>(2*absolute_point_index+1,0) -= (v14[0] + v14[1] + v14[2] + v14[3]);

                    lambda += 8;

                    float beta4[4];
                    _mm_store_ps(beta4, beta);
                    m += 2*(beta4[0] + beta4[1] + beta4[2] + beta4[3]);
                }
                for(; c < 2*patch_size+1;++c)
                {
                    double i_frame0 = ptr_1[1+c];
                    double j_frame0 = ptr_2[1+c];
                    i_frame0 = i_frame0 < 1 ? 1:i_frame0;
                    j_frame0 = j_frame0 < 1 ? 1:j_frame0;

                    double grad_1_x0 = (ptr_1[c+2] - ptr_1[c])/2;
                    double grad_1_y0 = (ptr_1_up[c+1] - ptr_1_dn[c+1])/2;
                    double grad_2_x0 = (ptr_2[c+2] - ptr_2[c])/2;
                    double grad_2_y0 = (ptr_2_up[c+1] - ptr_2_dn[c+1])/2;
                    double a0 = (1.0/j_frame0)*grad_2_x0 + (1.0/i_frame0)*grad_1_x0;
                    double b0 = (1.0/j_frame0)*grad_2_y0 + (1.0/i_frame0)*grad_1_y0;
                    double beta = log(j_frame0/i_frame0);

                    U.at<double>(0,0) += 0.5*a0*a0;
                    U.at<double>(1,0) += 0.5*a0*b0;
                    U.at<double>(0,1) += 0.5*a0*b0;
                    U.at<double>(1,1) += 0.5*b0*b0;

                    W.at<double>(2*absolute_point_index,0)   -= a0;
                    W.at<double>(2*absolute_point_index+1,0) -= b0;

                    V.at<double>(2*absolute_point_index,0)   -= beta*a0;
                    V.at<double>(2*absolute_point_index+1,0) -= beta*b0;

                    lambda += 2;
                    m += 2*beta ;
                }
            }

            Us.at(static_cast<unsigned long>(absolute_point_index)) = U.clone();


            cv::Mat U_INV_p = U.inv();

            U_INV.at<double>(2*absolute_point_index,2*absolute_point_index) = U_INV_p.at<double>(0,0);
            U_INV.at<double>(2*absolute_point_index+1,2*absolute_point_index) = U_INV_p.at<double>(1,0);
            U_INV.at<double>(2*absolute_point_index,2*absolute_point_index+1) = U_INV_p.at<double>(0,1);
            U_INV.at<double>(2*absolute_point_index+1,2*absolute_point_index+1) = U_INV_p.at<double>(1,1);
        }
        cv::Mat K_MAT;
        cv::solve(-W.t()*U_INV*W+lambda, -W.t()*U_INV*V+m, K_MAT);
        double K = K_MAT.at<double>(0,0);

        absolute_point_index = -1;
        for(int p = 0;p < nr_points;p++)
        {
            if(point_validity.at(p) == 0)
                continue;

            absolute_point_index++;

            cv::Mat U_p = Us.at(absolute_point_index);
            cv::Mat V_p = V(cv::Rect(0,2*absolute_point_index,1,2));
            cv::Mat W_p = W(cv::Rect(0,2*absolute_point_index,1,2));

            cv::Mat displacement;
            cv::solve(U_p, V_p - K*W_p, displacement);

            int filter_displacement = 4;
            if( displacement.at<double>(0,0) > filter_displacement || displacement.at<double>(1,0) > filter_displacement )
            {
                point_validity.at(p) = 0;
                continue;
            }

            output_points.at(p).x += displacement.at<double>(0,0);
            output_points.at(p).y += displacement.at<double>(1,0);

            // Filter out this point if too close at the boundaries
            double x = output_points.at(p).x;
            double y = output_points.at(p).y;

            if(x < filter_max || y < filter_max || x > image_cols-filter_max || y > image_rows-filter_max)
            {
                point_validity.at(p) = 0;
                continue;
            }
        }
        K_total = K;
    }
    return exp(K_total);
}

int getNrValidPoints(std::vector<int> validity_vector)
{
    // Simply sum up the validity vector
    int result = 0;
    for (int i : validity_vector) {
        result += i;
    }
    return result;
}

std::vector<int> checkLocationValidity(std::vector<cv::Point2f>& points, int patch_size, int image_width, int image_height)
{
    int min_x = patch_size + 1;
    int min_y = patch_size + 1;

    int max_x = image_width - patch_size -1;
    int max_y = image_height - patch_size-1;

    std::vector<int> is_valid;

    for (auto &point : points) {
        is_valid.push_back(point.x < min_x || point.x > max_x || point.y < min_y || point.y > max_y ? 0 : 1);
    }

    return is_valid;
}

