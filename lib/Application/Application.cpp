#include <Application.hpp>

Application::Application(Tickable *left, Tickable *right) noexcept
    : Tickable()
    , motorLeft(left)
    , motorRight(right)
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
