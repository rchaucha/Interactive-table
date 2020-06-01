#pragma once

#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"

using namespace cv;
using namespace std;


class DetectionTools
{
public:
   static vector<Rect2d> glasses(Mat);

private:
};

