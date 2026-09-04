#include<lpc21xx.h>
#include"types.h"
#include"lcd.h"
#include"KPM.h"
#include"defines.h"
#include"delay.h"
#include"lcd_defines.h"
#include"project.h"
#include"project_defines.h"
#include"block.h"
int M;
extern volatile u32 flag;//
int D_HOUR,D_MIN,D_SEC;
extern u32 CUR_T, ELP_T;
unsigned long int DURATION;
main()
{	T = 0,TAR = 15,L = TAR,M = 0;
	D_HOUR = 0;
	D_MIN = 0;
	D_SEC = 15;
	DURATION = 15;
	Init_block();
	Init_RTC();
	InitLCD();//initalizing lcd
	Init_KPM();//Initialize keypad
	Init_int();
	set();
	while(1)
	{
		flag = 0;
		if(READBIT(IOPIN0,IS)==0)
		{
			flag == 1;
		}
		display_mode();
	}
}
