#pragma once

#include <vector>
#include <activities\ActivityView.hpp>
#include <tools\RGBCameraInput.hpp>

class ActivityLogic : public std::enable_shared_from_this<ActivityLogic>
{
public:
   virtual ~ActivityLogic() {}

   virtual void run() = 0;
   
   virtual void update() = 0;

   virtual std::string getFolderName() const = 0;

   virtual const unsigned int getId() const noexcept final { return _ID; }

   virtual const ActivityView* getView() const noexcept = 0;

   bool operator==(const ActivityLogic& other);

protected:
   ActivityLogic();
   ActivityLogic(const ActivityLogic& orig) = delete;

   RGBCameraInput* _rgb_cam;

   const unsigned int _ID;
   static unsigned int _id_generator;
};