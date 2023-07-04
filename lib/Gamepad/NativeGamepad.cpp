#include "Core.hpp"
#include "NativeGamepad.hpp"

NativeGamepad::NativeGamepad() noexcept
  : Gamepad()
  , is_connected(false)
{
  
}

void NativeGamepad::connect() {
  this->is_connected = true;
  this->state.updated_at = millis();
}

void NativeGamepad::disconnect() {
  this->is_connected = false;
}

bool NativeGamepad::getState(Gamepad::State *state) {
  if (!this->is_connected) {
    return false;
  }
  if (state->updated_at == this->state.updated_at) {
    return false;
  }
  return true;
}
