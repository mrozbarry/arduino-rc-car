#pragma once

#include "Controller.hpp"

class Application {
  public:
    Application();
    ~Application();

    void setup();
    void loop();

  private:
    Controller *controller;
};
