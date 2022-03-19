#define SolenoidValve1 5
#define SolenoidValve2 18

void setup(){
 pinMode(SolenoidValve1, OUTPUT);
 pinMode(SolenoidValve2, OUTPUT);
}

void loop(){
 digitalWrite(SolenoidValve1,HIGH);
 delay(25000);
 digitalWrite(SolenoidValve1,LOW);
 delay(2000);
 digitalWrite(SolenoidValve2,HIGH);
 delay(25000);
 digitalWrite(SolenoidValve2,LOW);
 delay(2000);
 digitalWrite(SolenoidValve1,LOW);
 delay(10000);
 digitalWrite(SolenoidValve2,LOW);
 delay(10000);
}
