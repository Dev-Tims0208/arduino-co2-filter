///////////////////////////////////
// MQ-135 Gas sensor YT Tutorial //
//        ArduinoCraft           //
///////////////////////////////////
// connection of the necessary library
#include <Wire.h> 
#include <LiquidCrystal_I2C.h> 
#include <MQ135.h>
// Sensor pin
#define pinA A0
// initialization of the sensor from the library
MQ135 sensorMQ = MQ135(pinA); 
// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);  

void setup() {
  // initialization of communication over the serial link
  // at 9600 baud
  Serial.begin(9600); 
  lcd.begin(); 
	// Turn on the blacklight and print a message.
	lcd.backlight(); 
}
void loop() {
  // reading the gas concentration in ppm into the variable
  float ppm = sensorMQ.getPPM();
  // reading time from Arduino start in seconds
  long time = millis() / 1000;
  // print the measured concentration
  //lcd.print("mama mo");
  lcd.clear();
  lcd.print(String(ppm) + " CO2 (PPM)"); 
  delay(200);
}