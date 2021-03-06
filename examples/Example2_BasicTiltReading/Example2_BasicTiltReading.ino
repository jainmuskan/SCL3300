/* Read Tilt angles from Murata SCL3300 Inclinometer
 * Version 2.0.0 - February 22, 2020
 * Example2_BasicTiltReading
*/

#include <SPI.h>
#include <SCL3300.h>

SCL3300 inclinometer;
//Default SPI chip/slave select pin is D10

// Need the following define for SAMD processors
#if defined (ARDUINO_ARCH_SAMD)
#define Serial SerialUSB
#endif

void setup() {
  Serial.begin(9600);
  delay(2000); //SAMD boards may need a long time to init SerialUSB
  Serial.println("Reading basic Tilt values from SCL3300 Inclinometer");

  if (inclinometer.begin() == false) {
    Serial.println("Murata SCL3300 inclinometer not connected.");
    while(1); //Freeze
  }
}

void loop() {
  if (inclinometer.available()) { //Get next block of data from sensor
    Serial.print("X Tilt: ");
    Serial.print(inclinometer.getCalculatedAngleX());
    Serial.print("\t");
    Serial.print("Y Tilt: ");
    Serial.print(inclinometer.getCalculatedAngleY());
    Serial.print("\t");
    Serial.print("Z Tilt: ");
    Serial.println(inclinometer.getCalculatedAngleZ());
    delay(250); //Allow a little time to see the output
  }
}
