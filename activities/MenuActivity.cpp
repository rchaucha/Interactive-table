#include "MenuActivity.hpp"

using namespace cv;

MenuActivity::MenuActivity()
{}

void MenuActivity::run(cv::Mat frame)
{

}

bool MenuActivity::catchEvent(sf::Event event)
{
   return false;
}

std::vector<sf::Drawable> MenuActivity::getDrawables(sf::Event event)
{
   return std::vector<sf::Drawable>();
}
