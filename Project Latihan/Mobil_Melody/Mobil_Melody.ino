//motor 1
#define enA 9 //kiri
#define in1 4 //kiri maju
#define in2 5 //kiri mundur

//motor 2
#define enB 10 //kanan
#define in3 6 //kanan maju
#define in4 7 //kanan mundur

int speakerPin = 13;

int length = 15; // the number of notes
char notes[] = "ccggaagffeeddc "; // a space represents a rest
int beats[] = { 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 2, 4 };
int tempo = 300;

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

void setup(){
  // set all the motor control pins to outputs
  pinMode(enA, OUTPUT); //kiri
  pinMode(enB, OUTPUT); //kanan
  pinMode(in1, OUTPUT); //kiri maju
  pinMode(in2, OUTPUT); //kiri mundur
  pinMode(in3, OUTPUT); //kanan maju
  pinMode(in4, OUTPUT); //kanan mundur
  pinMode(speakerPin, OUTPUT); //buzzer
}

void demoOne(){
  //mundur kebelakang
  digitalWrite(in1, HIGH); //kiri maju
  digitalWrite(in2, LOW); //kiri mundur mati
  digitalWrite(in3, HIGH); //kanan maju
  digitalWrite(in4, LOW); //kanan mundur mati

  for (int i = 0; i < 50; i++) {
    analogWrite(enA, i); //speed motor kiri
    analogWrite(enB, i); //speed motor kanan
    delay(20); //jeda 20 ms
  }

  for (int i = 50; i > 0; i--) {
    analogWrite(enA, i); //speed motor kiri
    analogWrite(enB, i); //speed motor kanan
    delay(20); //jeda 20 ms
  }
  
  //kiri kanan mati semua
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW); 
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}

void demoTwo(){
  //Belok Kanan
  digitalWrite(in1, HIGH); //kiri maju
  digitalWrite(in2, LOW); //kiri mundur mati
  digitalWrite(in3, LOW); //kanan maju mati
  digitalWrite(in4, HIGH); //kanan mundur
   
  for (int i = 0; i < 50; i++) {
    analogWrite(enA, i); //speed motor kiri
    analogWrite(enB, i); //speed motor kanan
    delay(20); //jeda 20 ms
  }
  
  for (int i = 50; i > 0; --i){
    analogWrite(enA, i); //speed motor kiri
    analogWrite(enB, i); //speed motor kanan
    delay(20); //jeda 20 ms
  }

  //kiri kanan mati semua
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW); 
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW); 
}

void demoThree(){
  //maju kedepan
  digitalWrite(in1, LOW); //kiri maju
  digitalWrite(in2, HIGH); //kiri mundur mati
  digitalWrite(in3, LOW); //kanan maju
  digitalWrite(in4, HIGH); //kanan mundur mati

  for (int i = 0; i < 50; i++) {
    analogWrite(enA, i); //speed motor kiri
    analogWrite(enB, i); //speed motor kanan
    delay(20); //jeda 20 ms
  }

  for (int i = 50; i > 0; i--) {
    analogWrite(enA, i); //speed motor kiri
    analogWrite(enB, i); //speed motor kanan
    delay(20); //jeda 20 ms
  }
  
  //kiri kanan mati semua
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW); 
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}

void demoFour(){
  //Belok Kiri
  digitalWrite(in1, LOW); //kiri maju mati
  digitalWrite(in2, HIGH); //kiri mundur
  digitalWrite(in3, HIGH); //kanan maju 
  digitalWrite(in4, LOW); //kanan mundur mati
   
  for (int i = 0; i < 50; i++) {
    analogWrite(enA, i); //speed motor kiri
    analogWrite(enB, i); //speed motor kanan
    delay(20); //jeda 20 ms
  }
  
  for (int i = 50; i > 0; --i){
    analogWrite(enA, i); //speed motor kiri
    analogWrite(enB, i); //speed motor kanan
    delay(20); //jeda 20 ms
  }

  //kiri kanan mati semua
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW); 
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW); 
}

void melody(){
  for (int i = 0; i < length; i++) {
    if (notes[i] == ' ') {
      delay(beats[i] * tempo); // rest
    } else {
      playNote(notes[i], beats[i] * tempo);
    }

    // pause between notes
    delay(tempo / 2);
  }
}

void loop(){  
  for (int i = 0; i < 2; i++) {
    if(i<5){
      demoOne();
      delay(1000);
      melody();
    
      demoTwo();
      delay(1000);
      melody();

      demoOne();
      delay(1000);
      melody();

      demoTwo();
      delay(1000);
      melody();

      demoThree();
      delay(1000);
      melody();
    
      demoFour();
      delay(1000);
      melody();

      demoThree();
      delay(1000);
      melody();

      demoFour();
      delay(1000);
      melody();
    }
    else{
      digitalWrite(in1, LOW);
      digitalWrite(in2, LOW); 
      digitalWrite(in3, LOW);
      digitalWrite(in4, LOW); 
    }
  }
}
