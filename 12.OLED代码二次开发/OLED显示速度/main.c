#include "reg52.h"
#include "intrins.h"
#include "OLED.h"


sbit scl = P1^2;
sbit sda = P1^3;




void main(void)
{
    //1.OLED初始化
    Oled_Init();
    Oled_Clear();
    Oled_Show_Str(2,2,"Hello World!");

 
    while (1);
}