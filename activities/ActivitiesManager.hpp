#pragma once

#include "Activity.hpp"
#include <activities\MainActivity.hpp>
#include <activities\SecondaryActivity.hpp>
#include <gui\menu\SFMLMenu.hpp>

class ActivitiesManager
{
public:
   static ActivitiesManager* getInstance();

   static void addActivity(std::shared_ptr<Activity> activity) { _all_activities.push_back(activity); }

   static void updateActivities(cv::Mat frame);

   static void menuButtonClicked(SFMLMenu::LastAction last_action, cv::Mat frame);
   static void propagateEvent(sf::Event event);

   static void stopActivity(const unsigned int id);

   static const std::shared_ptr<MainActivity>& getMainActivity();
   static const std::vector<std::shared_ptr<SecondaryActivity>>& getSecondaryActivities() { return _secondary_activities; }
   
private:
   ActivitiesManager(); 

   static void launchActivity(std::shared_ptr<MainActivity> activity, cv::Mat frame);
   static void launchActivity(std::shared_ptr<SecondaryActivity> activity, cv::Mat frame);
   static void launchActivity(std::shared_ptr<Activity> activity, cv::Mat frame);

   // retourne -1 si pas trouvée
   static int getRunningSecondaryActivityIndexFromId(const unsigned int id);

   static std::vector<std::shared_ptr<Activity>> _all_activities;

   static std::shared_ptr<MainActivity> _main_activity;
   static std::vector<std::shared_ptr<SecondaryActivity>> _secondary_activities;

   static ActivitiesManager* _instance;
};

