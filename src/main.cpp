#include <Application.hpp>
#include <Core.hpp>
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
  app.tick();
}


#ifdef TARGET_NATIVE
int main() {
  ifNative(cout << "main" << endl);
  setup();

  ifNative(cout << "entering loop" << endl);
  for(;;) {
    ifNative(cout << millis() << endl);
    loop();
  }
  ifNative(cout << "exiting loop" << endl);

  return 0;
}
#endif
