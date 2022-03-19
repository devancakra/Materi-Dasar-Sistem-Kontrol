//Deklarasi Library dan Variabel 
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
#include "RTClib.h"
RTC_DS3231 rtc;
char dataHari[7][12] = {"Minggu", "Senin", "Selasa", "Rabu", "Kamis", "Jumat", "Sabtu"};
String hari, waktu; int tanggal, bulan, tahun, jam, menit, detik;

//Method setup
void setup () {
  Serial.begin(9600); //Memulai komunikasi serial dengan baud rate 9600
  RTCinit(); //Memanggil method RTCinit
  LCDinit(); //Memanggil method LCDinit
}

//Method loop
void loop () {
  DTnow(); //Memanggil method DTnow
  Viewnow(); //Memanggil method Viewnow
}

//Method RTCinit
void RTCinit(){
  rtc.begin(); //Memulai komunikasi serial dengan RTC
  rtc.adjust(DateTime(F(__DATE__), F(__TIME__))); //Pengaturan DateTime
}

// Method LCDinit
void LCDinit(){
  lcd.init(); //Memulai komunikasi serial dengan LCD
  lcd.clear(); //Hapus layar
  lcd.backlight(); lcd.setCursor(1,0); lcd.print("Memulai"); //Tampilan layar baris 1
  lcd.setCursor(1,1); lcd.print("Sistem pH..."); delay(5000); //Tampilan layar baris 2
  lcd.clear(); //Hapus layar
  lcd.backlight(); lcd.setCursor(1,0); lcd.print("Welcome to"); //Tampilan layar baris 1
  lcd.setCursor(1,1); lcd.print("PHIOTNET...."); delay(5000); //Tampilan layar baris 2
}

//Method DTnow
void DTnow(){
  DateTime now = rtc.now(); //Membuat objek baru: now untuk menampung method rtc
  hari = dataHari[now.dayOfTheWeek()]; //Hari
  tanggal = now.day(), DEC; bulan = now.month(), DEC; tahun = now.year(), DEC; //DD-MM-YYYY
  jam = now.hour(), DEC; menit = now.minute(), DEC; detik = now.second(), DEC; //hh:mm:ss
  waktu = String() + hari + ", " + tanggal + "-" + bulan + "-" + tahun + " (" + jam + ":" + menit + ":" + detik + ")"; //waktu
  Serial.println(waktu); delay(1000); //cetak serial monitor waktu
}

//Method Viewnow
void Viewnow(){
  lcd.clear(); //Hapus layar
  lcd.backlight(); lcd.setCursor(1,0); lcd.print("Uji Coba"); delay(1000); ////Tampilan layar baris 1
  lcd.backlight(); lcd.setCursor(1,1); lcd.print("LCD I2C.."); delay(1000); ////Tampilan layar baris 2
  lcd.clear(); //Hapus layar
  lcd.backlight(); lcd.setCursor(4,0); lcd.print(String() + tanggal + "-" + bulan + "-" + tahun); delay(1000); ////Tampilan layar baris 1
  lcd.backlight(); lcd.setCursor(3,1); lcd.print(String() + " (" + jam + ":" + menit + ":" + detik + ")"); delay(1000); ////Tampilan layar baris 2
}
