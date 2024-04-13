///////////////////////////////////
// MQ-135 Gas sensor YT Tutorial //
//        ArduinoCraft           //
///////////////////////////////////
// connection of the necessary library
#include "MQ135.h"
// Sensor pin
#define pinA A0
// initialization of the sensor from the library
MQ135 sensorMQ = MQ135(pinA);

void setup() {
  // initialization of communication over the serial link
  // at 9600 baud
  Serial.begin(9600);
}
void loop() {
  // reading the gas concentration in ppm into the variable
  float ppm = sensorMQ.getPPM();
  // reading time from Arduino start in seconds
  long time = millis() / 1000;
  // print the measured concentration
  Serial.print("Concentration of gases: ");
  Serial.print(ppm);
  Serial.print(" ppm | time since the launch of the Arduino: ");
  Serial.print(time / 60);  
  Serial.print("m");
  Serial.print(time % 60);  
  Serial.println("s.");

  delay(3000);
}