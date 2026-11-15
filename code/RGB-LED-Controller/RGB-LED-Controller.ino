/************************************************************************************************* 
                                      PROGRAMMINFO
************************************************************************************************** 
Funktion: RGB-KED-Controller

**************************************************************************************************
Version: 15.11.2026
**************************************************************************************************
Board: UNO
**************************************************************************************************
C++ Arduino IDE V1.8.13
**************************************************************************************************
Einstellungen:
https://dl.espressif.com/dl/package_esp32_index.json
http://dan.drown.org/stm32duino/package_STM32duino_index.json
https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_dev_index.json
*************************************************************************************************/ 


#define max_char 12
char message[max_char];    // speichert deine Nachricht
char r_char;               // liest jedes Zeichen
byte index = 0;            // definiert die Position in deinem Array
int i;

int redPin = 11;     // Rot RGB pin -> D11
int greenPin = 10;   // Grün RGB pin -> D10
int bluePin = 9;     // Blau RGB pin -> D9

int redValue = 255;     // Rot RGB pin -> D11
int greenValue = 255;   // Grün RGB pin -> D10
int blueValue = 255;     // Blau RGB pin -> D9

String redTempValue;     // Rot RGB pin -> D11
String greenTempValue;   // Grün RGB pin -> D10
String blueTempValue;     // Blau RGB pin -> D9

int flag = 0;
char currentColor;  

void setup() {
  pinMode(redPin,OUTPUT);
  pinMode(bluePin,OUTPUT);
  pinMode(greenPin, OUTPUT);
  // seriellen Anschluss mit 9600 Bit pro Sekunde starten:
  Serial.begin(9600);
}

void loop() {
  //Nachricht lesen 
  while(Serial.available() > 0){
    flag = 0;
    //Die Nachricht kann bis zu 12 Zeichen haben 
    if(index < (max_char-1)){         
      r_char = Serial.read();      // Liest ein Zeichen
      message[index] = r_char;     // Speichert das Zeichen im Nachrichten-Array
      if(r_char=='R'){
         currentColor = 'R';
         redTempValue = "";
      }
      else if(r_char=='G'){
         currentColor = 'G';
         greenTempValue = "";
      }
      else if(r_char=='B'){
         currentColor = 'B';
         blueTempValue = "";
      }
      if(currentColor == 'R' && r_char!='R'){
         redTempValue += r_char;
      }
      else if(currentColor == 'G' && r_char!='G'){
         greenTempValue += r_char;
      }
      else if(currentColor == 'B' && r_char!='B'){
         blueTempValue += r_char;
      }
      index++;                     // Position erhöhen
      message[index] = '\0';       // Lösche die letzte Position
   }
   
 }
 
 if(flag == 0){
   analogWrite(redPin, 255-redTempValue.toInt());
   analogWrite(greenPin, 255-greenTempValue.toInt());
   analogWrite(bluePin, 255-blueTempValue.toInt());
   Serial.print('R');
   Serial.println(redTempValue);
   Serial.print('G');
   Serial.println(greenTempValue);
   Serial.print('B');
   Serial.println(blueTempValue);
   Serial.print("NACHRICHT ");
   Serial.println(message);
   flag=1;
       for(i=0; i<12; i++){
      message[i] = '\0';
    } 
    //resests the index
    index=0;  
 }

}
