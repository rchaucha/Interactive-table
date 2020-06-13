#include "activities/GlassTrackingActivity.hpp"

#include <tools/TrackingTools.hpp>

GlassTrackingActivity::GlassTrackingActivity(VideoCapture& cap):
   _cap(cap)
{}

void GlassTrackingActivity::run(cv::Mat frame)
{
   TrackingTools::glassesTracking(_cap);
}

bool GlassTrackingActivity::catchEvent(sf::Event event)
{
   return false;
}

std::vector<sf::Drawable> GlassTrackingActivity::getDrawables(sf::Event event)
{
   return std::vector<sf::Drawable>();
}
