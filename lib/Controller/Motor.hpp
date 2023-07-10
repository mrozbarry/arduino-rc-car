#pragma once

#ifdef UNIT_TEST
#include <ArduinoFake.h>
#else
#include <Arduino.h>
#endif

class Motor {
public:
  Motor(int source, int gate, int drain) noexcept;

  void setup();
  void tick();

  int source;
  int gate;
  int drain;

  float value;
};

