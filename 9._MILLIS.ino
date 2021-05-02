long previousMillis = 0;
long currentMillis = 0;
int counter = 0;

void setup() {
  Serial.begin(115200);

}

void loop() {
  currentMillis = millis();
  if(currentMillis > previousMillis + 1000){
    previousMillis = currentMillis;
    counter++;
    Serial.println(counter);
  }
}
