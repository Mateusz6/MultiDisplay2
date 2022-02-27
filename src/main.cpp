#include <Arduino.h>
#include <Wire.h>
#include "ADS1X15.h"
#include "Nextion.h"

ADS1115 ADS(0x48); // sensor type and adress definition

NexPage p0 = NexPage(1,0,"main_page");

NexNumber p0_n0 = NexNumber(1,3,"n0temp");
NexNumber p0_n1 = NexNumber(1,8,"n1temp");

int temp1 = 0;
int temp2 = 0;

void setup() {

  ADS.begin();
  
  nexInit(115200L);
  Serial.begin(9600);
}

void loop() {
  delay(20);

  ADS.setGain(0);
  int16_t val_0 = ADS.readADC(0);
  float f = ADS.toVoltage(1);  // voltage factor
  Serial.print("\tAnalog0: "); Serial.print(val_0); Serial.print('\t'); Serial.println(val_0 * f, 3);

  if(temp2 <= 110)
  {
    //temp1=temp1+2;
    temp2=temp2+1;
  }else{
    //temp1=0;
    temp2=0;
  }

  temp1 = ((val_0-(5754))/(546/5));

  p0_n0.setValue(temp1);
  p0_n1.setValue(420);
}