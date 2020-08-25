#include "ActivitiesManager.hpp"

#include "activities/NoneActivity.hpp"
#include <activities\GlassTrackingActivity.hpp>

using namespace cv;
using namespace std;

std::vector<std::shared_ptr<Activity>> ActivitiesManager::_all_activities;
std::shared_ptr<MainActivity> ActivitiesManager::_main_activity = make_shared<NoneActivity>();
std::vector<std::shared_ptr<SecondaryActivity>> ActivitiesManager::_secondary_activities;

ActivitiesManager* ActivitiesManager::_instance = nullptr;


ActivitiesManager* ActivitiesManager::getInstance()
{
   if (_instance == nullptr)
      _instance = new ActivitiesManager;

   return _instance;
}

void ActivitiesManager::launchActivity(shared_ptr<MainActivity> activity, Mat frame)
{
   _main_activity = activity;
   activity->run(frame);
}

void ActivitiesManager::launchActivity(shared_ptr<SecondaryActivity> activity, Mat frame)
{
   _secondary_activities.push_back(activity);
   activity->run(frame);
}

void ActivitiesManager::launchActivity(shared_ptr<Activity> activity,  cv::Mat frame)
{
   if (shared_ptr<MainActivity> main_activity = dynamic_pointer_cast<MainActivity>(activity))
      launchActivity(main_activity, frame);
   
   else if (shared_ptr<SecondaryActivity> sec_activity = dynamic_pointer_cast<SecondaryActivity>(activity))
      launchActivity(sec_activity, frame);
}

void ActivitiesManager::updateActivities(Mat frame)
{
   if (_main_activity != nullptr)
      _main_activity->update(frame);

   for (auto& activity : _secondary_activities)
      activity->update(frame);
}

void ActivitiesManager::menuButtonClicked(SFMLMenu::LastAction last_action, Mat frame)
{
   switch (last_action.type)
   {
   case SFMLMenu::APP_LAUNCHER:
      launchActivity(last_action.element_clicked->getActivity(), frame);
      break;
   case SFMLMenu::APP_CLOSER:
      stopActivity(last_action.element_clicked->getActivity()->getId());
      break;
   case SFMLMenu::BUTTON:
      shared_ptr<SFMLButton> b = static_pointer_cast<SFMLButton>(last_action.element_clicked);
      b->getActivity()->buttonClicked(b->getName());
      break;
   }
}

void ActivitiesManager::propagateEvent(sf::Event event)
{
   for (auto& activity : _secondary_activities)
      if (activity->catchEvent(event))
         return;

   _main_activity->catchEvent(event);
}

void ActivitiesManager::stopActivity(const unsigned int id)
{
   if (_main_activity->getId() == id)
      _main_activity = make_shared<NoneActivity>();

   else
   {
      int ind = getRunningSecondaryActivityIndexFromId(id);

      if (ind != -1)
      {
         _secondary_activities[ind].reset();
         _secondary_activities.erase(_secondary_activities.begin() + ind);
      }
   }
}

const std::shared_ptr<MainActivity>& ActivitiesManager::getMainActivity()
{
   if (_main_activity == nullptr)
      _main_activity = make_shared<NoneActivity>();

   return _main_activity;
}

ActivitiesManager::ActivitiesManager()
{
   _instance = nullptr;
   _main_activity = make_shared<NoneActivity>();
}

int ActivitiesManager::getRunningSecondaryActivityIndexFromId(const unsigned int id)
{
   int ind = 0;

   for (auto& a : _secondary_activities)
   {
      if (a->getId() == id)
         break;
      ind++;
   }

   if (ind == _secondary_activities.size())
      return -1;
   
   return ind;
}
