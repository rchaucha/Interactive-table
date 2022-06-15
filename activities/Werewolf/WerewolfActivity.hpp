#pragma once

#include <opencv2/videoio.hpp>
#include "activities/MainActivity.hpp"
#include "WerewolfActivityView.hpp"

class WerewolfActivity : public MainActivity
{
public:
   WerewolfActivity(WerewolfActivityView* view);
   ~WerewolfActivity();

   virtual void run() override;
   virtual void update() override;

   inline virtual std::string getFolderName() const noexcept override { return "werewolf"; }
   inline virtual const ActivityView* getView() const noexcept override { return _view; }

private:
   WerewolfActivityView* _view;
};
