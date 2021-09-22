//deklarasi variabel global
const int pir = 10; //pin pir
const int led = 13; //pin led

//set pir -> netral = 0
int pirsetvalue = 0; 

//fungsi diproses 1 kali
void setup() {
  Serial.begin(9600); //memulai serial begin port 9600
  pinMode(led, OUTPUT); //inisialisasi led
  pinMode(pir, INPUT); //inisialisasi pir
}

//fungsi diproses berkali-kali
void loop() {
  pirsetvalue = digitalRead(pir); // membaca analog pir pin
  Serial.println(pirsetvalue); // serial monitoring

  if (pirsetvalue == 1){ // jika pirset respon maka led nyala
    digitalWrite(led, HIGH); //led nyala
    delay(100); // jeda waktu
  }
  else { // selain itu semua maka led mati
    digitalWrite(led, LOW); // led mati
    delay(100); // jeda waktu
  }
}