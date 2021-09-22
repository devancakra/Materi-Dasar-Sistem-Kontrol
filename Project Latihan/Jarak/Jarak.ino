int trigger = 13, echo = 12;
float jarak = 0;

void setup(){
  Serial.begin(9600);
  pinMode(trigger,OUTPUT);
  pinMode(echo, INPUT);
}

void loop(){
  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger, LOW);
  jarak=(float)pulseIn(echo, HIGH)/58;
  Serial.println(jarak);
  delay(100);
}