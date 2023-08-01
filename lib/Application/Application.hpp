#pragma once

#include <Tickable.hpp>
#include <Core.hpp>
#include <Bluepad32.h>

class Application : public Tickable {
  public:
    Application(Tickable *motorLeft, Tickable *motorRight) noexcept;
    ~Application();
    
    virtual void setup();
    virtual void tick();

  private:
    Tickable      *motorLeft;
    Tickable      *motorRight;
    ControllerPtr controller;
};
