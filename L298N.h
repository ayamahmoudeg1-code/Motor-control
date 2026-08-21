#ifndef L298N_H
#define L298N_H

void L298N_init(int IN1,int IN2,int ENA);
void L298N_drive(int IN1,int IN2, int ENA, int speed_in_pwm);

#endif //L298N_H