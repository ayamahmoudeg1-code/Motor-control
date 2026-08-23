#ifndef CytronMD10A_H
#define  CytronMD10A_H

#include <Arduino.h>

class CytronMD10A : public MotorDriver
{
  private:
  // defining cytron pins
  int PWM;
  int DIR;


  public:

  CytronMD10A(int PWM, int DIR): PWM(PWM), DIR(DIR){}

  void Cytron_init();
  void Drive(int speed_in_pwm) const override;
}
#endif //CytronMD10A_H