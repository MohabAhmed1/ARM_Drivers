/*
 * AFIO_program.c
 *
 *  Created on: Dec 17, 2022
 *      Author: speedTECH
 */

#include "STD_TYPES.h"
#include "Bit_Math.h"

#include "AFIO_interface.h"
#include "AFIO_private.h"
#include "AFIO_config.h"

void MAFIO_voidSetEXTIConfig(u8 Copy_u8EXTILine,u8 Copy_u8Port)
{
	u8 Local_u8RegisterIndex=0;
	/*changing the register index and the interrupt line to be applicable*/
	if(Copy_u8EXTILine <= 3)
	{
		Local_u8RegisterIndex=0;
	}
	else if(Copy_u8EXTILine <= 7)
	{
		Local_u8RegisterIndex=1;
		//Copy_u8EXTILine-=4;
		Local_u8RegisterIndex=Copy_u8EXTILine/4;
		Copy_u8EXTILine=Copy_u8EXTILine % 4;
	}
	else if(Copy_u8EXTILine <= 11)
	{
		Local_u8RegisterIndex=2;
		//Copy_u8EXTILine-=8;
		Local_u8RegisterIndex=Copy_u8EXTILine/4;
		Copy_u8EXTILine=Copy_u8EXTILine % 4;
	}
	else if(Copy_u8EXTILine <= 15)
	{
//		Local_u8RegisterIndex=3;
//		Copy_u8EXTILine-=12;
		Local_u8RegisterIndex=Copy_u8EXTILine/4;
		Copy_u8EXTILine=Copy_u8EXTILine % 4;
	}
MAFIO -> MAFIO_EXTICR[Local_u8RegisterIndex] &= ~ ((0b1111) << (Copy_u8EXTILine*4));
MAFIO -> MAFIO_EXTICR[Local_u8RegisterIndex] |= (Copy_u8Port)<<(Copy_u8EXTILine*4);
}
