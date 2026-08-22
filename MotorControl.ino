#include <CytronMotorDriver.h>

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



  
void setup() 
{
  Serial.begin(9600);
  
  analogReadResolution(12);     // 12-bit ADC range: 0 to 4095
  analogWriteFrequency(20000);  // Set 20kHz switching frequency

  pinMode(potPin, INPUT); // sitting potentiometer pin mode

  //BTS7960 enable pins
  pinMode(R_EN, OUTPUT);
  pinMode(L_EN, OUTPUT);
  //Enable the driver
  digitalWrite(R_EN, HIGH);
  digitalWrite(L_EN, HIGH);


  L298N_init(IN1,IN2,ENA); // Call initialization 
  Cytron_init(DIR,PWM); // Call initialization 
  BTS_init(RPWM,LPWM); // Call initialization


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

  L298N_drive(IN1,IN2,ENA,speed_in_pwm); // Calling L298N driving method
  Cytron_drive(DIR,PWM,speed_in_pwm); // Calling cytron driving method
  BTS_drive(RPWM,LPWM,speed_in_pwm); // Calling BTS7960 driving method
  

}
