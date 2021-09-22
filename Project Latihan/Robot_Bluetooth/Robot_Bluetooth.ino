#include <SoftwareSerial.h>
SoftwareSerial module_bluetooth(0, 1); // pin RX | TX
char data = 0;
#define enA 9
#define in1 4
#define in2 5
#define enB 10
#define in3 6
#define in4 7

int Buzzer = 8;
int Lamp1 = 13;
int Lamp2 = 12;
int motorSpeedA = 0;
int motorSpeedB = 0;


void setup(){
  Serial.begin(9600);
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(Buzzer, OUTPUT);
  pinMode(Lamp1, OUTPUT);
  pinMode(Lamp2, OUTPUT);
}

void loop(){
  if (Serial.available() > 0)  {
    data = Serial.read(); Serial.print(data);   //Pembacaan dan ditampilkan data yang masuk
    Serial.print("\n");
    // //Data yang masuk
    if (data == '1') {
      motorSpeedA = 150; //bisa diambil dari joystick, tapi sekarang kita input manual aja yak; 0-255
      motorSpeedB = 150; //bisa diambil dari joystick, tapi sekarang kita input manual aja yak; 0-255
      analogWrite(enA, motorSpeedA); // Send PWM signal to motor A
      analogWrite(enB, motorSpeedB); // Send PWM signal to motor B
      // Set Motor A backward
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
      // Set Motor B backward
      digitalWrite(in3, HIGH);
      digitalWrite(in4, LOW);

    }
    else if (data == '0') {
      motorSpeedA = 150; //bisa diambil dari joystick, tapi sekarang kita input manual aja yak; 0-255
      motorSpeedB = 150; //bisa diambil dari joystick, tapi sekarang kita input manual aja yak; 0-255
      analogWrite(enA, motorSpeedA); // Send PWM signal to motor A
      analogWrite(enB, motorSpeedB); // Send PWM signal to motor B
      digitalWrite(in1, LOW);
      digitalWrite(in2, HIGH);
      // Set Motor B forward
      digitalWrite(in3, LOW);
      digitalWrite(in4, HIGH);
    }
    else if (data == '2') {
      motorSpeedA = 80; //bisa diambil dari joystick, tapi sekarang kita input manual aja yak; 0-255
      motorSpeedB = 80; //bisa diambil dari joystick, tapi sekarang kita input manual aja yak; 0-255
      analogWrite(enA, motorSpeedA); // Send PWM signal to motor A
      analogWrite(enB, motorSpeedB); // Send PWM signal to motor B
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
      // Set Motor B RIGHT
      digitalWrite(in3, LOW);
      digitalWrite(in4, HIGH);
    }
    else if (data == '3') {
      motorSpeedA = 80; //bisa diambil dari joystick, tapi sekarang kita input manual aja yak; 0-255
      motorSpeedB = 80; //bisa diambil dari joystick, tapi sekarang kita input manual aja yak; 0-255
      analogWrite(enA, motorSpeedA); // Send PWM signal to motor A
      analogWrite(enB, motorSpeedB); // Send PWM signal to motor B
      digitalWrite(in1, LOW);
      digitalWrite(in2, HIGH);
      // Set Motor B LEFT
      digitalWrite(in3, HIGH);
      digitalWrite(in4, LOW);
    }
    else if (data == '4') {
      motorSpeedA = 255; //bisa diambil dari joystick, tapi sekarang kita input manual aja yak; 0-255
      motorSpeedB = 255; //bisa diambil dari joystick, tapi sekarang kita input manual aja yak; 0-255
      analogWrite(enA, motorSpeedA); // Send PWM signal to motor A
      analogWrite(enB, motorSpeedB); // Send PWM signal to motor B
      digitalWrite(in1, LOW);
      digitalWrite(in2, LOW);
      // Set Motor B STOP
      digitalWrite(in3, LOW);
      digitalWrite(in4, LOW);
    }
    else if (data == '5') {
      tone(Buzzer, 1275);
      delay(1000);
      noTone(Buzzer);
    }
    else if (data == '6') {
      digitalWrite(Lamp1, HIGH);
      digitalWrite(Lamp2, LOW);
    }
    else if (data == '7') {
      digitalWrite(Lamp1, LOW);
      digitalWrite(Lamp2, HIGH);
    }
  }
}
