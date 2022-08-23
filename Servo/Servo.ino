
#include <Servo.h>
Servo myservo;
#define servoPin 11


void setup() {
  myservo.attach(servoPin);
  pinMode(13, OUTPUT);

  myservo.writeMicroseconds(1500);
  digitalWrite(13, HIGH);
  delay(7000);
  digitalWrite(13, LOW);
}

void loop() {
  for (int i = 1500; i <= 1900; i += 100) {
    myservo.writeMicroseconds(i);
    delay(1000);
  }
  for (int i=1900; i>=1500; i-=100) {
    myservo.writeMicroseconds(i);
    delay(1000);
  }
  for (int i=1500; i>=1100; i-=100) {
    myservo.writeMicroseconds(i);
    delay(1000);
  }
  for (int i=1100; i<=1500; i+=100) {
    myservo.writeMicroseconds(i);
    delay(1000);
  }


}
