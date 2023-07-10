#include <unity.h>
#include <ArduinoFake.h>
#include <Controller.hpp>

using namespace fakeit;

void setUp(void) {
}

void tearDown(void) {
}

void it_creates_a_new_controller(void) {
  When(Method(ArduinoFake(), pinMode)).AlwaysReturn();

  Controller controller = Controller(
      Controller::MotorPins { 0, 0, 0 },
      Controller::MotorPins { 0, 0, 0 }
  );
  
  TEST_ASSERT_EQUAL_FLOAT(0.0f, controller.leftMotor);
  TEST_ASSERT_EQUAL_FLOAT(0.0f, controller.rightMotor);

  Verify(
      Method(ArduinoFake(), pinMode).Using(0, OUTPUT) +
      Method(ArduinoFake(), pinMode).Using(0, OUTPUT) +
      Method(ArduinoFake(), pinMode).Using(0, OUTPUT) +
      Method(ArduinoFake(), pinMode).Using(0, OUTPUT) +
      Method(ArduinoFake(), pinMode).Using(0, OUTPUT) +
      Method(ArduinoFake(), pinMode).Using(0, OUTPUT)
    );
}

void it_calculates_pin_output(void){
  When(Method(ArduinoFake(), analogWrite)).AlwaysReturn();

  Controller controller = Controller(
      Controller::MotorPins { 0, 1, 2 },
      Controller::MotorPins { 3, 4, 5 }
  );
  
  controller.tick(0);

  Verify(Method(ArduinoFake(), analogWrite).Using(0, 0)).Once();
  Verify(Method(ArduinoFake(), analogWrite).Using(1, 0)).Once();
  Verify(Method(ArduinoFake(), analogWrite).Using(2, 0)).Once();
  Verify(Method(ArduinoFake(), analogWrite).Using(3, 0)).Once();
  Verify(Method(ArduinoFake(), analogWrite).Using(4, 0)).Once();
  Verify(Method(ArduinoFake(), analogWrite).Using(5, 0)).Once();
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
