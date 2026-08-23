#include "CytronMotorDriver.h"
#include "MotorDriver.h"
#include "CytronMD10A.h"
#include <Arduino.h>


CytronMD motor1(PWM_DIR, PA6, PA12);

void CytronMD10A::Cytron_init() 
{

  //Pins mode is handeled by the cytron library internally. No complex code needed
}

void Drive(int speed_in_pwm) const override 
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
    motor1.setSpeed(abs(speed_in_pwm));

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