int led1 = 11,led2 = 10,led3 = 9;
int trigger = 13, echo = 12;
float jarak = 0;

void setup(){
  Serial.begin(9600);
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
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
  
  if(jarak <= 20){
    digitalWrite(led1,HIGH);
    digitalWrite(led2,LOW);
    digitalWrite(led3,LOW);
  }
  else if(jarak > 15 && jarak <= 25){
    digitalWrite(led1,LOW);
    digitalWrite(led2,HIGH);
    digitalWrite(led3,LOW);
  }
  else if(jarak > 25 && jarak <= 30){
    digitalWrite(led1,LOW);
    digitalWrite(led2,LOW);
    digitalWrite(led3,HIGH);
  }
}
