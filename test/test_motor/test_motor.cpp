#include "fakeit.hpp"
#include <ArduinoFake.h>
#include <Motor.hpp>
#include <unity.h>

using namespace fakeit;

void setUp(void) {}

void tearDown(void) {}

void it_creates_a_new_motor(void) {
  When(Method(ArduinoFake(), pinMode)).AlwaysReturn();

  Motor motor = Motor(0, 0, 0);

  motor.setup();

  Verify(Method(ArduinoFake(), pinMode).Using(0, OUTPUT) +
         Method(ArduinoFake(), pinMode).Using(0, OUTPUT) +
         Method(ArduinoFake(), pinMode).Using(0, OUTPUT));
}

void it_calculates_pin_output(void) {
  When(Method(ArduinoFake(), digitalWrite)).AlwaysReturn();
  When(Method(ArduinoFake(), analogWrite)).AlwaysReturn();

  Motor motor = Motor(0, 1, 2);

  motor.tick();

  Verify(Method(ArduinoFake(), digitalWrite).Using(0, LOW) +
         Method(ArduinoFake(), digitalWrite).Using(1, LOW) +
         Method(ArduinoFake(), analogWrite).Using(2, 0));
}


void it_calculates_pwm(void) {
  When(Method(ArduinoFake(), digitalWrite)).AlwaysReturn();
  When(Method(ArduinoFake(), analogWrite)).AlwaysReturn();

  Motor motor = Motor(0, 1, 2);

  motor.value = -0.5f; // -1.0f -> 255

  motor.tick();

  Verify(Method(ArduinoFake(), digitalWrite).Using(0, LOW) +
         Method(ArduinoFake(), digitalWrite).Using(1, HIGH) +
         Method(ArduinoFake(), analogWrite).Using(2, 127));
}


void it_constrains_value(void) {
  When(Method(ArduinoFake(), digitalWrite)).AlwaysReturn();
  When(Method(ArduinoFake(), analogWrite)).AlwaysReturn();

  Motor motor = Motor(0, 1, 2);

  motor.value = -2.0f; // -1.0f -> 255

  motor.tick();

  Verify(Method(ArduinoFake(), digitalWrite).Using(0, LOW) +
         Method(ArduinoFake(), digitalWrite).Using(1, HIGH) +
         Method(ArduinoFake(), analogWrite).Using(2, 255));
}

void it_runs_the_motor_forward(void) {
  When(Method(ArduinoFake(), digitalWrite)).AlwaysReturn();
  When(Method(ArduinoFake(), analogWrite)).AlwaysReturn();

  Motor motor = Motor(0, 1, 2);

  motor.value = 1.0f;

  motor.tick();

  Verify(Method(ArduinoFake(), digitalWrite).Using(0, HIGH) +
         Method(ArduinoFake(), digitalWrite).Using(1, LOW) +
         Method(ArduinoFake(), analogWrite).Using(2, 255));

}
int runTests(void) {
  UNITY_BEGIN();

  RUN_TEST(it_creates_a_new_motor);
  RUN_TEST(it_calculates_pin_output);
  RUN_TEST(it_calculates_pwm);
  RUN_TEST(it_constrains_value);
  RUN_TEST(it_runs_the_motor_forward);

  return UNITY_END();
}

#ifdef UNIT_TEST
int main(void) { return runTests(); }
#endif
