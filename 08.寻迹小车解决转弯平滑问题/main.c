#include "reg52.h"
#include "motor.h"
#include "delay.h"
#include "uart.h"
#include "time.h"

extern char leftSpeed;
extern char rightSpeed;

sbit leftSensor = P2^7;
sbit rightSensor = P2^6;


void main(void)
{
    Time0Init();
    Time1Init();
    //UartInit();
    
    
    
    while (1) {
               
        
        if (leftSensor == 0 && rightSensor == 0) {
            leftSpeed = 18;
            rightSpeed = 20;
        
        }

        if (leftSensor == 1 && rightSensor == 0) {
            
            leftSpeed = 15;
            rightSpeed = 25;
        }
        
        if (leftSensor == 0 && rightSensor == 1) {
            
            rightSpeed = 15;
            leftSpeed = 25;
        }       
        
        if (leftSensor == 1 && rightSensor == 1) {
            Stop();
        } 
                
        
    }

}