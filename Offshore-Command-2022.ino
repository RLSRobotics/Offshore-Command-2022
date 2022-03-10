
void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);
}

void loop() {
  if(Serial.available() >= 1) {
    
    digitalWrite(13, Serial.read());
  }
}
