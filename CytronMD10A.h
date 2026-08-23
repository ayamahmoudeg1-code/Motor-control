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
  CytronMD motor;


  public:

  CytronMD10A(int PWM, int DIR): PWM(PWM), DIR(DIR),  motor(PWM_DIR, PWM, DIR){} //constructor

  void Cytron_init();
  void Drive(int speed_in_pwm) override;
};
#endif //CytronMD10A_H