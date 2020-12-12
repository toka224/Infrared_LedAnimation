/**********************************************************/
/* Author    : Toka Medhat                                */
/* Date      : 19 Nov 2020                                */
/* Version   : V01                                        */
/**********************************************************/

#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "GPIO_interface.h"


#define SYSCLOCK    8000000
#define LED_NUM     8

void delay_ms(u32 ms);


void FlowerFunc(void)
{
	u8 j=0;

	for(u8 i=1 ; i<=LED_NUM/2 ; i++)
	{
		GPIO_voidSetPinValue(GPIOA,i,1);
		GPIO_voidSetPinValue(GPIOA,i+7-j,1);

		delay_ms(500);

		GPIO_voidSetPinValue(GPIOA,i,0);
		GPIO_voidSetPinValue(GPIOA,i+7-j,0);
		j+=2;
	}

	j=6;
	for(s8 i=(LED_NUM/2) ; i>=1 ; i--)
	{

		GPIO_voidSetPinValue(GPIOA,i,1);
		GPIO_voidSetPinValue(GPIOA,i+7-j,1);

		delay_ms(500);

		GPIO_voidSetPinValue(GPIOA,i,0);
		GPIO_voidSetPinValue(GPIOA,i+7-j,0);
		j-=2;
	}

	delay_ms(500);
}
void LedToLed(void)
{

	for(u8 i=1 ; i<=LED_NUM ; i++)
	{
		GPIO_voidSetPinValue(GPIOA,i,1);

		delay_ms(500);

		GPIO_voidSetPinValue(GPIOA,i,0);

	}
	for(s8 i=LED_NUM ; i>=1 ; i--)
	{
		GPIO_voidSetPinValue(GPIOA,i,1);

		delay_ms(500);

		GPIO_voidSetPinValue(GPIOA,i,0);

	}
	delay_ms(500);

}
void LedsOnOff(void)
{

	for(u8 i=1 ; i<=LED_NUM ; i++)
	{
		GPIO_voidSetPinValue(GPIOA,i,1);

	}
	delay_ms(500);

	for(u8 i=1 ; i<=LED_NUM ; i++)
	{

		GPIO_voidSetPinValue(GPIOA,i,0);

	}

	delay_ms(500);

}

void delay_ms(u32 ms)
{
	u32 i=0;
	for(i=0 ; i<(( SYSCLOCK/(12000) )*ms) ; i++)
	{
		__asm("NOP");
	}

}

