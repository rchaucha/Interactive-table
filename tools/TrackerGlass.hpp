#pragma once

#include <opencv2/tracking.hpp>

class TrackerGlass: public Tracker
{
public:
   /** @brief Constructor
   */
   CV_WRAP static Ptr<TrackerMOSSE> create();

   virtual ~TrackerMOSSE() CV_OVERRIDE {}
};