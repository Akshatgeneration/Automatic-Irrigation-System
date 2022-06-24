#include <AFMotor.h>

AF_DCMotor motor1(1, MOTOR12_1KHZ); 
int msensor = A0;
int msvalue = 0; 
int led = 13; 
boolean flag = false; 
void setup() {
  Serial.begin(9600);
  pinMode(msensor, INPUT);
  pinMode(led, OUTPUT);  
}
 
void loop() {
  msvalue = analogRead(msensor);
  Serial.println(msvalue);
  
  if ( (msvalue >= 500  ) && ( flag == false ) )
{
  digitalWrite(led, HIGH); 
   motor1.setSpeed(225); 
  motor1.run(FORWARD); 
  flag = true; 
  delay(1000); 
}
 
  if ( (msvalue <= 300  ) && ( flag == true ) )
{
  digitalWrite(led, LOW); 
   motor1.setSpeed(0); 
  motor1.run(RELEASE); 
  flag = false; 
  delay(1000); 
}
 
  delay(1000);   
}   
