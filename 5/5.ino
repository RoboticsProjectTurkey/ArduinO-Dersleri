const int trigger_pin = 12;
const int echo_pin = 13;
const int aled = 2;
const int bled = 3;
const int cled = 4;
const int dled = 5;
const int buzzer = 6;
int sure ;
int mesafe ;
  
void setup() {
pinMode(aled , OUTPUT);
pinMode(bled , OUTPUT);
pinMode(cled , OUTPUT);
pinMode(dled , OUTPUT);
pinMode(buzzer , OUTPUT);
pinMode(trigger_pin , OUTPUT);
pinMode(echo_pin ,INPUT);
Serial.begin(9600);
  
}
  
void loop()
{
digitalWrite(trigger_pin , HIGH);
delayMicroseconds(1000);
digitalWrite(trigger_pin , LOW);
sure = pulseIn(echo_pin , HIGH);
mesafe = (sure/2) / 29.1;
  
if (mesafe <= 10)
{
digitalWrite(aled , HIGH);
digitalWrite(buzzer , HIGH);
delay(250);
digitalWrite(aled , LOW);
digitalWrite(buzzer , LOW);
}
else if (mesafe <=25)
{
digitalWrite(bled , HIGH);
digitalWrite(buzzer , HIGH);
delay(500);
digitalWrite(bled , LOW);
digitalWrite(buzzer , LOW);
}
else if ( mesafe <=50)
{
digitalWrite(cled , HIGH);
digitalWrite(buzzer , HIGH);
delay(750);
digitalWrite(cled , LOW);
digitalWrite(buzzer , LOW);
}
else
{
digitalWrite(dled , HIGH);
delay(1000);
digitalWrite(dled , LOW);
  
}
}
