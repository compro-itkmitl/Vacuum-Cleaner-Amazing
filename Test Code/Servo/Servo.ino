#include <Servo.h> 
int servoPin = 3; 
 Servo Servo1; 
void setup() { 
   Servo1.attach(servoPin); 
}
void loop(){ 
   Servo1.write(0); 
   Serial.println("0 degree");
   delay(1000); 
   Servo1.write(90); 
   Serial.println("90 degree");
   delay(1000); 
   Servo1.write(180); 
   Serial.println("180 degree");
   delay(1000); 
}
