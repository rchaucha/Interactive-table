#include "DetectionTools.hpp"

vector<Rect2d> DetectionTools::glasses(Mat src)
{
   Mat gray;
   if (src.channels() != 1)      // on tranforme l'image en niveaux de gris
      cvtColor(src, gray, COLOR_BGR2GRAY);
   else
      gray = src;

   medianBlur(gray, gray, 5);
   vector<Vec3f> circles;
   vector<Rect2d> circles_rect;

   int R_MIN = 22, R_MAX = 46;

   HoughCircles(gray, circles, HOUGH_GRADIENT, 1,
      gray.rows / 9.0,  // change this value to detect circles with different distances to each other
      100, 30, R_MIN, R_MAX);
   
   double x, y, rayon;

   for (Vec3f c : circles)    // cercles -> rectangles
   {
      rayon = c[2];
      x = c[0] - rayon;
      y = c[1] - rayon;

      // On crée le rectangle qui entoure le cercle
      circles_rect.push_back(Rect2d(x, y, 2.0 * rayon, 2.0 * rayon));
   }

   return circles_rect;
}