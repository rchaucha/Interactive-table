#pragma once

#include <opencv2/core/mat.hpp>
#include <opencv2/core/types.hpp>

class DetectionTools
{
public:
   static std::vector<cv::Rect2d> glasses(const cv::Mat src);

private:
   static const int R_MIN = 20,
                    R_MAX = 30;
};

