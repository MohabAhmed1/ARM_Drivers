/*
 * NVIC_program.c
 *
 *  Created on: Dec 15, 2022
 *      Author: speedTECH
 */
#include "STD_TYPES.h"
#include "Bit_Math.h"

#include "NVIC_interface.h"
#include "NVIC_private.h"
#include "NVIC_config.h"


u8 MNVIC_u8EnableInterrupt(u8 Copy_u8IntNumber)
{
	u8 Local_u8ErrorState=OK;
	if(Copy_u8IntNumber<=31)
	{
		MNVIC_ISER0 = 1<<(Copy_u8IntNumber);
	}
	else if(Copy_u8IntNumber<=59)
	{
		Copy_u8IntNumber-=32;
		MNVIC_ISER1 = 1<<(Copy_u8IntNumber);
	}
	else
	{
		Local_u8ErrorState=NOK;
	}
	return Local_u8ErrorState;
}

u8 MNVIC_u8DisableInterrupt(u8 Copy_u8IntNumber)
{
	u8 Local_u8ErrorState=OK;
	if(Copy_u8IntNumber<=31)
	{
		MNVIC_ICER0 = 1<<(Copy_u8IntNumber);
	}
	else if(Copy_u8IntNumber<=59)
	{
		Copy_u8IntNumber-=32;
		MNVIC_ICER1 = 1<<(Copy_u8IntNumber);
	}
	else
	{
		Local_u8ErrorState=NOK;
	}
	return Local_u8ErrorState;
}
u8 MNVIC_u8SetPendingFlag(u8 Copy_u8IntNumber)
{
	u8 Local_u8ErrorState=OK;
	if(Copy_u8IntNumber<=31)
	{
		MNVIC_ISPR0 = 1<<(Copy_u8IntNumber);
	}
	else if(Copy_u8IntNumber<=59)
	{
		Copy_u8IntNumber-=32;
		MNVIC_ISPR1 = 1<<(Copy_u8IntNumber);
	}
	else
	{
		Local_u8ErrorState=NOK;
	}
	return Local_u8ErrorState;
}

u8 MNVIC_u8ClearPendingFlag(u8 Copy_u8IntNumber)
{
	u8 Local_u8ErrorState=OK;
	if(Copy_u8IntNumber<=31)
	{
		MNVIC_ICPR0 = 1<<(Copy_u8IntNumber);
	}
	else if(Copy_u8IntNumber<=59)
	{
		Copy_u8IntNumber-=32;
		MNVIC_ICPR1 = 1<<(Copy_u8IntNumber);
	}
	else
	{
		Local_u8ErrorState=NOK;
	}
	return Local_u8ErrorState;
}

u8 MNVIC_u8GetActiveFlag(u8 Copy_u8IntNumber)
{
	u8 Local_u8Result;
	if(Copy_u8IntNumber<=31)
	{
		Local_u8Result=GET_BIT(MNVIC_IABR0,Copy_u8IntNumber);
	}
	else if(Copy_u8IntNumber<=59)
	{
		Copy_u8IntNumber-=32;
		Local_u8Result=GET_BIT(MNVIC_IABR1,Copy_u8IntNumber);
	}

	return Local_u8Result;
}

u8 MNVIC_u8SetPriority(s8 Copy_s8IntID, u8 Copy_u8GroupPriority , u8 Copy_u8SubPriority, u32 Copy_u32GroupingType)
{
	u8 Local_u8ErrorState=OK;
	/*this equation make the suitable 4 bits for IPR by knowing the grouping type , group priority and sub priority*/
	u8 Local_u8Priority = Copy_u8SubPriority | (Copy_u8GroupPriority << (Copy_u32GroupingType - PRIORITY_GROUP3) / 0x100);
	if(Copy_s8IntID >= 0)
	{
		MNVIC_IPR[Copy_s8IntID] = Local_u8Priority << 4 ; /*shifting by 4 to make the 4 bits in the MSB in the byte of the register*/
	}
	else
	{
		Local_u8ErrorState=NOK;
	}
	MSCB_AIRCR= Copy_u32GroupingType; /*password + 3 bits grouping type */

	return Local_u8ErrorState;

}
