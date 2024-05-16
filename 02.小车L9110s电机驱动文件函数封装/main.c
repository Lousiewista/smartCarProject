#include "reg52.h"
#include "motor.h"
#include "delay.h"

void main(void)
{
    
    while (1) {
        goForward();
        Delay1000ms();
        Delay1000ms();
        goBack();
        Delay1000ms();
        Delay1000ms();        
        goRight();
        Delay1000ms();
        Delay1000ms();
        goLeft();
        Delay1000ms();
        Delay1000ms();
        
    }

}