#include <VirtualWire.h> // RF modül için gerekli Arduino kütüphanesi
char*mesaj;  // Alınan mesajın yazıldığı değişken
int led=2; //Ledin bağlı olduğu arduino pini
 
void setup() {
pinMode(led,OUTPUT);
Serial.begin(9600);
    vw_set_ptt_inverted(true);
    vw_set_rx_pin(6);  //RF alıcı modü data çıkışı bağlı olduğu arduino pini
    vw_setup(4000);
    vw_rx_start();
}
 
void loop() {
    uint8_t buf[VW_MAX_MESSAGE_LEN];
    uint8_t buflen = VW_MAX_MESSAGE_LEN;
    if (vw_get_message(buf, &buflen)) // Eğer gelen mesaj 0 ise ...
    {
      Serial.println(buf[0]);
       if(buf[0]==48) 
         { 
         Serial.println(buf[0]);
         digitalWrite(led,LOW); //Ledi söndür...
         }
         if(buf[0]==49)
         { 
          Serial.println(buf[0]);
          digitalWrite(led,HIGH);  //Ledi yak...
         }         
   }
    
}
