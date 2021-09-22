int Buzzer = 13;

void setup(){
pinMode(Buzzer, OUTPUT);
}

void loop(){
monotone();
delay(100);
silent();
delay(1000);
}

void monotone(){
tone(Buzzer, 264);
} 

void silent(){ 
noTone(Buzzer);
}