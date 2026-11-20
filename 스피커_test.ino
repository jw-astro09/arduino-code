const int buzzerPin = 8;

void setup() {
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  tone(buzzerPin, 1000); //주파수 설정(1000 = 1000 Hz)
  delay(1000); // 소리 지속 시간(1000 = 1초)

  // 1초 동안 정지
  noTone(buzzerPin);
  delay(1000);
}
