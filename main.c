/**********************************************************/
/* Author    : Toka Medhat                                */
/* Date      : 9 DEC 2020                                 */
/* Version   : V01                                        */
/**********************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "IR_interface.h"
#include "EXTI0_interface.h"
#include "NVIC_interface.h"
#include "STK_interface.h"

extern u32 u32RemoteData;


void FlowerFunc(void);
void LedToLed(void);
void LedsOnOff(void);

void voidPlay(void)
{
	switch (u32RemoteData)
	{

		case POWER:for(u8 i=1 ; i<9 ; i++)
		{

			GPIO_voidSetPinValue(GPIOA,i,0);

		}; break;
		case ZERO:FlowerFunc(); break;
		case ONE:LedToLed(); break;
		case TWO:LedsOnOff(); break;


	}
}


void main(void)
{
	/* RCC Initialize */
	RCC_voidInitSysClock();
	RCC_voidEnableClock(RCC_APB2,2);   /* GPIOA Enable Clock */
	RCC_voidEnableClock(RCC_APB2, 3);  /* GPIOB Enable Clock */

	/* IO Pins Initialization */
	GPIO_voidSetPinDirection(GPIOA,0,0b0100);/* A0 Input Floating    */
	GPIO_voidSetPinDirection(GPIOA,1,0b0010); /* A1 Output PP        */
	GPIO_voidSetPinDirection(GPIOA,2,0b0010); /* A2 Output PP        */
	GPIO_voidSetPinDirection(GPIOA,3,0b0010); /* A3 Output PP        */
	GPIO_voidSetPinDirection(GPIOA,4,0b0010); /* A4 Output PP        */
	GPIO_voidSetPinDirection(GPIOA,5,0b0010); /* A5 Output PP        */
	GPIO_voidSetPinDirection(GPIOA,6,0b0010); /* A6 Output PP        */
	GPIO_voidSetPinDirection(GPIOA,7,0b0010); /* A7 Output PP        */
	GPIO_voidSetPinDirection(GPIOA,8,0b0010); /* A8 Output PP        */
	GPIO_voidSetPinDirection(GPIOA,9,0b0010); /* A9 Output PP        */


	IR_voidInit();

	while(1)
	{
		voidPlay();

	}

}
