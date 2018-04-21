#include <ESP8266WiFi.h>
#include <SoftwareSerial.h>
#include <BlynkSimpleEsp8266.h>
SoftwareSerial NodeSerial(D2,D3);
#define BLYNK_PRINT Serial
const char* Wifi_id = " ID your Wifi or hotspot";
const char* Wifi_passwords = "Password your Wifi";
char auth[] = "Serial code for your email blynk";
void setup() {
  Serial.begin(9600);
  Blynk.begin(auth,Wifi_id,Wifi_passwords);
  NodeSerial.begin(57600);
}

void loop() {
  Blynk.run();
}

BLYNK_WRITE(V0){
  int y = param.asInt();
  if (y == 1)
  {
    Serial.println("V0 : ON");
  }
  else if(y == 0)
  {
    Serial.println("V0 : OFF");
  }
}

BLYNK_WRITE(V1){
   int y = param.asInt();
   if (y == 1)
   {
       Serial.println("V1 : ON");
   }
   else if(y == 0)
   {
       Serial.println("V1 : OFF");
   }
}

BLYNK_WRITE(V2){
  int y = param.asInt();
  if (y == 1)
  {
    Serial.println("V2 : ON");
  }
  else if(y == 0)
  {
    Serial.println("V2 : OFF");
  }
}

BLYNK_WRITE(V3){
    int y = param.asInt();
    if (y == 1)
    {
        NodeSerial.print(6);
        Serial.println("V3 : ON");
   }
   else if(y == 0){
       NodeSerial.print(y);
       Serial.println("V3 : OFF");
   }
}

BLYNK_WRITE(V4){
  int y = param.asInt();
  if (y == 1)
  {
    Serial.println("V4 : ON");
  }
  else if(y == 0)
  {
    Serial.println("V4 : OFF");
  }
}
