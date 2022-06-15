#include "ActivitiesManager.hpp"

#include <execution>
#include "activities/NoneActivity.hpp"
#include "activities\GlassTracking\GlassTrackingActivity.hpp"

using namespace cv;
using namespace std;

std::vector<std::shared_ptr<ActivityLogic>> ActivitiesManager::_all_activities;
std::shared_ptr<MainActivity> ActivitiesManager::_main_activity = make_shared<NoneActivity>();
std::vector<std::shared_ptr<SecondaryActivity>> ActivitiesManager::_secondary_activities;

ActivitiesManager* ActivitiesManager::_instance = nullptr;


ActivitiesManager* ActivitiesManager::getInstance()
{
   if (_instance == nullptr)
      _instance = new ActivitiesManager;

   return _instance;
}

void ActivitiesManager::launchActivity(shared_ptr<MainActivity> activity)
{
   _main_activity = activity;
   activity->run();
}

void ActivitiesManager::launchActivity(shared_ptr<SecondaryActivity> activity)
{
   _secondary_activities.push_back(activity);
   activity->run();
}

void ActivitiesManager::launchActivity(shared_ptr<ActivityLogic> activity)
{
   if (shared_ptr<MainActivity> main_activity = dynamic_pointer_cast<MainActivity>(activity))
      launchActivity(main_activity);
   
   else if (shared_ptr<SecondaryActivity> sec_activity = dynamic_pointer_cast<SecondaryActivity>(activity))
      launchActivity(sec_activity);
}

void ActivitiesManager::updateActivities()
{
   if (_main_activity)
      _main_activity->update();

   std::for_each(std::execution::par_unseq, _secondary_activities.begin(), _secondary_activities.end(),
      [](auto& activity) { activity->update(); });
}

void ActivitiesManager::propagateEvent(sf::Event event)
{
   for (auto& activity : _secondary_activities)
      if (activity->getView()->catchEvent(event))
         return;

   _main_activity->getView()->catchEvent(event);
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

   for (const auto& a : _secondary_activities)
   {
      if (a->getId() == id)
         break;
      ++ind;
   }

   if (ind == _secondary_activities.size())
      return -1;
   
   return ind;
}
