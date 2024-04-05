#include <Application.hpp>

Application::Application(Tickable *left, Tickable *right) noexcept
    : Tickable()
    , motorLeft(left)
    , motorRight(right)
    , controller(NULL)
{}
Application::~Application() {}

void Application::setup()
{
  motorLeft->setup();
  motorRight->setup();
}

void Application::tick()
{
  motorLeft->tick();
  motorRight->tick();
  
  delay(1000);
}

bool Application::onControllerConnect(Controller *controller)
{
  if (this.controller) {
    return false;
  }
}

bool Application::onControllerDisconnect(Controller *controller)
{
}
