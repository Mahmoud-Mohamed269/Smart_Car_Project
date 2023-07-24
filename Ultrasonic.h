#ifndef Ultrasonic_h
#define Ultrasonic_h

#include <Arduino.h>

class ultrasonic{
private:
  byte _Trig_pin;
  byte _Echo_pin;
  byte _Max_dist = 200;

public:
  ultrasonic(byte trig_pin, byte echo_pin);
  int distance();
};
#endif