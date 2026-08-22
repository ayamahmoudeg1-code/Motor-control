#include "BTS7960.h"

#include <Arduino.h>
#include <iostream>

void BTS_init(int RPWM, int LPWM)
{
  pinMode(RPWM, OUTPUT);
  pinMode(LPWM, OUTPUT);
 
}

void BTS_drive(int RPWM, int LPWM, int speed_in_pwm)
{
  // forward movement
   if  (speed_in_pwm >0)
  {
    analogWrite(RPWM,speed_in_pwm);
    analogWrite(LPWM,0);

    Serial.print("BTS speed: ");
    Serial.println( speed_in_pwm);

    Serial.println("Moving forward");
  }
  // backward movement
  else if  (speed_in_pwm <0)
  {
    analogWrite(RPWM,0);
    analogWrite(LPWM,speed_in_pwm);

    Serial.print("BTS speed: ");
    Serial.println( speed_in_pwm);

    Serial.println("Moving backward");
  }
  // stopping
  else
  {
    
    analogWrite(RPWM,0);
    analogWrite(LPWM,0);

    Serial.println("Stopped. currently at rest");
  }
}