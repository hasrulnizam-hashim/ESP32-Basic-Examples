void setup() {
  pinMode(10, OUTPUT);

}

void loop() {
  for(int led=0; led<80; led++){
    analogWrite(10, led);
    delay(10);
  }
  for(int led=80; led>0; led--){
    analogWrite(10, led);
    delay(10);
  }

}
