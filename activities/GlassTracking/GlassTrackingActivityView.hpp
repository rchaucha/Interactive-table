#pragma once

#include <activities\ActivityView.hpp>
#include <map>
#include <opencv2/core.hpp>

class GlassTrackingActivity;

class GlassTrackingActivityView : public ActivityView
{
public:
   GlassTrackingActivityView(const sf::Vector2u window_size, const sf::Vector2u frame_size);
   ~GlassTrackingActivityView();

   void setActivityLogic(GlassTrackingActivity* activity) noexcept { _activity = activity; }

   virtual bool catchEvent(sf::Event event) const override;
   virtual std::vector<std::shared_ptr<sf::Drawable>> getDrawables() const override;
   virtual std::vector<std::shared_ptr<SFMLSquareButton>> getMenuButtons() const override;

   void loadTextures();
   void setGlassesTexture();
   void update(const std::vector<cv::Rect2d>& roi);

private:
   GlassTrackingActivity* _activity;

   std::map<unsigned int, unsigned int> _roi_index_to_texture_index;
   std::vector<std::shared_ptr<SFMLSquareButton>> _buttons;

   std::vector<sf::Texture> _texture_container;

   const std::vector<cv::Rect2d>* _roi = nullptr;

   const unsigned int _NBR_OF_EFFECTS = 5;
};

