#include <SoftwareSerial.h>

SoftwareSerial BTSerial(2, 3); // RX, TX

void setup() {
  Serial.begin(9600);  // 시리얼 모니터와의 통신 속도
  BTSerial.begin(9600); // HC-05 모듈과의 통신 속도

  Serial.println("Slave ready. Waiting for data from master...");
}

void loop() {
  // HC-05에서 수신된 데이터를 시리얼 모니터에 출력
  if (BTSerial.available()) {
    while (BTSerial.available()) {
      char c = BTSerial.read();
      Serial.write(c);
    }
  }
}
