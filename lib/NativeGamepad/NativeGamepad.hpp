#pragma once

#include "Gamepad.hpp"

class NativeGamepad: public Gamepad {
  public:
    NativeGamepad() noexcept;
    void connect();
    bool getState(Gamepad::State *state);
};
