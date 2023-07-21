#pragma once

#ifdef UNIT_TEST
#include <ArduinoFake.h>
#else
#include <Arduino.h>
#endif

class Motor {
public:
  Motor(int in1, int in2, int pwm) noexcept;

  void setup();
  void tick();

  int in1;
  int in2;
  int pwm;

  float value;
};



