#include "Application.hpp"
#include "Core.hpp"
#ifdef TARGET_NATIVE
#include <iostream>
using std::cout;
using std::endl;
#endif

Application app = Application();

void setup() {
  ifNative(cout << "Hello world" << endl);
  app.setup();
}

void loop() {
  app.loop();
}


#ifdef TARGET_NATIVE
int main() {
  ifNative(cout << "main" << endl);
  setup();

  ifNative(cout << "entering loop" << endl);
  for(;;) {
    cout << millis() << endl;
    loop();
    delay(1000);
  }
  ifNative(cout << "exiting loop" << endl);

  return 0;
}
#endif
