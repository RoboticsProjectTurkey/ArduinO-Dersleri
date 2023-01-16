int pirPin = 8;                   //Sensörü takacağımız pin
int aled = 9;
int bled = 10;
int buzzer = 2;
int hareket;                      //Sensörden aldığımız veri



void setup() {

  pinMode(pirPin, INPUT);         //Sensör pinimizi giriş olarak ayarlyoruz.
  pinMode(aled, OUTPUT);      
  pinMode(bled, OUTPUT);        
  pinMode(buzzer, OUTPUT);  
  

}

void loop() {
  hareket = digitalRead(pirPin);  //Sensörden okuma yapıyoruz.
  
  if(hareket == HIGH){            //Hareketlilik var ise içerideki komutlar uygulanır.
   digitalWrite(buzzer,HIGH);
   digitalWrite(bled,HIGH);
   digitalWrite(aled,LOW);
   delay(400);
   digitalWrite(buzzer,LOW);
  }
  else{                           //Hareketlilik yok ise içerideki komutlar uygulanır.
   digitalWrite(buzzer,LOW);
   digitalWrite(bled,LOW);
   digitalWrite(aled,HIGH);
    
  }
}
