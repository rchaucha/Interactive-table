#include <iostream>

#include "gui/GUI.hpp"

using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
   VideoCapture cap;

   if (!cap.open(0))
      cerr << "La webcam est introuvable" << endl;
   else
   {
      Mat frame;
      cap >> frame;

      sf::RenderWindow window(sf::VideoMode::getFullscreenModes()[0], "Interactive table", sf::Style::Fullscreen);

      GUI gui(window, cap);

      gui.launch();
   }

   return 0;
}
