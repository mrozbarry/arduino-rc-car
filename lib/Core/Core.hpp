#pragma once

#ifdef TARGET_NATIVE

#include <ArduinoFake.h>

void delay(unsigned long milliseconds);
unsigned long millis();

#ifndef ifNative
#define ifNative(x) x
#endif
#ifndef ifArduino
#define ifArduino(x)
#endif


#else

#include <Arduino.h>

#ifndef ifNative
#define ifNative(x)
#endif
#ifndef ifArduino
#define ifArduino(x) x
#endif

#endif
