#pragma once

#include <vector>
#include <opencv2/core/utility.hpp>
#include <opencv2/tracking/tracker.hpp>

class Tracking
{
   /* Initialise les trackers
      Retourne faux si aucun verre n'a été trouvé */
   virtual bool init(cv::Mat frame) = 0;

   /* Met à jour les trackers
      Retourne faux si frame est vide */
   virtual bool update(cv::Mat frame) = 0;

   /* Renvoie les rectangles d'intérêt (ROI) */
   std::vector<cv::Rect2d> getROI(cv::Mat frame) { return _roi; }

protected:
   cv::Ptr<cv::MultiTracker> _multi_tracker;
   vector<cv::Rect2d> _roi;
};

