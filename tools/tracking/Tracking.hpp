#pragma once

#include <vector>
#include <opencv2/core/utility.hpp>
#include <opencv2/tracking/tracker.hpp>

class Tracking
{
public:
   /* Init trackers
      Return false if no glass has been found */
   virtual bool init(const cv::Mat& frame) = 0;

   /* Updates trackers */
   virtual void update(const cv::Mat& frame) = 0;

   /* Return rectangles of interest (ROI) */
   const std::vector<cv::Rect2d>& getROI() const noexcept { return _roi; }

protected:
   cv::Ptr<cv::MultiTracker> _multi_tracker;
   std::vector<cv::Rect2d> _roi;
};

