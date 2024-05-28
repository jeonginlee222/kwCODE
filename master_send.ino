#include <SoftwareSerial.h>

SoftwareSerial BTSerial(2, 3); // RX, TX

void setup() {
  Serial.begin(9600);  // 시리얼 모니터와의 통신 속도
  BTSerial.begin(9600); // HC-05 모듈과의 통신 속도

  Serial.println("Master ready. Enter text to send to slave:");
}

void loop() {
  // 시리얼 모니터에서 입력 받은 데이터를 HC-05로 전송
  if (Serial.available()) {
    while (Serial.available()) {
      char c = Serial.read();
      BTSerial.write(c);
    }
  }
}
