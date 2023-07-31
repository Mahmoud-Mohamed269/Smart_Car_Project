/*
   -- Smart Car --
   
   This source code of graphical user interface 
   has been generated automatically by RemoteXY editor.
   To compile this code using RemoteXY library 3.1.8 or later version 
   download by link http://remotexy.com/en/library/
   To connect using RemoteXY mobile app by link http://remotexy.com/en/download/                   
     - for ANDROID 4.11.1 or later version;
     - for iOS 1.9.1 or later version;
    
   This source code is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.    
*/

//////////////////////////////////////////////
//        RemoteXY include library          //
//////////////////////////////////////////////

// RemoteXY select connection mode and include library 
#define REMOTEXY_MODE__SOFTSERIAL
#include <SoftwareSerial.h>

#include <RemoteXY.h>

// RemoteXY connection settings 
#define REMOTEXY_SERIAL_RX 52
#define REMOTEXY_SERIAL_TX 53
#define REMOTEXY_SERIAL_SPEED 9600
#define REMOTEXY_ACCESS_PASSWORD "Car"


// RemoteXY configurate  
#pragma pack(push, 1)
uint8_t RemoteXY_CONF[] =   // 311 bytes
  { 255,10,0,25,0,123,1,16,8,0,3,4,0,1,7,26,2,26,4,0,
  0,25,7,20,30,66,2,0,80,5,17,6,133,1,31,31,79,78,0,79,
  70,70,0,129,0,76,1,23,3,1,69,109,101,114,103,101,110,99,121,32,
  83,116,111,112,0,65,107,43,22,9,9,65,107,32,33,9,9,65,107,54,
  33,9,9,65,107,43,44,9,9,65,105,34,8,7,7,65,105,44,8,7,
  7,65,105,54,8,7,7,129,0,40,16,16,4,16,67,97,114,32,86,105,
  101,119,0,129,0,34,3,27,4,16,76,105,110,101,32,68,101,116,101,99,
  116,105,111,110,0,129,0,0,46,14,3,16,70,114,111,110,116,32,108,105,
  103,104,116,0,129,0,17,46,14,3,16,66,97,99,107,32,108,105,103,104,
  116,0,1,1,69,39,11,10,2,31,0,1,1,79,27,11,10,2,31,0,
  1,1,89,39,11,10,2,31,0,1,1,79,51,11,10,2,31,0,129,0,
  83,29,4,7,16,70,0,129,0,82,53,5,7,16,66,0,129,0,73,41,
  4,7,16,76,0,129,0,92,41,5,7,16,82,0,1,0,85,14,10,10,
  4,31,0,129,0,87,18,6,2,16,66,101,101,112,101,114,0,10,56,18,
  50,11,11,1,8,31,79,78,0,31,79,70,70,0,10,56,2,50,11,11,
  16,8,8,79,78,0,31,79,70,70,0,129,0,9,3,18,4,16,66,108,
  117,101,116,111,111,116,104,0,129,0,9,10,18,4,16,79,98,115,116,97,
  99,108,101,0,129,0,9,16,18,4,16,76,105,110,101,32,70,111,108,108,
  111,119,101,114,0,129,0,9,22,18,4,16,77,97,122,101,0,67,0,8,
  32,11,5,16,26,11 };
  
// this structure defines all the variables and events of your control interface 
struct {

    // input variables
  uint8_t Mode_select; // =0 if select position A, =1 if position B, =2 if position C, ... 
  int8_t speed_slider; // =0..100 slider position 
  uint8_t Emergency_stop_switch; // =1 if switch ON and =0 if OFF 
  uint8_t Left; // =1 if button pressed, else =0 
  uint8_t Forward; // =1 if button pressed, else =0 
  uint8_t Right; // =1 if button pressed, else =0 
  uint8_t Backward; // =1 if button pressed, else =0 
  uint8_t Beeper; // =1 if button pressed, else =0 
  uint8_t Back_light; // =1 if state is ON, else =0 
  uint8_t Front_light; // =1 if state is ON, else =0 

    // output variables
  uint8_t Front_view_r; // =0..255 LED Red brightness 
  uint8_t Front_view_g; // =0..255 LED Green brightness 
  uint8_t Left_view_r; // =0..255 LED Red brightness 
  uint8_t Left_view_g; // =0..255 LED Green brightness 
  uint8_t Right_view_r; // =0..255 LED Red brightness 
  uint8_t Right_view_g; // =0..255 LED Green brightness 
  uint8_t Back_view_r; // =0..255 LED Red brightness 
  uint8_t Back_view_g; // =0..255 LED Green brightness 
  uint8_t Left_line_r; // =0..255 LED Red brightness 
  uint8_t Left_line_g; // =0..255 LED Green brightness 
  uint8_t Center_line_r; // =0..255 LED Red brightness 
  uint8_t Center_line_g; // =0..255 LED Green brightness 
  uint8_t Right_line_r; // =0..255 LED Red brightness 
  uint8_t Right_line_g; // =0..255 LED Green brightness
  char Speed_Monitor[11];  // string UTF8 end zero 

    // other variable
  uint8_t connect_flag;  // =1 if wire connected, else =0 

} RemoteXY;
#pragma pack(pop)

/////////////////////////////////////////////
//           END RemoteXY include          //
/////////////////////////////////////////////

//////////////////////////////////////////////
//        Ultrasonic include file          //
//////////////////////////////////////////////

#include "Ultrasonic.h"
/*create ultrasonic objects*/
ultrasonic s1(2,3);   /*Front Sensor*/
ultrasonic s2(4,5);   /*Back Sensor*/
ultrasonic s3(6,7);   /*Right Sensor*/
ultrasonic s4(8,9);   /*Left Sensor*/

//////////////////////////////////////////////
//        END Ultrasonic include          //
//////////////////////////////////////////////

//////////////////////////////////////////////
//        LED include  file        //
//////////////////////////////////////////////

#include "LED.h"
/*create LED objects*/
LED front_right_led_1(22);
LED front_right_led_2(23);
LED front_right_led_3(24);

LED front_left_led_1(25);
LED front_left_led_2(26);
LED front_left_led_3(27);

LED back_right_led_1(28);
LED back_right_led_2(29);
LED back_right_led_3(30);

LED back_left_led_1(31);
LED back_left_led_2(32);
LED back_left_led_3(33);

//////////////////////////////////////////////
//        END LED include          //
//////////////////////////////////////////////

//////////////////////////////////////////////
//        IR include file          //
//////////////////////////////////////////////

#include "IR.h"
/*create IR objects*/
IR Right_IR(10);                  /*Right sensor*/
IR Center_IR(11);                 /*Center sensor*/
IR Left_IR(12);                   /*Left sensor*/
bool line_detection[3];           /*Array for storing line detections*/

//////////////////////////////////////////////
//        END IR include          //
//////////////////////////////////////////////

//////////////////////////////////////////////
//        Motor include file        //
//////////////////////////////////////////////
#include "Motor.h"
/*create Motor objects*/
Motor Forward_Right_Motor(41);
Motor Backward_Right_Motor(40);
Motor Forward_Left_Motor(42);
Motor Backward_Left_Motor(43);
Motor Right_Speed(44);
Motor Left_Speed(45);

/*Functions for Directions*/
void forward();
void backward();
void right();
void left();
void stop();

//////////////////////////////////////////////
//        END Motor include          //
//////////////////////////////////////////////

byte speed;                     /*Global Variable for Motros' speed control*/

#define PIN_BEEPER 46           /*define the buzzer pin*/

/*The declaration of needed functions*/
void Bluetooth_Mode();

void Obstacle_Mode();
//time counting instead of delay
unsigned long previous_time[3] = {0}; //array used for storing the previous time for stop, backward and turn right or left
unsigned long current_time;           //store the current time
#define turn_interval 700             //interval for turning right or left
#define back_interval 500             //interval for going back
#define stop_interval 500             //interval to stop the motors

void Line_Follower_Mode();

void setup() 
{
  //initialize the application 
  RemoteXY_Init ();

  //initialize the buzzer pin as output 
  pinMode (PIN_BEEPER, OUTPUT);

  //set the application's indicators as green
  RemoteXY.Front_view_r = 0;
  RemoteXY.Front_view_g = 255;
  RemoteXY.Back_view_r = 0;
  RemoteXY.Back_view_g = 255;
  RemoteXY.Right_view_r = 0;
  RemoteXY.Right_view_g = 255;
  RemoteXY.Left_view_r = 0;
  RemoteXY.Left_view_g = 255;

  RemoteXY.Left_line_r = 0;
  RemoteXY.Left_line_g = 255;
  RemoteXY.Center_line_r = 0;
  RemoteXY.Center_line_g = 255;
  RemoteXY.Right_line_r = 0;
  RemoteXY.Right_line_g = 255;
}

void loop() 
{ 
  RemoteXY_Handler ();

/*******************************************************************/
/*Turning on the beeper*/

if(RemoteXY.Beeper)
{
  tone(PIN_BEEPER, 480);  //set the buzzer tone on
}
else
{
  noTone(PIN_BEEPER);     //set the buzzer tone off
}
/*******************************************************************/

/*******************************************************************/
/*apply the needed speed from the slider*/

speed = RemoteXY.speed_slider;            //reading from the slider
speed = map(speed, 0, 100, 0, 255);       //map the reading to be between 0 & 255
itoa (speed, RemoteXY.Speed_Monitor, 10); //display the reading on the application
Right_Speed.set_speed(&speed);            //set the speed to the right side of motors
Left_Speed.set_speed(&speed);             //set the speed to the left side of motors

/*******************************************************************/

/*******************************************************************/
/*Flashing Front and Back Lights*/

if (RemoteXY.Front_light!=0)
{
  /*  button pressed, set the front LEDs on */
  front_right_led_1.LED_is_ON();
  front_right_led_2.LED_is_ON();
  front_right_led_3.LED_is_ON();
  front_left_led_1.LED_is_ON();
  front_left_led_2.LED_is_ON();
  front_left_led_3.LED_is_ON();
}
  else
{
  /*  button not pressed, set the front LEDs off */
  front_right_led_1.LED_is_OFF();
  front_right_led_2.LED_is_OFF();
  front_right_led_3.LED_is_OFF();
  front_left_led_1.LED_is_OFF();
  front_left_led_2.LED_is_OFF();
  front_left_led_3.LED_is_OFF();
}
if (RemoteXY.Back_light!=0)
{
  /*  button pressed, set the back LEDs on */
  back_right_led_1.LED_is_ON();
  back_right_led_2.LED_is_ON();
  back_right_led_3.LED_is_ON();
  back_left_led_1.LED_is_ON();
  back_left_led_2.LED_is_ON();
  back_left_led_3.LED_is_ON();
}
  else
{
  /*  button not pressed, set the back LEDs off */
  back_right_led_1.LED_is_OFF();
  back_right_led_2.LED_is_OFF();
  back_right_led_3.LED_is_OFF();
  back_left_led_1.LED_is_OFF();
  back_left_led_2.LED_is_OFF();
  back_left_led_3.LED_is_OFF();
}
/*******************************************************************/

/*******************************************************************/
//check the car modes

  switch (RemoteXY.Mode_select) {
    case 0:
      /*  current position A */
      Bluetooth_Mode();         //call the bluetooth mode
      break;
    case 1:
      /*  current position B */
      Obstacle_Mode();          //call the obstacle mode
      break;
    case 2:
      /*  current position C */
      Line_Follower_Mode();     //call the line follower mode
      break;
    case 3:
      /*  current position D */
      //Maze_Mode();            //call the maze mode
      break;
  }
}

/*******************************************************************/

/*******************************************************************/
/*The definition of needed functions*/

void Bluetooth_Mode()
{
/*******************************************************************/
/*checking the switch*/

if (RemoteXY.Emergency_stop_switch!=0) {
    /*  switch on  */
    stop();                           //call the stop function
    Right_Speed.set_speed(0);         //set the right side speed to zero
    Left_Speed.set_speed(0);          //set the left side speed to zero
  }

/*******************************************************************/
  if (RemoteXY.Forward!=0)
    {
      /*  button pressed */
      forward();                      //call the forward function
    }
  /*******************************************************************/
  else if (RemoteXY.Backward!=0) 
  {
    /*  button pressed */
    backward();                       //call the backward function
  }
  /*******************************************************************/
  else if (RemoteXY.Right!=0)
  {
    /*  button pressed */
    right();                          //call the right function
  }
  /*******************************************************************/
  else if (RemoteXY.Left!=0)
  {
    /*  button pressed */
    left();                           //call the left function
  }
  /*******************************************************************/
  else 
  {
    /*  button not pressed */
    stop();                           //call the stop function
  }

  byte d1 = s1.distance();            //reading from front sensor
  if(d1 < 20)                         //check the distance
  {
    RemoteXY.Front_view_r = 255;      //set the indicator to be red
    RemoteXY.Front_view_g = 0;
    stop();                           //call the stop function
    Right_Speed.set_speed(0);         //set the right side speed to zero
    Left_Speed.set_speed(0);          //set the left side speed to zero

    /*check for pressing any button to avoid the obstacle*/
    if(RemoteXY.Backward!=0)
    {
      /*  button pressed */
      backward();                     //call the backward function
      Right_Speed.set_speed(&speed);  //set the speed to the right side of motors
      Left_Speed.set_speed(&speed);   //set the speed to the left side of motors
    }
    else if(RemoteXY.Right!=0)
    {
      /*  button pressed */
      right();                        //call the right function
      Right_Speed.set_speed(&speed);  //set the speed to the right side of motors
      Left_Speed.set_speed(&speed);   //set the speed to the left side of motors
    }
    else if(RemoteXY.Left!=0)
    {
      /*  button pressed */
      left();                         //call the left function
      Right_Speed.set_speed(&speed);  //set the speed to the right side of motors
      Left_Speed.set_speed(&speed);   //set the speed to the left side of motors
    }
  }
  /*******************************************************************/
  else
  {
    Right_Speed.set_speed(0);           //set the right speed to be zero
    Left_Speed.set_speed(0);            //set the left speed to be zero
    RemoteXY.Front_view_r = 0;          //set the indicator to be green
    RemoteXY.Front_view_g = 255;
  }
  /*******************************************************************/
  byte d2 = s2.distance();              //reading from back sensor
  if(d2 < 20)                           //check the distance
  {
    RemoteXY.Back_view_r = 255;         //set the indicator to be red
    RemoteXY.Back_view_g = 0;
    stop();                             //call the stop function
    Right_Speed.set_speed(0);           //set the right side speed to zero
    Left_Speed.set_speed(0);            //set the left side speed to zero
    /*check for pressing any button to avoid the obstacle*/
    if(RemoteXY.Forward!=0)
    {
      /*  button pressed */
      forward();                        //call the forward function
      Right_Speed.set_speed(&speed);    //set the speed to the right side of motors
      Left_Speed.set_speed(&speed);     //set the speed to the left side of motors
    }
    else if(RemoteXY.Right!=0)
    {
      /*  button pressed */
      right();                          //call the right function
      Right_Speed.set_speed(&speed);    //set the speed to the right side of motors
      Left_Speed.set_speed(&speed);     //set the speed to the left side of motors
    }
    else if(RemoteXY.Left!=0)
    {
      /*  button pressed */
      left();                             //call the right function
      Right_Speed.set_speed(&speed);      //set the speed to the right side of motors
      Left_Speed.set_speed(&speed);       //set the speed to the left side of motors
    }
  }
  /*******************************************************************/
  else
  {
    Right_Speed.set_speed(0);             //set the right side speed to zero
    Left_Speed.set_speed(0);              //set the left side speed to zero
    RemoteXY.Back_view_r = 0;             //set the indicator to be green
    RemoteXY.Back_view_g = 255;
  }
  /*******************************************************************/
  byte d3 = s3.distance();                //reading from right sensor
  if(d3 < 20)                             //check the distance
  {
    RemoteXY.Right_view_r = 255;          //set the indicator to be red
    RemoteXY.Right_view_g = 0;
    stop();                               //call the stop function
    Right_Speed.set_speed(0);             //set the right side speed to zero
    Left_Speed.set_speed(0);              //set the left side speed to zero
    /*check for pressing any button to avoid the obstacle*/
    if(RemoteXY.Forward!=0)
    {
      /*  button pressed */
      forward();                           //call the forward function
      Right_Speed.set_speed(&speed);       //set the speed to the right side of motors
      Left_Speed.set_speed(&speed);        //set the speed to the left side of motors
    }
    else if(RemoteXY.Backward!=0)
    {
      /*  button pressed */
      backward();                         //call the backward function
      Right_Speed.set_speed(&speed);      //set the speed to the left side of motors
      Left_Speed.set_speed(&speed);       //set the speed to the left side of motors
    }
    else if(RemoteXY.Left!=0)
    {
      /*  button pressed */
      left();                             //call the left function
      Right_Speed.set_speed(&speed);      //set the speed to the right side of motors
      Left_Speed.set_speed(&speed);       //set the speed to the left side of motors
    }
  }
  /*******************************************************************/
  else
  {
    Right_Speed.set_speed(0);              //set the right side speed to zero
    Left_Speed.set_speed(0);               //set the left side speed to zero
    RemoteXY.Right_view_r = 0;             //set the indicator to be green
    RemoteXY.Right_view_g = 255;
  }
  /*******************************************************************/
  byte d4 = s4.distance();                 //reading from left sensor
  if(d4 < 20)                              //check the distance
  {
    RemoteXY.Left_view_r = 255;            //set the indicator to be red
    RemoteXY.Left_view_g = 0;
    stop();                                //call the stop function
    Right_Speed.set_speed(0);              //set the right side speed to zero
    Left_Speed.set_speed(0);               //set the left side speed to zero
    /*check for pressing any button to avoid the obstacle*/
    if(RemoteXY.Forward!=0)
    {
      /*  button pressed */
      forward();                           //call the forward function
      Right_Speed.set_speed(&speed);       //set the speed to the right side of motors
      Left_Speed.set_speed(&speed);        //set the speed to the left side of motors
    }
    else if(RemoteXY.Backward!=0)
    {
      /*  button pressed */
      backward();                          //call the backward function
      Right_Speed.set_speed(&speed);       //set the speed to the right side of motors
      Left_Speed.set_speed(&speed);        //set the speed to the left side of motors
    }
    else if(RemoteXY.Right!=0)
    {
      /*  button pressed */
      right();                             //call the right function
      Right_Speed.set_speed(&speed);       //set the speed to the right side of motors
      Left_Speed.set_speed(&speed);        //set the speed to the left side of motors
    }
  }
  /*******************************************************************/
  else
  {
    Right_Speed.set_speed(0);               //set the right side speed to zero
    Left_Speed.set_speed(0);                //set the left side speed to zero
    RemoteXY.Left_view_r = 0;               //set the indicator to be green
    RemoteXY.Left_view_g = 255;
  }
  /*******************************************************************/
}

void Obstacle_Mode()
{
  /*******************************************************************/
  /*checking the switch*/

  if (RemoteXY.Emergency_stop_switch!=0)  //check the emergency slider
  {
    /*  switch on  */
    stop();                               //call the stop function
    Right_Speed.set_speed(0);             //set the right side speed to zero
    Left_Speed.set_speed(0);              //set the left side speed to zero
  }
  /*******************************************************************/
  current_time = millis();                //read the current time from arduino timer in milli seconds

  byte Front_View = s1.distance();        //read the distance from front senor

  if(Front_View >= 35)                    //check the front sensor if it not detectes any obstacle
  {
    forward();                            //call the forward function
    RemoteXY.Front_view_r = 0;            //set the indicator to be green
    RemoteXY.Front_view_g = 255;
  }
  /*******************************************************************/
  else
  {
    RemoteXY.Front_view_r = 255;          //set the indicator to be red
    RemoteXY.Front_view_g = 0;
    /*Stop interval*/
    /*wait for the car to stop for duration 500 ms*/
    if(current_time - previous_time[0] >= stop_interval)
    {
      stop();                            //call the stop function
      previous_time[0] = current_time;   //update the prevoius time of stop to the current time of stop
    }
    /*******************************************************************/
    /*backward interval*/
    /*wait for the car to move backward 500 ms*/
    if(current_time - previous_time[1] >= back_interval)
    {
      backward();                       //call the backward function
      previous_time[1] = current_time;  //update the prevoius time of backward to the current time of backward
    }
    /*******************************************************************/
    /*Stop interval*/
    /*wait for the car to stop for duration 500 ms*/
    if(current_time - previous_time[0] >= stop_interval)
    {
      stop();                           //call the stop function
      previous_time[0] = current_time;  //update the prevoius time of stop to the current time of stop
    }
    /*checks the side views of the car*/
    byte Right_View = s3.distance();    //read from the right sensor
    byte Left_View = s4.distance();     //read from the left sensor
    /*******************************************************************/
    if(Right_View > Left_View)          //check if the right distance is bigger than the left distance
    {
      RemoteXY.Right_view_r = 0;        //set the right indicator to be green 
      RemoteXY.Right_view_g = 255;
      RemoteXY.Left_view_r = 255;       //set the left indicator to be red
      RemoteXY.Left_view_g = 0;
      /*turn interval*/
      /*wait for the car to turn right for 700 ms*/
      if(current_time - previous_time[2] >= turn_interval)
      {
        right();                          //call the right function
        previous_time[2] = current_time;  //update the prevoius time of right to the current time of right
      }
    /*******************************************************************/
    /*Stop interval*/
    /*wait for the car to stop for duration 500 ms*/
      if(current_time - previous_time[0] >= stop_interval)
      {
        stop();                           //call the stop function
        previous_time[0] = current_time;  //update the prevoius time of stop to the current time of stop
      }
    }
    /*******************************************************************/
    else
    {
      RemoteXY.Right_view_r = 255;        //set the right indicator to be red
      RemoteXY.Right_view_g = 0;
      RemoteXY.Left_view_r = 0;           //set the left indicator to be green
      RemoteXY.Left_view_g = 255;
      /*turn interval*/
      /*wait for the car to turn left for 700 ms*/
      if(current_time - previous_time[2] >= turn_interval)
      {
        left();                           //call the left function
        previous_time[2] = current_time;  //update the prevoius time of left to the current time of left
      }
      /*******************************************************************/
    /*Stop interval*/
    /*wait for the car to stop for duration 500 ms*/
      if(current_time - previous_time[0] >= stop_interval)
      {
        stop();                           //call the stop function
        previous_time[0] = current_time;  //update the prevoius time of stop to the current time of stop
      }
    }
  }
  /*******************************************************************/
}

void Line_Follower_Mode()
{
  /*******************************************************************/
  /*checking the switch*/

  if (RemoteXY.Emergency_stop_switch!=0)
  {
    /*  switch on  */
    stop();                             //call the stop function
    Right_Speed.set_speed(0);           //set the right speed to be zero
    Left_Speed.set_speed(0);            //set the left speed to be zero
  }
  /*******************************************************************/
  /*******************************************************************/
  line_detection[0] = Right_IR.IR_read();   //store the right sensor reading in the first index
  line_detection[1] = Center_IR.IR_read();  //store the center sensor reading in the second index
  line_detection[2] = Left_IR.IR_read();    //store the left sensor reading in the third index
  /*******************************************************************/
  /*check if the center sensor detects the line, the car moves forward*/
  if((line_detection[0] == 0) && (line_detection[1] == 1) && (line_detection[2] == 0))
  {
    forward();                             //call the forward function
    RemoteXY.Center_line_r = 255;          //set the center indicator to be red
    RemoteXY.Center_line_g = 0;
  }
  /*******************************************************************/
  /*check if the right sensor detects the line, the car moves right*/
  else if((line_detection[0] == 1) && (line_detection[1] == 0) && (line_detection[2] == 0))
  {
    right();                              //call the right function
    RemoteXY.Right_line_r = 255;          //set the right indicator to be red          
    RemoteXY.Right_line_g = 0;
  }
  /*******************************************************************/
  /*check if the left sensor detects the line, the car moves left*/
  else if((line_detection[0] == 0) && (line_detection[1] == 0) && (line_detection[2] == 1))
  {
    left();                               //call the left function
    RemoteXY.Left_line_r = 255;           //set the left indicator to be red
    RemoteXY.Left_line_g = 0;
  }
  /*******************************************************************/
  /*check if the right, center and left sensors detect the line, the car stops*/
  else if((line_detection[0] == 1) && (line_detection[1] == 1) && (line_detection[2] == 1))
  {
    stop();                               //call the stop function
    RemoteXY.Center_line_r = 255;         //set the center indicator to be red
    RemoteXY.Center_line_g = 0;
    RemoteXY.Right_line_r = 255;          //set the right indicator to be red
    RemoteXY.Right_line_g = 0;
    RemoteXY.Left_line_r = 255;           //set the left indicator to be red
    RemoteXY.Left_line_g = 0;
  }
  /*******************************************************************/
  else
  {
    RemoteXY.Center_line_r = 0;           //set the center indicator to be green
    RemoteXY.Center_line_g = 255;
    RemoteXY.Right_line_r = 0;            //set the right indicator to be green
    RemoteXY.Right_line_g = 255;
    RemoteXY.Left_line_r = 0;             //set the left indicator to be green
    RemoteXY.Left_line_g = 255;
  }
  /*******************************************************************/
}
/*******************************************************************/
void forward()
{
  Forward_Right_Motor.Motor_ON();       //set the forward right motor on
  Backward_Right_Motor.Motor_OFF();     //set the backward right motor off
  Forward_Left_Motor.Motor_ON();        //set the forward left motor on
  Backward_Left_Motor.Motor_OFF();      //set the backward left motor off
}
/*******************************************************************/
  void backward()
{
  Forward_Right_Motor.Motor_OFF();      //set the forward right motor off
  Backward_Right_Motor.Motor_ON();      //set the backward right motor on
  Forward_Left_Motor.Motor_OFF();       //set the forward left motor off
  Backward_Left_Motor.Motor_ON();       //set the backward left motor on
  /*turn on the back LEDs*/
  back_right_led_1.LED_is_ON();
  back_right_led_2.LED_is_ON();
  back_right_led_3.LED_is_ON();
  back_left_led_1.LED_is_ON();
  back_left_led_2.LED_is_ON();
  back_left_led_3.LED_is_ON();
}
/*******************************************************************/
void right()
{
  Forward_Right_Motor.Motor_OFF();    //set the forward right motor off
  Backward_Right_Motor.Motor_ON();    //set the backward right motor on
  Forward_Left_Motor.Motor_ON();      //set the forward left motor on
  Backward_Left_Motor.Motor_OFF();    //set the backward left motor off
}
/*******************************************************************/
void left()
{
  Forward_Right_Motor.Motor_ON();     //set the forward right motor on
  Backward_Right_Motor.Motor_OFF();   //set the backward right motor off
  Forward_Left_Motor.Motor_OFF();     //set the forward left motor off
  Backward_Left_Motor.Motor_ON();     //set the backward left motor on
}
/*******************************************************************/
void stop()
{
  Forward_Right_Motor.Motor_OFF();     //set the forward right motor off
  Backward_Right_Motor.Motor_OFF();    //set the backward right motor off
  Forward_Left_Motor.Motor_OFF();      //set the forward left motor off
  Backward_Left_Motor.Motor_OFF();     //set the backward left motor off
}
/*******************************************************************/