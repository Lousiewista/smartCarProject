#include "reg52.h"
#include "motor.h"
#include "delay.h"
#include "uart.h"
#include "time.h"
#include "stdio.h"
#include "string.h"

sbit speedIO = P3^2;//外部中断0
unsigned int speedCnt = 0;

extern unsigned int speed;
extern char signal;

char speedMessage[24];

void Ex0Init()
{
    EX0 = 1;//允许中断
    //EA = 1; //在串口初始化函数中已经打开了总中断
    IT0 = 1; //外部中断的下降沿触发
    
    
}


void main(void)
{
    Time0Init();
    
    UartInit();//串口相关初始化
    
    Ex0Init();//外部中断初始化
    
    
    
    while (1) {
        if (signal) {
            sprintf(speedMessage,"speed:%d\r\n",speed);
            sendString(speedMessage);
            memset(speedMessage,'\0',24);
            
            signal = 0;
            
        }
    }

}

void speedHandler() interrupt 0
{
    speedCnt++;

}