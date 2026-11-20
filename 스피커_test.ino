const int buzzerPin = 8;

void setup() {
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  tone(buzzerPin, 1000); //주파수 설정(1000 = 1000 Hz, 2000 = 2000 Hz)
  delay(1000); // 소리 지속 시간(1000 = 1초, 2000 = 2초)

  noTone(buzzerPin);
  delay(1000); // 1초동안 일시정지
}
