#include <MotorRight.hpp>

#ifndef D5
#define D5  5
#endif

#ifndef D6
#define D6  6
#endif

#ifndef D7
#define D7  7
#endif

MotorRight::MotorRight() noexcept
  : Motor(D6, D7, D5)
{}
