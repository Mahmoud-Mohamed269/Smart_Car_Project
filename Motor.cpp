#include "Motor.h"

Motor :: Motor(byte pin){
  pinMode(pin, OUTPUT);
  _pin = pin;
}

void Motor :: Motor_ON(){
  digitalWrite(_pin, HIGH);
}

void Motor :: Motor_OFF(){
  digitalWrite(_pin, LOW);
}

void Motor :: set_speed(byte *speed){
  analogWrite(_pin, *speed);
}