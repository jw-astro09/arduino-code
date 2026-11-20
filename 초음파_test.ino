// 배선: VCC -> 5V, GND -> GND, TRIG -> D9, ECHO -> D10

const byte TRIG_PIN = 9;
const byte ECHO_PIN = 10;

void setup() {
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  digitalWrite(TRIG_PIN, LOW);

  Serial.begin(9600); // serial monitor 속도를 9600으로 맞추면 초음파를 통해 측정한 거리 조히 가능
  Serial.println("HC-SR04 ultrasonic sensor test");
}

void loop() {
  // 트리거 펄스 생성
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  unsigned long duration = pulseIn(ECHO_PIN, HIGH, 30000UL);  // 왕복 시간 측정: 30 ms 초과 시 측정 실패로 처리(30000UL = 30ms)

  if (duration == 0) {
    Serial.println("측정 실패: 센서 연결 또는 측정 범위를 확인하세요.");
  } else {
    float distanceCm = duration * 0.0343f / 2.0f;
    Serial.print("거리: ");
    Serial.print(distanceCm, 1);
    Serial.println(" cm");
  }

  delay(500);
}
