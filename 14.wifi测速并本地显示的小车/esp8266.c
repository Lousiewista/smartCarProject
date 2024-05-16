#include "uart.h"

//1 工作在路由模式
code char LYMO[] = "AT+CWMODE=2\r\n";
//2 使能多链接
code char DLJ[] = "AT+CIPMUX=1\r\n"; 
//3 建立TCPServer
code char JLFW[] = "AT+CIPSERVER=1\r\n"; // default port = 333 



char AT_OK_Flag = 0;				//OK返回值的标志位
char Client_Connect_Flag = 0;

void initWifi_AP()
{
	sendString(LYMO);
	while(!AT_OK_Flag);
	AT_OK_Flag = 0;
	sendString(DLJ);
	while(!AT_OK_Flag);
	AT_OK_Flag = 0;
}

void waitConnect()
{
	sendString(JLFW);
	while(!Client_Connect_Flag);
	AT_OK_Flag = 0;	
}