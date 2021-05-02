void setup() {
  pinMode(19, INPUT_PULLUP);
  pinMode(2,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(16,OUTPUT);
}

void loop() {
  kelip(2,500);
  kelip(4,500);
  kelip(16,500);
}

void kelip(int pin, int lengah){
  digitalWrite(pin,HIGH);
  delay(lengah);
  digitalWrite(pin,LOW);
  delay(lengah);
}
