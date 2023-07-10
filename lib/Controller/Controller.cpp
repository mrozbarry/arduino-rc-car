#include <Controller.hpp>
#include <Core.hpp>

Controller::Controller(MotorPins left, MotorPins right) noexcept
    : left(left)
    , right(right)
    , leftMotor(0.0f)
    , rightMotor(0.0f)
{
  pinMode(left.source, OUTPUT);
  pinMode(left.gate, OUTPUT);
  pinMode(left.drain, OUTPUT);

  pinMode(right.source, OUTPUT);
  pinMode(right.gate, OUTPUT);
  pinMode(right.drain, OUTPUT);
}

void Controller::tick(long milliseconds) {
  leftMotor = tickMotor(left, leftMotor);
  rightMotor = tickMotor(right, rightMotor);
}


float Controller::tickMotor(MotorPins& pins, float value)
{
  float clamped = constrain(value, -1.0f, 1.0f);
  float absolute = abs(clamped);
  bool forward = absolute > 0.05f;

  analogWrite(pins.source, 0);
  analogWrite(pins.gate, 0);
  analogWrite(pins.drain, 0);

  return clamped;
}
