#include<lpc21xx.h>
#include"types.h"
#include"delay.h"
#include"KPM.h"
#include"lcd.h"
#include"lcd_defines.h"
#include"project.h"
#include"block.h"
//extern s32 S;
u32 LAST_TIME = 0;
//extern s32	S;
volatile u32 flag;
extern char WEEK[][4];
int T,TAR,L;
int EDIT_KEY;
//volatile extern int p;//extern int p;
void Init_Mode_isr(void)__irq
{
	//s32 h,m,sec;//
	//InitLCD();
	//Init_KPM();
	//Init_RTC();
	//while(1)
	//{
	CmdLCD(CLEAR_LCD);
	StrLCD("Display Menu");
	if(keyscan()=='E')//flag==1
	{
		CmdLCD(CLEAR_LCD);
		CmdLCD(GOTO_LINE1_POS0);
		StrLCD("MEMU FOR UPDATE");
		CmdLCD(0XC0);
		StrLCD("A-TIME  B-TARGET");
		delay_ms(200);
		switch(keyscan())
		{
			case 'A': CmdLCD(CLEAR_LCD);
					  CmdLCD(GOTO_LINE1_POS0);
					  StrLCD("UPDATE TIME&DATE");
					  delay_ms(2000);
					  CmdLCD(CLEAR_LCD);
					  CmdLCD(0X80);
					  StrLCD("1-H  2-M 3-S");//3-S//4-D
					  //CmdLCD(0xC0);
					  //StrLCD("5-Mon 6-Week");
					  delay_ms(200);
					  switch(keyscan())
					  {
					  	/*case '1':	CmdLCD(CLEAR_LCD);
									edit_hours();
									break;

						case '2':	CmdLCD(CLEAR_LCD);
									edit_min();
									break;

						case '3':	CmdLCD(CLEAR_LCD);
									edit_seconds();
									break;*/
						case '1': set_1();
								  break;
					  }
					  break;
			case 'B': CmdLCD(CLEAR_LCD);
					  CmdLCD(GOTO_LINE1_POS0);
					  StrLCD("A - UPDATE TARGRT");
					  CmdLCD(0xC0);
					  StrLCD("B - DURATION");
					  switch(keyscan())
					  {
					  	case 'A' :  CmdLCD(CLEAR_LCD);
									edit_tar();
									break;
						case 'B' :  set_duration();
									break;
									/*
									CmdLCD(CLEAR_LCD);
									StrLCD("Due: ");
									S = ReadNum();
									delay_ms(200);
									break;
									*/
					  }
					  break;
		}
	}
	//}
	flag=0;
	VICVectAddr = 0;
	EXTINT = 1<<0;
}
