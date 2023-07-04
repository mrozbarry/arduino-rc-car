#pragma once

#ifdef UNIT_TEST
    #include "ArduinoFake.h"
#else
    #include "Arduino.h"
#endif

class Application {
  public:
    Application();
    virtual ~Application();

    virtual void setup();
    virtual void loop();
};
