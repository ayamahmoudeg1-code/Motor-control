#include "MotorDriver.h"
#include "BTS7960.h"
#include <Arduino.h>

//setting pins mode
void BTS7960::BTS_init()
{
  pinMode(RPWM, OUTPUT);
  pinMode(LPWM, OUTPUT);
  //BTS7960 enable pins
  pinMode(R_EN, OUTPUT);
  pinMode(L_EN, OUTPUT);
  //Enable the driver
  digitalWrite(R_EN, HIGH);
  digitalWrite(L_EN, HIGH);
 
}

// driving states
void BTS7960::Drive(int speed_in_pwm) 
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
    analogWrite(LPWM,abs(speed_in_pwm)); //using abs beacuse the analogWrite expects non-negative magnitude PWM duty value


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