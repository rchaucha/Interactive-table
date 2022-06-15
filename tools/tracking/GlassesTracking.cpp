#include "GlassesTracking.hpp"

#include "tools/detection/DetectionTools.hpp"
#include <opencv2/highgui.hpp>


bool GlassesTracking::init(const cv::Mat& frame)
{
   _roi = DetectionTools::glasses(frame);

   if (_roi.size() < 1)
      return false;

   _multi_tracker = cv::MultiTracker::create();

   for (const auto& rect : _roi)
      _multi_tracker->add(cv::TrackerGlass::create(), frame, rect);

   return true;
}

void GlassesTracking::update(const cv::Mat& frame)
{
   // If glasses have been detected, we track them, otherwise we try to detect
   if (_roi.size() > 0)
   {
      _roi.clear();

      _multi_tracker->update(frame);

      for (const auto& object : _multi_tracker->getObjects())
      {
         _roi.push_back(object);

      #ifdef _DEBUG
         rectangle(frame, object, cv::Scalar(255, 0, 0), 2, 1);
      #endif
      }
   }
   else
   {
      init(frame);
   }
   
#ifdef _DEBUG
   imshow("MultiTracker", frame);
#endif
}