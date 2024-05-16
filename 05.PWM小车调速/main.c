#include "reg52.h"
#include "motor.h"
#include "delay.h"
#include "uart.h"
#include "time.h"

extern char speed;

void main(void)
{
    Time0Init();
    
    //UartInit();
    
    
    
    while (1) {
        speed = 10; //10份全速运行，30份停止，所以慢。20ms是40份的500μs
        Delay1000ms();
        Delay1000ms();
        
        speed = 20;
        Delay1000ms();
        Delay1000ms();
        
        speed = 40;
        Delay1000ms();
        Delay1000ms();
        
        
        
    }

}