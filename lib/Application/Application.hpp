#pragma once

#include <Tickable.hpp>
#include <Core.hpp>
#include <Controller.hpp>

class Application : public Tickable {
  public:
    Application(Tickable *motorLeft, Tickable *motorRight) noexcept;
    ~Application();
    
    virtual void setup();
    virtual void tick();

    bool onControllerConnect(Controller *controller);
    bool onControllerDisconnect(Controller *controller);

  private:
    Tickable      *motorLeft;
    Tickable      *motorRight;
    Controller    *controller;
};
