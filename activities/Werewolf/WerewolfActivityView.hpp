#pragma once

#include <activities\ActivityView.hpp>
#include <map>
#include <opencv2/core.hpp>

class WerewolfActivity;

class WerewolfActivityView : public ActivityView
{
public:
   WerewolfActivityView(const sf::Vector2u window_size, const sf::Vector2u frame_size);
   ~WerewolfActivityView();

   void setActivityLogic(WerewolfActivity* activity) noexcept { _activity = activity; }

   virtual bool catchEvent(sf::Event event) const override;
   virtual std::vector<std::shared_ptr<sf::Drawable>> getDrawables() const override;
   virtual std::vector<std::shared_ptr<SFMLSquareButton>> getMenuButtons() const override;

private:
   WerewolfActivity* _activity;

   std::vector<std::shared_ptr<SFMLSquareButton>> _buttons;
};

