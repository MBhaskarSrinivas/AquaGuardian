#include<lpc21xx.h>
#include"project.h"
#include"project_defines.h"
#include"types.h"
void Init_int(void)
{
	PINSEL0	&=	~(3<<(1*2));//assging pin 1 as external interrupt
	PINSEL0	|=	EINTO_PIN_FUNC;//assigning address of pin 1 
	VICIntEnable = 1<<EINTO_VIC_CHANO;//assginig channel no.2
	VICVectCntl0 = (1<<5)|EINTO_VIC_CHANO;
	VICVectAddr0 = (u32)Init_Mode_isr;
	EXTMODE = 1<<0;
}
