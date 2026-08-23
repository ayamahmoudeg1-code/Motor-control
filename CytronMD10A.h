#ifndef CytronMD10A_H
#define  CytronMD10A_H
#include "MotorDriver.h"
#include <Arduino.h>

class CytronMD10A : public MotorDriver
{
  private:
  // defining cytron pins
  int PWM;
  int DIR;
  //brand new info!
  // beacause I'm using cytron library, it creats object and only handles it through the library
  //but I want to use the OOP constructtor instead so "mutable" tells the compiler that this
  // motor it created can be changed using parent inherited method
  mutable CytronMD motor;


  public:

  CytronMD10A(int PWM, int DIR): PWM(PWM), DIR(DIR),  motor(PWM_DIR, PA6, PA12){}

  void Cytron_init();
  void Drive(int speed_in_pwm) const override;
};
#endif //CytronMD10A_H