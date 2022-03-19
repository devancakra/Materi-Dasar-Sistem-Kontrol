//============================================================ Deklarasi Library ===========================================================
#include <WiFi.h> //Pemanggilan Library WiFi
#include <PubSubClient.h> //Pemanggilan Library PubSubClient
#include <CTBot.h> //Pemanggilan Library CTBot

CTBot myBot; //Constructor CTBot
WiFiServer server(80); //Constructor WiFiServer
WiFiClient espClient; //Constructor WiFiClient
PubSubClient client(espClient); //Constructor PubSubClient

//============================================================= Define Variabel =============================================================
#define mqtt_server "i-ot.net" //Nama Platform IoT (Broker)
#define mqtt_port 1883 //Port I-ot.net
#define mqtt_username "devancakra6@gmail.com" //Username I-ot.net
#define mqtt_password "m00nrush311099" //Password I-ot.net
#define BOTtoken "2130879110:AAEoY1qtnB3xcspCUjCYsUGImysau3N802U" //API bot telegram
#define ssid "WIJAYA" //Nama wifi router
#define password "iswari71" //Password wifi router

//============================================================== Method Setup ===============================================================
void setup(){
  Serial.begin(9600); //Memulai komunikasi serial dengan baud rate 9600
  connectWiFi(); //Memanggil fungsi connectWiFi
  connectIoT(); //Memanggil fungsi connectIoT (i-ot.net)
  connectBot(); //Memanggil fungsi connectBot (Bot Telegram)
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

//========================================================== Method Konfigurasi IoT ========================================================
void connectIoT(){
  Serial.print("\n[Konfigurasi IoT]\nmencoba menghubungkan ke Platform : "); 
  Serial.println(mqtt_server); 
  client.setServer(mqtt_server, mqtt_port); 

  while(!client.connected()){
    if(client.connect("ESP32Client", mqtt_username, mqtt_password)){
      Serial.println("\nstatus :\ni-ot.net berhasil tersambung");  
    } else{
      Serial.print("\nstatus :\ni-ot.net gagal tersambung (" + String(client.state()) + ")\nmenyambungkan kembali");
      while(!client.connect("ESP32Client", mqtt_username, mqtt_password)){
        delay(500);
        Serial.print(".");
      }
    }
  } 
  
  delay(1000);
}

//====================================================== Method Konfigurasi Bot Telegram ===================================================
void connectBot(){
  myBot.setTelegramToken(BOTtoken);
  myBot.wifiConnect(ssid, password); 
  myBot.setMaxConnectionRetries(5);
  Serial.println("\n[Konfigurasi Bot Telegram]\nmencoba menghubungkan ke : phiotnet_bot"); 

  if(myBot.testConnection()){
    Serial.println("\nstatus :\nbot telegram berhasil tersambung"); 
  } else{ 
    Serial.print("\nstatus :\nbot telegram gagal tersambung\nmenyambungkan kembali"); 
    while (!myBot.testConnection()){ 
      delay(1000);
      Serial.print(".");
    }
  } delay(1000); 
  
  Serial.print("==================================================================================\n\n");
}
