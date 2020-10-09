#include <Arduino.h>
#include "SparkFun_BNO080_Arduino_Library.h" // Click here to get the library: http://librarymanager/All#SparkFun_BNO080
#include "SPI.h"
#include "Adafruit_GFX.h"
#include "Adafruit_ILI9341.h"

#define TFT_DC 9
#define TFT_CS 10
Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC);
BNO080 myIMU;

void setup() {
  // Serial.begin(115200);
  // Serial.println();
  // Serial.println("BNO080 Read Example");
  tft.begin();

  Wire.begin();

  myIMU.begin();

  Wire.setClock(400000); //Increase I2C data rate to 400kHz

  myIMU.enableStepCounter(500); //Send data update every 500ms

  // Serial.println(F("Step Counter enabled"));
  // Serial.println(F("Step count since sketch started:"));
}

void loop() {
    if (myIMU.dataAvailable() == true)
  {
    unsigned int steps = myIMU.getStepCount();
    tft.setCursor(0, 0);
    tft.setTextColor(ILI9341_WHITE);  tft.setTextSize(1);
    tft.println("helloworld");
    // Serial.print(steps);
    // Serial.print(F(","));

    // Serial.println();
  }
}