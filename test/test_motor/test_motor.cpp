#include <unity.h>
#include <ArduinoFake.h>
#include <Motor.hpp>

using namespace fakeit;

void setUp(void) {
}

void tearDown(void) {
}

void it_creates_a_new_motor(void) {
  When(Method(ArduinoFake(), pinMode)).AlwaysReturn();

  Motor motor = Motor(0, 0, 0);
  
  TEST_ASSERT_EQUAL_FLOAT(0.0f, motor.value);

  motor.setup();

  Verify(
      Method(ArduinoFake(), pinMode).Using(0, OUTPUT) +
      Method(ArduinoFake(), pinMode).Using(0, OUTPUT) +
      Method(ArduinoFake(), pinMode).Using(0, OUTPUT)
    );
}

void it_calculates_pin_output(void){
  When(Method(ArduinoFake(), digitalWrite)).AlwaysReturn();

  Motor motor = Motor(0, 1, 2);
  
  motor.tick();

  Verify(
      Method(ArduinoFake(), digitalWrite).Using(0, 0) +
      Method(ArduinoFake(), digitalWrite).Using(1, 0) +
      Method(ArduinoFake(), digitalWrite).Using(2, 0)
  );
}

int runTests(void) {
  UNITY_BEGIN();

  RUN_TEST(it_creates_a_new_motor);
  RUN_TEST(it_calculates_pin_output);

  return UNITY_END();
}

#ifdef UNIT_TEST
int main(void) {
  return runTests();
}
#endif
