#pragma once

#ifndef TARGET_NATIVE

#include <Arduino.h>

#ifndef ifNative
#define ifNative(x)
#endif
#ifndef ifArduino
#define ifArduino(x) x
#endif


#else
void delay(unsigned long milliseconds);
unsigned long millis();

#ifndef ifNative
#define ifNative(x) x
#endif
#ifndef ifArduino
#define ifArduino(x)
#endif

#endif
