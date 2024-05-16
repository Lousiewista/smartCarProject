#include "reg52.h"
#include "motor.h"
#include "delay.h"
#include "uart.h"
#include "time.h"

extern char leftSpeed;
extern char rightSpeed;


void main(void)
{
    Time0Init();
    Time1Init();
    //UartInit();
    
    
    
    while (1) {
        
        leftSpeed = 10; //10份全速运行，30份停止，所以慢。20ms是40份的500μs
        rightSpeed = 40;
        Delay1000ms();
        Delay1000ms();
        
        leftSpeed = 20;
        rightSpeed = 20;
        Delay1000ms();
        Delay1000ms();
        
        leftSpeed = 40;
        rightSpeed = 10;
        Delay1000ms();
        Delay1000ms();
        
        
        
    }

}