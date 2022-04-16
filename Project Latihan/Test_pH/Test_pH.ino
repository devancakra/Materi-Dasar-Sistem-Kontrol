void setup() 
{
 Serial.begin(9600);
}


void loop() 
{
  //Cek Tegangan
  int sensorValue = analogRead(35);
  float xn = sensorValue * (5.0 / 1023.0) / 10;
  float xcal = 3.7;
  float x = abs(xn - xcal);
  Serial.print("Deteksi Tegangan: " + String (x));
  float a = 21.84; float b = -5.27; //Linear Regression Value
  float y = a + b * x; //pH Value

  //set point atas dan bawah
  if(y>14.00){ y = 14.00; } 
  else if (y<0.00){ y = 0.00; }
  Serial.println(" _ Deteksi pH: " + String(y));
  delay(1000);
}
