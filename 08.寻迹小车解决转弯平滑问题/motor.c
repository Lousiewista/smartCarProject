#include "reg52.h"

sbit RightConlA = P3^2;
sbit RightConlB = P3^3;

sbit LeftConlA = P3^4;
sbit LeftConlB = P3^5;


void leftGoForward()
{
    LeftConlA = 0;
    LeftConlB = 1;
}

void leftStop()
{
    LeftConlA = 0;
    LeftConlB = 0;

}


void rightGoForward()
{
    RightConlA = 0;
    RightConlB = 1;
}


void rightStop()
{
    RightConlA = 0;
    RightConlB = 0;

}



void goLeft()
{
    LeftConlA = 0;
    LeftConlB = 0;
    
    RightConlA = 0;
    RightConlB = 1;

}


void goRight()
{
    LeftConlA = 0;
    LeftConlB = 1;
    
    RightConlA = 0;
    RightConlB = 0;

}



void goForward()
{
    LeftConlA = 0;
    LeftConlB = 1;
    
    RightConlA = 0;
    RightConlB = 1;

}

void goBack()
{
    LeftConlA = 1;
    LeftConlB = 0;
    
    RightConlA = 1;
    RightConlB = 0;
}


void Stop()
{
    LeftConlA = 0;
    LeftConlB = 0;
    
    RightConlA = 0;
    RightConlB = 0;
}





