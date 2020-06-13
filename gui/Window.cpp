#include "Window.hpp"

using namespace cv;
using namespace std;

Window::Window(MainActivity& main_activity, VideoCapture& cap) :
   _main_activity(main_activity),
   _cap(cap),
   _window(sf::VideoMode(sf::VideoMode::getFullscreenModes()[0]), "Interactive table", sf::Style::Fullscreen)
{}

void Window::launch()
{
   Mat frame;
   sf::Event event;

   // on laisse passer quelques images pour que la camera se stabilise
   for (int i = 0; i < 30; i++) { _cap >> frame; }
   
   while (_window.isOpen())
   {
      _window.clear(sf::Color::White);

      // On affiche tous les éléments de l'activité principale
      _main_activity.run(frame);
      drawElements(_main_activity);

      // On affiche tous les éléments des activités secondaires
      for (SecondaryActivity& activity : _secondary_activities)
      {
         activity.run(frame);
         drawElements(activity);
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

void Window::drawElements(Activity& activity)
{
   for (auto& e : activity.getDrawables())
      _window.draw(*e);
}

void Window::propagateEvent(sf::Event event)
{
   for (SecondaryActivity& activity : _secondary_activities)
      if (activity.catchEvent(event))
         return;

   _main_activity.catchEvent(event);
}
