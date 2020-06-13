#pragma once

#include <vector>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <opencv2/videoio.hpp>
#include "activities/SecondaryActivity.hpp"
#include "activities/MainActivity.hpp"

class Window
{
public:
   Window(MainActivity& main_activity, cv::VideoCapture& cap);

   void launch();
   void replaceMainActivity(MainActivity& new_activity) { _main_activity = new_activity; }
   void addSecondaryActivity(SecondaryActivity& new_activity) { _secondary_activities.push_back(new_activity); }

private:
   /* Transmet l'event aux activités actives, il sera capté par la première qui en a besoin */
   void propagateEvent(sf::Event event);

   /* Dessine tous les éléments de l'activité sur la fenetre */
   void drawElements(Activity& activity);

   cv::VideoCapture& _cap;
   MainActivity& _main_activity;
   std::vector<SecondaryActivity&> _secondary_activities;
   sf::RenderWindow _window;
};

