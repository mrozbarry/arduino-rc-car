#pragma once

class Controller {
public:
  struct MotorPins{
    int source;
    int gate;
    int drain;
  };
  
  Controller(MotorPins left, MotorPins right) noexcept;
  
  float getLeftMotorState();
  float getRightMotorState();
  
  void tick(long milliseconds);
  
private:
  MotorPins left, right;
};
