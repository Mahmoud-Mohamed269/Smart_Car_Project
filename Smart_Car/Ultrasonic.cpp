#include "Ultrasonic.h"

unsigned long prev_time[3] = {0}; //storing the previous time
unsigned long curr_time;  //storing the current time

ultrasonic :: ultrasonic(byte trig_pin, byte echo_pin){
  pinMode(trig_pin, OUTPUT);
  pinMode(echo_pin, INPUT);
_Trig_pin = trig_pin;
_Echo_pin = echo_pin;
}

int ultrasonic :: distance(){
  curr_time = micros();
  if(curr_time - prev_time[0] >= 5)
  {
    digitalWrite(_Trig_pin, LOW);
    prev_time[0] = curr_time;
  }
  if(curr_time - prev_time[1] >= 10)
  {
    digitalWrite(_Trig_pin, HIGH);
    prev_time[0] = curr_time;
  }
  digitalWrite(_Trig_pin, LOW);
  
  int duration = pulseIn(_Echo_pin, HIGH);
  int cm = (duration/2) / 29.1;
return cm;
}