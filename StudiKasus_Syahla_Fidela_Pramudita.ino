#include <Wire.h> // Mengimpor pustaka Wire.h untuk komunikasi I2C (tidak digunakan dalam program ini)

// Pin sensor TCRT5000
const int sensor1Pin = 2;  // Mendefinisikan pin GPIO 2 untuk sensor infrared kiri
const int sensor2Pin = 4;  // Mendefinisikan pin GPIO 4 untuk sensor infrared kanan

// Pin motor DC
const int motor1PinA = 14; // Mendefinisikan pin GPIO 14 untuk motor DC kiri (arah maju)
const int motor1PinB = 15; // Mendefinisikan pin GPIO 15 untuk motor DC kiri (arah mundur)
const int motor2PinA = 12; // Mendefinisikan pin GPIO 12 untuk motor DC kanan (arah maju)
const int motor2PinB = 13; // Mendefinisikan pin GPIO 13 untuk motor DC kanan (arah mundur)

void setup() { 
  pinMode(sensor1Pin, INPUT); // set sensor1Pin sebagai input
  pinMode(sensor2Pin, INPUT); // set sensor2Pin sebagai input

  pinMode(motor1PinA, OUTPUT); // Set motor1PinA sebagai output untuk motor DC kiri (maju)
  pinMode(motor1PinB, OUTPUT); // Set motor1PinB sebagai output untuk motor DC kiri (mundur)
  pinMode(motor2PinA, OUTPUT); // Set motor2PinA sebagai output untuk motor DC kanan (maju)
  pinMode(motor2PinB, OUTPUT); // Set motor2PinB sebagai output untuk motor DC kanan (mundur)
}

void loop() {
  int sensor1Value = digitalRead(sensor1Pin); // Membaca nilai dari sensor kiri
  int sensor2Value = digitalRead(sensor2Pin); // Membaca nilai dari sensor kanan

  // Robot bergerak maju saat mendeteksi garis hitam pada kedua sensor
  if (sensor1Value == LOW && sensor2Value == LOW) {
    // Bergerak maju
    digitalWrite(motor1PinA, HIGH); // Nyalakan motor DC kiri maju
    digitalWrite(motor1PinB, LOW); // Matikan motor DC kiri mundur
    digitalWrite(motor2PinA, HIGH); // Nyalakan motor kanan maju
    digitalWrite(motor2PinB, LOW); // Matikan motor DC mundur

  } else if (sensor1Value == LOW) {
    // Jika hanya sensor kiri yang mendeteksi garis, belok kiri
    digitalWrite(motor1PinA, LOW); // Matikan motor DC kiri maju
    digitalWrite(motor1PinB, HIGH);// Nyalakan motor DC kiri mundur
    digitalWrite(motor2PinA, HIGH); // Nyalakan motor DC kanan maju
    digitalWrite(motor2PinB, LOW); // Nyalakan motor DC kanan mundur

  } else if (sensor2Value == LOW) {
    // Jika hanya sensor kanan yang mendeteksi garis, belok kanan
    digitalWrite(motor1PinA, HIGH); // Nyalakan motor DC kiri maju
    digitalWrite(motor1PinB, LOW); // Matikan motor DC kiri mundur
    digitalWrite(motor2PinA, LOW); // Matikan motor DC kanan maju
    digitalWrite(motor2PinB, HIGH); // Nyalakan motor DC kanan mundur
  } else {
    // Jika tidak ada sensor yang mendeteksi garis, berhenti
    digitalWrite(motor1PinA, LOW); // Matikan motor DC kiri maju
    digitalWrite(motor1PinB, LOW); // Matikan motor DC kiri mundur
    digitalWrite(motor2PinA, LOW); // Matikan motor DC kanan maju
    digitalWrite(motor2PinB, LOW); // Matikan motor DC kanan mundur
  }

  // Deteksi jika robot sudah di titik B
  if (sensor1Value == LOW && sensor2Value == LOW) {
    // Robot mencapai titik B
    digitalWrite(motor1PinA, LOW); // Matikan motor DC kiri maju
    digitalWrite(motor1PinB, LOW); // Matikan motor DC kiri mundur
    digitalWrite(motor2PinA, LOW); // Matikan motor DC kanan maju
    digitalWrite(motor2PinB, LOW); // Matikan motor DC kanan mundur

    delay(5000); // Tunggu selama 5 detik

    // Mulai kembali ke titik A (mundur)
    digitalWrite(motor1PinA, LOW); //Matikan motor DC kiri maju
    digitalWrite(motor1PinB, HIGH); // Nyalakan motor DC kiri mundur
    digitalWrite(motor2PinA, LOW); // Matikan motor DC kanan maju
    digitalWrite(motor2PinB, HIGH); // Nyalakan motor DC kanan mundur

  }
}
