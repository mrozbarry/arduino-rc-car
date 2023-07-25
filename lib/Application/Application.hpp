#pragma once

#include <Tickable.hpp>
#include <Core.hpp>

class Application : public Tickable {
  public:
    Application(Tickable *motorLeft, Tickable *motorRight) noexcept;
    ~Application();
    
    virtual void setup();
    virtual void tick();

  private:
    Tickable *motorLeft;
    Tickable *motorRight;
};
