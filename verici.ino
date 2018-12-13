#include <VirtualWire.h> // RF modül için gerekli Arduino kütüphanesi
char*mesaj; // Gönderilecek mesajın yazıldığı değişken
const int buton1=6;
const int buton2=7;

bool buton1Durum;
bool buton2Durum;
 
void setup() {
Serial.begin(9600);
pinMode(buton1,INPUT);
pinMode(buton2,INPUT);
  
   vw_set_ptt_inverted(true);
   vw_set_tx_pin(12); // Verici modülün data pin bağlantısı
   vw_setup(4000);
}
 
void loop() {
 buton1Durum=digitalRead(buton1); // Buton1'den okunan değeri değişkene aktardık.
 buton2Durum=digitalRead(buton2); // Buton2'den okunan değeri değişkene aktardık.
 
if(buton1Durum==HIGH)
{
  mesaj="0" ; 
  Serial.println(mesaj); //Oluşturduğumuz mesaj değişkenini serial ekranda yazdırdık.
  vw_send((uint8_t *)mesaj, strlen(mesaj)); //Mesaj değişkenini RF 433 ile alıcı modüle gönderiyoruz.
  vw_wait_tx();
  delay(2);
}

if(buton2Durum==HIGH)
{
  mesaj="1" ; 
  Serial.println(mesaj); //Oluşturduğumuz mesaj değişkenini serial ekranda yazdırdık.
  vw_send((uint8_t *)mesaj, strlen(mesaj)); //Mesaj değişkenini RF 433 ile alıcı modüle gönderiyoruz.
  vw_wait_tx();
  delay(2);
}
  

}
