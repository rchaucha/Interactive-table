#include "Window.hpp"

using namespace cv;

Window::Window(MainActivity& main_activity, VideoCapture& cap) :
   _main_activity(main_activity),
   _cap(cap)
{}

void Window::launch()
{
   _main_activity.run();

   for (SecondaryActivity& activity : _secondary_activities)
      activity.run();


}

void Window::propagateEvent(sf::Event event)
{
   for (SecondaryActivity& activity : _secondary_activities)
      if (activity.catchEvent(event))
         return;

   _main_activity.catchEvent(event);
}
