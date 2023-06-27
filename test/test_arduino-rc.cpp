#include "unity.h"
#include <Arduino.h>

void setUp(void) {
  // before hook
}

void tearDown(void) {
  // after hook
}

void test_thing(void) {
  TEST_FAIL_MESSAGE("haha fool");
}

int runTests(void) {
  UNITY_BEGIN();
  RUN_TEST(test_thing);
  return UNITY_END();
}

#ifdef UNIT_TEST
int main(void) {
  runTests();
}
#endif

void setup() {
  delay(2000);
  runTests();
}

void loop() {}
