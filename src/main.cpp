#include <Arduino.h>
#include "bno080/SparkFun_BNO080_Arduino_Library.h" // Click here to get the library: http://librarymanager/All#SparkFun_BNO080
#include <Adafruit_ILI9341.h>
#include "Ads_112c04/Ads_112c04.h"

#define TFT_CS 13
#define TFT_DC 12
#define TFT_RST 14

char buffer[20];

BNO080 myIMU;

Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC, TFT_RST);
Ads_112c04 &ads;

void setup()
{
  ads = Ads_112c04::instance;
  Serial.begin(115200);
  Serial.println();
  Serial.println("BNO080 Read Example");

void setup() {
  // Serial.begin(115200);
  // Serial.println();
  // Serial.println("BNO080 Read Example");
  tft.begin();
  tft.setRotation(2);
  tft.fillScreen(ILI9341_BLUE);

  Wire.begin();

  myIMU.begin();

  ads.init(Ads_112c04::AxState::DGND, Ads_112c04::AxState::DGND);
  ads.configRegister0(Ads_112c04::Gain::GAIN_1);
  ads.configRegister1(Ads_112c04::SpeedOfSample::SPS_1000,Ads_112c04::Mode::Mode_Normal,Ads_112c04::ConvMode);
  ads.startConv();

  Wire.setClock(400000); //Increase I2C data rate to 400kHz

  myIMU.enableStepCounter(500); //Send data update every 500ms
  myIMU.enableGyro(50);
}

void loop()
{
  Serial.println("hhh");
  double adc=ads.readADC();
  Serial.println("adc:"+adc);
  
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