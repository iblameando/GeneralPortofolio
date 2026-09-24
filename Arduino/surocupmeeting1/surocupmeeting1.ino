#include <SoftwareSerial.h>
SoftwareSerial BT(2,3);
#define ledPin 13
String cmd;

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
  Serial.println("Ketik 'on' utk nyalain LED, 'off' untuk matikan LED.");
}

void loop() {
  if (BT.available() > 0) {
    cmd = Serial.readStringUntil('\n');
    cmd.trim();
    cmd.toLowerCase();

    if (cmd == "1") {
      digitalWrite(ledPin, HIGH);
      Serial.println("LED: NYALA");
    }
    else if (cmd == "2" ){
      digitalWrite(ledPin, LOW);
      Serial.println("LED: MATI");
    }
    else if (cmd == "delaypendek" ){
      digitalWrite(ledPin, LOW);
      Serial.println("LED: MATI");
      delay(100);
      digitalWrite(ledPin, HIGH);
      Serial.println("LED: NYALA");
    }
    else {
      Serial.println("Input yang ada di list bang, perintah ga dikenal");
    }
  }
}
