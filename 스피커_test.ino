const int buzzerPin = 8;

void setup() {
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  // 피에조에서 1000 Hz 소리를 1초 동안 출력
  tone(buzzerPin, 1000);
  delay(1000);

  // 1초 동안 정지
  noTone(buzzerPin);
  delay(1000);
}
