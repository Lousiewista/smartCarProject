#include "reg52.h"
#include "motor.h"
#include "string.h"
#define SIZE 12

sfr AUXR = 0x8E;

char buffer[SIZE];


void UartInit(void)
{
    AUXR = 0x01;
    SCON = 0x50; //配置串口工作方式1：REN能接受
    TMOD &= 0xF0;
    TMOD |= 0x20;//定时器1工作方式8位自动重装
    
    TH1 = 0xFD;// 
    TL1 = 0xFD;//9600波特率
    TR1 = 1;//启动定时器
    
    EA = 1;//开启总中断
    ES = 1;//开启串口中断
    
}


//M1前 M2后 M3左 M4右
void Uart_Handler() interrupt 4

{
    static int i = 0;//static 静态变量，被初始化一次，
    //在这个函数内相当与全局变量的作用，不会反复被执行初始化，区别是只能在这个函数内被调用
    char tmp;
    
    if (RI) {   //中断处理函数中，对于接收中断的响应
        RI = 0;//清除接收中断标志
        
        tmp = SBUF;
        if (tmp == 'M') {
            i = 0;
        }
        buffer[i++] = tmp;
         


        if (buffer[0] == 'M') {
            switch(buffer[1]) {
                case '1':
                    goForward();
                    Delay10ms();
                    break;
                case '2':
                    goBack();
                    Delay10ms();
                    break;
                case '3':
                    goLeft();
                    Delay10ms();
                    break;
                case '4':
                    goRight();
                    Delay10ms();
                    break;
                default:
                    Stop();
                    break;

            }
            
        }
        

    }
        if (i == 12) {
            memset(buffer, '\0', SIZE);
            i = 0;
        }
            
} 
    

