#include "Application.hpp"

Application::Application()
  : controller(Controller::MotorPins { 0, 0, 0 }, Controller::MotorPins { 0, 0, 0 })
{}
Application::~Application() {}

void Application::setup()
{
}

void Application::loop()
{
  controller.tick(millis());
  delay(10);
}
