#include "MotorDriver.h"
#include "L298N.h"
#include <Arduino.h>


//setting pins mode
void L298N::L298N_init()
{
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);

  digitalWrite(IN1,LOW);
  digitalWrite(IN2,LOW);
  analogWrite(ENA,0);

}

// driving states
void L298N::Drive(int speed_in_pwm) 
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

  }
  // backward movement
  else if  (speed_in_pwm <0)
  {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    analogWrite(ENA, abs(speed_in_pwm)); //using abs beacuse the analogWrite expects non-negative magnitude PWM duty value

    Serial.print("speed: ");
    Serial.println( speed_in_pwm);

    Serial.println("Moving backward");

  }
  // stopping
  else
  {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    analogWrite(ENA,0);
  
    Serial.println("Stopped. currently at rest");

  }
  
}