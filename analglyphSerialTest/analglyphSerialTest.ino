void setup() {
  Serial.begin(9600);
}

void loop() {
  for(int i = 0; i < 10; i++)
  {
    Serial.write(0);
    delay(100);
  }
  for(int i = 0; i < 10; i++)
  {
    Serial.write(1);
    delay(100);
  }
}
