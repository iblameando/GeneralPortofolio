#include <SoftwareSerial.h> // Library ini torang pake supaya bisa bikin komunikasi serial tambahan di pin digital biasa.

// --------------------
// KONFIG PIN & VARIABEL
// --------------------
SoftwareSerial bluetooth(3, 2); // RX=3, TX=2
// Ingat: RX = terima data, jadi kabelnya sambung ke TX Bluetooth.
// TX = kirim data, jadi kabelnya sambung ke RX Bluetooth.

const int motorKiriMaju  = 10;  // Pin 10 khusus bikin motor kiri maju
const int motorKiriMundur= 9;   // Pin 9 bikin motor kiri mundur
const int motorKananMaju = 5;   // Pin 5 bikin motor kanan maju
const int motorKananMundur= 6;  // Pin 6 bikin motor kanan mundur
// Jadi tiap motor ada dua pin: satu mo putar maju, satu mo putar mundur.
// Kalo dua-dua LOW = motor diam. Kalo dua-dua HIGH = motor kaya direm.

String command; // Variabel ini untuk simpan perintah dari HP (Bluetooth)

// --------------------
// SETUP: cuma jalan sekali waktu Arduino nyala
// --------------------
void setup() {
  Serial.begin(9600); // Nyalakan komunikasi serial ke laptop, bisa lihat pesan di monitor
  bluetooth.begin(9600); // Nyalakan Bluetooth komunikasi
  Serial.println("Robot so siap mo jalan! Mode gampang, nda pake atur kecepatan.");

  // Atur semua pin motor jadi OUTPUT, supaya bisa kirim sinyal HIGH/LOW
  pinMode(motorKiriMaju, OUTPUT);
  pinMode(motorKiriMundur, OUTPUT);
  pinMode(motorKananMaju, OUTPUT);
  pinMode(motorKananMundur, OUTPUT);

  berhenti(); // Panggil fungsi stop supaya pas Arduino baru hidup, motor nda langsung jalan.
}

// --------------------
// LOOP: ini yang jalan ulang-ulang terus
// --------------------
void loop() {
  if (bluetooth.available()) { // Cek, ada data datang dari Bluetooth? pake sintaks available -> namaVariable.avalaible
    command = bluetooth.readStringUntil('\n'); // Baca sampe ketemu ENTER dari HP
    command.trim(); // Bersihkan spasi yang nda perlu

    Serial.print("Perintah masuk: ");
    Serial.println(command); // Kirim ke laptop supaya torang bisa pantau

    processCommand(command); // Kirim data ke fungsi untuk diproses
  }
}

// --------------------
// PROSES PERINTAH: tentukan robot mo bikin apa
// --------------------
void processCommand(String cmd) {
  if (cmd.startsWith("X:")) { // Kalo data ada "X:", itu berarti data joystick
    handleJoystick(cmd); // Proses joystick
    return; // Henti disini, nda usah cek perintah angka lagi
  }

  // Perintah manual pake angka (contoh dari aplikasi Android)
  if (cmd == "1") maju();        // 1 = maju lurus
  else if (cmd == "3") mundur();  // 3 = mundur
  else if (cmd == "2") belokKiri(); // 2 = belok kiri
  else if (cmd == "4") belokKanan(); // 4 = belok kanan
  else if (cmd == "0") berhenti();  // 0 = stop total
}

// --------------------
// ATUR MOTOR PAKE PWM (untuk joystick, supaya bisa atur kecepatan)
// --------------------
void setMotor(int speedLeft, int speedRight) {
  // speedLeft & speedRight: nilai dari -255 sampe 255.
  // Nilai negatif = maju, positif = mundur (tergantung cara pasang motor).

  // Motor kiri
  if (speedLeft < 0) { // kalo minus -> motor kiri maju
    analogWrite(motorKiriMaju, -speedLeft);
    analogWrite(motorKiriMundur, 0);
  } else if (speedLeft > 0) { // kalo plus -> motor kiri mundur
    analogWrite(motorKiriMaju, 0);
    analogWrite(motorKiriMundur, speedLeft);
  } else { // kalo 0 -> motor kiri diam
    analogWrite(motorKiriMaju, 0);
    analogWrite(motorKiriMundur, 0);
  }

  // Motor kanan
  if (speedRight < 0) { // motor kanan maju
    analogWrite(motorKananMaju, -speedRight);
    analogWrite(motorKananMundur, 0);
  } else if (speedRight > 0) { // motor kanan mundur
    analogWrite(motorKananMaju, 0);
    analogWrite(motorKananMundur, speedRight);
  } else { // motor kanan diam
    analogWrite(motorKananMaju, 0);
    analogWrite(motorKananMundur, 0);
  }
}

// --------------------
// HANDLE JOYSTICK: bikin robot bisa gerak pelan/cepat sesuai joystick
// --------------------
void handleJoystick(String data) {
  int commaIndex = data.indexOf(','); // Cari koma pemisah nilai X & Y
  String xString = data.substring(2, commaIndex); // Ambil angka X dari string
  String yString = data.substring(data.indexOf('Y') + 2); // Ambil angka Y

  float xValue = xString.toFloat(); // Ubah jadi angka float
  float yValue = yString.toFloat();

  float deadband = 0.1; // Zona mati: biar robot nda goyang kalo joystick cuma gerak sedikit

  if (abs(xValue) < deadband) xValue = 0; // Nolkan X kalo gerak kecil
  if (abs(yValue) < deadband) yValue = 0; // Nolkan Y kalo gerak kecil

  int maxPWM = 255;
  int speedY = (int)(yValue * maxPWM);  // maju/mundur sesuai Y
  int speedX = (int)(xValue * maxPWM);  // belok sesuai X

  // Hitung kecepatan tiap motor pake prinsip differential drive
  int leftMotor  = speedY - speedX;
  int rightMotor = speedY + speedX;

  leftMotor  = constrain(leftMotor, -255, 255);
  rightMotor = constrain(rightMotor, -255, 255);

  setMotor(leftMotor, rightMotor); // Kirim nilai ke motor
}

// --------------------
// FUNGSI GERAKAN DASAR (DIGITALWRITE)
// --------------------
void maju() {
  /* LOGIKA MAJU:
     - Motor kiri pin MAJU = HIGH
     - Motor kanan pin MAJU = HIGH
     - Pin mundur = LOW semua
     Hasil: dua motor putar arah sama, robot maju lurus ke depan. */
  digitalWrite(motorKiriMaju, HIGH);
  digitalWrite(motorKiriMundur, LOW);
  digitalWrite(motorKananMaju, HIGH);
  digitalWrite(motorKananMundur, LOW);
}

void mundur() {
  /* LOGIKA MUNDUR:
     - Motor kiri pin MUNDUR = HIGH
     - Motor kanan pin MUNDUR = HIGH
     - Pin maju = LOW semua
     Hasil: dua motor putar arah mundur, robot jalan mundur. */
  digitalWrite(motorKiriMaju, LOW);
  digitalWrite(motorKiriMundur, HIGH);
  digitalWrite(motorKananMaju, LOW);
  digitalWrite(motorKananMundur, HIGH);
}

void belokKanan() {
  /* LOGIKA BELOK KANAN:
     - Motor kiri maju, motor kanan mundur.
     Jadi robot mutar di tempat ke kanan (pivot kanan).
     Cocok untuk belok tajam. */
  digitalWrite(motorKiriMaju, HIGH);
  digitalWrite(motorKiriMundur, LOW);
  digitalWrite(motorKananMaju, LOW);
  digitalWrite(motorKananMundur, HIGH);
}

void belokKiri() {
  /* LOGIKA BELOK KIRI:
     - Motor kiri mundur, motor kanan maju.
     Jadi robot mutar di tempat ke kiri.
     Sama kaya belok kanan, cuma kebalik arah. */
  digitalWrite(motorKiriMaju, LOW);
  digitalWrite(motorKiriMundur, HIGH);
  digitalWrite(motorKananMaju, HIGH);
  digitalWrite(motorKananMundur, LOW);
}

void berhenti() {
  /* LOGIKA BERHENTI:
     Semua pin LOW = motor mati total.
     Robot diem, nda gerak. */
  digitalWrite(motorKiriMaju, LOW);
  digitalWrite(motorKiriMundur, LOW);
  digitalWrite(motorKananMaju, LOW);
  digitalWrite(motorKananMundur, LOW);
}

void rem() {
  /* LOGIKA REM:
     Semua pin HIGH = motor kaya di-shorted.
     Hasil: robot stop mendadak, berasa ada rem. */
  digitalWrite(motorKiriMaju, HIGH);
  digitalWrite(motorKiriMundur, HIGH);
  digitalWrite(motorKananMaju, HIGH);
  digitalWrite(motorKananMundur, HIGH);
}
