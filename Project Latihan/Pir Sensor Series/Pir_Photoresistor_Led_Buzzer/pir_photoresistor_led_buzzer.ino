// deklarasi variabel global
const int pir = 9; // pin pir
const int led = 10; // pin led
const int ldr = 5; // pin pir
const int buzzer = 8; // pin buzzer

//set pir -> netral = 0
int pirsetvalue = 0; 
//set ldr -> netral = 0
int ldrsetvalue = 0;

//fungsi diproses 1 kali
void setup()
{
  Serial.begin(9600); // memulai serial begin port 9600
  pinMode(led, OUTPUT); // inisialisasi led
  pinMode(pir, INPUT); // inisialisasi pir
  pinMode(ldr, INPUT); // inisialisasi ldr
  pinMode(buzzer, INPUT); // inisialisasi buzzer
}

//fungsi diproses berkali-kali
void loop()
{
  ldrsetvalue = analogRead(ldr); // membaca analog ldr pin
  Serial.println(ldrsetvalue); // serial monitoring ldr
  pirsetvalue = digitalRead(pir); // membaca analog pir pin
  //Serial.println(pirsetvalue); // serial monitoring pir

  if (ldrsetvalue > 200){ // jika ldrset keadaan terang -> dianalogikan siang
  	digitalWrite(led, LOW); // led mati
    noTone(buzzer); // buzzer mati
    delay(100); // jeda waktu
  }
  else if (ldrsetvalue < 200){ // jika ldrset keadaan gelap -> dianalogikan menjelang malam/malam
    digitalWrite(led, LOW); // led mati
    noTone(buzzer); // buzzer mati
    delay(100); // jeda waktu
    if (pirsetvalue == 1){// jika pirset respon maka led + buzzer nyala
      	digitalWrite(led, HIGH); // led nyala
      	tone(buzzer, 100); // buzzer nyala
    	delay(100); // jeda waktu
    }
  }
  else { // selain itu semua maka led + buzzer mati
    digitalWrite(led, LOW); // led mati
    noTone(buzzer); // buzzer mati
    delay(100); // jeda waktu
  }
}