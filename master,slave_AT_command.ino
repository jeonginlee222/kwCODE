#include <SoftwareSerial.h>

SoftwareSerial BTSerial(2, 3); // RX, TX

void setup() {
  
  Serial.begin(9600);  // PC와의 통신 속도
  BTSerial.begin(38400);  // HC-05 기본 AT 모드 보드레이트
}

void loop() {
  // 시리얼 모니터에서 입력 받은 데이터를 HC-05로 전송
  if (Serial.available())
    BTSerial.write(Serial.read());
  if (BTSerial.available())
    Serial.write(BTSerial.read());
  }
