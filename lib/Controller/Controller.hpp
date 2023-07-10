#pragma once

#ifdef UNIT_TEST
#include <ArduinoFake.h>
#else
#include <Arduino.h>
#endif

class Controller {
public:
  struct MotorPins{
    int source;
    int gate;
    int drain;
  };
  
  Controller(MotorPins left, MotorPins right) noexcept;
  
  void tick(long milliseconds);

  float leftMotor;
  float rightMotor;
  
private:
  float tickMotor(MotorPins& pins, float value);

  MotorPins left, right;
};
