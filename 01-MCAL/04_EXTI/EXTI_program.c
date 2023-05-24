/*
 * EXTI_program.c
 *
 *  Created on: Dec 16, 2022
 *      Author: speedTECH
 */

#include "STD_TYPES.h"
#include "Bit_Math.h"

#include "EXTI_interface.h"
#include "EXTI_config.h"
#include "EXTI_private.h"


static void (*pvInt0CallBackFunc)(void)=NULL;
static void (*pvInt1CallBackFunc)(void)=NULL;

u8 MEXTI_u8Init(u8 Copy_u8EXTILine,u8 Copy_u8EXTIMode)
{
	CLR_BIT(MEXTI->MEXTI_IMR,Copy_u8EXTILine);/*Disable interrupt*/

	u8 Local_u8ErrorState=OK;
	switch (Copy_u8EXTIMode)
	{
	case RISING:   SET_BIT(MEXTI->MEXTI_RTSR,Copy_u8EXTILine);break;
	case FALLING:  SET_BIT(MEXTI->MEXTI_FTSR,Copy_u8EXTILine);break;
	case ON_CHANGE:SET_BIT(MEXTI->MEXTI_RTSR,Copy_u8EXTILine);
				   SET_BIT(MEXTI->MEXTI_FTSR,Copy_u8EXTILine);break;
	default:Local_u8ErrorState=NOK;	break;
	}
	return Local_u8ErrorState;

}

u8 MEXTI_u8EnableEXTI(u8 Copy_u8EXTILine)
{
	u8 Local_u8ErrorState=OK;
	if(Copy_u8EXTILine<=15)
	{
		SET_BIT(MEXTI->MEXTI_IMR,Copy_u8EXTILine);
	}
	else
	{
		Local_u8ErrorState=NOK;
	}
	return Local_u8ErrorState;
}
u8 MEXTI_u8DisableEXTI(u8 Copy_u8EXTILine)
{
	u8 Local_u8ErrorState=OK;
	if(Copy_u8EXTILine<=15)
	{
		CLR_BIT(MEXTI->MEXTI_IMR,Copy_u8EXTILine);
	}
	else
	{
		Local_u8ErrorState=NOK;
	}

	return Local_u8ErrorState;
}
u8 MEXTI_u8SWTrigger(u8 Copy_u8EXTILine)
{
	u8 Local_u8ErrorState=OK;
	if(Copy_u8EXTILine<=15)
	{
		SET_BIT(MEXTI->MEXTI_SWIER,Copy_u8EXTILine);
	}
	else
	{
		Local_u8ErrorState=NOK;
	}

	return Local_u8ErrorState;
}
u8 MEXTI_u8SetCallBackInt0(void (*Copy_pvCallBackFunc)(void))
{
	u8 Local_u8ErrorState=OK;
	if(Copy_pvCallBackFunc==NULL)
	{
		Local_u8ErrorState=NULL_POINTER;
	}
	else
	{
		pvInt0CallBackFunc=Copy_pvCallBackFunc;
	}
	return Local_u8ErrorState;
}
u8 MEXTI_u8SetCallBackInt1(void (*Copy_pvCallBackFunc)(void))
{
	u8 Local_u8ErrorState=OK;
	if(Copy_pvCallBackFunc==NULL)
	{
		Local_u8ErrorState=NULL_POINTER;
	}
	else
	{
		pvInt1CallBackFunc=Copy_pvCallBackFunc;
	}
	return Local_u8ErrorState;
}
void EXTI0_IRQHandler(void)
{
	pvInt0CallBackFunc();
	SET_BIT(MEXTI->MEXTI_PR,MEXTI_LINE0);/*clear pending flag*/
}
void EXTI1_IRQHandler(void)
{
	pvInt1CallBackFunc();
	SET_BIT(MEXTI->MEXTI_PR,MEXTI_LINE1);/*clear pending flag*/
}
