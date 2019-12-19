#ifndef MYHARRIS_H
#define MYHARRIS_H

#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>

namespace mycv{

void detectHarrisCorners(const cv::Mat& imgSrc, cv::Mat& imgDst, double alpha);

}
#endif
