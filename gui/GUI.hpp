#pragma once

#include <memory>
#include "gui/menu/SFMLMenu.hpp"

class ActivitiesManager;
class MainActivity;
class SecondaryActivity;
class RGBCameraInput;
class sf::Event;

class GUI
{
public:
   GUI(sf::RenderWindow& window);

   void launch();

private:
   void handleEvents() const noexcept;
   void propagateEvent(sf::Event event) const noexcept;
   void drawActivities() const noexcept;
   void drawElements(const ActivityLogic& activity) const noexcept;
   void addActivity(std::shared_ptr<MainActivity> activity) noexcept;
   void addActivity(std::shared_ptr<SecondaryActivity> activity) noexcept;

   RGBCameraInput* _rgb_cam;
   SFMLMenu _menu;
   sf::RenderWindow& _window;

   ActivitiesManager* _activities_manager;
};
