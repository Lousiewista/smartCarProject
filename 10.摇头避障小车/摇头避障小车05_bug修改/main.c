#include "reg52.h"
#include "hc04.h"
#include "delay.h"
#include "sg90.h"
#include "motor.h"

#define MIDDLE 0
#define LEFT 1
#define RIGHT 2

void main()
{
	char dir;
	
	double disMiddle;
	double disLeft;
	double disRight;
	
	Time0Init();
	Time1Init();
	//舵机的初始位置

	sgMiddle();
	Delay300ms();
	Delay300ms();
	dir = MIDDLE;
	
	while(1){
		
		if(dir != MIDDLE){
			sgMiddle();
			dir = MIDDLE;
			Delay300ms();
		}
		disMiddle = get_distance();
		
		if(disMiddle > 35){
			//前进
			goForward();
		}else if(disMiddle < 10){
			goBack();
			
		}else
		{
			//停止
			stop();
			//测左边距离
			sgLeft();
			Delay300ms();
			disLeft = get_distance();
			
			sgMiddle();
			Delay300ms();
			
			sgRight();
			dir = RIGHT;
			Delay300ms();
			disRight = get_distance();
			
			if(disLeft < disRight){
				goRight();
				Delay150ms();
				stop();
			}
			if(disRight < disLeft){
				goLeft();
				Delay150ms();
				stop();
			}
		}
		
	}
}






