#pragma once

#include <thread>
#include <opencv2/videoio.hpp>

class ToolsManager
{
public:
   ToolsManager() {};

   void static glassTracking();

private:
   void static detec(cv::VideoCapture cap);
};

