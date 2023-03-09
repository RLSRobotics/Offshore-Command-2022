#include <Servo.h>

Servo servo0;
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;

#define servo0Pin 2
#define servo1Pin 3
#define servo2Pin 4
#define servo3Pin 5
#define servo4Pin 6
#define servo5Pin 7

int light = 44;
void setup() {
  Serial.begin(9600);
  Serial.setTimeout(5);
  pinMode(light, OUTPUT);

  servo0.attach(servo0Pin);
  servo0.writeMicroseconds(1500);
  servo1.attach(servo1Pin);
  servo1.writeMicroseconds(1500);
  servo2.attach(servo2Pin);
  servo2.writeMicroseconds(1500);
  servo3.attach(servo3Pin);
  servo3.writeMicroseconds(1500);
  servo4.attach(servo4Pin);
  servo4.writeMicroseconds(1500);
  servo5.attach(servo5Pin);
  servo5.writeMicroseconds(1500);
  
  delay(7000);
  digitalWrite(light, 1);
  delay(100);
  digitalWrite(light, 0);
}

void loop() {
  //note: expecting byte array of x elements from python, bytearray([a, b, c]) works in python
  //set integer as the number of bytes expected to be sent through python

  //0 = test "A" button, 1-6 = motors
  while (Serial.available() < 7);

  int bytesToRead = Serial.available();
  byte input[bytesToRead];
  
  for (int i = 0; i < bytesToRead; i++) {
    input[i] = Serial.read();
  }
  
  int motorPower0 = (input[1] * 3) + 1200;
  int motorPower1 = (input[2] * 3) + 1200;
  int motorPower2 = (input[3] * 3) + 1200;
  int motorPower3 = (input[4] * 3) + 1200;
  int motorPower4 = (input[5] * 3) + 1200;
  int motorPower5 = (input[6] * 3) + 1200;

  
  servo0.writeMicroseconds(motorPower0);
  servo1.writeMicroseconds(motorPower1);
  servo2.writeMicroseconds(motorPower2);
  servo3.writeMicroseconds(motorPower3);
  servo4.writeMicroseconds(motorPower4);
  servo5.writeMicroseconds(motorPower5);

  
  if (input[0] == 1) {
    digitalWrite(light, 1);
  } else {
    digitalWrite(light, 0);
  }
  Serial.print("received");
  //delay(20);
}
