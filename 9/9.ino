#define led 3   //led pini 
void setup() {
  
pinMode(led,OUTPUT);  //ledi çikış yaptık
Serial.begin(9600);  //seri portu başlattık

}
void loop() {
int deger=analogRead(A0);   //değeri okuduk
Serial.println(deger);     //değeri seri porta yazdırdık
if(deger==0){           
digitalWrite(led,HIGH);
}
else{
digitalWrite(led,LOW);
}
delay(500);
}
