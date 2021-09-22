int buzzer = 3;
int hijau = 4;
int kuning = 5;
int merah = 6;

void setup(){
	pinMode(buzzer, OUTPUT);
	pinMode(hijau, OUTPUT);
	pinMode(kuning, OUTPUT);
	pinMode(merah, OUTPUT);
}

void loop(){
digitalWrite(hijau,HIGH);
digitalWrite(kuning,LOW);
digitalWrite(merah,LOW);
tone1();
delay(1000);
silent();
delay(10000);

digitalWrite(hijau,LOW);
digitalWrite(kuning,HIGH);
digitalWrite(merah,LOW);
tone2();
delay(1000);
silent();
delay(10000);

digitalWrite(hijau,LOW);
digitalWrite(kuning,LOW);
digitalWrite(merah,HIGH);
tone3();
delay(1000);
silent();
delay(10000);
}

void tone1(){
	tone(buzzer, 1275);
} 

void tone2(){
	tone(buzzer, 1915);
} 

void tone3(){
	tone(buzzer, 1515);
} 

void silent(){ 
	noTone(buzzer);
}
