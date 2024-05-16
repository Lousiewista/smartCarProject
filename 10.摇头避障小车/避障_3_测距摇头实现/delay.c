#include "intrins.h"

void Delay150ms()		//@11.0592MHz
{
	unsigned char i, j, k;

	_nop_();
	_nop_();
	i = 7;
	j = 78;
	k = 167;
	do
	{
		do
		{
			while (--k);
		} while (--j);
	} while (--i);
}



void Delay2000ms()		//@11.0592MHz
{
	unsigned char i, j, k;

	_nop_();
	i = 15;
	j = 2;
	k = 235;
	do
	{
		do
		{
			while (--k);
		} while (--j);
	} while (--i);
}





void Delay10us()		//@11.0592MHz
{
	unsigned char i;

	i = 2;
	while (--i);
}


void Delay30ms()		//@11.0592MHz
{
	unsigned char i, j, k;

	_nop_();
	_nop_();
	i = 2;
	j = 67;
	k = 183;
	do
	{
		do
		{
			while (--k);
		} while (--j);
	} while (--i);
}


