#include <Servo.h>

Servo servo0;
#define servo0Pin 2

int light = 44;
void setup() {
  Serial.begin(9600);
  Serial.setTimeout(5);
  pinMode(light, OUTPUT);

  servo0.attach(servo0Pin);
  servo0.writeMicroseconds(1500);
}

void loop() {
  //note: expecting byte array of x elements from python, bytearray([a, b, c]) works in python
  //set integer as the number of bytes expected to be sent through python
  while (Serial.available() < 2);
  int bytesToRead = Serial.available();
  byte input[bytesToRead];
  
  for (int i = 0; i < bytesToRead; i++) {
    input[i] = Serial.read();
  }
  
  int motorPower0 = (input[1] * 4) + 1100;
  
  servo0.writeMicroseconds(motorPower0);
  
  if (input[0] == 1) {
    digitalWrite(light, 1);
  } else {
    digitalWrite(light, 0);
  }
  Serial.print("received");
  delay(20);
}
