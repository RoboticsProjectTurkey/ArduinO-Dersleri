// Volt Meter on Nokia 5110
// 10K Ohm potentiometer on A0
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>

//   PINS                                   CLK, DIN, DC, CE, RST
Adafruit_PCD8544 display = Adafruit_PCD8544(7,   6,   5,  4,  3);

int sensorPin = A0;   // select the input pin for the potentiometer
int sensorValue = 0;  // variable to store the value coming from the sensor

void setup()   {
  Serial.begin(9600);
  display.begin();      // Initialise display
  int con = 56;         // Change up or down by 1 to get
  int bias = 4;         // the best settings for your display
  display.setBias(bias);
  display.setContrast(con);
  display.clearDisplay();
  display.setCursor(0,5);
  display.println("Project Turkey");
  display.setCursor(0,15);
  display.print("Volt Meter");
  display.setCursor(17,40);
  display.print("Volts:");
  display.display();  // Static parts of screen written at this point
}

int bar(int v, float vv) {  // Bar graph
  display.drawLine(0,28,0,40, BLACK);  
  display.fillRect(1,30,80,8,WHITE);   // Rub out old bar graph
  display.fillRect(0,30,v,8,BLACK);    // Write new bar graph
  display.fillRect(55,40,26,10,WHITE); // Rub out old text
  display.setCursor(55,40);
  display.print(vv);                   // Write new text
  display.display();                   // Update display
}
// ++++++++++++Main Loop ++++++++++++++
void loop() {
  // Read pot and display values
  sensorValue = analogRead(sensorPin); // Read the value from the sensor
  float volts = (sensorValue * 5.0 / 1023.0);  // Calculate voltage
  int x = float(sensorValue * 80.0/1023);     // Calculate percentage
  bar(x,volts);  // Redraw bar graph
  delay(100);      // Delay to reduce jitter 
}
