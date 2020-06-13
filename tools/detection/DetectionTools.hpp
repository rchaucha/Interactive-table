#pragma once

#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"

class DetectionTools
{
public:
   static vector<Rect2d> glasses(Mat);

private:
};

