#include "reg52.h"
#include "intrins.h"
#include "hc04.h"
#include "delay.h"
#include "sg90.h"




void main(void)
{

    double dis;

    Time0Init();
    Time1Init();

    sgMiddle();
    Delay150ms();    

    while (1) {
        

        sgLeft();
        Delay150ms();
        sgRight();
        Delay150ms();
        sgMiddle();
        Delay150ms();       


    }
}


