#ifndef IR_h
#define IR_h

#include<Arduino.h>

class IR
{
  //class code goes here
  public:
  IR(byte pin);
  byte IR ::IR_read();

  private:
  byte _pin;
};

#endif