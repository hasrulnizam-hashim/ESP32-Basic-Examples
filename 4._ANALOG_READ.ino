void setup() {
  Serial.begin(115200);
  pinMode(10,OUTPUT);
}

void loop() {
  int pot = analogRead(A0);
  float voltage = pot*0.00488;

  int led = map(pot,0,1023,0,80);
  analogWrite(10,led);
  
  Serial.print("Value: ");
  Serial.println(pot);
  Serial.print("Voltage: ");
  Serial.println(voltage);
  delay(200);

}
