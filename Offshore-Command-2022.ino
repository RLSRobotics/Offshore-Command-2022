int light = 44;
void setup() {
  Serial.begin(9600);
  Serial.setTimeout(5);
  pinMode(light, OUTPUT);
}

void loop() {
  //note: expecting byte array of x elements from python, bytearray([a, b, c]) works in python
  //set integer as the number of bytes expected to be sent through python
  while (Serial.available() < 1);
  int bytesToRead = Serial.available();
  byte input[bytesToRead];
  
  for (int i = 0; i < bytesToRead; i++) {
    input[i] = Serial.read();
  }
  if (input[0] == 1) {
    //Serial.print works even with string concat and can be picked up by python
    Serial.print("received 1");
    digitalWrite(light, 1);
  } else {
    Serial.print("received not 1");
    digitalWrite(light, 0);
  }
  delay(20);
}
