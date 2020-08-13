#pragma once

#include <vector>
#include <opencv2/core/utility.hpp>
#include <opencv2/tracking/tracker.hpp>

class Tracking
{
public:
   /* Initialise les trackers
      Retourne faux si aucun verre n'a été trouvé */
   virtual bool init(const cv::Mat frame) = 0;

   /* Met à jour les trackers */
   virtual void update(const cv::Mat frame) = 0;

   /* Renvoie les rectangles d'intérêt (ROI) */
   std::vector<cv::Rect2d> getROI() const noexcept { return _roi; }

protected:
   cv::Ptr<cv::MultiTracker> _multi_tracker;
   std::vector<cv::Rect2d> _roi;
};

