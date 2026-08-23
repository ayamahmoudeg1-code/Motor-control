#ifndef L298N_H
#define L298N_H

#include <Arduino.h>

class L298N : public MotorDriver
{
  private:
  // defining l298n pins 
  int ENA; 
  int IN1; 
  int IN2;

  public:
  L298N(int ENA, int IN1, int IN2): ENA(ENA), IN1(IN1), IN2(IN2){}

  void L298N_init();
  void Drive(int speed_in_pwm) const override;

}
#endif //L298N_H