#pragma once

#include <vector>
#include <memory>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <opencv2/videoio.hpp>
#include "activities/SecondaryActivity.hpp"
#include "activities/MainActivity.hpp"
#include "activities/ActivitiesManager.hpp"
#include "gui/menu/SFMLMenu.hpp""

class GUI
{
public:
   GUI(sf::RenderWindow& window, cv::VideoCapture& cap);

   void launch();

private:
   void handleEvents();
   void propagateEvent(sf::Event event);
   void drawActivities();
   void drawElements(const Activity& activity);
   void addActivity(std::shared_ptr<MainActivity> activity);
   void addActivity(std::shared_ptr<SecondaryActivity> activity);

   cv::VideoCapture& _cap;
   cv::Mat _current_frame;
   SFMLMenu _menu;
   sf::RenderWindow& _window;

   ActivitiesManager* _activities_manager;
};
