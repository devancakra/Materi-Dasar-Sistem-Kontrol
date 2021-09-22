void setup()
{
  Serial.begin(9600);
  pinMode(A0, INPUT);
}

void loop()
{
  Serial.print(analogRead(A0));
  Serial.print("\n");
}
