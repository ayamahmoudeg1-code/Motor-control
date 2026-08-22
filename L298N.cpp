#include "L298N.h"
#include <Arduino.h>
#include <iostream>

using namespace std;

//Initializing pins 
void L298N_init(int IN1, int IN2 , int ENA)
{
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);

  digitalWrite(IN1,LOW);
  digitalWrite(IN2,LOW);
  analogWrite(ENA,0);

}

// Main driving logic
void L298N_drive(int IN1,int IN2, int ENA, int speed_in_pwm)
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
    analogWrite(ENA, speed_in_pwm);

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