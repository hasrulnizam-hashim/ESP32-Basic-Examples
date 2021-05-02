void setup() {
  Serial.begin(115200);
  pinMode(10,OUTPUT);

}

void loop() {
  int ldr = analogRead(A2);
  float volt = ldr*0.00488;

  if (volt < 3.0)
    digitalWrite(10,1);  
  if (volt > 3.5)
    digitalWrite(10,0);
  
  Serial.print("Voltage: ");
  Serial.println(volt);
  delay(200);

}
