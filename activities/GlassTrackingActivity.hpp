#pragma once

#include "activities/SecondaryActivity.hpp"
#include <opencv2/videoio.hpp>

class GlassTrackingActivity : public SecondaryActivity
{
   GlassTrackingActivity();

   virtual void run(cv::Mat frame) override;
   virtual bool catchEvent(sf::Event event) override;
   virtual std::vector<sf::Drawable> getDrawables(sf::Event event) override;

private:
};

