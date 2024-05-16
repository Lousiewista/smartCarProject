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
    
    initSG90_0();
    
    

    while (1) {

        dis = get_distance();
        if (dis <10 ) {//如果小于10厘米，或者SW1按键按下去

            //开盖，灯状态：D5亮
            openStatusLight();
            openBin();
                        
        }else {
            //关盖，灯状态：D5亮
            closeStatusLight();
            closeBin();
           
        }

    }
}


