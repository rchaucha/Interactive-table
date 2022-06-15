#include "DetectionTools.hpp"

#include <execution>
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"

// Creation of the rectangle containing the circle
cv::Rect2d circlesToRect(cv::Vec3f c)
{
   double rayon = c[2];
   double x = c[0] - rayon;
   double y = c[1] - rayon;

   return cv::Rect2d(x, y, 2.0 * rayon, 2.0 * rayon);
}

// Detect glasses in the image src
std::vector<cv::Rect2d> DetectionTools::glasses(const cv::Mat src)
{
   cv::Mat gray;
   if (src.channels() != 1)    // to greyscale
      cvtColor(src, gray, cv::COLOR_BGR2GRAY);
   else
      gray = src;

   medianBlur(gray, gray, 5);

   std::vector<cv::Vec3f> circles;
   HoughCircles(gray, circles, cv::HOUGH_GRADIENT, 1,
      gray.rows / 9.0,  // change this value to detect circles with different distances to each other
      100, 30, R_MIN, R_MAX);
   
   std::vector<cv::Rect2d> rects;
   rects.resize(circles.size());

   std::transform(std::execution::par_unseq, circles.begin(), circles.end(), rects.begin(), circlesToRect);

   return rects;
}