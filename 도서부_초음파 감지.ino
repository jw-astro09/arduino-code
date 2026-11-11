const int trigPin = 9;
const int echoPin = 10;
const int buzzerPin = 8;

const float detectionDistance = 300.0;  // 감지 거리(cm)

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  long duration;
  float distance;

  // TRIG 신호 초기화
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // 초음파 발사 신호
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // ECHO 핀의 HIGH 지속 시간 측정
  duration = pulseIn(echoPin, HIGH, 30000);

  if (duration == 0) {
    Serial.println("MEASURE FAILED");
    noTone(buzzerPin);
  } else {
    // 왕복 시간으로부터 거리 계산
    distance = duration * 0.0343 / 2.0;

    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");

    if (distance <= detectionDistance) {
      Serial.println("DETECTED");
      tone(buzzerPin, 1000);
    } else {
      Serial.println("OUT OF RANGE");
      noTone(buzzerPin);
    }
  }

  delay(200);
}