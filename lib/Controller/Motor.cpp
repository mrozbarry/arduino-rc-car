#include <Motor.hpp>

Motor::Motor(int in1, int in2, int pwm) noexcept
  : in1(in1)
  , in2(in2)
  , pwm(pwm)
  , value(0.0f)
{}

void Motor::setup()
{
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(pwm, OUTPUT);
}

void Motor::tick()
{
  int pwmValue = constrain(int(255.0f * abs(value)), 0, 255);

  digitalWrite(in1, 0);
  digitalWrite(in2, 0);
  analogWrite(pwm, pwmValue);
}
