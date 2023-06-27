#pragma once

class Application {
  public:
    Application();
    virtual ~Application();

    virtual void setup();
    virtual void loop();
};
