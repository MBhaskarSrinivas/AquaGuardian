#include"project_defines.h"
#include"project.h"
#include"types.h"
#include<lpc21xx.h>
void Init_block(void)
{
	IODIR0 |= 1<<BUZZER;
	IODIR0 |= 1<<YL;
	IODIR0 |= 1<<GL;
	IODIR0 |= 1<<RL;
}
