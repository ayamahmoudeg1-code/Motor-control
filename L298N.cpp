#include "MotorDriver.h"
#include "L298N.h"
#include <Arduino.h>


//Initializing pins 
void L298N::L298N_init()
{
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);

  digitalWrite(IN1,LOW);
  digitalWrite(IN2,LOW);
  analogWrite(ENA,0);

}

// Main driving logic
void L298N::Drive(int speed_in_pwm) const 
{
  // forward movement
   if  (speed_in_pwm >0)
  {
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    analogWrite(ENA,speed_in_pwm);

    Serial.print("speed: ");
    Serial.println( speed_in_pwm);

    Serial.println("Moving forward");
    delay(3000);

  }
  // backward movement
  else if  (speed_in_pwm <0)
  {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    analogWrite(ENA, abs(speed_in_pwm));

    Serial.print("speed: ");
    Serial.println( speed_in_pwm);

    Serial.println("Moving backward");
    delay(3000);

  }
  // stopping
  else
  {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    analogWrite(ENA,0);
  
    Serial.println("Stopped. currently at rest");
    delay(3000);

  }
  
}