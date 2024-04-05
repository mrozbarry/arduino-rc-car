#pragma once

#include "Gamepad.hpp"
#include <Bluepad32.h>

class Blue32Controller : public Gamepad
{
  public:
    Blue32Controller(ControllerPtr controller) noexcept;
    ~Blue32Controller();

    void setup();
    void tick();

    ControllerPtr controller;
};
