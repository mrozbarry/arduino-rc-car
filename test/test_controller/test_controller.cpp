#include <unity.h>
#include <Arduino.h>
#include "Controller.hpp"

void setUp(void) {
}

void tearDown(void) {
}

void it_creates_a_new_controller(void) {
  Controller controller = Controller(
      Controller::MotorPins { 0, 0, 0 },
      Controller::MotorPins { 0, 0, 0 }
  );
  
  TEST_ASSERT_EQUAL_FLOAT(0.0f, controller.getLeftMotorState());
  TEST_ASSERT_EQUAL_FLOAT(0.0f, controller.getRightMotorState());
}

void it_calculates_pin_output(void){
  Controller controller = Controller(
      Controller::MotorPins { 0, 1, 2 },
      Controller::MotorPins { 3, 4, 5 }
  );
  
  controller.tick(0);
  
  for(int i=0; i<6; i++) {
    TEST_ASSERT_EQUAL_INT(LOW, digitalRead(i));
  }
}

int runTests(void) {
  UNITY_BEGIN();

  RUN_TEST(it_creates_a_new_controller);
  RUN_TEST(it_calculates_pin_output);

  return UNITY_END();
}

#ifdef UNIT_TEST
int main(void) {
  return runTests();
}
#endif
