void setup() {
  pinMode(19, INPUT_PULLDOWN);
  pinMode(2,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(16,OUTPUT);
  pinMode(15,INPUT);
}

void loop() {
  int pot = analogRead(15);

  if(pot > 1365) digitalWrite(2,HIGH);
  if(pot > 2730) digitalWrite(4,HIGH);
  if(pot > 4080) digitalWrite(16,HIGH);

  if(pot < 1360) digitalWrite(2,LOW);
  if(pot < 2720) digitalWrite(4,LOW);
  if(pot < 4070) digitalWrite(16,LOW);

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
