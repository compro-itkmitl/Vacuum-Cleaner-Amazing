#include <Ultrasonic.h>
Ultrasonic ultrasonic(12, 13);

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.print("Distance in CM: ");
  Serial.println(ultrasonic.distanceRead());
  delay(1000);
}
