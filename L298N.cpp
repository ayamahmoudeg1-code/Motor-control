#include "L298N.h"
#include <Arduino.h>
#include <iostream>

using namespace std;

void L298N_init(int IN1, int IN2 , int ENA)
{
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);

  digitalWrite(IN1,LOW);
  digitalWrite(IN2,LOW);
  analogWrite(ENA,0);

}

void L298N_drive(int IN1,int IN2, int ENA, int speed_in_pwm)
{
   if  (speed_in_pwm >0)
  {
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    analogWrite(ENA,speed_in_pwm);

    Serial.println("speed: ");
    Serial.println( speed_in_pwm);

    Serial.println("Moving forward");
  }
  else if  (speed_in_pwm <0)
  {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    analogWrite(ENA,-speed_in_pwm);

    Serial.println("speed: ");
    Serial.println( speed_in_pwm);

    Serial.println("Moving backward");
  }
  else
  {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    analogWrite(ENA,0);

    Serial.println("speed: ");
    Serial.println( speed_in_pwm);

    Serial.println("Stopped. currently at rest");
  }
  
}