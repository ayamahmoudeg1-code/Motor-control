#ifndef  BTS7960_H
#define  BTS7960_H
#include "MotorDriver.h"
#include <Arduino.h>

class BTS7960 : public MotorDriver
{
  private:
  // defining BTS7960 pins
  int RPWM ;
  int LPWM ;
  int R_EN ;
  int L_EN ;
  
  public:

  BTS7960(int RPWM, int LPWM, int R_EN, int L_EN): RPWM(RPWM), LPWM(LPWM), R_EN(R_EN), L_EN(L_EN) {}

  void BTS_init();
  void Drive(int speed_in_pwm) const override;

};

#endif //BTS7960_H