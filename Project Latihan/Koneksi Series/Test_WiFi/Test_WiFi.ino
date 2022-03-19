//============================================================ Deklarasi Library ===========================================================
#include <WiFi.h> //Pemanggilan Library WiFi


//============================================================= Define Variabel =============================================================
#define ssid "NAMA_WIFIMU_CUY_TAROH_SINI" //Nama wifi router
#define password "PASSWORD_WIFIMU_CUY_TAROH_SINI" //Password wifi router

//============================================================== Method Setup ===============================================================
void setup(){
  Serial.begin(9600); //Memulai komunikasi serial dengan baud rate 9600
  connectWiFi(); //Memanggil fungsi connectWiFi
}

//============================================================== Method Loop ===============================================================
void loop(){
  reconnectWiFi();
}

//========================================================== Method Konfigurasi WiFi =======================================================
void connectWiFi(){
  Serial.println("\n==================================================================================");
  Serial.print("[Konfigurasi Wi-Fi]\nmencoba menghubungkan ke Wi-Fi : "); 
  Serial.println(ssid); 
  WiFi.begin(ssid, password);
  
  while(WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }
  
  Serial.println();
  Serial.println("\nstatus :\nWi-Fi berhasil tersambung");
  Serial.println(WiFi.localIP());
  delay(1000);
}

//========================================================== Method Reconnect WiFi =========================================================
void reconnectWiFi(){
  // Reconnect Wi-Fi
  unsigned long currentMillis = millis();
  unsigned long previousMillis = 0;
  unsigned long interval = 30000;
  if ((WiFi.status() != WL_CONNECTED) && (currentMillis - previousMillis >=interval)) {
    Serial.print(millis());
    WiFi.disconnect();
    WiFi.reconnect();
    previousMillis = currentMillis;
  } delay(1000);
}
