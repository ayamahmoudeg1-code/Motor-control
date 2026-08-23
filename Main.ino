#include <CytronMotorDriver.h>
#include "MotorDriver.h"
#include "CytronMD10A.h"
#include "L298N.h"
#include "BTS7960.h"

#define potPin  PA2
// defining l298n pins 
#define ENA  PA3
#define IN1  PA4
#define IN2  PA5
// defining cytron pins
#define PWM  PA6
#define DIR  PA12
// defining BTS7960 pins
#define RPWM PA7
#define LPWM PA8
#define R_EN PB2
#define L_EN PB12


L298N motor(ENA, IN1, IN2);
CytronMD10A motor2(PWM, DIR);
BTS7960 motor3(RPWM, LPWM, R_EN, L_EN);
  
void setup() 
{
  Serial.begin(9600);
  
  analogReadResolution(12);     // 12-bit ADC range: 0 to 4095
  analogWriteFrequency(20000);  // Set 20kHz switching frequency

  pinMode(potPin, INPUT); // sitting potentiometer pin mode

  motor.L298N_init(); // Call initialization 
  motor2.Cytron_init(); // Call initialization 
  motor3.BTS_init(); // Call initialization


}

void loop() 
{
  /*New learned logic:
  mapping directly from -225 to 255 is more effiecient in forward and backward motion
  then manually dividing the mapping into the three stops(forward, mid point , backward) according to the potentiometer reading
    */
  int potVal=analogRead(potPin); // Reading potentiometer (controlling speed)
  int speed_in_pwm =0;
  // 1. Center Position Check (Deadband) -> STOP
  if (potVal >= 2000 && potVal <= 2100)
  {
    speed_in_pwm = 0; 
  }
  // 2. Knob is turned Left -> BACKWARD (outputs negative values: 0 down to -255)
  else if (potVal < 2000)
  {
    speed_in_pwm = map(potVal, 0, 1999, -255, 0); 
  }
  // 3. Knob is turned Right -> FORWARD (outputs positive values: 0 up to 255)
  else 
  {
    speed_in_pwm = map(potVal, 2101, 4095, 0, 255); 
  }

  motor.Drive(speed_in_pwm); // Calling L298N driving method
  motor2.Drive(speed_in_pwm);// Calling cytron driving method
  motor3.Drive(speed_in_pwm);// Calling BTS7960 driving method
  

}
