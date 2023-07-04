#include <unity.h>


void setUp(void) {
}

void tearDown(void) {
}

void it_something(void)
{
  TEST_ASSERT_TRUE_MESSAGE(false, "Test not implemented");
}

// int runTests(void) {
//   UNITY_BEGIN();
// 
//   RUN_TEST(it_something);
// 
//   return UNITY_END();
// }

#ifdef UNIT_TEST
int main(void) {
  return runTests();
}
#endif

