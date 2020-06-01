#include <iostream>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/core/utility.hpp>
#include <opencv2/tracking.hpp>
#include <cstring>
#include <sstream>
#include <string>
#include <thread>
#include "RGBProcessing.hpp"

using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
   RGBProcessing RGB_tracker;
   RGB_tracker.glassTracking(argc, argv);
   
   return 0;
}