#include "00-LIB/STD_TYPES.h"
#include "00-LIB/BIT_MATH.h"

#include "01-MCAL/00-RCC/RCC_interface.h"
#include "01-MCAL/01-PORT/PORT_interface.h"
#include "01-MCAL/02-DIO/DIO_interface.h"
#include "01-MCAL/03-STK/STK_interface.h"
#include "01-MCAL/05-EXTI/EXTI_interface.h"
#include "01-MCAL/06-AFIO/AFIO_interface.h"
#include "01-MCAL/08-TIM/TIM_interface.h"
#include "01-MCAL/10-PWM/PWM_interface.h"
#include "01-MCAL/04-NVIC/NVIC_interface.h"

#include "DMA_interface.h"
u8 flag=0;
u32 Arr1[1000]={0};
u32 Arr2[1000];
u32 Arr3[1000]={0};
u32 Arr4[1000];
void ISR()
{
	flag=1;
}
int main (void)
{

	RCC_voidInitSysClock();
	RCC_voidEnableClock(RCC_DMA1,RCC_AHB);
	MNVIC_u8EnableInterrupt(NVIC_DMA1);

	DMA_voidSetCallBack(ISR, CH1);
	DMA_voidInit();
	DMA_u8ChannelStart(Arr1, Arr2, 1000);

	for(u16 i=0;i<1000;i++)
	{
		Arr4[i]=Arr3[i];
	}
	while(1)
	{

	}
}

