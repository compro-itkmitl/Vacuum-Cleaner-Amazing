#include <ESP8266WiFi.h>
#include <SoftwareSerial.h>
#include <BlynkSimpleEsp8266.h>
SoftwareSerial NodeSerial(D2,D3);
#define BLYNK_PRINT Serial
const char* Wifi_id = "packpackpack";
const char* Wifi_passwords = "pack0000";
char return_value;
char auth[] = "ab59a0effb704f628037590d932a8299";
void setup(){
 Serial.begin(9600);
 Blynk.begin(auth,Wifi_id,Wifi_passwords);
 NodeSerial.begin(57600);
}

void loop(){
 Blynk.run();
}

BLYNK_WRITE(V1){ // read value from blynk V1
 int y = param.asInt(); 
   //return value for arduino
 if (y == 1)
 {
   NodeSerial.print(2);
   Blynk.virtualWrite(V6, "FORWORD");
   Serial.println("V1 : Forward");
 }
 else if(y == 0){
   NodeSerial.print(y);
   Blynk.virtualWrite(V6, " ");
   Serial.println("V1 : off");
 }
}

BLYNK_WRITE(V2){ // read value from blynk V1
  int y = param.asInt();
    //return value for arduino
  if (y == 1)
  {
    NodeSerial.print(4);
    Blynk.virtualWrite(V6, "LEFT");
    Serial.println("V2 : Left");
  }
  else if(y == 0){
   NodeSerial.print(y);
   Blynk.virtualWrite(V6, " ");
   Serial.println("V2 : off");
 }
}

BLYNK_WRITE(V3){ // read value from blynk V1
  int y = param.asInt();
    //return value for arduino
  if (y == 1)
  {
    NodeSerial.print(6);
    Blynk.virtualWrite(V6, "RIGHT");
    Serial.println("V3 : Right");
  }
  else if(y == 0){
   NodeSerial.print(y);
   Blynk.virtualWrite(V6, " ");
   Serial.println("V3 : off");
 }
}

BLYNK_WRITE(V4){ // read value from blynk V1
  int y = param.asInt();
    //return value for arduino
  if (y == 1)
  {
    NodeSerial.print(8);
    Blynk.virtualWrite(V6, "BACKWORD");
    Serial.println("V4 : Backward");
  }
  else if(y == 0){
   NodeSerial.print(y);
   Blynk.virtualWrite(V6, " ");
   Serial.println("V4 : off");
 }
}

BLYNK_WRITE(V5){ // read value from blynk V1
  int y = param.asInt();
    //return value for arduino
  if (y == 1)
  {
    NodeSerial.print(3);
    Blynk.virtualWrite(V0, "MODE : CONTROL");
    Serial.println("V5 : Move for Controller(3)");
  }
  else if (y == 0)
  {
    NodeSerial.print(9);
    Blynk.virtualWrite(V0, "MODE : Auto");
    Blynk.virtualWrite(V6, " ");
    Serial.println("V5 : Move for Automatic(9)");
  }
}


