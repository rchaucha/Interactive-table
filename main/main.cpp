#include <iostream>

#include "gui/GUI.hpp"
#include "tools/RGBCameraInput.hpp"
#include <tools/AudioPlayer.hpp>

int main(int argc, char** argv)
{
   /*
   AudioPlayer::playSound("werewolf", "music.ogg");

   std::string a;
   std::cin >> a;
   */
   
   RGBCameraInput* rbg_cam = RGBCameraInput::getInstance();
   
   if (!rbg_cam->openCamera())
   {
      std::cerr << "La webcam est introuvable" << std::endl;
      return -1;
   }
   
   sf::RenderWindow window(sf::VideoMode::getFullscreenModes()[0], "Interactive table", sf::Style::Fullscreen);

   GUI gui(window);
   gui.launch();
   
   return 0;
}
