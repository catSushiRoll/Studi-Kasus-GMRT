#include <Servo.h>
Servo servoMotor;

const int potensioPin = A0;
const int led1Pin = 9;
const int led2Pin = 10;
const int servoPin = 6;

void setup() {
  servoMotor.attach(servoPin);
  pinMode(led1Pin, OUTPUT);
  pinMode(led2Pin, OUTPUT);
  Serial.begin(9600);

}

void loop() {
  int potensioValue = analogRead(potensioPin);
  int servoPos = map (potensioValue, 0,1023,0,180);
  servoMotor.write(servoPos);

  if (servoPos > 90){
    int brightness1 = map(servoPos,90,180,0,255);
    int brightness2 = 0;

    analogWrite(led1Pin, brightness1);
    analogWrite(led2Pin, brightness2);
  } else if (servoPos < 90) { // Posisi bawah
    int brightness2 = map(servoPos, 0, 90, 255, 0); // LED2 semakin terang
    int brightness1 = 0; // LED1 mati
    analogWrite(led1Pin, brightness1);
    analogWrite(led2Pin, brightness2);
  } else { // Posisi tengah
    analogWrite(led1Pin, 0); // Kedua LED mati
    analogWrite(led2Pin, 0);
  }

  // Menampilkan nilai potensiometer dan posisi servo di Serial Monitor
  Serial.print("Potentiometer Value: ");
  Serial.print(potensioValue);
  Serial.print(" | Servo Position: ");
  Serial.println(servoPos);
  
  delay(5000); // Menunggu sedikit untuk stabilitas
}

