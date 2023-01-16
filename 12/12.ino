#include <SPI.h> 
#include <MFRC522.h>
const byte green = 4;
const byte red = 2;
MFRC522 rfid(10, 9);
byte card[4] = {199, 0, 43, 83};
boolean ok; 
void setup() 
{ 
  Serial.begin(9600); 
  pinMode(green, OUTPUT); 
  pinMode(red, OUTPUT);
  SPI.begin();
  rfid.PCD_Init(); 
} 
void loop()
{ 
  ok = true;
  if ( rfid.PICC_IsNewCardPresent())
  { 
    if ( rfid.PICC_ReadCardSerial())
    { Serial.print("Card of Reading");
     Serial.print(rfid.uid.uidByte[0]); 
     Serial.print(",");
     Serial.print(rfid.uid.uidByte[1]); 
     Serial.print(","); 
     Serial.print(rfid.uid.uidByte[2]); 
     Serial.print(","); 
     Serial.println(rfid.uid.uidByte[3]);
    } 
    for (int i = 0; i < 4; i++) 
    {
      if (rfid.uid.uidByte[i] != card[i])
      {
        ok = false;
      }
    } 
    if (ok == true) 
    { 
      Serial.println("True Card"); 
      digitalWrite(green, HIGH); 
      delay(1000); 
      digitalWrite(green, LOW);
    } 
    else 
    {
      Serial.println("False Card"); 
      digitalWrite(red, HIGH);
      delay(1000);
      digitalWrite(red, LOW);
    } 
    rfid.PICC_HaltA(); 
  } 
}
