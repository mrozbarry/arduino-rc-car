#pragma once

#include <Tickable.hpp>
#include <inttypes.h>

class Gamepad : public Tickable
{
  public:
    struct State
    {
      float   leftAxis;
      float   rightAxis;
      bool    isBrakePressed;
      uint8_t battery;
    };

    virtual ~Gamepad() {};

    virtual bool getState(State *state) = 0;
};
