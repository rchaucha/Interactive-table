#include "GlassesTracking.hpp"

#include "tools/detection/DetectionTools.hpp"

using namespace std;
using namespace cv;

bool GlassesTracking::init(Mat frame)
{
   _roi = DetectionTools::glasses(frame);

   if (_roi.size() < 1)
      return false;

   _multi_tracker = MultiTracker::create();

   for (int i = 0; i < _roi.size(); i++)
      _multi_tracker->add(TrackerGlass::create(), frame, Rect2d(_roi[i]));

   return true;
}

bool GlassesTracking::update(Mat frame)
{
   if (frame.rows == 0 || frame.cols == 0)  // stop the program if no more images
      return false;

   _roi.clear();

   _multi_tracker->update(frame);

   for (unsigned i = 0; i < _multi_tracker->getObjects().size(); i++)
      _roi.push_back(_multi_tracker->getObjects()[i]);
   
   return true;
}