#pragma once

#include <Tickable.hpp>
#ifdef UNIT_TEST
#include <ArduinoFake.h>
#else
#include <Arduino.h>
#endif

class Motor : public Tickable {
public:
  Motor(int in1, int in2, int pwm) noexcept;

  virtual void setup();
  virtual void tick();

  int in1;
  int in2;
  int pwm;

  float value;
};



