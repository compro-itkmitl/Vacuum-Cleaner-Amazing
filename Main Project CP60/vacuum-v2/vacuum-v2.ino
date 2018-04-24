//กรณีไม่มีblynk และ servo V.2 
#include <SoftwareSerial.h>
#include <Servo.h> // library Servo
#include <AFMotor.h> // library Motor
#include <Ultrasonic.h> //library Ultrasonic

Servo myservo;//Name servo
Ultrasonic ultrasonic(12, 13); //ช่องของultrasonic sensor
SoftwareSerial NodeSerial(2,3);
AF_DCMotor motor1(4,0); // MotorRight analog5
AF_DCMotor motor2(5,0); // MotorRight analog5
AF_DCMotor motor3(6,0); // MotorLight analog6
AF_DCMotor motor4(7,0); // MotorLight analog7
char MCU_input;
int Distance = 0;
int count;

void setup(){
  Serial.begin(9600);
  NodeSerial.begin(57600);
  myservo.attach(9);   // link Servo analog 9
  myservo.write(90);   // myservo.write(__) in blank is a degree to turn servoa
  moveStop();
  delay(200);  
  NodeSerial.available();
}

void loop(){
  Distance = sonic();
  int Distance_left;
  Serial.println("Distance : ");
  Serial.println(Distance);
  if(Distance <= 20)
  {
    turnRight();
    delay(10);
  }
  else
  {
    moveForward();
  }
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
  analogWrite(4, 200); // 160 analog9 on broad & Forward_motor
  analogWrite(5, 0);   //  255 analog6 on broad & Forward_motor   
  analogWrite(6, 0);
  analogWrite(7, 225); 
} 

// moveRight odject.
void turnRight() { 
  analogWrite(4, 200);     // run analog4 motorRight
  analogWrite(5, 0);         
  analogWrite(6, 0);
  analogWrite(7, 0);
}

// moveLeft odject.
void turnLeft() { 
  analogWrite(4, 0);      
  analogWrite(5, 0);       
  analogWrite(6, 0);
  analogWrite(7, 200);  // run analog7 motorLeft 
}

// moveBackward odject.
void moveBackward(){
  analogWrite(4, 0);   
  analogWrite(5, 200);   // analog5 moveBackward
  analogWrite(6, 200);   // analog6 moveBackward
  analogWrite(7, 0);
}


int lookRight() 
{    
    Distance = sonic(); // call Function ultasonic
    Serial.print("Distance in CM R: ");
    Serial.println(Distance);
    myservo.write(90);  // myservo.write(__) in blank is a degree to turn servo
    delay(500); 
    myservo.write(0);  // myservo.write(__) in blank is a degree to turn servo
    delay(500);
    myservo.write(90);
    return Distance;
}

int lookLeft()
{   
    Distance = sonic(); // call Function ultasonic
    Serial.print("Distance in CM L: ");
    Serial.println(Distance);
    myservo.write(90); // myservo.write(__) in blank is a degree to turn servo     
    delay(500);
    myservo.write(180); // myservo.write(__) in blank is a degree to turn servo
    delay(500);
    myservo.write(90);
    return Distance;
}


int sonic(){
  int lange;
  lange = ultrasonic.distanceRead();
  delayMicroseconds(10);
  return lange;
}

