// deklarasi variabel global
const int pir = 9; // pin pir
const int led = 10; // pin led
const int ldr = 5; // pin pir

//set pir -> netral = 0
int pirsetvalue = 0; 
//set ldr -> netral = 0
int ldrsetvalue = 0;

void setup()
{
  Serial.begin(9600); // memulai serial begin port 9600
  pinMode(led, OUTPUT); // inisialisasi led
  pinMode(pir, INPUT); // inisialisasi pir
  pinMode(ldr, INPUT); // inisialisasi ldr
}

void loop()
{
  ldrsetvalue = analogRead(ldr); // membaca analog ldr pin
  Serial.println(ldrsetvalue); // serial monitoring ldr
  pirsetvalue = digitalRead(pir); // membaca analog pir pin
  //Serial.println(pirsetvalue); // serial monitoring pir

  if (ldrsetvalue > 200){ // jika ldrset keadaan terang -> dianalogikan siang
  	digitalWrite(led, LOW); // led mati
    delay(100); // jeda waktu
  }
  else if (ldrsetvalue < 200){ // jika ldrset keadaan gelap -> dianalogikan menjelang malam/malam
    digitalWrite(led, LOW); // led mati
    delay(100); // jeda waktu
    if (pirsetvalue == 1){// jika pirset respon maka led nyala
      	digitalWrite(led, HIGH); // led nyala
    	delay(100); // jeda waktu
    }
  }
  else { // selain itu semua maka led mati
    digitalWrite(led, LOW); // led mati
    delay(100); // jeda waktu
  }
}