#include "reg52.h"
#include "motor.h"

extern unsigned int speedCnt;

char signal = 0;

unsigned int cnt = 0;
unsigned int speed;


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
    

    
    if (cnt == 2000) {//爆表了2000次，经过了不20ms
        signal = 1;
        cnt = 0;//当100次表示1s,重新让cnt从0开始，计算下一次的1s
        speed = speedCnt;
        speedCnt = 0;//计算小车速度，也就是拿到speedCnt的值
        //1秒后拿到speedCnt个格子，就能算出这一秒的速度，格子在这里清零
    }    
    
}
