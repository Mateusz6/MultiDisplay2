#pragma once 

#include "Nextion.h"
#include <Arduino.h>

struct SensorDataS // definition is in main.cpp, this was delcared here to make it visible for functions below
{
  int c0s0, c0s1, c1s0, c1s1, c2s0, c2s1, c3s0, c3s1; // these are raw values, to ger real values they must be divided by 100
};
void T_1_1_PopCallback(void *ptr);
void T_1_2_PopCallback(void *ptr);
void T_1_3_PopCallback(void *ptr);
void T_1_4_PopCallback(void *ptr);
void T_2_1_PopCallback(void *ptr);
void T_2_2_PopCallback(void *ptr);
void T_2_3_PopCallback(void *ptr);
void T_2_4_PopCallback(void *ptr);
void p5_CTU_PopCallback(void *ptr);
void p5_CPU_PopCallback(void *ptr);

void NexScreenInitialize();
void NexScreenUnitsUp(int t, int p);
void NexSensorStatusUp(int i0s, int i1s, int i2s, int i3s);
void NexSensorDataUp(SensorDataS& data);
void nexLoop();
