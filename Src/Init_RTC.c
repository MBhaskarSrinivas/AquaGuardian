#include<lpc21xx.h>
#include"block.h"
#include"types.h"
s8 WEEK[][4] = {"SUN","MON","TUE","WED","THU","FRI","SAT"};
//s32 S = 15;
extern u32 LAST_TIME;
void Init_RTC(void)
{
	CCR = 1<<1;
	PREINT = 456;
	PREFRAC = 25024;
	CCR = 1<<0;

	SEC = 0;
	MIN = 30;
	HOUR = 10;
	DOM = 21;
	MONTH = 8;
	YEAR = 2026;
	DOW = 6;
	LAST_TIME = (HOUR * 3600) + (MIN * 60) + SEC;
}
