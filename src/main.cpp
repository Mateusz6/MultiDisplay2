#include <Arduino.h>
#include <Wire.h>
#include "ADS1X15.h"
#include "Nextion.h"
#include "NexScreen.h"

ADS1115 ADS(0x49); // sensor type and adress definition, purple sensor with adr pin pulled up, adress 0x49

int i1State = 0;//state of the 5-pin input, 0 - nothing connected, 1 - temp sensor connected, 2 - temp and preassure sensor
int i2State = 0;

int temp_0 = 0;
int temp_1 = 0;

void setup() {

  ADS.begin();
  Serial.begin(9600);
  
  NexScreenInitialize();
}

void loop() {
  delay(20);

  ADS.setGain(0);
  //int16_t val_0 = ADS.readADC(0);
  //int16_t val_1 = ADS.readADC(1);
  //float f = ADS.toVoltage(1);  // voltage factor
  //Serial.print("\tAnalog0: "); Serial.print(val_0); Serial.print('\t'); Serial.println(val_0 * f, 3);
  
  //temp_0 = ((val_0-(5754))/(546/5));
  //temp_1 = val_1;

  

  //Serial.println(val_0);
  //NexSensorDataUp(0,0,0,0,0,0,0,0);
}