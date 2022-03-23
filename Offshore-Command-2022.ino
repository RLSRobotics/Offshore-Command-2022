//int light = 44;
//void setup() {
//  Serial.begin(9600);
//  pinMode(light, OUTPUT);
//  digitalWrite(light, 1);
//}
//
//void loop() {
// 
//}


int light = 44;
void setup() {
  Serial.begin(9600);
  Serial.setTimeout(5);
  pinMode(light, OUTPUT);
}

void loop() {
  while (!Serial.available());
  int x = Serial.readString().toInt();
    
  if (x == 2) {
    Serial.write("received 2");
    digitalWrite(light, 0);
  } else {
    Serial.write("received other");
    digitalWrite(light, 1);
  }
  delay(20);
  
}
