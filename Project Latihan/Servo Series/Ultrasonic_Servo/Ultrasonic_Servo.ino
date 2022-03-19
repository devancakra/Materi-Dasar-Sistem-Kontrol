#include <Servo.h>   //servo library
Servo servo;  //call feature -> servo

//Define Pin Devices
#define trigPin 5    
#define echoPin 4 

//Create Variable
long duration, dist, average;   
long avg[3];   //array for average

void setup() {       
    Serial.begin(9600);
    servo.attach(2);  //IO Servo
    pinMode(trigPin, OUTPUT); pinMode(echoPin, INPUT);  //IO Ultrasonic
    servo.write(0); servo.detach(); //set null servo degree
} 

//Measuring Distance
void measure() {  
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(15);
  
  digitalWrite(trigPin, LOW);
  pinMode(echoPin, INPUT);
  
  duration = pulseIn(echoPin, HIGH);
  dist = (duration/2) / 29.1;
}

//Loop Operation
void loop() { 
  //Average Distance
  for (int i=0;i<=2;i++) {   
    measure();               
    avg[i]=dist;            
    delay(10);
  }
  dist=(avg[0]+avg[1]+avg[2])/3;    

  //Logic Conditions   
  if ( dist < 50 ) {
    servo.attach(2);
    int RightPosition = 0;
    int CenterPosition = 90;
    int LeftPosition = 180;
    servo.write(RightPosition);
    delay(1000);
    servo.write(CenterPosition);
    delay(1000);
    servo.write(LeftPosition);
    delay(1000);
    servo.detach();
  }

  Serial.print("Distance: ");
  Serial.println(dist);
}
