void setup() {
  pinMode(7, INPUT);    //set pin sbg input
  pinMode(13, OUTPUT);  //set pin sbg output

}

void loop() {
  int button = digitalRead(7);  //baca pin 7
  if(button == 1){              //jika button ditekan
    digitalWrite(13, HIGH);
  }
  else{
    digitalWrite(13, LOW);
  }
}
