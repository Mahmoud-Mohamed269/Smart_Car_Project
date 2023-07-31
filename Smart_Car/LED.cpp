#include "LED.h"

LED :: LED(byte pin){
  pinMode(pin, OUTPUT);
  _pin = pin;
}

void LED ::LED_is_ON(){
  digitalWrite(_pin, HIGH);
}

void LED ::LED_is_OFF(){
  digitalWrite(_pin, LOW);
}