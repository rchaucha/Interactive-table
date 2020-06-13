#pragma once

#include <iostream>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/core/utility.hpp>
#include <opencv2/tracking.hpp>
#include <cstring>
#include <sstream>
#include <string>

using namespace cv;
using namespace std;

class TrackingTools
{
public:
   TrackingTools() {};

   static int traitementCouleur(VideoCapture);
   static void glassesTracking(VideoCapture);

private:
};

