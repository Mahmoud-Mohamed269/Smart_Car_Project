#ifndef LED_h
#define LED_h

#include<Arduino.h>

class LED
{
  //class code goes here
  public:
  LED(byte pin);
  void LED_is_ON();
  void LED_is_OFF();  

  private:
  byte _pin;
};

#endif