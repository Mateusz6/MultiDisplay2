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

unsigned long lastTime; // used for slowed-down reading from ADS
unsigned long lastTime2; // used for slowed-down reading from ADS

int16_t val_00, val_01, val_02, val_03, val_10, val_11, val_12, val_13;

SensorDataS SensorData;

void calcData(int inputState, int tempUnit, int pressUnit, int& temp, int& press, int16_t val1, int16_t val2)
{
  if(inputState == 1){
    temp = (((val1*100)-(575400))/109); // calculating temperature, assuming that temp-only sensor is connected, unit - Celcius
  }
  else if(inputState == 2)
  {
    temp = (((10932 - val2)*100)/113);
    press = ((val1-3800)/4);
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

  ADS0.begin(); //initializing ADS modules
  ADS1.begin();

  Wire.setClock(600000); //increasing I2C speed to minimize data read time

  ADS0.setDataRate(7); //setting highest possible data rate for both ADS modules
  ADS1.setDataRate(7);


  Serial.begin(115200); //initialazing serial communication with given baud rate
  
  NexScreenInitialize(); //initializing Nextion screen

  delay(2000);

  //getting state of each input of the board, 0 - nothing connected, 1 - temp sensor conn. , 2 - temp and pressure sensor conn.
  //jumpers on free channels should be closer to ESP32 (press & temp position) on the board, otherwise it can cause false readings of input states
  i0State = getChannelState(ADS0.readADC(0), ADS0.readADC(1));
  i1State = getChannelState(ADS0.readADC(2), ADS0.readADC(3));
  i2State = getChannelState(ADS1.readADC(0) + ADS1offset, ADS1.readADC(1) + ADS1offset);
  i3State = getChannelState(ADS1.readADC(2) + ADS1offset, ADS1.readADC(3) + ADS1offset);
}

void loop() {

  valSmooth_00 = (valArray[0]+valArray[1]+valArray[2]+valArray[3]+valArray[4]+valArray[5]+valArray[6]+valArray[7]+valArray[8]+valArray[9])/10;

  if(lastTime + 100 < millis())
  {
    val_00 = ADS0.readADC(0);
    val_01 = ADS0.readADC(1);
    val_02 = ADS0.readADC(2);
    val_03 = ADS0.readADC(3);
    val_10 = ADS1.readADC(0) + ADS1offset; //adding offset to correct for the shift in red values on ADC1, reason of this shift is unknown
    val_11 = ADS1.readADC(1) + ADS1offset;
    val_12 = ADS1.readADC(2) + ADS1offset;
    val_13 = ADS1.readADC(3) + ADS1offset;

    lastTime = millis();
  }

  if(currentPage == 1)
  {
    NexSensorStatusUp(i0State, i1State, i2State, i3State);
    NexScreenUnitsUp(tempUnit, pressUnit);
  }

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

  Serial.print(val_00);
  Serial.print(" - ");
  Serial.println(valSmooth_00);

  NexSensorDataUp(SensorData);
  nexLoop();
}