#include "reg52.h"
#include "motor.h"
#include "delay.h"
#include "uart.h"
#include "time.h"
#include "stdio.h"
#include "string.h"
#include "OLED.h"
#include "esp8266.h"

sbit speedIO = P3^2;//外部中断0
unsigned int speedCnt = 0;

extern unsigned int speed;
extern char signal;

char speedMessage[24];

char FSSJ[] = "AT+CIPSEND=0,20\r\n";

void Ex0Init()
{
    EX0 = 1;//允许中断
    //EA = 1; //在串口初始化函数中已经打开了总中断
    IT0 = 1; //外部中断的下降沿触发
    
    
}

char putchar(char c)
{
    SendByte(c);
    return c;
}


void main(void)
{
    Time0Init();
    
    UartInit();//串口相关初始化
    Delay1000ms();
    
    initWifi_AP();//初始化wifi工作在AP模式
    
    waitConnect();//等待客户端的连接

    Ex0Init();//外部中断初始化
    
    Oled_Init();
    
    Oled_Clear();
    
    while (1) {
        if (signal) {
			sendString(FSSJ);
			Delay1000ms();            
            sprintf(speedMessage,"speed:%d cm/s",speed);
            printf("\r\n");
            sendString(speedMessage);
            

            
            signal = 0;
            
        }
        
        Oled_Show_Str(2,2,speedMessage);

    }

}

void speedHandler() interrupt 0
{
    speedCnt++;

}