#pragma once

#include "Gamepad.hpp"

class NativeGamepad: public Gamepad {
  public:
    NativeGamepad() noexcept;

    void connect();
    void disconnect();

    bool getState(Gamepad::State *state);

  private:
    bool is_connected;
};
