#include "CytronMotorDriver.h"
#include "CytronMD10A.h"
#include <Arduino.h>
#include <iostream>

CytronMD motor1(PWM_DIR, PA6, PA12);

void Cytron_init(int DIR,int PWM) 
{

  //Pins mode is handeled by the cytron library internally. No complex code needed
}

void Cytron_drive(int DIR,int PWM,int speed_in_pwm)
{
  if (speed_in_pwm> 0)
  {
    motor1.setSpeed(speed_in_pwm);

    Serial.print("cytron speed: ");
    Serial.println( speed_in_pwm);

    Serial.println("Moving forward");
  }
  else if (speed_in_pwm < 0 )
  {
    motor1.setSpeed(speed_in_pwm);

    Serial.print("cytron speed: ");
    Serial.println( speed_in_pwm);

    Serial.println("Moving backward");
  }
  else
  {
    motor1.setSpeed(0);
     
    Serial.println("Stopped. currently at rest");
    
  }
}