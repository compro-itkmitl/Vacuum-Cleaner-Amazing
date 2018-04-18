#include <AFMotor.h>
AF_DCMotor Motor1(4);
AF_DCMotor Motor2(6);
void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
    Motor1.setSpeed(255);
    Motor2.setSpeed(255);
    Motor1.run(FORWARD);
    Motor2.run(FORWARD);
    delay(1000);
}
