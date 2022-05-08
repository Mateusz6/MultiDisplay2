#include <Arduino.h>
#include <Wire.h>
#include "ADS1X15.h"
#include "Nextion.h"
#include "NexScreen.h"

ADS1115 ADS(0x49); // sensor type and adress definition, purple sensor with adr pin pulled up, adress 0x49

int i1State = 0;//state of the 5-pin input, 0 - nothing connected, 1 - temp sensor connected, 2 - temp and preassure sensor
int i2State = 0;

int temp_0 = 0;
int press_0 = 222; // 222 is a test value

extern int currentPage;
extern int tempUnit;
extern int pressUnit;

SensorDataS SensorData;

void setup() {

  ADS.begin();
  Serial.begin(9600);
  
  NexScreenInitialize();

  SensorData.c0s0=66;
  SensorData.c0s1=666;
  SensorData.c1s0=420;
  SensorData.c1s1=2137;
  SensorData.c2s0=66;
  SensorData.c2s1=666;
  SensorData.c3s0=420;
  SensorData.c3s1=2137;
}

void loop() {
  delay(20);

  int16_t val_0 = ADS.readADC(0);
  if(true){
    temp_0 = (((val_0*100)-(575400))/109); // calculating temperature, assuming that temp-only sensor is connected, unit - Celcius
  }else{
    temp_0 = 4444;
    press_0 = 7777;
  }

  if(tempUnit == 2)
  {
    temp_0 = ((temp_0 * 9) / 5) + 3200;
  }

  SensorData.c0s0 = temp_0;
  SensorData.c0s1 = press_0;
  Serial.print(pressUnit);
  // Serial.print(" - ");
  Serial.println(tempUnit);
  NexSensorStatusUp(2,2,2,2);
  NexScreenUnitsUp(tempUnit, pressUnit);
  NexSensorDataUp(SensorData);
  nexLoop();
}