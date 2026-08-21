int IN1 = PA4;
int IN2 = PA5;
int ENA = PA3;
int potPin = PA2;
void setup() 
{
  Serial.begin(9600);
  
  pinMode(potPin, INPUT);
  void L298N_init(int IN1,int IN2,int ENA);
}

void loop() 
{
  int potVal=analogRead(potPin);
  int speed_in_pwm =map(potVal, 0, 4095, 0, 255);

  void L298N_drive(int IN1,int IN2, int ENA, int speed_in_pwm);
}
