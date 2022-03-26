#pragma once 

#include "Nextion.h"
#include <Arduino.h>

void NexInitialize();
void NexSensorDataUp(int i0s, int i1s, int i2s, int i3s, int i0v, int i1v, int i2v, int i3v);
