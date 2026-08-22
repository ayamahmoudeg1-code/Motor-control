#ifndef CytronMD10A_H
#define  CytronMD10A_H

#include <Arduino.h>

void Cytron_init(int DIR,int PWM);
void Cytron_drive(int DIR,int PWM,int speed_in_pwm);

#endif //CytronMD10A_H