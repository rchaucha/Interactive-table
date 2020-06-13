#pragma once

#include <opencv2/videoio.hpp>
#include "activities/SecondaryActivity.hpp"
#include "tools/tracking/GlassesTracking.hpp"

class GlassTrackingActivity : public SecondaryActivity
{
public:
   GlassTrackingActivity(cv::Mat frame);

   virtual void run(cv::Mat frame) override;
   virtual bool catchEvent(sf::Event event) override;
   virtual std::vector<std::unique_ptr<sf::Drawable>> getDrawables() override;

private:
   GlassesTracking _glasses_tracking;
};
