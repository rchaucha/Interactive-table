#pragma once

#include "MainActivity.hpp"
#include "NoneActivityView.hpp"

class NoneActivity : public MainActivity
{
public:
   NoneActivity() : MainActivity()
      {}

   virtual void run() override
      {}

   virtual void update() override 
      {}
   
   virtual std::string getFolderName() const override
      { return ""; }

   virtual const ActivityView* getView() const noexcept override
      { return new NoneActivityView; }
};

