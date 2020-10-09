#include <Arduino.h>
#include "bno080/SparkFun_BNO080_Arduino_Library.h" // Click here to get the library: http://librarymanager/All#SparkFun_BNO080
#include <Adafruit_ILI9341.h>

#define TFT_CS 13
#define TFT_DC 12
#define TFT_RST 14

char buffer[20];

BNO080 myIMU;

Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC,TFT_RST);


void setup() {
  // Serial.begin(115200);
  // Serial.println();
  // Serial.println("BNO080 Read Example");
  tft.begin();
  tft.setRotation(2);
  tft.fillScreen(ILI9341_BLUE);

  Wire.begin();

  myIMU.begin();

  Wire.setClock(400000); //Increase I2C data rate to 400kHz

  myIMU.enableStepCounter(500); //Send data update every 500ms
  myIMU.enableGyro(50);
}

void loop() {
    if (myIMU.dataAvailable() == true)
  {
    unsigned int steps = myIMU.getStepCount();
    float X = myIMU.getGyroX();
    
    tft.setCursor(0, 0);
    tft.setTextColor(ILI9341_WHITE);  tft.setTextSize(1);
    sprintf(buffer,"steps:%d",steps);
    tft.println(buffer);
    sprintf(buffer,"X:%.2f",X);
    tft.println(buffer);
  }
  
}