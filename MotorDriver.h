#ifndef Motor_Driver_H
#define Motor_Driver_H

class MotorDriver 
{
  
 public:


 virtual void Drive(int speed_in_pwm) const = 0; 

};

#endif //Motor_Driver_H 