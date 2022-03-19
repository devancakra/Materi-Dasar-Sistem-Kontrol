//define Pins
#include <Servo.h>

Servo servo;
int pos = 0;

void setup() 
{
  Serial.begin(9600);
  servo.attach(2);
  servo.attach(0);
  Serial.println("Mengatur arah servo ");
}

void loop() 
{
    if(Serial.available()>0){
      String baca = Serial.readString();
      unsigned int sudut = baca.toInt();
      Serial.print(" sudut putar : ");
      Serial.println(sudut);
      servo.write(sudut);
    }
}
