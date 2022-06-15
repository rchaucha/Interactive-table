#pragma once

#include <chrono>
#include <iostream>
#include <string>

class Timer
{
public:
   Timer(std::string&& name):
      m_name(std::move(name)),
      m_start(std::chrono::high_resolution_clock::now())
   {}

   ~Timer()
   {
      stop();
   }

   void stop()
   {
      auto end_point = std::chrono::high_resolution_clock::now();

      auto start = std::chrono::time_point_cast<std::chrono::microseconds>(m_start).time_since_epoch().count();
      auto end = std::chrono::time_point_cast<std::chrono::microseconds>(end_point).time_since_epoch().count();

      auto duration = end - start;

      std::cout << m_name << " : " << duration << "ms" << std::endl;
   }

private:
   const std::string m_name;
   const std::chrono::time_point<std::chrono::high_resolution_clock> m_start;
};