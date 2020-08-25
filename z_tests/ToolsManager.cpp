#include "ToolsManager.hpp"

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
#include "tools/detection/DetectionTools.hpp"

#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"

using namespace cv;
using namespace std;

void ToolsManager::glassTracking()
{
   

   //thread t(ToolsManager::detec, cap);

   //tracker.traitementCouleur(cap);
   //TrackingTools::glassesTracking(cap);

   //t.join();
}

void ToolsManager::detec(VideoCapture cap)
{
   Mat src;
   vector<Vec3f> circles;
   int R_MIN = 40, R_MAX = 70;

   while (1) {
      Mat gray;
      cap.read(src);
      cvtColor(src, gray, COLOR_BGR2GRAY);
      medianBlur(gray, gray, 5);

      HoughCircles(gray, circles, HOUGH_GRADIENT, 1,
         gray.rows / 10,  // change this value to detect circles with different distances to each other
         100, 30, R_MIN, R_MAX);

      for (size_t i = 0; i < circles.size(); i++)
      {
         Vec3f c = circles[i];
         Point center = Point(c[0], c[1]);
         int radius = c[2];

         circle(src, center, 1, Scalar(0, 100, 100), 3, LINE_AA);    // dessiner le centre et le cercle
         circle(src, center, radius, Scalar(255, 0, 255), 3, LINE_AA);
      }

      imshow("detected circles", src);

      if (waitKey(1) == 27) break;  //quit on ESC button
   }
}
