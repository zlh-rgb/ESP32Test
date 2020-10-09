#include <Arduino.h>
#include "SparkFun_BNO080_Arduino_Library.h" // Click here to get the library: http://librarymanager/All#SparkFun_BNO080
BNO080 myIMU;

void setup() {
  Serial.begin(115200);
  Serial.println();
  Serial.println("BNO080 Read Example");

  Wire.begin();

  myIMU.begin();

  Wire.setClock(400000); //Increase I2C data rate to 400kHz

  myIMU.enableStepCounter(500); //Send data update every 500ms

  Serial.println(F("Step Counter enabled"));
  Serial.println(F("Step count since sketch started:"));
}

void loop() {
    if (myIMU.dataAvailable() == true)
  {
    unsigned int steps = myIMU.getStepCount();

    Serial.print(steps);
    Serial.print(F(","));

    Serial.println();
  }
}