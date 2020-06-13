#include <iostream>

#include "gui/GUI.hpp"
#include "activities/MenuActivity.hpp"

using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
   VideoCapture cap;

   if (!cap.open(0))
      cerr << "La webcam est introuvable" << endl;
   else
   {
      sf::RenderWindow window(sf::VideoMode::getFullscreenModes()[0], "Interactive table", sf::Style::Fullscreen);
      MenuActivity menu(window.getSize());

      GUI gui(&menu, window, cap);

      gui.launch();
   }

   return 0;
}
