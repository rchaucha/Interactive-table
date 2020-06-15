#include "MenuActivity.hpp"

using namespace cv;
using namespace std;

MenuActivity::MenuActivity(const sf::Vector2u window_size, const sf::Vector2u frame_size):
   MainActivity(window_size, frame_size)
{}

void MenuActivity::run(cv::Mat frame)
{

}

bool MenuActivity::catchEvent(sf::Event event)
{
   return false;
}

vector<unique_ptr<sf::Drawable>> MenuActivity::getDrawables() const
{
   return vector<unique_ptr<sf::Drawable>>();
}
