/* Melody
 * (cleft) 2005 D. Cuartielles for K3
 *
 * This example uses a piezo speaker to play melodies.  It sends
 * a square wave of the appropriate frequency to the piezo, generating
 * the corresponding tone.
 *
 * The calculation of the tones is made following the mathematical
 * operation:
 *
 *       timeHigh = period / 2 = 1 / (2 * toneFrequency)
 *
 * where the different tones are described as in the table:
 *
 * note   frequency   period  timeHigh
 * c          261 Hz          3830  1915
 * d          294 Hz          3400  1700
 * e          329 Hz          3038  1519
 * f          349 Hz          2864  1432
 * g          392 Hz          2550  1275
 * a          440 Hz          2272  1136
 * b          493 Hz          2028  1014
 * C          523 Hz          1912  956
 *
 * http://www.arduino.cc/en/Tutorial/Melody
 */

int speakerPin = 13;

int length = 15; // the number of notes
char notes[] = "ccggaagffeeddc "; // a space represents a rest
int beats[] = { 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 2, 4 };
int tempo = 300;

void setup()    // dijalankan sekali
{
  	pinMode(speakerPin, OUTPUT);
    pinMode(7, OUTPUT);    // pin 7(led Putih) sebagai digital output
    pinMode(6, OUTPUT);    // pin 8(led Merah) sebagai digital output
   	pinMode(5, OUTPUT);    // pin 7(led Biru) sebagai digital output
    pinMode(4, OUTPUT);    // pin 8(led Oranye) sebagai digital output
   	pinMode(3, OUTPUT);    // pin 7(led Kuning) sebagai digital output
    pinMode(2, OUTPUT);    // pin 8(led Hijau) sebagai digital output
}

void playTone(int tone, int duration) {
  for (long i = 0; i < duration * 1000L; i += tone * 2) {
    digitalWrite(speakerPin, HIGH);
    delayMicroseconds(tone);
    digitalWrite(speakerPin, LOW);
    delayMicroseconds(tone);
  }
}

void playNote(char note, int duration) {
  char names[] = { 'c', 'd', 'e', 'f', 'g', 'a', 'b', 'C' };
  int tones[] = { 1915, 1700, 1519, 1432, 1275, 1136, 1014, 956 };

  // play the tone corresponding to the note name
  for (int i = 0; i < 8; i++) {
    if (names[i] == note) {
      playTone(tones[i], duration);
    }
  }
}

void loop() {
  for (int i = 0; i < length; i++) {
    if (notes[i] == ' ') {
      delay(beats[i] * tempo); // rest
    } else {
      playNote(notes[i], beats[i] * tempo);
      	led1();
    	led2();
    	led3();
  		led4();
   		led5();
    	led6();
      	off();
    }
    // pause between notes
    delay(tempo / 10000);
  }
}

void led1(){
 	digitalWrite(7, HIGH); // Led Putih nyala
    digitalWrite(6, LOW);  // Led Merah mati
  	digitalWrite(5, LOW);  // Led Biru mati
    digitalWrite(4, LOW);  // Led Oranye mati
  	digitalWrite(3, LOW);  // Led Kuning mati
    digitalWrite(2, LOW);  // Led Hijau mati
    delay(100);           // Tunggu selama 100 millisecond
}

void led2(){
  	digitalWrite(7, LOW);  // Led Putih mati
    digitalWrite(6, HIGH); // Led Merah nyala
  	digitalWrite(5, LOW);  // Led Biru mati
    digitalWrite(4, LOW);  // Led Oranye mati
  	digitalWrite(3, LOW);  // Led Kuning mati
    digitalWrite(2, LOW);  // Led Hijau mati
    delay(100);           // Tunggu selama 100 millisecond
}

void led3(){
  	digitalWrite(7, LOW);  // Led Putih mati
    digitalWrite(6, LOW);  // Led Merah mati
  	digitalWrite(5, HIGH); // Led Biru nyala
    digitalWrite(4, LOW);  // Led Oranye mati
  	digitalWrite(3, LOW);  // Led Kuning mati
    digitalWrite(2, LOW);  // Led Hijau mati
    delay(100);           // Tunggu selama 100 millisecond
}

void led4(){
  	digitalWrite(7, LOW);  // Led Putih mati
    digitalWrite(6, LOW);  // Led Merah mati
  	digitalWrite(5, LOW);  // Led Biru mati
    digitalWrite(4, HIGH); // Led Oranye nyala
  	digitalWrite(3, LOW);  // Led Kuning mati
    digitalWrite(2, LOW);  // Led Hijau mati
    delay(100);           // Tunggu selama 100 millisecond
}

void led5(){
  	digitalWrite(7, LOW);  // Led Putih mati
    digitalWrite(6, LOW);  // Led Merah mati
  	digitalWrite(5, LOW);  // Led Biru mati
    digitalWrite(4, LOW);  // Led Oranye mati
  	digitalWrite(3, HIGH); // Led Kuning nyala
    digitalWrite(2, LOW);  // Led Hijau mati
    delay(100);           // Tunggu selama 100 millisecond
}

void led6(){
  	digitalWrite(7, LOW);  // Led Putih mati
    digitalWrite(6, LOW);  // Led Merah mati
  	digitalWrite(5, LOW);  // Led Biru mati
    digitalWrite(4, LOW);  // Led Oranye mati
  	digitalWrite(3, LOW);  // Led Kuning mati
    digitalWrite(2, HIGH); // Led Hijau nyala
    delay(100);           // Tunggu selama 100 millisecond
}

void off(){
  	digitalWrite(7, LOW);  // Led Putih mati
    digitalWrite(6, LOW);  // Led Merah mati
  	digitalWrite(5, LOW);  // Led Biru mati
    digitalWrite(4, LOW);  // Led Oranye mati
  	digitalWrite(3, LOW);  // Led Kuning mati
    digitalWrite(2, LOW);  // Led Hijau mati
    delay(100);           // Tunggu selama 100 millisecond
	noTone(speakerPin);
}