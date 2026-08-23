#ifndef Motor_Driver_H
#define Motor_Driver_H

class MotorDriver 
{
  
 public:


 virtual void Drive(int speed_in_pwm)  = 0; //parent speed controlling method

};

#endif //Motor_Driver_H 