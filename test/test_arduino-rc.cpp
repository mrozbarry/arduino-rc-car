#include "unity.h"
#include "NativeGamepad.hpp"
#include "Gamepad.hpp"

void setUp(void) {
  // before hook
}

void tearDown(void) {
  // after hook
}

void it_gets_gamepad_state(void) {

  NativeGamepad gamepad = NativeGamepad();
  Gamepad::State state;

  TEST_ASSERT_FALSE(gamepad.getState(&state));

  gamepad.connect();

  TEST_ASSERT_TRUE(gamepad.getState(&state));
}

int runTests(void) {
  UNITY_BEGIN();
  RUN_TEST(it_gets_gamepad_state);
  return UNITY_END();
}

#ifdef UNIT_TEST
int main(void) {
  runTests();
}
#endif
