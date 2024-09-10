#include <Servo.h>

#define ECHOPIN 2   // Pin TRIG sensor HC-SR04
#define TRIGPIN 4   // Pin ECHO sensor HC-SR04
#define REDLED 13   // Pin LED merah
#define BLUELED 12  // Pin LED biru
#define GREENLED 11 // Pin LED hijau

Servo myservo;        // Buat objek servo
long duration;        // Durasi pulsa
float distanceCm;     // Jarak dalam cm
float tolerance = 0.5; // Toleransi untuk deteksi kelipatan

void setup() {
  pinMode(TRIGPIN, OUTPUT);    // Set pin TRIG sebagai output
  pinMode(ECHOPIN, INPUT);     // Set pin ECHO sebagai input
  pinMode(REDLED, OUTPUT);     // Set pin LED merah sebagai output
  pinMode(BLUELED, OUTPUT);    // Set pin LED biru sebagai output
  pinMode(GREENLED, OUTPUT);   // Set pin LED hijau sebagai output
  myservo.attach(8);           // Hubungkan servo ke pin digital 8
  
  Serial.begin(9600);          // Mulai komunikasi serial
}

void loop() {
  // Bersihkan TRIG
  digitalWrite(TRIGPIN, LOW);
  delayMicroseconds(2);
  
  // Set TRIG HIGH selama 10 microdetik
  digitalWrite(TRIGPIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGPIN, LOW);

  // Hitung durasi ECHO HIGH
  duration = pulseIn(ECHOPIN, HIGH, 20000); // Timeout 20ms (20000 mikrodetik)

  // Konversi durasi ke jarak
  distanceCm = duration * 0.034 / 2;

  // Reset semua LED
  digitalWrite(REDLED, LOW);
  digitalWrite(BLUELED, LOW);
  digitalWrite(GREENLED, LOW);

  // Logika untuk lampu LED dan servo dengan toleransi
  if (distanceCm > 0 && distanceCm < 400) { // Validasi jarak agar tetap di dalam rentang yang bisa diukur
    if (abs(fmod(distanceCm, 2) - 2) < tolerance || abs(fmod(distanceCm, 2)) < tolerance) { 
        // Jarak mendekati kelipatan 2 cm
        digitalWrite(REDLED, HIGH);
        myservo.write(20); // Servo berputar 20 derajat
    }
    if (abs(fmod(distanceCm, 3) - 3) < tolerance || abs(fmod(distanceCm, 3)) < tolerance) { 
        // Jarak mendekati kelipatan 3 cm
        digitalWrite(BLUELED, HIGH);
        myservo.write(30); // Servo berputar 30 derajat
    }
    if (abs(fmod(distanceCm, 7) - 7) < tolerance || abs(fmod(distanceCm, 7)) < tolerance) { 
        // Jarak mendekati kelipatan 7 cm
        digitalWrite(GREENLED, HIGH);
        myservo.write(70); // Servo berputar 70 derajat
    }
  } else {
    Serial.println("Jarak di luar rentang yang bisa diukur.");
  }

  // Tampilkan jarak pada serial monitor
  Serial.print("Distance: ");
  Serial.print(distanceCm);
  Serial.println(" cm");

  delay(450); 
}
