//KPM.c
#include "types.h"
#include"delay.h"
#include "defines.h"
#include"LCD.h"
#include"lcd_defines.h"
#include "KPM_defines.h"
#include"block.h"
#include <lpc21xx.h>
extern int EDIT_KEY;

 /*u32 KPMLUT[4][4]={{1,2,3,4},

									 {5,6,7,8},

									 {9,10,11,12},

									 {13,14,15,16}};*/

 u8 KPMLUT[4][4]={{'1','2','3','A'},

									 {'4','5','6','B'},

									 {'7','8','9','C'},

									 {'E','0','*','D'}};
						 

void Init_KPM(void)
{
	//cfg rows(p1.16-p1.19) as ouputs
	WRITENIBBLE(IODIR1,ROW0,15);
}
u32 colscan(void)
{
	if(READNIBBLE(IOPIN1,COL0)<15)
		return 0;
	else 
		return 1;
}
u32 rowcheck(void)
{
	u32 rno;
	for(rno=0; rno<4; rno++)
	{
		WRITENIBBLE(IOPIN1,ROW0,(~(1<<rno)));
		if(colscan()==0)
			break;
	}
	//make rows as defaults
	IOCLR1=15<<ROW0;
	return rno;
}
u32 colcheck(void)
{
	u32 cno;
	for(cno=0; cno<4; cno++)
	{
		if(READBIT(IOPIN1,(cno+COL0))==0)
			break;
	}
	return cno;
}
u32 keyscan(void)
{
	u32 rno,cno,key;
	//wait for switch press
	while(colscan());
	//find rno
	rno=rowcheck();
	//find cno
	cno=colcheck();
	//collect key using kpmLut
	key=KPMLUT[rno][cno];
	//wait for switch release
	while(!colscan());
	return key;
}
u32 ReadNum(void)
{
	u8 key;
	u32 num=0;
	u32 d = 0;
	while(1)
	{
		go: key=keyscan();
		delay_ms(50);
		if(key>='0'&&key<='9')
		{
			num=(num*10)+(key-48);
			if(d<3)
			{
				U32LCD(num%10);
			}
			//d++;
			else
			{
				CmdLCD(CLEAR_LCD);
				StrLCD("not allowed");
				delay_ms(250);
				CmdLCD(CLEAR_LCD);
				d = 0;
				goto go;
			}
			d++;
		}
		else if(key == 'C')
		{
			if(d > 0)
			{
				num = num/10;
				d--;
				CmdLCD(0x10);
				CharLCD(' ');
				CmdLCD(0x10);
			}
		}
		else if(key == 'E')
		{
			break;
		}
	}
	return num;
}
u32 ReadNumEdit(void)
{
	u8 key;
	u32 num = 0;
	u32 d = 0;
	//u32 EDIT_KEY = 0;
	while(1)
	{
		key = keyscan();
		delay_ms(50);
		if(key >= '0' && key<= '9')
		{
			go:num = (num * 10) + (key - '0');
			if(d<3)
			{
				U32LCD(num%10);
			}
			//d++;
			else
			{
				CmdLCD(CLEAR_LCD);
				StrLCD("not allowed");
				delay_ms(250);
				CmdLCD(CLEAR_LCD);
				d = 0;
				goto go;
			}
			//d++;
	//		U32LCD(num);
			d++;
		}
		else if(key == 'C')
		{
			if(d > 0)
			{
				num = num/10;
				d--;

				CmdLCD(0x10);
				CharLCD(' ');
				CmdLCD(0x10);
			}
		}
		else if(key == 'D')
		{
			EDIT_KEY = 'D';
			return num;
		}
		else if(key == 'B')
		{
			EDIT_KEY = 'B';
			return num;
		}
		else if (key == 'E')
		{
			EDIT_KEY = 'E';
			return num;
		}
	}
}
