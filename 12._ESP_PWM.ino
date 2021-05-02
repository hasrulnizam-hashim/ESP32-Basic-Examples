void setup() {
  pinMode(19, INPUT_PULLDOWN);
  pinMode(2,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(16,OUTPUT);
  pwm(0,2);
  pwm(1,4);
  pwm(2,16);
}

void loop() {
  fader(0);
  fader(1);
  fader(2);
  
//  if (butang(19) == 1){
//    kelip(2,500);
//    kelip(4,500);
//    kelip(16,500);
//  }
//  else{
//  }

}

void pwm(int channel, int pin){
  ledcSetup(channel,2000,8);  //set channel 0 with max 2000Hz and max 8bit.
  ledcAttachPin(pin,channel);  //Attach channel 0 to pin 16
}

void fader(int channel){
  for(int pwm = 0; pwm < 80; pwm++){
    ledcWrite(channel,pwm);   //set pwm value to channel 0
    delay(10);
  }
  for(int pwm = 80; pwm > 0; pwm--){
    ledcWrite(channel,pwm);   //set pwm value to channel 0
    delay(10);
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
