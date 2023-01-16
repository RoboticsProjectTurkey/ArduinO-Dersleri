int xPin = A0; 
int yPin = A1; 
int ledK=2; int ledM=3; int ledY=4; int ledS=5;
 
int xPozisyon = 0;
int yPozisyon = 0;
 
 
void setup() {
pinMode(xPin, INPUT);
pinMode(yPin, INPUT);
pinMode(ledK,OUTPUT); pinMode(ledM,OUTPUT); 
pinMode(ledY,OUTPUT); pinMode(ledS,OUTPUT);
}
 
void loop() {
xPozisyon = analogRead(xPin);
yPozisyon = analogRead(yPin);
if(xPozisyon<10){digitalWrite(ledK,HIGH);}else{digitalWrite(ledK,LOW);}
if(xPozisyon>1000){digitalWrite(ledM,HIGH);}else{digitalWrite(ledM,LOW);} 
if(yPozisyon<10){digitalWrite(ledY,HIGH);}else{digitalWrite(ledY,LOW);}
if(yPozisyon>1000){digitalWrite(ledS,HIGH);}else{digitalWrite(ledS,LOW);} 
}
