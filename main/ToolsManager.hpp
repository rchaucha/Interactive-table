#pragma once

#include <thread>
#include <opencv2/videoio.hpp>

class ToolsManager
{
public:
   ToolsManager() {};

   void glassTracking(int argc, char** argv);

private:
   void static detec(cv::VideoCapture cap);
};

