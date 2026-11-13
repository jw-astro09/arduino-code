# HC-SR04 초음파 감지 회로 연결 매뉴얼

이 매뉴얼은 같은 폴더의 `도서부_초음파 감지.ino`, `초음파_test.ino`, `piezo_test.ino` 코드에 맞춘 Arduino UNO 연결 방법입니다.

## 1. 준비물

- Arduino UNO
- HC-SR04 초음파 센서
- 피에조 부저(Piezo)
- 점퍼선
- 코드 업로드용 케이블

## 2. HC-SR04 연결

| HC-SR04 핀 | Arduino UNO 핀 | 기능 |
|---|---|---|
| VCC | 5V | 전원 |
| TRIG | D9 | 초음파 발사 신호 |
| ECHO | D10 | 반사 신호 입력 |
| GND | GND | 접지 |

```text
HC-SR04                 Arduino UNO
VCC   ------------------ 5V
TRIG  ------------------ D9
ECHO  ------------------ D10
GND   ------------------ GND
```

## 3. 피에조 부저 연결

| 피에조 단자 | Arduino UNO 핀 |
|---|---|
| `+` 또는 긴 다리 | D8 |
| `-` 또는 짧은 다리 | GND |

```text
피에조 +  ---------------- Arduino D8
피에조 -  ---------------- Arduino GND
```

피에조의 `+` 단자를 D8에 연결해야 합니다. 피에조가 무극성으로 표시된 경우에도 위 연결을 우선 사용합니다.

## 4. 전체 연결 요약

```text
                 ┌──────────────┐
                 │  Arduino UNO │
                 │              │
HC-SR04 VCC  ────┤ 5V           │
HC-SR04 GND  ────┤ GND          │
HC-SR04 TRIG ────┤ D9           │
HC-SR04 ECHO ────┤ D10          │
피에조 +     ────┤ D8           │
피에조 -     ────┤ GND          │
                 └──────────────┘
```

## 5. 사용할 코드

사람 또는 물체가 센서에서 300 cm 이내에 있으면 피에조가 1000 Hz로 울립니다. 감지 기준은 `도서부_초음파 감지.ino`의 다음 값으로 설정되어 있습니다.

```cpp
const float detectionDistance = 300.0;
```

감지 거리를 100 cm로 바꾸려면 다음과 같이 수정합니다.

```cpp
const float detectionDistance = 100.0;
```

이 코드는 다음 핀 번호를 사용합니다.

```cpp
const int trigPin = 9;
const int echoPin = 10;
const int buzzerPin = 8;
```

## 6. Arduino IDE 사용 절차

1. `도서부_초음파 감지.ino`를 Arduino IDE에서 엽니다.
2. 보드에서 `Arduino Uno`를 선택합니다.
3. 연결된 COM 포트를 선택합니다.
4. 코드를 업로드합니다.
5. Serial Monitor를 엽니다.
6. 보드레이트를 `9600 baud`로 설정합니다.

정상적으로 측정되면 다음과 같은 메시지가 출력됩니다.

```text
Distance: 64.7 cm
DETECTED
```

거리가 기준보다 멀면 다음과 같이 출력됩니다.

```text
Distance: 350.0 cm
OUT OF RANGE
```

## 7. 코드별 용도

### `초음파_test.ino`

HC-SR04의 거리 측정만 확인하는 코드입니다. 피에조를 사용하지 않고 Serial Monitor에 거리만 출력합니다.

연결은 다음 네 선만 필요합니다.

```text
VCC -> 5V
GND -> GND
TRIG -> D9
ECHO -> D10
```

### `piezo_test.ino`

피에조 연결만 확인하는 코드입니다.

```text
피에조 + -> D8
피에조 - -> GND
```

1초 동안 소리가 나고 1초 동안 멈추는 동작을 반복합니다.

### `도서부_초음파 감지.ino`

HC-SR04로 거리를 측정하고, 설정된 거리 안에 물체가 있으면 피에조를 울리는 최종 코드입니다.

## 8. Tinkercad에서 확인하는 방법

1. `Ultrasonic Distance Sensor` 또는 `HC-SR04` 부품을 사용합니다.
2. 반드시 `VCC`, `TRIG`, `ECHO`, `GND` 네 핀이 있는 센서를 선택합니다.
3. 센서를 다음처럼 연결합니다.

```text
VCC -> 5V
TRIG -> D9
ECHO -> D10
GND -> GND
```

4. 피에조를 `D8`과 `GND`에 연결합니다.
5. 시뮬레이션을 시작합니다.
6. 시뮬레이션 중 센서를 클릭합니다.
7. 센서 앞의 파란색 가상 물체를 움직여 거리를 바꿉니다.
8. Serial Monitor의 거리값과 피에조 동작을 확인합니다.

## 9. 문제 해결

### `MEASURE FAILED`가 반복되는 경우

- 센서가 HC-SR04인지 확인합니다.
- `TRIG`가 D9에 연결되었는지 확인합니다.
- `ECHO`가 D10에 연결되었는지 확인합니다.
- VCC와 GND가 서로 바뀌지 않았는지 확인합니다.
- Arduino와 센서의 GND가 공통으로 연결되었는지 확인합니다.

### 거리는 출력되지만 피에조가 울리지 않는 경우

- 피에조 `+`를 D8에 연결했는지 확인합니다.
- 피에조 `-`를 GND에 연결했는지 확인합니다.
- 코드의 `buzzerPin`이 실제 연결 핀과 같은지 확인합니다.
- `distance`가 `detectionDistance`보다 작은지 확인합니다.
- `piezo_test.ino`로 피에조만 먼저 테스트합니다.

## 10. 주의사항

- 이 회로는 물체까지의 거리를 측정합니다. 초음파만으로 사람인지 다른 물체인지 구분하지는 못합니다.
- `PING)))` 센서는 `TRIG`와 `ECHO`가 분리된 HC-SR04와 연결 방식이 다릅니다. 이 매뉴얼에는 HC-SR04만 적용합니다.
- 실제 HC-SR04 모듈은 일반적으로 5 V Arduino UNO에 직접 연결할 수 있지만, 3.3 V 보드에서는 ECHO 전압을 확인해야 합니다.
