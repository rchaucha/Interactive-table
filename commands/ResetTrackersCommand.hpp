#pragma once

#include "Command.hpp"
#include "activities/GlassTracking/GlassTrackingActivity.hpp"

class ResetTrackersCommand : public Command
{
public:
   ResetTrackersCommand(GlassTrackingActivity* const activity): _activity(activity)
      {}

   virtual void execute() const override 
      { _activity->resetTrackers(); }

private:
   GlassTrackingActivity* const _activity;
};

