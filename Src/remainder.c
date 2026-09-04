#include<lpc21xx.h>
#include"types.h"
#include"defines.h"
#include"lcd.h"
#include"KPM.h"
#include"delay.h"
#include"lcd_defines.h"
#include"project.h"
#include"project_defines.h"
#include"block.h"
u32 DB_FLAG;
void remainder(void)
{
	DB_FLAG = 0;//this reminder has not been answered yet"
	StrLCD("!! TAKE WATER !!");
	IOSET0 |= 1<<BUZZER;
	IOSET0 |= 1<<YL;//IOCLR0 |= 1<<YL;//
	delay_ms(5000);
	//CmdLCD(CLEAR_LCD);
	if(READBIT(IOPIN0,DB)==0)
	{
		DB_FLAG = 1;
		T = T + 1;
		L = TAR - T;//L = (TAR > T)?(TAR - T) : 0;
		while(READBIT(IOPIN0,DB)==0);
	}
	else
	{
		M = M + 1;			  //
	}
	IOCLR0 = 1<<BUZZER;
	IOCLR0 = 1<<YL;//IOSET0 |= 1<<YL;//

	if(DB_FLAG == 1)
	{
		IOCLR0 |= 1<<GL;//IOSET0 |= 1<<GL;//
	}
	else
	{
		IOCLR0 |= 1<<RL;//IOSET0 |= 1<<RL;//
	}
}
