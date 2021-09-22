void setup()    // dijalankan sekali
{
    pinMode(4, OUTPUT);    // pin 4(led Hijau) sebagai digital output
    pinMode(5, OUTPUT);    // pin 5(led Kuning) sebagai digital output
   	pinMode(6, OUTPUT);    // pin 6(led Merah) sebagai digital output
}
 
void loop()    // dijalankan berulang terus menerus
{
    digitalWrite(4, HIGH); // Led Hijau nyala
    digitalWrite(5, LOW);  // Led Kuning mati
  	digitalWrite(6, LOW);  // Led Merah mati
    delay(10000);           // Tunggu selama 10000 millisecond
    
  	digitalWrite(4, LOW); // Led Hijau mati
    digitalWrite(5, HIGH);  // Led Kuning nyala
  	digitalWrite(6, LOW);  // Led Merah mati
    delay(5000);           // Tunggu selama 5000 millisecond
  	
  	digitalWrite(4, LOW);  // Led Hijau mati
    digitalWrite(5, LOW);  // Led Kuning mati
  	digitalWrite(6, HIGH); // Led Merah nyala
    delay(15000);           // Tunggu selama 15000 millisecond
}
