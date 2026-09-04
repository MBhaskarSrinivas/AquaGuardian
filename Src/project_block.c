#include<lpc21xx.h>
#include"lcd.h"
#include"KPM.h"
#include"defines.h"
#include"lcd_defines.h"
#include"delay.h"
#include"project.h"
#include"project_defines.h"
#include"block.h"
s32 h,m,sec;
u32 CUR_T,ELP_T;
//int EDIT_KEY = 0;
void set(void)
{
	StrLCD("  Welcome  ");
	delay_ms(2000);
	CmdLCD(CLEAR_LCD);
}
void edit_hours(void)
{
	CmdLCD(CLEAR_LCD);
	input1:StrLCD("hours: ");
	h = ReadNumEdit();//h = ReadNum();
	if(h>=0&&h<24)
	{
		HOUR = h;
		StrLCD("Hour updated!");
	}
	else
	{
		CmdLCD(CLEAR_LCD);
		StrLCD("ERROE!!");
		delay_ms(300);
		CmdLCD(CLEAR_LCD);
		goto input1;
	}
}
void edit_min(void)
{
	CmdLCD(CLEAR_LCD);
	input2:StrLCD("min: ");
	m = ReadNumEdit();//m = ReadNum();
	if(m>=0&&m<60)
	{
		MIN = m;
		StrLCD("Min updated!");
	}
	else
	{
		CmdLCD(CLEAR_LCD);
		StrLCD("ERROE!!");
		delay_ms(300);
		CmdLCD(CLEAR_LCD);
		goto input2;
	}
}
void edit_seconds(void)
{
	CmdLCD(CLEAR_LCD);
	input3:StrLCD("sec: ");
	sec = ReadNumEdit();//sec = ReadNum();
	if(sec>=0&&sec<60)
	{
		SEC = sec;
		StrLCD("Seconds updated!");
	}
	else
	{
		CmdLCD(CLEAR_LCD);
		StrLCD("ERROE!!");
		delay_ms(300);
		CmdLCD(CLEAR_LCD);
		goto input3;
	}
}
void edit_tar(void)
{
	CmdLCD(CLEAR_LCD);
	target:StrLCD("TAR: ");
	TAR = ReadNum();
	if(TAR > 0)
	{	
		L = (TAR > 0)? TAR - T : 0;//L = TAR - T;
		StrLCD("TARGET UPDATED");
	}
	else
	{
		CmdLCD(CLEAR_LCD);
		StrLCD("Invalid Target");
		delay_ms(300);
		CmdLCD(CLEAR_LCD);
		goto target;
	}
}
void set_1(void)
{
	//flag = 1;
	int field = 1;
	while(1)
	{
		if(field == 1)
		{
		   edit_hours();
		   if(EDIT_KEY == 'D')
		   {	
		   		field = 2;
		   }
		   else if(EDIT_KEY == 'B')
		   {
		   		field = 3;
		   }
		   else if (EDIT_KEY == 'E')
		   {
		   		break;
		   }
		}
		else if(field == 2)
		{
			edit_min();
			if(EDIT_KEY == 'D')
		   	{	
		   		field = 3;
		   	}
		   else if(EDIT_KEY == 'B')
		   	{
		   		field = 1;
		   	}
		   else if (EDIT_KEY == 'E')
		   	{
		   		break;
		   	}
		}
		else if(field == 3)
		{
			edit_seconds();
			if(EDIT_KEY == 'D')
		   {	
		   		field = 1;
		   }
		   else if(EDIT_KEY == 'B')
		   {
		   		field = 2;
		   }
		   else if (EDIT_KEY == 'E')
		   {
		   		break;
		   }
		}
		//flag = 0;
	}
	DURATION = (D_HOUR * 3600)+(D_MIN * 60)+D_SEC;
	if(DURATION < 1 || DURATION > 86400)
	{
		CmdLCD(CLEAR_LCD);
		StrLCD("Invalid Reminder");
		delay_ms(1000);
		return;
	}
	else
	{
		CmdLCD(CLEAR_LCD);
		StrLCD("Time is set");
		delay_ms(1000);
	}
}
void linit(void)
{
	CUR_T = (HOUR * 3600UL)+(MIN * 60UL)+SEC;
	if(CUR_T >= LAST_TIME)
	{
		ELP_T = CUR_T - LAST_TIME;
	}
	else
	{
		ELP_T = (86400UL - LAST_TIME)+CUR_T;
	}
	if((flag == 0)&&(ELP_T >= S))//if(ELP_T >= S)
	{
		remainder();
		LAST_TIME = CUR_T;
	}
}
void set_duration(void)
{
    CmdLCD(CLEAR_LCD);
    StrLCD("Duration Hour");

    D_HOUR = ReadNum();

    if(D_HOUR > 24)
    {
        CmdLCD(CLEAR_LCD);
        StrLCD("INVALID");
        delay_ms(1000);
        return;
    }

    CmdLCD(CLEAR_LCD);
    StrLCD("Duration Min");

    D_MIN = ReadNum();

    if(D_MIN >= 60)
    {
        CmdLCD(CLEAR_LCD);
        StrLCD("INVALID");
        delay_ms(1000);
        return;
    }

    CmdLCD(CLEAR_LCD);
    StrLCD("Duration Sec");

    D_SEC = ReadNum();

    if(D_SEC >= 60)
    {
        CmdLCD(CLEAR_LCD);
        StrLCD("INVALID");
        delay_ms(1000);
        return;
    }

    S = (D_HOUR * 3600UL) +
        (D_MIN * 60UL) +
         D_SEC;

    if(S == 0 || S > 86400UL)
    {
        CmdLCD(CLEAR_LCD);
        StrLCD("INVALID");
        delay_ms(1000);
        return;
    }

    CmdLCD(CLEAR_LCD);
    StrLCD("DURATION SET");
    delay_ms(1000);
}
															