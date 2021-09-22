int LM = 13;
int LH = 1;
int LB = 0;

void setup()
{
  pinMode(LM, OUTPUT);
  pinMode(LB, OUTPUT);
  pinMode(LH, OUTPUT);
}

void loop()
{
  digitalWrite(LM, HIGH); // LED Merah nyala
  digitalWrite(LB, LOW); // LED Biru mati
  delay(1000); //Waktu tunggu 1 detik
  digitalWrite(LH, HIGH); // LED Hijau nyala
  digitalWrite(LM, LOW); // LED Merah mati
  delay(1000); //Waktu tunggu 1 detik
  digitalWrite(LB, HIGH); // LED Biru nyala
  digitalWrite(LM, LOW); // LED Merah mati
  delay(1000); //Waktu tunggu 1 detik
}
