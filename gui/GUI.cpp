#include "GUI.hpp"

#include "activities/GlassTrackingActivity.hpp"
#include <activities\MenuActivity.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

using namespace cv;
using namespace std;

GUI::GUI(MainActivity* main_activity, sf::RenderWindow& window, VideoCapture& cap) :
   _cap(cap),
   _window(window),
   _main_activity(main_activity)
{}

void GUI::launch()
{
   Mat frame;
   sf::Event event;

   // on laisse passer quelques images pour que la camera se stabilise
   for (int i = 0; i < 30; i++) { _cap >> frame; }
   
   if (frame.rows != 0 && frame.cols != 0)
   {
      GlassTrackingActivity glass_tracking_act(_window.getSize(), frame);
      addSecondaryActivity(&glass_tracking_act);
   }

   while (_window.isOpen())
   {
      _cap >> frame;

      if (frame.rows == 0 || frame.cols == 0)  // stop the program if no more images
         return;

      _window.clear(sf::Color::White);

      // On affiche tous les éléments de l'activité principale
      _main_activity->run(frame);
      drawElements(*_main_activity);

      // On affiche tous les éléments des activités secondaires
      for (auto& activity : _secondary_activities)
      {
         activity->run(frame);
         drawElements(*activity);
      }

      _window.display();

      // On propage les évènements aux activités si ce n'est pas la touche ESC
      while (_window.pollEvent(event))
      {
         if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
            return;
         else
            propagateEvent(event);
      }
   }
}

void GUI::drawElements(const Activity& activity)
{
   for (const auto& e : activity.getDrawables())
      _window.draw(*e);
}

void GUI::propagateEvent(sf::Event event)
{
   for (auto& activity : _secondary_activities)
      if (activity->catchEvent(event))
         return;

   _main_activity->catchEvent(event);
}
