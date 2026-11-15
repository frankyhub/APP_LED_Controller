/************************************************************************************************* 
                                      PROGRAMMINFO
************************************************************************************************** 
Funktion: APP LED Controller
Vor dem Programm hochladen RX und TX Verbindung löasen!!!!!!!!!!!!!!!
Bluetooth mitHC05 koppeln
NANO-Shield 2022 V1 D0 RXT D1 TXT
**************************************************************************************************
Version: 27.02.2022
**************************************************************************************************
Board: NANO V3 
HC 05 Bluetooth Wireless RF-Transceiver-Modul RS232 
**************************************************************************************************
C++ Arduino IDE V1.8.13
**************************************************************************************************
Einstellungen:
https://dl.espressif.com/dl/package_esp32_index.json
http://dan.drown.org/stm32duino/package_STM32duino_index.json
https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_dev_index.json
**************************************************************************************************
**************************************************************************************************/
int led = 13;    // Onboard LED Ausgang 13 
int state;       // LED Status


void setup() {

    pinMode(led, OUTPUT);
    digitalWrite(led, LOW); 
    Serial.begin(9600);
}

void loop() {
    //Wert auslesen und speichern
    if(Serial.available() > 0){     
     state = Serial.read();   

    }   
    // Wenn der Status 0 ist -> LED aus
    if (state == '0') {
        digitalWrite(led, LOW); 

    }
    
    // Wenn der Status 1 ist -> LED ein
    else if (state == '1') {
        digitalWrite(led, HIGH); 

    }

    //LED Status
    Serial.println(state);
}
