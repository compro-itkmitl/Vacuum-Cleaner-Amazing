#include <Servo.h> // library Servo
#include <AFMotor.h> // library Motor
AF_DCMotor motor1(4,0); // MotorRight analog5
AF_DCMotor motor2(5,0); // MotorRight analog5
AF_DCMotor motor3(6,0); // MotorLight analog6
AF_DCMotor motor4(7,0); // MotorLight analog7

void setup() {
  Serial.begin(9600);  // set serial ultrasonic
}

void loop() {
  // put your main code here, to run repeatedly:
  moveStop();
  delay(1000);
  moveForward();
  delay(1000);
  turnRight();
  delay(1000);
  moveBackward();
  delay(1000);
  turnLeft();
  delay(1000);
  
}
// stop movement
void moveStop() {  
  analogWrite(4, 0);      // analog4 on broad & stop_motorRight
  analogWrite(5, 0);      // analog6 on broad & stop_motorLeft
  analogWrite(6, 0);
  analogWrite(7, 0);
}
// moveForward odject.
void moveForward() {   
   analogWrite(4, 200); //Forward_motor
   analogWrite(5, 0);     
   analogWrite(6, 0);
   analogWrite(7, 225); //Forward_motor 

} 
// moveRight odject.
void turnRight() { 
 analogWrite(4, 200);     //Forward_motorRight
 analogWrite(5, 0);       //stop_motorLeft  
 analogWrite(6, 0);
 analogWrite(7, 0);
}
// moveLeft odject.
void turnLeft() { 
 analogWrite(4, 0);      //stop_motorRight
 analogWrite(5, 0);      //Forward_motorRight   
 analogWrite(6, 0);
 analogWrite(7, 200);
}
// moveBackward odject.
void moveBackward(){
  analogWrite(4, 0);     //moveBackward_motorRight
  analogWrite(5, 200);   //moveBackward_motorRight
  analogWrite(6, 200);
  analogWrite(7, 0);
}
