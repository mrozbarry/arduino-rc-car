#include <MotorLeft.hpp>

#ifndef D2
#define D2  2
#endif

#ifndef D3
#define D3  3
#endif

#ifndef D4
#define D4  4
#endif

MotorLeft::MotorLeft() noexcept
  : Motor(D3, D4, D2)
{}
