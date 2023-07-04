#include "./Controller.hpp"
#include "Core.hpp"

Controller::Controller(MotorPins left, MotorPins right) noexcept
    : left(left)
    , right(right)
{}

float Controller::getLeftMotorState() { return 0.0f; }

float Controller::getRightMotorState() { return 0.0f; }

void Controller::tick(long milliseconds){
  
}


