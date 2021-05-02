void setup() {
  Serial.begin(115200);
  pinMode(10,OUTPUT);

}

void loop() {
  int temp = analogRead(A1)/2;
  int temp1 = analogRead(A1);
  
  Serial.print("Temp= ");
  Serial.println(temp);
  Serial.print("Temp1= ");
  Serial.println(temp1);  
  delay(200);

}
