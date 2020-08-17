#pragma once

#include <vector>
#include <memory>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <opencv2/videoio.hpp>
#include "activities/SecondaryActivity.hpp"
#include "activities/MainActivity.hpp"
#include "gui\menu\SFMLMenuModel.hpp""

class GUI
{
public:
   GUI(MainActivity* main_activity, sf::RenderWindow& window, cv::VideoCapture& cap);

   void launch();
   void constexpr replaceMainActivity(MainActivity* new_activity) { _main_activity = std::unique_ptr<MainActivity>(new_activity); }
   void addSecondaryActivity(SecondaryActivity* new_activity) { _secondary_activities.push_back(std::unique_ptr<SecondaryActivity>(new_activity)); }
   
private:
   void handleEvents();
   void propagateEvent(sf::Event event);
   void drawActivities(cv::Mat frame);
   void drawElements(const Activity& activity);

   cv::VideoCapture& _cap;
   SFMLMenuModel _buttons_manager;
   std::unique_ptr<MainActivity> _main_activity;
   std::vector<std::unique_ptr<SecondaryActivity>> _secondary_activities;
   sf::RenderWindow& _window;
};
