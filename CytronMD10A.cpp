#include "CytronMotorDriver.h"
#include "MotorDriver.h"
#include "CytronMD10A.h"
#include <Arduino.h>


void CytronMD10A::Cytron_init() 
{

  //Pins mode is handeled by the cytron library internally. No complex code needed
}

void CytronMD10A::Drive(int speed_in_pwm) const 
{
  if (speed_in_pwm> 0)
  {
    motor.setSpeed(speed_in_pwm);

    Serial.print("cytron speed: ");
    Serial.println( speed_in_pwm);

    Serial.println("Moving forward");
    delay(3000);
  }
  else if (speed_in_pwm < 0 )
  {
    motor.setSpeed(abs(speed_in_pwm));

    Serial.print("cytron speed: ");
    Serial.println( speed_in_pwm);

    Serial.println("Moving backward"); 
    delay(3000);

  }
  else
  {
    motor.setSpeed(0);
     
    Serial.println("Stopped. currently at rest");
    delay(3000);

    
  }
}