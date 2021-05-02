void setup() {
  // put your setup code here, to run once:
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
//  digitalWrite(13, HIGH);
//  delay(500);
//  digitalWrite(13, LOW);
//  delay(500);

  pelangi(1,0,1,500);
  pelangi(1,1,0,500);
  pelangi(1,1,1,500);
}

void pelangi(int merah, int hijau, int biru, int lengah){
  digitalWrite(12, merah);
  digitalWrite(11, hijau);
  digitalWrite(10, biru);
  delay(lengah);
}
