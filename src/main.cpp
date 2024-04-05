#include <Application.hpp>
#include <Core.hpp>
#include <Bluepad32.h>
#include <MotorLeft.hpp>
#include <MotorRight.hpp>
#ifdef TARGET_NATIVE
#include <iostream>
using std::cout;
using std::endl;
#endif

Application *app = NULL;

void onControllerConnect(ControllerPtr controller)
{
}

void onControllerDisconnect(ControllerPtr controller)
{
}

void setup() {
  ifNative(cout << "Hello world" << endl);
  app = new Application(
      new MotorLeft(),
      new MotorRight(),
  );
  app.setup();

  BP32.setup(
    &onControllerConnect,
    &onControllerDisconnect
  );
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
