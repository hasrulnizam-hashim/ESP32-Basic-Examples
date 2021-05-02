void setup() {
  pinMode(19, INPUT_PULLDOWN);
  pinMode(2,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(16,OUTPUT);
}

void loop() {
//  kelip(2,500);
//  kelip(4,500);
//  kelip(16,500);

  if (butang(19) == 1){
    kelip(2,500);
    kelip(4,500);
    kelip(16,500);
  }
  else{
    
  }
}

void kelip(int pin, int lengah){
  digitalWrite(pin,HIGH);
  delay(lengah);
  digitalWrite(pin,LOW);
  delay(lengah);
}

int butang(int pin){
  int button = digitalRead(pin);
  return button;
}
