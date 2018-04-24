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
  //automove
  Distance = sonic(); //call function sonic to check obstacle 
  int Distance_Right = 0; 
  int Distance_Left =  0;
  if(Distance <= 15){ //Check Distance to area
    moveStop();
    delay(500);
    Distance_Left = lookLeft();

    if(Distance_Left > 20){ 
      turnLeft(); 
      delay(1000);
      moveStop();
    }
    else{
      Distance_Right = lookRight();
      if(Distance_Right > 20){
          turnRight(); 
          delay(1000);
          moveStop();
        }
        else{
          moveBackward();
          delay(2000);
          turnRight();
          delay(1000); 
          }
      }
  }
  //END Check area
  //sonic check to forward
  else{ 
    moveForward(); 
  }//End automove


  //Controller
if(NodeSerial.available() > 0)
{
  while(1){
      MCU_input = NodeSerial.read(); //read value return from NodeSerial
      Serial.println(MCU_input);

      if (MCU_input == '2'){
        moveForward();
      }
      else if (MCU_input == '4'){
        turnLeft();
      }
      else if (MCU_input == '6'){
        turnRight();
      }
      else if (MCU_input == '8'){
        moveBackward();
      }
      else if (MCU_input == '0'){
        moveStop();
      }
      else if (MCU_input == '9')
      {
        break;
      }
    }
  }//END controller
}

//servo turnRight for check ultrasonic
int lookRight() 
{    
    int Distance;
    
    myservo.write(90);  // myservo.write(__) in blank is a degree to turn servo
    delay(500);
    myservo.write(0);  // myservo.write(__) in blank is a degree to turn servo
    delay(1000);
    Distance = ultrasonic.distanceRead();
    Serial.print("Dis R:");
    Serial.println(Distance);
    delay(500);
    myservo.write(90);
    return Distance;
}

//servo turnLeft for check ultrasonic
int lookLeft()
{   
    int Distance;
    
    myservo.write(90); // myservo.write(__) in blank is a degree to turn servo  
    delay(500);
    myservo.write(160); // myservo.write(__) in blank is a degree to turn servo
    delay(1000);
    Distance = ultrasonic.distanceRead();
    Serial.print("Dis L:");
    Serial.println(Distance);
    delay(500);
    myservo.write(90);
    return Distance;
}

int sonic(){
  /* "How to" 
  int ac,DDds;
  for(i = 0; i < 10; i++){
    AD = AD + analogRead(0);
    delay(50);
    Distance =(AD*3)/100;
  }*/
  int lange;
  lange = ultrasonic.distanceRead();
  Serial.print("Distance in CM: ");
  Serial.println(lange);
  delayMicroseconds(10);
  return lange;
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
