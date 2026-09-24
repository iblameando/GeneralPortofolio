#include <SoftwareSerial.h>

SoftwareSerial BT(3, 2);
int pin = 13;
char data;
int in1 = 9;
int in2 = 10;
int in3 = 5;
int in4 = 6;

void setup() {
  pinMode(pin, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  Serial.begin(9600);
  BT.begin(9600);
  digitalWrite(pin, LOW);
}

void loop() {
  if (BT.available()) {
    data = BT.read();
    if (data == '1') {
      maju();
    } 
    if (data == '3') {
      mundur();
    } 
    if (data == '2') {
      kiri();
    } 
    if (data == '4') {
      kanan();
    }
    if (data == 'S') {
      majuKiri();
    }
    if (data == 'C') {
      majuKanan();
    }
    if (data == '0') {
      analogWrite(in1, 0);
      analogWrite(in2, 0);
      analogWrite(in3, 0);
      analogWrite(in4, 0);
    }
  }
}

void maju() {
  analogWrite(in1, 255);
  analogWrite(in2, 0);
  analogWrite(in3, 255);
  analogWrite(in4, 0);
}
void mundur() {
  analogWrite(in1, 0);
  analogWrite(in2, 255);
  analogWrite(in3, 0);
  analogWrite(in4, 255);
}
void kiri() {
  analogWrite(in1, 255);
  analogWrite(in2, 0);
  analogWrite(in3, 0);
  analogWrite(in4, 255);
}
void kanan() {
  analogWrite(in1, 0);
  analogWrite(in2, 255);
  analogWrite(in3, 255);
  analogWrite(in4, 0);
}
void majuKiri() {
  analogWrite(in1, 255);
  analogWrite(in2, 0);
  analogWrite(in3, 100);
  analogWrite(in4, 0);
}
void majuKanan() {
  analogWrite(in1, 100);
  analogWrite(in2, 0);
  analogWrite(in3, 255);
  analogWrite(in4, 0);
}
