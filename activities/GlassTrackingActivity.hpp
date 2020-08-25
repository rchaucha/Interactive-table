#pragma once

#include <opencv2/videoio.hpp>
#include "activities/SecondaryActivity.hpp"
#include "tools/tracking/GlassesTracking.hpp"

class GlassTrackingActivity : public SecondaryActivity
{
public:
   GlassTrackingActivity(const sf::Vector2u window_size, const sf::Vector2u frame_size);

   virtual void run(cv::Mat frame) override;
   virtual void update(cv::Mat frame) override;
   virtual bool catchEvent(sf::Event event) override;

   virtual std::vector<std::shared_ptr<sf::Drawable>> getDrawables() const override;
   virtual void buttonClicked(std::string button_id) override;
   virtual std::vector<std::shared_ptr<SFMLButton>> getButtons() override;

   virtual std::string getFolderName() const override;

   /*virtual std::shared_ptr<Activity> makeUniqueActivity() const override 
      { return std::make_shared<GlassTrackingActivity>(*this); }

   virtual std::shared_ptr<SecondaryActivity> makeUniqueSecondary() const override
      { return std::make_shared<GlassTrackingActivity>(*this); }
      */
   void resetTrackers();

private:
   GlassesTracking _glasses_tracking;

   std::vector<std::shared_ptr<SFMLButton>> _buttons;
};
