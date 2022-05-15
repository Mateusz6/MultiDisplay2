#include <Arduino.h>
#include <Wire.h>
#include "ADS1X15.h"
#include "Nextion.h"
#include "NexScreen.h"

#define ADS1offset 3230 //offset to correct for the shift in readed valued on ADC1, reason of this shift is unknown

ADS1115 ADS0(0x49); // sensor type and adress definition, purple sensor with adr pin pulled up, adress 0x49
ADS1115 ADS1(0x48); // sensor type and adress definition, purple sensor with adr pin floating, adress 0x48

int i0State, i1State, i2State, i3State = 0; //state of the 5-pin input, 0 - nothing connected, 1 - temp sensor connected, 2 - temp and preassure sensor

int temp_0, temp_1, temp_2, temp_3;
int press_0, press_1, press_2, press_3;

extern int currentPage;
extern int tempUnit;
extern int pressUnit;

int16_t val_00, val_01, val_02, val_03, val_10, val_11, val_12, val_13;

SensorDataS SensorData;

void calcData(int inputState, int tempUnit, int pressUnit, int& temp, int& press, int16_t valT, int16_t valP)
{
  if(inputState == 1){
    temp = (((valT*100)-(575400))/109); // calculating temperature, assuming that temp-only sensor is connected, unit - Celcius
  }
  else if(inputState == 2)
  {
    temp = 4444;
    press = 7777;
  }
  else
  {
    temp = 666;
    press = 555;
  }

  if(tempUnit == 2)
  {
    temp = ((temp * 9) / 5) + 3200;
  }
}

void setup() {

  ADS0.begin();
  ADS1.begin();
  Serial.begin(9600);
  
  NexScreenInitialize();

  delay(1000);

  i0State = getChannelState(ADS0.readADC(0), ADS0.readADC(1));
  i1State = getChannelState(ADS0.readADC(2), ADS0.readADC(3));
  i2State = getChannelState(ADS1.readADC(0) + ADS1offset, ADS1.readADC(1) + ADS1offset);
  i3State = getChannelState(ADS1.readADC(2) + ADS1offset, ADS1.readADC(3) + ADS1offset);

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

  val_00 = ADS0.readADC(0);
  val_01 = ADS0.readADC(1);
  val_02 = ADS0.readADC(2);
  val_03 = ADS0.readADC(3);
  val_10 = ADS1.readADC(0) + ADS1offset; //adding offset to correct for the shift in readed valued on ADC1, reason of this shift is unknown
  val_11 = ADS1.readADC(1) + ADS1offset;
  val_12 = ADS1.readADC(2) + ADS1offset;
  val_13 = ADS1.readADC(3) + ADS1offset;

  calcData(i0State, tempUnit, pressUnit, temp_0, press_0, val_00, val_01);
  calcData(i1State, tempUnit, pressUnit, temp_1, press_1, val_02, val_03);
  calcData(i2State, tempUnit, pressUnit, temp_2, press_2, val_10, val_11);
  calcData(i3State, tempUnit, pressUnit, temp_3, press_3, val_12, val_13);


  SensorData.c0s0 = temp_0;
  SensorData.c0s1 = press_0;
  SensorData.c1s0 = temp_1;
  SensorData.c1s1 = press_1;
  SensorData.c2s0 = temp_2;
  SensorData.c2s1 = press_2;
  SensorData.c3s0 = temp_3;
  SensorData.c3s1 = press_3;

  Serial.println(val_10);
  NexSensorStatusUp(i0State, i1State, i2State, i3State);
  NexScreenUnitsUp(tempUnit, pressUnit);
  NexSensorDataUp(SensorData);
  nexLoop();
}