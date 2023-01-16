//Motor Pinlerimiz
int motora1 = 9;
int motora2 = 3;
int motorb1 = 10;
int motorb2 = 5;

void setup() {
  //pin modlarını tanımladık.
  pinMode(motora1, OUTPUT);
  pinMode(motora2, OUTPUT);
  pinMode(motorb1, OUTPUT);
  pinMode(motorb2, OUTPUT);
}

void loop() {
  motorkontrol(0,60);
  motorkontrol2(0,60);
}


//Motor kontrol fonksiyonumuz.
void motorkontrol(int x,int y){
  analogWrite(motora1,x);
  analogWrite(motora2,y);
  }
void motorkontrol2(int x,int y){
  analogWrite(motorb1,x);
  analogWrite(motorb2,y);
  }
