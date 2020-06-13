#pragma once

#include "activities/MainActivity.hpp"
#include <opencv2/videoio.hpp>

class MenuActivity : public MainActivity
{
public:
   MenuActivity();

   virtual void run(cv::Mat frame) override;
   virtual bool catchEvent(sf::Event event) override;
   virtual std::vector<sf::Drawable> getDrawables(sf::Event event) override;

private:
};

