#include "00-LIB/STD_TYPES.h"
#include "00-LIB/BIT_MATH.h"

#include "DMA_interface.h"
#include "DMA_private.h"
#include "DMA_config.h"


static void (*Globalptr2func[7])(void)={NULL};
void DMA_voidInit(void)
{
	#if MEM_TO_MEM==ENABLED
	DMA -> Channel[CH_ID-1].CCR |= 1<<DMA_MEM2MEM;
	#elif MEM_TO_MEM==DISABLED
	CLR_BIT(DMA -> Channel[CH_ID-1].CCR ,DMA_MEM2MEM);
	#endif
	#if CH_PRIORITY==PRIO_VERY_HIGH
	DMA -> Channel[CH_ID-1].CCR |= 1<<DMA_PL1;		/*Channel Priority*/
	DMA -> Channel[CH_ID-1].CCR |= 1<<DMA_PL0;
	#elif CH_PRIORITY==PRIO_HIGH
	DMA -> Channel[CH_ID-1].CCR |= 1<<DMA_PL1;		/*Channel Priority*/
	CLR_BIT(DMA -> Channel[CH_ID-1].CCR ,DMA_PL0);
	#elif CH_PRIORITY==PRIO_MEDIUM
	CLR_BIT(DMA -> Channel[CH_ID-1].CCR ,DMA_PL1);	/*Channel Priority*/
	DMA -> Channel[CH_ID-1].CCR |= 1<<DMA_PL0;
	#elif CH_PRIORITY==PRIO_LOW
	CLR_BIT(DMA -> Channel[CH_ID-1].CCR ,DMA_PL1);		/*Channel Priority*/
	CLR_BIT(DMA -> Channel[CH_ID-1].CCR ,DMA_PL0);
	#endif
	#if MEM_SIZE==MEM_SIZE_32
	DMA -> Channel[CH_ID-1].CCR |= 1<<DMA_MSIZE1;		/*Memory size*/
	CLR_BIT(DMA -> Channel[CH_ID-1].CCR ,DMA_MSIZE0);
	#elif MEM_SIZE==MEM_SIZE_16
	CLR_BIT(DMA -> Channel[CH_ID-1].CCR ,DMA_MSIZE1);
	DMA -> Channel[CH_ID-1].CCR |= 1<<DMA_MSIZE0;
	#elif MEM_SIZE==MEM_SIZE_8
	CLR_BIT(DMA -> Channel[CH_ID-1].CCR ,DMA_MSIZE1);
	CLR_BIT(DMA -> Channel[CH_ID-1].CCR ,DMA_MSIZE0);

	#endif
	#if PER_SIZE==PER_SIZE_32
	DMA -> Channel[CH_ID-1].CCR |= 1<<DMA_PSIZE1;		/*Peripheral Priority*/
	CLR_BIT(DMA -> Channel[CH_ID-1].CCR ,DMA_PSIZE0);
	#elif PER_SIZE==PER_SIZE_16
	CLR_BIT(DMA -> Channel[CH_ID-1].CCR ,DMA_PSIZE1);		/*Peripheral Priority*/
	DMA -> Channel[CH_ID-1].CCR |= 1<<DMA_PSIZE0;
	#elif MEM_SIZE==MEM_SIZE_8
	CLR_BIT(DMA -> Channel[CH_ID-1].CCR ,DMA_PSIZE1);		/*Peripheral Priority*/
	CLR_BIT(DMA -> Channel[CH_ID-1].CCR ,DMA_PSIZE0);
	#endif
	/*Memory Increment*/
	#if MINC==ENABLED
	DMA -> Channel[CH_ID-1].CCR |= 1<<DMA_MINC;
	#elif MINC==DISABLED
	CLR_BIT(DMA -> Channel[CH_ID-1].CCR ,DMA_MINC);
	#endif
	/*Peripheral Increment*/
	#if PINC==ENABLED
	DMA -> Channel[CH_ID-1].CCR |= 1<<DMA_PINC;
	#elif PINC==DISABLED
	CLR_BIT(DMA -> Channel[CH_ID-1].CCR ,DMA_PINC);
	#endif
	/*Circular mode*/
	#if CIRC==ENABLED
	DMA -> Channel[CH_ID-1].CCR |= 1<<DMA_CIRC;
	#elif CIRC==DISABLED
	CLR_BIT(DMA -> Channel[CH_ID-1].CCR ,DMA_CIRC);
	#endif
	/*Interrupt Enable*/
	#if TRANSFER_INTERRUPT == ENABLED
	DMA -> Channel[CH_ID-1].CCR |= 1<<DMA_TCIE;
	#elif TRANSFER_INTERRUPT == DISABLED
	CLR_BIT(DMA -> Channel[CH_ID-1].CCR ,DMA_TCIE);
	#endif
	#if DIR==READ_MEM
	CLR_BIT(DMA -> Channel[CH_ID-1].CCR ,DMA_DIR);
	#elif DIR==READ_PER
	SET_BIT(DMA -> Channel[CH_ID-1].CCR ,DMA_DIR);
	#endif
}

void DMA_u8ChannelStart(u32 * Copy_pu32SourceAdress, u32 * Copy_pu32DestinationAdress, u16 Copy_u16BlockLength )
{
	/*Channel Disabled*/
	CLR_BIT(DMA -> Channel[CH_ID-1].CCR ,DMA_EN);
	/*Source Address*/
	DMA -> Channel[CH_ID-1].CPAR= (u32)Copy_pu32SourceAdress;
	/*Destination Address*/
	DMA -> Channel[CH_ID-1].CMAR= (u32)Copy_pu32DestinationAdress;
	/*Block Length*/
	DMA -> Channel[CH_ID-1].CNDTR= Copy_u16BlockLength;
	/*Enable the Channel */

	SET_BIT(DMA -> Channel[CH_ID-1].CCR ,DMA_EN);

}
u8 DMA_voidSetCallBack(void (*Localptr2func)(void),u8 Local_u8ChannelNumber)
{
	u8 Local_u8ErrorStatus=OK;
	if(Localptr2func != NULL)
	{
	Globalptr2func[Local_u8ChannelNumber-1]=Localptr2func;
	}
	else
	{
		Local_u8ErrorStatus=NULL_POINTER;
	}

	return Local_u8ErrorStatus;
}



void DMA1_Channel1_IRQHandler (void)
{
	if (Globalptr2func[0]!=NULL)
	{
		Globalptr2func[0]();
	}
	SET_BIT(DMA -> IFCR ,DMA_TCIF_CH1);
	SET_BIT(DMA -> IFCR ,DMA_GIF_CH1);

}

void DMA1_Channel2_IRQHandler (void)
{
	if (Globalptr2func[1]!=NULL)
		{
			Globalptr2func[1]();
		}
	SET_BIT(DMA -> IFCR ,DMA_TCIF_CH2);
	SET_BIT(DMA -> IFCR ,DMA_GIF_CH2);
}

void DMA1_Channel3_IRQHandler (void)
{
	if (Globalptr2func[2]!=NULL)
		{
			Globalptr2func[2]();
		}
	SET_BIT(DMA -> IFCR ,DMA_TCIF_CH3);
	SET_BIT(DMA -> IFCR ,DMA_GIF_CH3);
}

void DMA1_Channel4_IRQHandler (void)
{
	if (Globalptr2func[3]!=NULL)
			{
				Globalptr2func[3]();
			}
	SET_BIT(DMA -> IFCR ,DMA_TCIF_CH4);
	SET_BIT(DMA -> IFCR ,DMA_GIF_CH4);
}

void DMA1_Channel5_IRQHandler (void)
{
	if (Globalptr2func[4]!=NULL)
			{
				Globalptr2func[4]();
			}
	SET_BIT(DMA -> IFCR ,DMA_TCIF_CH5);
	SET_BIT(DMA -> IFCR ,DMA_GIF_CH5);
}

void DMA1_Channel6_IRQHandler (void)
{
	if (Globalptr2func[5]!=NULL)
			{
				Globalptr2func[5]();
			}
	SET_BIT(DMA -> IFCR ,DMA_TCIF_CH6);
	SET_BIT(DMA -> IFCR ,DMA_GIF_CH6);
}

void DMA1_Channel7_IRQHandler (void)
{
	if (Globalptr2func[6]!=NULL)
			{
				Globalptr2func[6]();
			}
	SET_BIT(DMA -> IFCR ,DMA_TCIF_CH7);
	SET_BIT(DMA -> IFCR ,DMA_GIF_CH7);
}




