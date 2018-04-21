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
    delay(100);
    Distance_Right = lookRight(); //call lookRight check obstacle
    Distance_Left = lookLeft();   //call lookLeft check obstacle 

    if(Distance_Right == Distance_Left){ 
      moveBackward();
      delay(500);
      moveStop();
      while(1){ // check Right & Left to choice forword
        Distance_Right = lookRight();
        Distance_Right = lookLeft();
        if(Distance_Right > Distance_Left){
          turnRight(); 
          moveStop();
          break;
        }
        else if(Distance_Left > Distance_Right){
          turnLeft(); 
          break;
        }
        else if (Distance_Right < Distance_Left){
          moveBackward();
          continue;
        }
      }
    }
    else if(Distance_Right > Distance_Left){ 
      turnRight(); 
      moveStop();
    }
    else if (Distance_Right < Distance_Left){ 
      turnLeft(); 
      moveStop(); 
    }
  } //END Check area
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
int lookRight() {    
  Distance = sonic(); // call Function sonic
  Serial.print("Distance in CM R: ");
  myservo.write(90);  // myservo.write(__) in blank is a degree to turn servo 
  delay(500);
  myservo.write(0);  // myservo.write(__) in blank is a degree to turn servo
  delay(500);
  myservo.write(90);
  return Distance;
}

//servo turnLeft for check ultrasonic
int lookLeft(){   
  Distance = sonic(); // call Function sonic
  Serial.print("Distance in CM L: ");
  myservo.write(90); // myservo.write(__) in blank is a degree to turn servo    
  delay(500); 
  myservo.write(180); // myservo.write(__) in blank is a degree to turn servo
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
