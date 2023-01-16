int sclk = 13;
int mosi = 11;
int cs = 10;
int dc = 9;
int rst = 8;
#include <SPI.h>
#include <Adafruit_GFX.h> // grafik kütüphanesi
#include <Adafruit_ST7735.h> // donanım kütüphanesi
Adafruit_ST7735 tft = Adafruit_ST7735 (cs, dc, rst);
void setup() {
  Serial.begin (9600);
  tft.initR();
  Serial.println ("TFT bağlandı");
  tft.setRotation(3); //Ekranın yönünü yatay yapalım
  tft.fillScreen (0x07FF);  //Ekranın rengi kırmızı olsun
  tft.fillRoundRect(15, 30, 130, 70, 3, 0xFFFF); //Kırmızı ekranın ortasına siyah dikdörtgen çizelim
  tft.setTextColor(0x0000); ////Yazının rengi beyaz olsun
  tft.setTextSize(2);  // Yazı boyutu 2 olsun
  tft.setCursor (25, 35);  // Yazının başlangıç pikselinin koordinatları
  tft.print ("Robotics");  // Ekrana yazdırılacak metin
  tft.setTextColor(0x001F);  //Yazının rengi sarı olsun
  tft.drawLine(0, 52, 180, 52, 0x0000);//Yazı arasına beyaz çizgi çizelim
  tft.setCursor (40, 55);  // Yazının başlangıç pikselinin koordinatları
  tft.print ("Project");  // Ekrana yazdırılacak metin
  tft.drawLine(0, 73, 180, 73, 0x0000);//Yazı arasına beyaz çizgi çizelim
  tft.setTextColor(0x0000);  //Yazının rengi beyaz olsun
  tft.setCursor (55, 75);  // Yazının başlangıç pikselinin koordinatları
  tft.print ("Turkey");  // Ekrana yazdırılacak metin
}
void loop() {
}
