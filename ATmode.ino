#include <SoftwareSerial.h>

SoftwareSerial BTSerial(2, 3); // RX, TX

void setup() {
  // Set pin 9 as output and set it HIGH to enter AT mode
  pinMode(9, OUTPUT);
  digitalWrite(9, HIGH);
  
  // Start communication with Serial Monitor
  Serial.begin(9600);
  Serial.println("Enter AT commands:");
  
  // Start communication with HC-05
  BTSerial.begin(38400);  // Default baud rate for HC-05 AT mode
}

void loop() {
  // Read from Bluetooth module and send to Serial Monitor
  if (BTSerial.available()) {
    Serial.write(BTSerial.read());
  }
  
  // Read from Serial Monitor and send to Bluetooth module
  if (Serial.available()) {
    BTSerial.write(Serial.read());
  }
}
