#pragma once

#include "tools/tracking/Tracking.hpp"

class GlassesTracking : public Tracking
{
public:
   virtual bool init(cv::Mat frame) override;
   virtual void update(cv::Mat frame) override;
};

