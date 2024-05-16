#include "reg52.h"
#include "motor.h"

char speed;
char cnt = 0;

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
    //4.打开定时器1中断
    ET0 = 1;
    //5.打开总中断EA
    EA = 1;
}

void Time0Handler() interrupt 1
{
    
    cnt++; //统计爆表的次数  cnt=1的时候，爆表1
    
    //重新给初值
    TL0 = 0x33;
    TH0 = 0XFE;//重新给初值
    
    //控制PWM波
    if (cnt < speed) {
        goForward();
    }else {
        Stop();
    }
    
    if (cnt == 40) {
        cnt = 0;//当100次表示1s,重新让cnt从0开始，计算下一次的1s
    }    
    
}
