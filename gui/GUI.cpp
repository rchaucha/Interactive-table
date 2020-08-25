#include "GUI.hpp"

#include "activities/GlassTrackingActivity.hpp"
#include "SFML/Graphics/RectangleShape.hpp"

using namespace cv;
using namespace std;


GUI::GUI(sf::RenderWindow& window, VideoCapture& cap) :
   _cap(cap),
   _window(window),
   _activities_manager(ActivitiesManager::getInstance())
{}

void GUI::launch()
{
   for (int i = 0; i < 30; i++)     // on laisse passer quelques images pour que la camera se stabilise
      _cap >> _current_frame;
   
   if (_current_frame.rows == 0 || _current_frame.cols == 0)
   {
      cerr << "Image vide" << endl;
      return;
   }

   addActivity(make_shared<GlassTrackingActivity>(_window.getSize(), sf::Vector2u(_current_frame.cols, _current_frame.rows)));

   while (_window.isOpen())
   {
      _cap >> _current_frame;

      if (_current_frame.rows == 0 || _current_frame.cols == 0)  // stop the program if no more images
         return;

      _window.clear(sf::Color::Black);

      _activities_manager->updateActivities(_current_frame);
      drawActivities();

      _window.display();

      handleEvents();
   }
}

void GUI::drawActivities()
{
   drawElements(*_activities_manager->getMainActivity());

   for (auto& activity : _activities_manager->getSecondaryActivities())
      drawElements(*activity);

   _menu.draw(_window);
}

void GUI::drawElements(const Activity& activity)
{
   for (const auto& e : activity.getDrawables())
      _window.draw(*e);
}

void GUI::addActivity(shared_ptr<MainActivity> activity)
{
   _activities_manager->addActivity(activity);
   _menu.addActivity(activity);
}

void GUI::addActivity(shared_ptr<SecondaryActivity> activity)
{
   _activities_manager->addActivity(activity);
   _menu.addActivity(activity);
}

void GUI::handleEvents()
{
   sf::Event event;

   // On propage les évènements aux activités si ce n'est pas la touche ESC
   while (_window.pollEvent(event))
   {
      if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
         exit(0);
      else
         propagateEvent(event);
   }
}

void GUI::propagateEvent(sf::Event event)
{
   if (_menu.catchEvent(event))
   {
      _activities_manager->menuButtonClicked(_menu.getLastAction(), _current_frame);
      return;
   }

   _activities_manager->propagateEvent(event);
}

