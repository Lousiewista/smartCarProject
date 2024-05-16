#include "reg52.h"
#include "delay.h"

sbit D5 = P3^7;
sbit D6 = P3^6;
sbit sg90_con = P1^1;

int angle;
int cnt = 0;


void Time0Init()
{
//1.配置定时器0工作模式为16位计时
    TMOD &= 0xF0; //设定定时器模式
    TMOD |= 0X01;
    //2.给初值，定一个10ms出来
    TL0 = 0x33;
    TH0 = 0XFE;
    //3.开始计时；
    TR0 = 1;
    TF0 = 0;
    //4.打开定时器1中断
    ET0 = 1;
    //5.打开总中断EA
    EA = 1;
}




//void openStatusLight()
//{
//    D5 = 0;
//    D6 = 1;
//}

//void closeStatusLight()
//{
//    D5 = 1;
//    D6 = 0;
//}




void sgMiddle()
{
    angle = 3; //4 = 135度 2.0ms高电平  3 = 90度 5 = 180度
    cnt = 0;
    Delay2000ms();
}

void sgRight()
{
    angle = 1;
    cnt = 0;
    Delay150ms();
}

void sgLeft()
{
    angle = 5;
    cnt = 0;
    Delay150ms();
}


void Time0Handler() interrupt 1
{
    
    cnt++; //统计爆表的次数  cnt=1的时候，爆表1
    
    //重新给初值
    TL0 = 0x33;
    TH0 = 0XFE;//重新给初值
    
    //控制PWM波
    if (cnt < angle) {
        sg90_con = 1;
    }else {
        sg90_con = 0;
    }
    
    if (cnt == 40) {
        cnt = 0;//当100次表示1s,重新让cnt从0开始，计算下一次的1s
        sg90_con = 1;
    }    
    
}
