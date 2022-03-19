//Deklarasi Library
#include <RTClib.h>

//Inisialisasi Constructor
RTC_DS3231 rtc;

//Deklarasi Variabel Dengan Tipe Data
char dataHari[7][12] = {"Minggu", "Senin", "Selasa", "Rabu", "Kamis", "Jumat", "Sabtu"};
String hari, waktu; int tanggal, bulan, tahun, jam, menit, detik;

//Method Setup
void setup() {
  RTCinit(); //Memanggil method RTCinit
}

//Method Loop
void loop(){
  Serial.begin(9600);
  DTnow(); //Memanggil method DTnow
}

//Method RTCinit
void RTCinit(){
  rtc.begin(); //Memulai komunikasi serial dengan RTC
  rtc.adjust(DateTime(F(__DATE__), F(__TIME__))); //Pengaturan DateTime
//  rtc.adjust(DateTime(2022, 3, 19, 10, 27, 0));
}

//Method DTnow
void DTnow(){
  DateTime now = rtc.now(); //Membuat objek baru: now untuk menampung method RTC
  hari = dataHari[now.dayOfTheWeek()]; //Hari
  tanggal = now.day(), DEC; bulan = now.month(), DEC; tahun = now.year(), DEC; //DD-MM-YYYY
  jam = now.hour(), DEC; menit = now.minute(), DEC; detik = now.second(), DEC; //hh:mm:ss
  waktu = String() + hari + ", " + tanggal + "-" + bulan + "-" + tahun + " (" + jam + ":" + menit + ":" +
  detik + ")"; //waktu
  Serial.println(waktu); delay(1000); //cetak serial monitor waktu
}
