#include "IR.h"

IR :: IR(byte pin){
  pinMode(pin, INPUT);
  _pin = pin;
}

byte IR ::IR_read(){
  return digitalRead(_pin);
}