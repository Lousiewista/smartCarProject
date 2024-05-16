#include "reg52.h"
#include "motor.h"
#include "delay.h"

//循迹
//sbit leftSensor = P2^7;
//sbit rightSensor = P2^6;

//跟随
sbit leftSensor = P2^5;
sbit rightSensor = P2^4;

void main(void)
{

        //下方小车两个模块都能反射回来红外，输出低电平，灯亮，直走
        
        
        //上方小车左模块遇到黑线，红外被吸收，左模块输出高电平，右模块输出低电平，左转，反之右转

    
    while (1) {
        
        if (leftSensor == 0 && rightSensor == 0) {
            goForward();
        
        }

        if (leftSensor == 1 && rightSensor == 0) {
            goRight();
        }
        
        if (leftSensor == 0 && rightSensor == 1) {
            goLeft();
        }       
        
        if (leftSensor == 1 && rightSensor == 1) {
            Stop(); 
        } 
        

        
    }

}