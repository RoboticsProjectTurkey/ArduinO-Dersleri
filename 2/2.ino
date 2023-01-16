int deger = 0;
int led = 6;
void setup() {
  // put your setup code here, to run once:
  pinMode(led, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  deger = analogRead(A0);
  analogWrite(led, deger);
}
