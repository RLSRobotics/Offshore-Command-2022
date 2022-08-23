#include <Servo.h>

Servo servo0;
#define servo0Pin 2

int light = 44;
void setup() {
  pinMode(light, OUTPUT);

  servo0.attach(servo0Pin);

  servo0.writeMicroseconds(1500);
  
  delay(7000);
  
  servo0.writeMicroseconds(1700);
  
}

void loop() {
  
}
