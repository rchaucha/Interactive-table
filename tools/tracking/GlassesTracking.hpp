#pragma once

#include "tools/tracking/Tracking.hpp"

class GlassesTracking : public Tracking
{
public:
   virtual bool init(const cv::Mat& frame) override;
   virtual void update(const cv::Mat& frame) override;
};

