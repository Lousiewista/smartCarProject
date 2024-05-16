#include "reg52.h"
#include "motor.h"

char leftSpeed;
char leftCnt = 0;

char rightSpeed;
char rightCnt = 0;


void Time0Init()
{
//1.配置定时器0工作模式为16位计时
    TMOD = 0x01;
    //2.给初值，定一个10ms出来
    TL0 = 0x33;
    TH0 = 0XFE;
    //3.开始计时；
    TR0 = 1;
    TF0 = 0;
    //4.打开定时器0中断
    ET0 = 1;
    //5.打开总中断EA
    EA = 1;
}

void Time1Init()
{
//1.配置定时器1工作模式为16位计时
    TMOD &= 0x0F;
    TMOD |= 0x1 << 4;
    //2.给初值，定一个10ms出来
    TL1 = 0x33;
    TH1 = 0XFE;
    //3.开始计时；
    TR1 = 1;
    TF1 = 0;
    //4.打开定时器1中断
    ET1 = 1;
    //5.打开总中断EA
    EA = 1;
}




void Time0Handler() interrupt 1
{
    
    leftCnt++; //统计爆表的次数  cnt=1的时候，爆表1
    
    //重新给初值
    TL0 = 0x33;
    TH0 = 0XFE;//重新给初值
    
    //控制PWM波
    if (leftCnt < leftSpeed) {
        leftGoForward();
    }else {
        leftStop();
    }
    
    if (leftCnt == 40) {
        leftCnt = 0;//当100次表示1s,重新让cnt从0开始，计算下一次的1s
    }    
    
}


void Time1Handler() interrupt 3
{
    
    rightCnt++; //统计爆表的次数  cnt=1的时候，爆表1
    
    //重新给初值
    TL1 = 0x33;
    TH1 = 0XFE;//重新给初值
    
    //控制PWM波
    if (rightCnt < rightSpeed) {
        rightGoForward();
    }else {
        rightStop();
    }
    
    if (rightCnt == 40) {
        rightCnt = 0;//当100次表示1s,重新让cnt从0开始，计算下一次的1s
    }    
    
}