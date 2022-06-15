#pragma once

#include <activities\ActivityView.hpp>

class NoneActivityView : public ActivityView
{
public:
   NoneActivityView(): ActivityView(sf::Vector2u(0, 0), sf::Vector2u(0, 0)) {}

   virtual bool catchEvent(sf::Event event) const override
      { return false; }

   virtual std::vector<std::shared_ptr<sf::Drawable>> getDrawables() const override
      { return std::vector<std::shared_ptr<sf::Drawable>>(); }
   
   virtual std::vector<std::shared_ptr<SFMLSquareButton>> getMenuButtons() const override
      { return std::vector<std::shared_ptr<SFMLSquareButton>>(); }
};

