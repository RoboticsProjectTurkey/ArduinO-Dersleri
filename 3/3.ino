const int LEDdizisi[] = {2,3,4,5,6,7,8,9,10,11,12};

void setup () {     
 
  for(int i=0; i<11 ;i++)    
  { /* For dongusuyle LEDdizisi elemanlarina ulasiyoruz */
    pinMode(LEDdizisi[i], OUTPUT); /* LED pinleri cikis olarak ayarlandi */
  }

}

void loop() {                                                
  for(int i=0; i<11; i++){ /* Tum LEDleri sirayla 50 milisaniye yakip sonduruyoruz */
    digitalWrite(LEDdizisi[i],HIGH);      
    delay(50);                           
    digitalWrite(LEDdizisi[i],LOW);         
  }
 
  for(int j=7;j>-1; j--)
  { /* LEDleri geri yonde 50 milisaniye yakip sonduruyoruz */
    digitalWrite(LEDdizisi[j],HIGH);     
    delay(50); //Bu değeri çoğaltırsanız led geçişleri biraz yavaşlar
    digitalWrite(LEDdizisi[j], LOW);
  }
}
