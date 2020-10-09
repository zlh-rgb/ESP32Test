#include <Arduino.h>
#include "bno080/SparkFun_BNO080_Arduino_Library.h" // Click here to get the library: http://librarymanager/All#SparkFun_BNO080
#include <Adafruit_ILI9341.h>

#define TFT_CS 13
#define TFT_DC 12
#define TFT_RST 14

BNO080 myIMU;
Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC);


void setup() {
  Serial.begin(115200);
  Serial.println();
  Serial.println("BNO080 Read Example");
  tft.begin();
  tft.fillScreen(ILI9341_BLUE);

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