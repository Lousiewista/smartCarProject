#include "reg52.h"
#include "delay.h"

sbit Trig = P2^3;
sbit Echo = P2^2;



void Time1Init()
{
    TMOD &= 0x0F; //设定定时器模式
    TMOD |= 0X10;
    TH1 = 0;
    TL1 = 0;
    //设置定时器0工作模式1，初始值设定0开始数数，不着急启动定时器
}


void startHC()
{
    Trig = 0;
    Trig = 1;
    Delay10us();
    Trig =0;
}



double get_distance()
{
    double time;
    
    TH1 = 0;
    TL1 = 0;
    
    Delay30ms();
    startHC();
        
    while (Echo == 0); 
    TR1 = 1;
        
    while (Echo == 1);   
    TR1 = 0;
             
    time = (TH1 * 256 + TL1) * 1.085;  
        
    return (time * 0.017);
}


