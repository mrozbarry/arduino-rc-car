#include "Core.hpp"

#ifdef TARGET_NATIVE

#include <chrono>
#include <thread>

std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

void delay(unsigned long milliseconds)
{
  std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
}

unsigned long millis()
{
  std::chrono::steady_clock::time_point now = std::chrono::steady_clock::now();
  return std::chrono::duration_cast<std::chrono::milliseconds>(now - begin).count();
}

#endif

