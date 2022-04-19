int light = 44;
void setup() {
  Serial.begin(9600);
  Serial.setTimeout(5);
  pinMode(light, OUTPUT);
}

void loop() {
  //note: expecting byte array of x elements from python, bytearray([a, b, c]) works in python
  //set integer as the number of bytes expected to be sent through python
  while (Serial.available() < 3);
  int bytesToRead = Serial.available();
  byte input[bytesToRead];
  
  for (int i = 0; i < bytesToRead; i++) {
    input[i] = Serial.read();
  }
  if (input[2] == 0xf1) {
    //Serial.print works even with string concat and can be picked up by python
    Serial.print("received 0");
    digitalWrite(light, 0);
  } else {
    Serial.print("received not 0");
    digitalWrite(light, 1);
  }
  delay(20);
}
