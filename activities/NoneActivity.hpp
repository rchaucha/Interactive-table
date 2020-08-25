#pragma once

#include "MainActivity.hpp"

class NoneActivity : public MainActivity
{
public:
   NoneActivity() : MainActivity(sf::Vector2u(0, 0), sf::Vector2u(0, 0)) 
      {}

   virtual void run(cv::Mat frame) override
      {}

   virtual void update(cv::Mat frame) override 
      {}

   virtual bool catchEvent(sf::Event event) override 
      { return false; }

   virtual std::vector<std::shared_ptr<sf::Drawable>> getDrawables() const override 
      { return std::vector<std::shared_ptr<sf::Drawable>>(); }

   virtual std::vector<std::shared_ptr<SFMLButton>> getButtons() override
      { return std::vector<std::shared_ptr<SFMLButton>>(); }
   
   virtual std::string getFolderName() const override
      { return ""; }

   virtual void buttonClicked(std::string button_id) override
      {}

  /* virtual std::shared_ptr<Activity> makeUniqueActivity() const override
      { return std::make_shared<NoneActivity>(*this); }

   virtual std::shared_ptr<MainActivity> makeUniqueMain() const override
      { return std::make_shared<NoneActivity>(*this); }
      */
};

