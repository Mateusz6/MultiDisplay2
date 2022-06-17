#include "NexScreen.h"

NexPage p0_home = NexPage(0,0,"intro page");
NexPage p5_debug = NexPage(1,0,"debug page");
NexPage T_1_1 = NexPage(2,0,"T_1_1");
NexPage T_1_2 = NexPage(3,0,"T_1_2");
NexPage T_1_3 = NexPage(4,0,"T_1_3");
NexPage T_1_4 = NexPage(5,0,"T_1_4");
NexPage T_2_1 = NexPage(6,0,"T_2_1");
NexPage T_2_2 = NexPage(7,0,"T_2_2");
NexPage T_2_3 = NexPage(8,0,"T_2_3");
NexPage T_2_4 = NexPage(9,0,"T_2_4");
//below elements are buttons
NexButton p5_CTU = NexButton(1, 37, "b2");// "change temperature unit" button
NexButton p5_CPU = NexButton(1, 38, "b3");// "change pressure unit" button
//below elements are numbers representing units, 1 - metric, 2 - imperial
NexNumber p5_debug_nTempUnit = NexNumber(1, 26, "nTempUnit");
NexNumber p5_debug_nPressUnit = NexNumber(1, 27, "nPressureUnit");
//below elements are number values representing state of each channel/input, 0 - nothing connected, 1 - temp sensor, 2 - temp & press sensor 
NexNumber p5_debug_n0s = NexNumber(1,2,"n0s");
NexNumber p5_debug_n1s = NexNumber(1,3,"n1s");
NexNumber p5_debug_n2s = NexNumber(1,4,"n2s");
NexNumber p5_debug_n3s = NexNumber(1,5,"n3s");
//below elements are raw values, 5-digit ints on nextion display
NexNumber p5_debug_n00r = NexNumber(1, 12, "n00r");//channel 0, sensor 0 (temp sensor)
NexNumber p5_debug_n10r = NexNumber(1, 19, "n10r");//channel 0, sensor 1 (press sensor)
NexNumber p5_debug_n01r = NexNumber(1, 13, "n01r");//channel 1, sensor 0 (temp sensor)
NexNumber p5_debug_n11r = NexNumber(1, 20, "n11r");//channel 1, sensor 1 (press sensor)
NexNumber p5_debug_n02r = NexNumber(1, 14, "n02r");//channel 2, sensor 0 (temp sensor)
NexNumber p5_debug_n12r = NexNumber(1, 21, "n12r");//channel 2, sensor 1 (press sensor)
NexNumber p5_debug_n03r = NexNumber(1, 15, "n03r");//channel 3, sensor 0 (temp sensor)
NexNumber p5_debug_n13r = NexNumber(1, 22, "n13r");//channel 3, sensor 1 (press sensor)
//below elements are final values, 3-digit float numbers on nextion display, each final value = raw value / 100, this division is handled by nextion
NexNumber p5_debug_n00val = NexNumber(1, 28, "n00val");//channel 0, sensor 0 (temp sensor)
NexNumber p5_debug_n10val = NexNumber(1, 32, "n10val");//channel 0, sensor 1 (press sensor)
NexNumber p5_debug_n01val = NexNumber(1, 29, "n01val");//channel 1, sensor 0 (temp sensor)
NexNumber p5_debug_n11val = NexNumber(1, 33, "n11val");//channel 1, sensor 1 (press sensor)
NexNumber p5_debug_n02val = NexNumber(1, 30, "n02val");//channel 2, sensor 0 (temp sensor)
NexNumber p5_debug_n12val = NexNumber(1, 34, "n12val");//channel 2, sensor 1 (press sensor)
NexNumber p5_debug_n03val = NexNumber(1, 31, "n03val");//channel 3, sensor 0 (temp sensor)
NexNumber p5_debug_n13val = NexNumber(1, 35, "n13val");//channel 3, sensor 1 (press sensor)

//below elements are final values, 3-digit float numbers on each page
NexNumber T_1_1_t0val = NexNumber(2, 7, "x0");//page 2, channel 0, sensor 0 (temp sensor)
NexNumber T_1_1_p0val = NexNumber(2, 8, "x1");//page 2, channel 0, sensor 1 (press sensor)

NexNumber T_1_2_t0val = NexNumber(3, 11, "x0");//page 3, channel 0, sensor 0 (temp sensor)
NexNumber T_1_2_p0val = NexNumber(3, 12, "x1");//page 3, channel 0, sensor 1 (press sensor)
NexNumber T_1_2_t1val = NexNumber(3, 13, "x2");//page 3, channel 1, sensor 0 (temp sensor)
NexNumber T_1_2_p1val = NexNumber(3, 14, "x3");//page 3, channel 1, sensor 1 (press sensor)

NexNumber T_1_3_t0val = NexNumber(4, 15, "x0");//page 4, channel 0, sensor 0 (temp sensor)
NexNumber T_1_3_p0val = NexNumber(4, 16, "x1");//page 4, channel 0, sensor 1 (press sensor)
NexNumber T_1_3_t1val = NexNumber(4, 17, "x2");//page 4, channel 1, sensor 0 (temp sensor)
NexNumber T_1_3_p1val = NexNumber(4, 18, "x3");//page 4, channel 1, sensor 1 (press sensor)
NexNumber T_1_3_t2val = NexNumber(4, 20, "x5");//page 4, channel 2, sensor 0 (temp sensor)
NexNumber T_1_3_p2val = NexNumber(4, 19, "x4");//page 4, channel 2, sensor 1 (press sensor)


NexNumber T_1_4_t0val = NexNumber(5, 23, "x0");//page 5, channel 0, sensor 0 (temp sensor)
NexNumber T_1_4_p0val = NexNumber(5, 24, "x1");//page 5, channel 0, sensor 1 (press sensor)
NexNumber T_1_4_t1val = NexNumber(5, 25, "x2");//page 5, channel 1, sensor 0 (temp sensor)
NexNumber T_1_4_p1val = NexNumber(5, 26, "x3");//page 5, channel 1, sensor 1 (press sensor)
NexNumber T_1_4_t2val = NexNumber(5, 19, "x4");//page 5, channel 2, sensor 0 (temp sensor)
NexNumber T_1_4_p2val = NexNumber(5, 20, "x5");//page 5, channel 2, sensor 1 (press sensor)
NexNumber T_1_4_t3val = NexNumber(5, 21, "x6");//page 5, channel 3, sensor 0 (temp sensor)
NexNumber T_1_4_p3val = NexNumber(5, 22, "x7");//page 5, channel 3, sensor 1 (press sensor)

NexNumber T_2_1_t0val = NexNumber(6, 1, "x0");//page 6, channel 0, sensor 0 (temp sensor)
NexNumber T_2_1_p0val = NexNumber(6, 2, "x1");//page 6, channel 0, sensor 1 (press sensor)

NexNumber T_2_2_t0val = NexNumber(7, 1, "x0");//page 7, channel 0, sensor 0 (temp sensor)
NexNumber T_2_2_p0val = NexNumber(7, 2, "x1");//page 7, channel 0, sensor 1 (press sensor)
NexNumber T_2_2_t1val = NexNumber(7, 3, "x2");//page 7, channel 1, sensor 0 (temp sensor)
NexNumber T_2_2_p1val = NexNumber(7, 4, "x3");//page 7, channel 1, sensor 1 (press sensor)

NexNumber T_2_3_t0val = NexNumber(8, 1, "x0");//page 8, channel 0, sensor 0 (temp sensor)
NexNumber T_2_3_p0val = NexNumber(8, 2, "x1");//page 8, channel 0, sensor 1 (press sensor)
NexNumber T_2_3_t1val = NexNumber(8, 3, "x2");//page 8, channel 1, sensor 0 (temp sensor)
NexNumber T_2_3_p1val = NexNumber(8, 4, "x3");//page 8, channel 1, sensor 1 (press sensor)
NexNumber T_2_3_t2val = NexNumber(8, 5, "x5");//page 8, channel 2, sensor 0 (temp sensor)
NexNumber T_2_3_p2val = NexNumber(8, 6, "x4");//page 8, channel 2, sensor 1 (press sensor)

NexNumber T_2_4_t0val = NexNumber(9, 1, "x0");//page 5, channel 0, sensor 0 (temp sensor)
NexNumber T_2_4_p0val = NexNumber(9, 2, "x1");//page 5, channel 0, sensor 1 (press sensor)
NexNumber T_2_4_t1val = NexNumber(9, 3, "x2");//page 5, channel 1, sensor 0 (temp sensor)
NexNumber T_2_4_p1val = NexNumber(9, 3, "x3");//page 5, channel 1, sensor 1 (press sensor)
NexNumber T_2_4_t2val = NexNumber(9, 4, "x4");//page 5, channel 2, sensor 0 (temp sensor)
NexNumber T_2_4_p2val = NexNumber(9, 5, "x5");//page 5, channel 2, sensor 1 (press sensor)
NexNumber T_2_4_t3val = NexNumber(9, 6, "x6");//page 5, channel 3, sensor 0 (temp sensor)
NexNumber T_2_4_p3val = NexNumber(9, 7, "x7");//page 5, channel 3, sensor 1 (press sensor)

int currentPage = 1;
int tempUnit = 1; // temperature unit, 1 - metric (C), 2 - imperial (F)
int pressUnit = 1; // press unit, 1 - metric (BAR), 2 - imperial (PSI)

NexTouch *nex_listen_list[] = 
{
    &p5_debug,
    &T_1_1,
    &T_1_2,
    &T_1_3,
    &T_1_4,
    &T_2_1,
    &T_2_2,
    &T_2_3,
    &T_2_4,
    &p5_CPU,
    &p5_CTU,
    NULL
};

void NexScreenInitialize()
{
    //nexInit(115200L);
    nexInit(250000);
    p5_debug.attachPop(p5_debug_PopCallback);
    T_1_1.attachPop(T_1_1_PopCallback);
    T_1_2.attachPop(T_1_2_PopCallback);
    T_1_3.attachPop(T_1_3_PopCallback);
    T_1_4.attachPop(T_1_4_PopCallback);
    T_2_1.attachPop(T_2_1_PopCallback);
    T_2_2.attachPop(T_2_2_PopCallback);
    T_2_3.attachPop(T_2_3_PopCallback);
    T_2_4.attachPop(T_2_4_PopCallback);
    p5_CTU.attachPop(p5_CTU_PopCallback);
    p5_CPU.attachPop(p5_CPU_PopCallback);
    currentPage = 1;
    tempUnit = 1;
    pressUnit = 1;
}

int getChannelState(int16_t val0, int16_t val1)
{
    if(val1 > 16000 && val1 < 20000 && val0 > 5000 && val0 < 16000) // based on tested valued for diffrient sensors
    {
        return 1; // meaning that temperature sensor is connected
    }
        else if(val0 > 2000 && val0 < 16000 && val1 > 300 && val1 < 15000) // based on tested valued for diffrient sensors
    {
        return 2; // meaning that preassure and temp sensor is connected
    }
        else if(val0 > 16000 && val0 < 20000 && val1 > 16000 && val1 < 20000) // from testing, free pins cause reading of 17632, range of 16'000 - 20'000 is supposed to catch that value
    {
        return 0; // meaning that nothing is connected
    }
    else
    {
        return 0;
    }
}

void NexSensorStatusUp(int i0s, int i1s, int i2s, int i3s)
{
    p5_debug_n0s.setValue(i0s);
    p5_debug_n1s.setValue(i1s);
    p5_debug_n2s.setValue(i2s);
    p5_debug_n3s.setValue(i3s);
}

void NexSensorDataUp(SensorDataS& data)
{
    //switching betwen sending diffrient sets of data to diffrient pages, case number coresponds to page id
    switch(currentPage){
    case 1:
        //setting values of raw data number boxes
        p5_debug_n00r.setValue(data.c0s0);
        p5_debug_n10r.setValue(data.c0s1);
        p5_debug_n01r.setValue(data.c1s0);
        p5_debug_n11r.setValue(data.c1s1);
        p5_debug_n02r.setValue(data.c2s0);
        p5_debug_n12r.setValue(data.c2s1);
        p5_debug_n03r.setValue(data.c3s0);
        p5_debug_n13r.setValue(data.c3s1);
        //setting values of final number boxes
        p5_debug_n00val.setValue(data.c0s0);
        p5_debug_n10val.setValue(data.c0s1);
        p5_debug_n01val.setValue(data.c1s0);
        p5_debug_n11val.setValue(data.c1s1);
        p5_debug_n02val.setValue(data.c2s0);
        p5_debug_n12val.setValue(data.c2s1);
        p5_debug_n03val.setValue(data.c3s0);
        p5_debug_n13val.setValue(data.c3s1);
        break;
    
    case 2:
        //setting values for page T_1_1
        T_1_1_t0val.setValue(data.c0s0);
        T_1_1_p0val.setValue(data.c0s1);
        break;
    case 3:
        //setting values for page T_1_2
        T_1_2_t0val.setValue(data.c0s0);
        T_1_2_p0val.setValue(data.c0s1);
        T_1_2_t1val.setValue(data.c1s0);
        T_1_2_p1val.setValue(data.c1s1);
        break;
    case 4:
        //setting values for page T_1_3
        T_1_3_t0val.setValue(data.c0s0);
        T_1_3_p0val.setValue(data.c0s1);
        T_1_3_t1val.setValue(data.c1s0);
        T_1_3_p1val.setValue(data.c1s1);
        T_1_3_t2val.setValue(data.c2s0);
        T_1_3_p2val.setValue(data.c2s1);
        break;
    case 5:
        //setting values for page T_1_4
        T_1_4_t0val.setValue(data.c0s0);
        T_1_4_p0val.setValue(data.c0s1);
        T_1_4_t1val.setValue(data.c1s0);
        T_1_4_p1val.setValue(data.c1s1);
        T_1_4_t2val.setValue(data.c2s0);
        T_1_4_p2val.setValue(data.c2s1);
        T_1_4_t3val.setValue(data.c3s0);
        T_1_4_p3val.setValue(data.c3s1);
        break;
    case 6:
        //setting values for page T_2_1
        T_2_1_t0val.setValue(data.c0s0);
        T_2_1_p0val.setValue(data.c0s1);
        break;
    case 7:
        //setting values for page T_2_2
        T_2_2_t0val.setValue(data.c0s0);
        T_2_2_p0val.setValue(data.c0s1);
        T_2_2_t1val.setValue(data.c1s0);
        T_2_2_p1val.setValue(data.c1s1);
        break;
    case 8:
        //setting values for page T_2_3
        T_2_3_t0val.setValue(data.c0s0);
        T_2_3_p0val.setValue(data.c0s1);
        T_2_3_t1val.setValue(data.c1s0);
        T_2_3_p1val.setValue(data.c1s1);
        T_2_3_t2val.setValue(data.c2s0);
        T_2_3_p2val.setValue(data.c2s1);
        break;
    case 9:
        //setting values for page T_2_4
        T_2_4_t0val.setValue(data.c0s0);
        T_2_4_p0val.setValue(data.c0s1);
        T_2_4_t1val.setValue(data.c1s0);
        T_2_4_p1val.setValue(data.c1s1);
        T_2_4_t2val.setValue(data.c2s0);
        T_2_4_p2val.setValue(data.c2s1);
        T_2_4_t3val.setValue(data.c3s0);
        T_2_4_p3val.setValue(data.c3s1);
        break;
    }
}

void NexScreenUnitsUp(int t, int p)
{
    p5_debug_nTempUnit.setValue(t);
    p5_debug_nPressUnit.setValue(p);
}

void nexLoop()
{
    nexLoop (nex_listen_list);
}

//callback functions used for page dete
void p5_debug_PopCallback(void *ptr)
{
    currentPage = 1;
}

void T_1_1_PopCallback(void *ptr)
{
    currentPage = 2;
}

void T_1_2_PopCallback(void *ptr)
{
    currentPage = 3;
}

void T_1_3_PopCallback(void *ptr)
{
    currentPage = 4;
}

void T_1_4_PopCallback(void *ptr)
{
    currentPage = 5;
}

void T_2_1_PopCallback(void *ptr)
{
    currentPage = 6;
}

void T_2_2_PopCallback(void *ptr)
{
    currentPage = 7;
}

void T_2_3_PopCallback(void *ptr)
{
    currentPage = 8;
}

void T_2_4_PopCallback(void *ptr)
{
    currentPage = 9;
}

void p5_CTU_PopCallback(void *ptr)
{
    tempUnit++;
    if(tempUnit > 2)
    {
        tempUnit = 1;
    }
}

void p5_CPU_PopCallback(void *ptr)
{
    pressUnit++;
    if(pressUnit > 2)
    {
        pressUnit = 1;
    }
}