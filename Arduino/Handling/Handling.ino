#include <SoftwareSerial.h> 

// --- KONFIGURASI BLUETOOTH ---
SoftwareSerial bluetooth(3, 2); // RX, TX

// --- KONFIGURASI PIN MOTOR ---
const int motorKiriMaju    = 5;   // IN1
const int motorKiriMundur  = 6;   // IN2
const int motorKananMaju   = 11;  // IN3
const int motorKananMundur = 10;  // IN4

// --- PIN RELAY / AKSI ---
const int solenoidPin       = 7;
const int handlingMotorPin  = 8;

// --- KONFIGURASI ---
const bool ACTIVE_LOW_LOGIC = true;   // ubah ke false jika relay aktif di HIGH

// --- VARIABEL GLOBAL ---
String command;
bool statusSolenoid       = false;
bool statusHandlingMotor  = false;
bool robotSedangBergerak  = false;

unsigned long lastDataTime = 0;           
const unsigned long timeoutBT = 30000;     

void setup() {
  Serial.begin(9600);
  bluetooth.begin(9600);
  Serial.println("Robot siap. Mode D-Pad & Analog aktif.");

  pinMode(motorKiriMaju, OUTPUT);
  pinMode(motorKiriMundur, OUTPUT);
  pinMode(motorKananMaju, OUTPUT);
  pinMode(motorKananMundur, OUTPUT);
  pinMode(solenoidPin, OUTPUT);
  pinMode(handlingMotorPin, OUTPUT);

  // Kondisi awal
  berhenti();
  digitalWrite(solenoidPin,  ACTIVE_LOW_LOGIC ? HIGH : LOW);
  digitalWrite(handlingMotorPin, ACTIVE_LOW_LOGIC ? HIGH : LOW);

  // Matikan semua motor dengan paksa saat startup
  analogWrite(motorKiriMaju, 0);
  analogWrite(motorKiriMundur, 0);
  analogWrite(motorKananMaju, 0);
  analogWrite(motorKananMundur, 0);
}

void loop() {
  if (bluetooth.available()) {
    command = bluetooth.readStringUntil('\n');
    command.trim();
    if (command.length() == 0) return;

    Serial.print("Perintah Diterima: ");
    Serial.println(command);

    processCommand(command);
    lastDataTime = millis();   
  }

  // --- Cek koneksi bluetooth ---
  if (millis() - lastDataTime > timeoutBT) {
    berhenti();
  }
}

// --- PENGOLAH PERINTAH ---
void processCommand(String cmd) {
  if (cmd.startsWith("X:")) {
    handleJoystick(cmd);
    return;
  }

  if      (cmd == "2") maju();
  else if (cmd == "4") mundur();
  else if (cmd == "3") belokKiri();
  else if (cmd == "1") belokKanan();
  else if (cmd == "0") berhenti();
  else if (cmd == "X") activateSolenoid();
  else if (cmd == "T") toggleHandlingMotor();
  else if (cmd == "C") turn180();
  else if (cmd == "S") autoStraight();
  else if (cmd == "R1"){ Serial.println("Command R1 belum diimplementasi"); }
  else if (cmd == "L1"){ Serial.println("Command L1 belum diimplementasi"); }
}

void setMotor(int speedLeft, int speedRight) {
  // --- LEFT MOTOR ---
  if (speedLeft > 0) {
    analogWrite(motorKiriMaju, 255);   // full power forward
    analogWrite(motorKiriMundur, 0);
  } else if (speedLeft < 0) {
    analogWrite(motorKiriMaju, 0);
    analogWrite(motorKiriMundur, 255); // full power backward
  } else {
    analogWrite(motorKiriMaju, 0);
    analogWrite(motorKiriMundur, 0);
  }

  // --- RIGHT MOTOR ---
  if (speedRight > 0) {
    analogWrite(motorKananMaju, 255);  
    analogWrite(motorKananMundur, 0);
  } else if (speedRight < 0) {
    analogWrite(motorKananMaju, 0);
    analogWrite(motorKananMundur, 255);
  } else {
    analogWrite(motorKananMaju, 0);
    analogWrite(motorKananMundur, 0);
  }

  robotSedangBergerak = (speedLeft != 0 || speedRight != 0);
}


void handleJoystick(String data) {
  int commaIndex = data.indexOf(',');
  if (commaIndex == -1) return;

  float yValue = data.substring(2, commaIndex).toFloat();         
  float xValue = data.substring(data.indexOf('Y') + 2).toFloat(); 

  xValue = -xValue;   
  yValue = -yValue;   

  float deadband = 0.2;
  if (abs(xValue) < deadband) xValue = 0;
  if (abs(yValue) < deadband) yValue = 0;

  // --- Hanya 4 arah ---
  if (yValue > deadband) {       
    maju();
  }
  else if (yValue < -deadband) {  
    mundur();
  }
  else if (xValue < -deadband) {  
    belokKiri();  
  }
  else if (xValue > deadband) {   
    belokKanan();
  }
  else { 
    berhenti();
  }
}

// --- GERAKAN DASAR ---
void maju()        { setMotor( 1,  1); }   
void mundur()      { setMotor(-1, -1); }  
void belokKiri()   { setMotor(-1,  1); }  
void belokKanan()  { setMotor( 1, -1); }  
void berhenti()    { setMotor(0, 0); }

// --- SOLENOID ---
void activateSolenoid() {
  statusSolenoid = !statusSolenoid;
  digitalWrite(solenoidPin, statusSolenoid ? (ACTIVE_LOW_LOGIC ? LOW : HIGH)
                                           : (ACTIVE_LOW_LOGIC ? HIGH : LOW));
}

// --- HANDLING MOTOR (TOGGLE MANUAL) ---
void toggleHandlingMotor() {
  statusHandlingMotor = !statusHandlingMotor;
  digitalWrite(handlingMotorPin, statusHandlingMotor ? (ACTIVE_LOW_LOGIC ? LOW : HIGH) 
                                                     : (ACTIVE_LOW_LOGIC ? HIGH : LOW));
  Serial.print("Handling Motor: ");
  Serial.println(statusHandlingMotor ? "NYALA" : "MATI");
}

// --- FITUR BARU ---
// Auto-straight 2 detik
void autoStraight() {
  Serial.println("Auto Straight 2 detik");
  setMotor(1, 1);
  delay(2000);
  berhenti(); 
}

// Quick 180° turn
void turn180() {
  Serial.println("Quick 180 Turn");
  setMotor(1, -1);  // spin in place
  delay(1000);      // atur waktu agar pas 180° (coba 1000–1200 ms)
  berhenti();
}
