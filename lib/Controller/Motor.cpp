#include <Motor.hpp>

Motor::Motor(int source, int gate, int drain) noexcept
  : value(0.0f)
{}

void Motor::setup()
{
  pinMode(source, OUTPUT);
  pinMode(gate, OUTPUT);
  pinMode(drain, OUTPUT);
}

void Motor::tick()
{
  value = constrain(value, -1.0f, 1.0f);
  float absolute = abs(value);
  bool forward = absolute > 0.05f;

  digitalWrite(source, 0);
  digitalWrite(gate, 0);
  digitalWrite(drain, 0);
}
