#define PiezoBuzzer 2

void setup(){
 pinMode(PiezoBuzzer, OUTPUT);
}

void loop(){
 digitalWrite(PiezoBuzzer,HIGH);
 delay(1000);
 digitalWrite(PiezoBuzzer,LOW);
 delay(1000);
 digitalWrite(PiezoBuzzer,HIGH);
 delay(1000);
 digitalWrite(PiezoBuzzer,LOW);
 delay(1000);
 digitalWrite(PiezoBuzzer,HIGH);
 delay(1000);
 digitalWrite(PiezoBuzzer,LOW);
 delay(1000);
}
