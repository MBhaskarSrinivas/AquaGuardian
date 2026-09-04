#include<lpc21xx.h>
#include"types.h"
#include"lcd.h"
#include"KPM.h"
#include"delay.h"
#include"defines.h"
#include"lcd_defines.h"
#include"project.h"
#include"project_defines.h"
#include"block.h"
extern u32 LAST_TIME;
s32 S = 15;
s32 p;
//int Remainder;
s32 Rflag = 0;
void display_mode(void)
{
	/*if(SEC == S && Rflag == 0) //((S/15)==1)
	{				
		Rflag = 1;
		remainder();
	}*
	if(SEC != S)
	{
		Rflag = 0;
	} */
	linit();
	if(TAR != 0)
	{
		p = ((T * 100)/TAR);
	}
	else
	{
		p = 0;
	}
	CmdLCD(CLEAR_LCD);
	CmdLCD(GOTO_LINE1_POS0);
	CharLCD((HOUR/10)+48);
	CharLCD((HOUR%10)+48);
	CharLCD(':');
	CharLCD((MIN/10)+48);
	CharLCD((MIN%10)+48);
	CharLCD(':');
	CharLCD((SEC/10)+48);
	CharLCD((SEC%10)+48);
	CmdLCD(0xc0);
	CharLCD((DOM/10)+48);
	CharLCD((DOM%10)+48);
	CharLCD('/');
	CharLCD((MONTH/10)+48);
	CharLCD((MONTH%10)+48);
	CharLCD('/');
	U32LCD(YEAR);
	CmdLCD(GOTO_LINE1_POS0 + 10);		
	StrLCD(WEEK[DOW]);
	delay_ms(1000);
	CmdLCD(CLEAR_LCD);
	CmdLCD(GOTO_LINE1_POS0);
	CharLCD((HOUR/10)+48);
	CharLCD((HOUR%10)+48);
	CharLCD(':');
	CharLCD((MIN/10)+48);
	CharLCD((MIN%10)+48);
	CharLCD(':');
	CharLCD((SEC/10)+48);
	CharLCD((SEC%10)+48);
	CharLCD(0x80+10);
	U32LCD(p);
	CharLCD('%');
	CmdLCD(0xc0);		
	StrLCD("C:");
	S32LCD(T);//displaying No of glasses taken in a day till next remainder
	CmdLCD(0xc0+4);//at line 2 position 4 displaying No of glasses to be take(target)
	StrLCD("X:");
	S32LCD(TAR);//displaying Target
	CmdLCD(0xc0+9);//moving curser to next position(at 9) in line 2 
	StrLCD("L:");
	S32LCD(L);//displaying No of glasses left 
	CmdLCD(0xc0+13);  //
	StrLCD("M:");
	S32LCD(M);	//
	delay_ms(1000);//waiting(delay) to observe and then moving to next content
	CmdLCD(CLEAR_LCD);
	//}
}
