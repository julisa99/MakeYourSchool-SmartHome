#include <WiFi.h>
#include <Espalexa.h>
#include <Adafruit_NeoPixel.h>

Adafruit_NeoPixel leuchtstreifen(60, 13, NEO_GRB + NEO_KHZ800);
Espalexa espalexa;

void starteInternetverbindung() {
  if (WiFi.status() != WL_CONNECTED) {
    WiFi.begin("DeinWLAN", "GeheimesPasswort");

    while (WiFi.status() != WL_CONNECTED) {
      delay(500);
    }
  }
}

void aktualisiereLeuchtstreifen(uint8_t helligkeit, uint32_t farbe) {
  leuchtstreifen.clear(); 
  leuchtstreifen.setBrightness(helligkeit);
  leuchtstreifen.fill(farbe);
  leuchtstreifen.show();
}

void setup()
{
  leuchtstreifen.begin();           
  starteInternetverbindung();  
  espalexa.addDevice("Leuchtstreifen", aktualisiereLeuchtstreifen);
  espalexa.begin();
}
 
void loop()
{
   espalexa.loop();
   delay(1);
}