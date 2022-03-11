int light = 44;
void setup() {
  Serial.begin(9600);
  pinMode(light, OUTPUT);
  digitalWrite(light, 1);
}

void loop() {
  
  //digitalWrite(13, a);
  if(Serial.available() > 0) {
    digitalWrite(light, Serial.read());
    //String data = Serial.readStringUntil('\n');
//    if (data == "1") {
//          digitalWrite(light, 1);
//      } else {
//            digitalWrite(light, 0);
//        }
    
  }
}
