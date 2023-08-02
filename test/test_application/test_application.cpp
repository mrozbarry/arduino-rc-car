#include "fakeit.hpp"
#include <ArduinoFake.h>
#include <Application.hpp>
#include <MotorLeft.hpp>
#include <MotorRight.hpp>
#include <unity.h>

using namespace fakeit;

void setUp(void) {}

void tearDown(void) {}

struct SomeInterface {
  virtual int setup(int) = 0;
};

void it_creates_a_new_application(void) {
  Mock<Tickable> left;
  Mock<Tickable> right;
  
  When(Method(left, setup)).AlwaysReturn();
  When(Method(right, setup)).AlwaysReturn();
  
  Application application = Application(&left.get(), &right.get());
  
  application.setup();
  
  Verify(
      Method(left, setup) +
      Method(right, setup)
  ).Exactly(1);
}


int runTests(void) {
  UNITY_BEGIN();

  RUN_TEST(it_creates_a_new_application);

  return UNITY_END();
}

#ifdef UNIT_TEST
int main(void) { return runTests(); }
#endif
