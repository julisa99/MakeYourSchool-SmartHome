# LED-Streifen mit Alexa ansteuern 
Workshop für den MakeYourSchool Alumni Netzwerktag am 12.06.2021

## Materialien
 - WS2812B LED Streifen
 - ESP32 Dev Board
 - 3 Jumperkabel (männlich auf männlich, das erkennt ihr an den metallenen Spitzen) 
 - 3 Jumperkabel (weiblich auf weiblich)
 - Mikro-USB-Kabel (Falls dein ESP32 nicht erkannt wird, probiere ein anderes Kabel, da es sein kann, dass du kein Kabel zur Datenübertragung erwischt hast, sondern nur eins, welches laden kann)
 
## Aufbau
Stecke jeweils einen männlichen Jumperkabel in einen weiblichen Jumperkabel. Dadurch erhältst du ein langes Kabel, welches auf der einen Seite einen weiblichen Anschluss hat und auf der anderen einen männlichen. Die weiblichen Enden steckst du beim ESP32 Dev Board in die Anschlüsse GND, 5V und G13. Die männlichen Enden kannst du bei deinem LED-Streifen anschließen. Dort steckst du die Spitzen entsprechend der Abbildung so an, dass 5V mit 5V, GND mit GND und G13 mit Din verbunden ist. Du kannst auf deinem LED-Streifen kleine weiße Pfeile erkennen, das steht für die Richtung des Datenflusses. Es ist also wichtig, an welchem Ende des LED-Streifens du den Mikrocontroller anschließt.
![led-esp32](https://user-images.githubusercontent.com/8758907/121436202-6efcf300-c980-11eb-92a6-3f77b4eb689f.png)

## Programmierung
1. Installiere die Arduino IDE für dein Betriebssystem. Du findest die Software hier zum Download: https://www.arduino.cc/en/main/software
2. Bei der Installation der Arduino IDE fehlen die sogenannten Boardinformationen für den ESP32. Damit du diesen programmieren kannst, kopiere https://dl.espressif.com/dl/package_esp32_index.json 
3. Öffne die Arduino IDE. Klicke unter "Datei" auf die Schaltfläche "Voreinstellungen". Bei dem Abschnitt "Zusätzliche Boardverwalter-URLs" fügst du den kopieren Link hinzu. 
![grafik](https://user-images.githubusercontent.com/8758907/121437678-fea3a100-c982-11eb-8d2b-4866af5fd97c.png)
4. Nun gehst du zum "Boardverwalter" unter "Werkzeuge" und dann "Board" und tippst in das Suchfeld "esp32" ein und anschließend auf "Installieren". 
![grafik](https://user-images.githubusercontent.com/8758907/121437614-ea5fa400-c982-11eb-89ee-417fe2a434c8.png)
5. Wähle unter "Werkzeuge" die Schaltfläche "Board" und dort den "ESP32 Dev Module" aus.
![grafik](https://user-images.githubusercontent.com/8758907/121437842-34488a00-c983-11eb-88c9-7b3c792171d1.png)
6. Öffne die [MakeYourSchool-SmartHome.ino](https://github.com/julisa99/MakeYourSchool-SmartHome/blob/main/MakeYourSchool-SmartHome.ino) in der Arduino IDE.
7. Trage in Zeile 10 deine entsprechenden Zugangsdaten für dein WLAN ein.
8. Installiere die zwei verwendeten Bibliotheken. Gehe dafür unter "Sketch" auf "Bibliothek einbinden" und dann "Bibliothek verwalten". Drt gibst du im Suchfeld "espalexa" ein und klickst auf "Installieren". Danach gibst du im Suchfeld "Adafruit NeoPixel" ein und installierst diese Bibliothek auch.
9. Schließe dein ESP32 Dev Board mit dem Mikro-USB-Kabel an deinen Computer an.
10. Wähle unter "Werkzeuge" die Schaltfläche "Ports" und dort den COM-Anschluss aus, wo dein ESP32 DEV Board angeschlossen ist.
11. Klicke auf den Hochladen-Button, also den kreisförmigen Button mit dem Pfeil nach rechts.
12. Für das Raufspielen neuer Software auf den Mikrocontroller musst du meist die BOOT-Taste während des Hochladens an deinem ESP32 Dev Board gedrückt halten. Am besten startest du mit dem Raufdrücken, wenn in der Arduino IDE die Ausgabe "Connecting.......__" unten im schwarzen Feld angezeigt wird und du kannst die Taste loslassen, sobald dort eine Textflut an anderen Informationen ausgegeben wird.

## Alexa nutzen
Starte die Suche nach neuen Geräten, indem du sagst "Alexa, suche neue Geräte". Alternativ kannst du das auch über die Alexa-App machen. Alexa findet dann das Gerät "Leuchtstreifen". Steuere das Gerät mit Befehlen wie "Alexa, mache Leuchtstreifen grün", "Alexa, dimme Leuchtstreifen auf 20 Prozent" oder "Alexa, schalte Leuchtstreifen aus".
