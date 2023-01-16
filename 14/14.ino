// 10K Ohm potentiometer on A0
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_BMP085.h>
#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>

//   PINS                                   CLK, DIN, DC, CE, RST
Adafruit_PCD8544 display = Adafruit_PCD8544(7,   6,   5,  4,  3);

Adafruit_BMP085 bmp;

void setup()   {
  SPI.begin();
  Wire.begin();
  bmp.begin();
  Serial.begin(9600);
  display.begin();      // Initialise display
  int con = 55;         // Change up or down by 1 to get
  int bias = 4;         // the best settings for your display
  display.setBias(bias);
  display.setContrast(con);
  display.clearDisplay();
  display.setCursor(0,5);
  display.println("Project Turkey");
  display.setCursor(0,15);
  display.print("BMP180");
  display.setCursor(17,40);
  display.print("Weather");
  display.display();  // Static parts of screen written at this point
}
// ++++++++++++Main Loop ++++++++++++++
void loop() {
  display.clearDisplay();
  display.setCursor(0,0);
  display.println("Temperature =");
  display.setCursor(40,10);
  display.println(bmp.readTemperature());

  display.setCursor(0,30);
  display.println("Pressure =");
  display.setCursor(40,40);
  display.println(bmp.readPressure());
  
  display.display();
  delay(1000);

  display.clearDisplay();
  display.setCursor(0,0);
  display.println("Altitude =");
  display.setCursor(40,10);
  display.println(bmp.readAltitude());

  display.setCursor(0,20);
  display.println("Pressure");
  display.setCursor(0,30);
  display.println("at sealevel =");
  display.setCursor(40,40);
  display.println(bmp.readSealevelPressure());
  
  display.display();
  delay(1000);
}
