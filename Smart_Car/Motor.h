#ifndef MOTOR_h
#define MOTOR_h

#include<Arduino.h>

class Motor
{
  //class code goes here
  public:
  Motor(byte pin);
  void Motor_ON();
  void Motor_OFF();
  void set_speed(byte *speed);

  private:
  byte _pin;
};

#endif