#include "GUI.hpp"

#include "activities/GlassTracking/GlassTrackingActivity.hpp"
#include "SFML/Graphics/RectangleShape.hpp"
#include "activities/ActivitiesManager.hpp"
#include <tools/RGBCameraInput.hpp>

GUI::GUI(sf::RenderWindow& window) :
   _rgb_cam(RGBCameraInput::getInstance()),
   _window(window),
   _activities_manager(ActivitiesManager::getInstance())
{}

void GUI::launch()
{
   for (int i = 0; i < 30; i++)     // on laisse passer quelques images pour que la camera se stabilise
      _rgb_cam->updateFrame();
   
   if (_rgb_cam->isFrameEmpty())
   {
      std::cerr << "Image vide" << std::endl;
      return;
   }

   auto activity_shared_ptr = std::make_shared<GlassTrackingActivity>(new GlassTrackingActivityView(_window.getSize(), _rgb_cam->getFrameSize()));

   addActivity(activity_shared_ptr);

   while (_window.isOpen())
   {
      _rgb_cam->updateFrame();

      if (_rgb_cam->isFrameEmpty())
      {
         std::cerr << "Image vide" << std::endl;
         return;
      }

      _window.clear(sf::Color::Black);

      _activities_manager->updateActivities();
      drawActivities();

      _window.display();

      handleEvents();
   }
}

void GUI::drawActivities() const noexcept
{
   drawElements(*_activities_manager->getMainActivity());

   for (const auto& activity : _activities_manager->getSecondaryActivities())
      drawElements(*activity);

   _menu.draw(_window);
}

void GUI::drawElements(const ActivityLogic& activity) const noexcept
{
   for (const auto& e : activity.getView()->getDrawables())
      _window.draw(*e);
}

void GUI::addActivity(std::shared_ptr<MainActivity> activity) noexcept
{
   _activities_manager->addActivity(activity);
   _menu.addActivity(activity);
}

void GUI::addActivity(std::shared_ptr<SecondaryActivity> activity) noexcept
{
   _activities_manager->addActivity(activity);
   _menu.addActivity(activity);
}

void GUI::handleEvents() const noexcept
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

void GUI::propagateEvent(sf::Event event) const noexcept
{
   if (!_menu.catchEvent(event))
      _activities_manager->propagateEvent(event);
}

