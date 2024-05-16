#include "reg52.h"
#include "intrins.h"
#include "hc04.h"
#include "delay.h"
#include "sg90.h"

#define MIDDLE 0
#define LEFT   1
#define RIGHT  2



void main(void)
{
    char dir;
    
    double disMiddle;
    double disLeft;
    double disRight;

    Time0Init();
    Time1Init();

    sgMiddle();
    Delay150ms();

     
    dir = MIDDLE;

    while (1) {
        if (dir != MIDDLE) {
            sgMiddle();
            dir = MIDDLE;
            Delay150ms();
                        
        }
                
        disMiddle = get_distance();
        
        if (disMiddle > 35) {
            
        } else {
            sgLeft();
            Delay150ms();
            
            disLeft = get_distance();
            
            sgMiddle();
            Delay150ms();
            
            
            sgRight();
            dir = RIGHT;
            Delay150ms();
            
            disRight = get_distance();
                                    
        } 
        

    }
}


