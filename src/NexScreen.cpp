#include "NexScreen.h"

NexPage p0_home = NexPage(0,0,"intro page");
NexPage p5_debug = NexPage(1,0,"debug page");

NexNumber p5_debug_n0s = NexNumber(1,2,"n0s");
NexNumber p5_debug_n1s = NexNumber(1,3,"n1s");
NexNumber p5_debug_n2s = NexNumber(1,4,"n2s");
NexNumber p5_debug_n3s = NexNumber(1,5,"n3s");

void NexScreenInitialize()
{
    nexInit(115200L);
}

void NexSensorDataUp(int i0s, int i1s, int i2s, int i3s, int i0v, int i1v, int i2v, int i3v)
{
    p5_debug_n0s.setValue(1);
    p5_debug_n1s.setValue(2);
    p5_debug_n2s.setValue(1);
    p5_debug_n3s.setValue(3);
}