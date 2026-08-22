#ifndef  BTS7960_H
#define  BTS7960_H

#include <Arduino.h>

void BTS_init(int RPWM, int LPWM);
void BTS_drive(int RPWM, int LPWM, int speed_in_pwm);

#endif //BTS7960_H