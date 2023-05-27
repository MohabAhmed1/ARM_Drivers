/*******************************************************************************/
/******************      Author : Mohab Ahmed  		 ***********************/
/***********************   	Layer : MCAL 	         ***********************/
/************************ 	Version : 1.0            ***********************/
/**************************  SWC : SPI     	         ***********************/
/*******************************************************************************/


#include "00-LIB/BIT_MATH.h"
#include "00-LIB/STD_TYPES.h"
#include "00-LIB/Software_Delay.h"

#include "SPI_interface.h"
#include "SPI_private.h"
#include "SPI_config.h"


static volatile SPI_t* const SPI [2] = {SPI1 , SPI2};



void SPI_voidInit(SPI_Config_t* SPI_Ptr)
{

	u8 Local_u8SPINum = SPI_Ptr -> SPI_Type ;

	/*Clock Phase*/
	if(SPI_Ptr -> SPI_Clk_Phase <= SPI_Phase_Trailing_Edge)
	{
		SPI[Local_u8SPINum] -> CR1 |= (SPI_Ptr -> SPI_Clk_Phase << SPI_CR1_CPHA) ;
	}

	/*Clock Polarity*/
	if(SPI_Ptr -> SPI_Clk_Polarity <= SPI_Phase_Idle_High)
	{
		SPI[Local_u8SPINum] -> CR1 |= (SPI_Ptr -> SPI_Clk_Polarity << SPI_CR1_CPOL) ;
	}

	/*Master Selection*/
	if(SPI_Ptr -> SPI_Mode == SPI_Master_Mode)
	{
		SET_BIT(SPI[Local_u8SPINum] -> CR1  , SPI_CR1_MSTR);
	}
	else
	{
		CLR_BIT(SPI[Local_u8SPINum] -> CR1  , SPI_CR1_MSTR);
	}

	/*Baud rate*/
	if(SPI_Ptr -> SPI_Mode == SPI_Master_Mode)
	{
		SPI[Local_u8SPINum] -> CR1 &= BAUD_MASK;
		SPI[Local_u8SPINum] -> CR1 |= SPI_Ptr -> SPI_Baud_Rate << SPI_CR1_BR0;
	}

	/*Frame Format*/
	if(SPI_Ptr -> SPI_FrameFormat <= SPI_MSB_First)
	{
		SPI[Local_u8SPINum] -> CR1 |= (SPI_Ptr -> SPI_FrameFormat << SPI_CR1_LSBFIRST) ;
	}

	/*Data Length*/
	if(SPI_Ptr -> SPI_DataLength <= SPI_16BitData)
	{
		SPI[Local_u8SPINum] -> CR1 |= (SPI_Ptr -> SPI_DataLength << SPI_CR1_DFF) ;
	}

	/*Full duplex*/
	CLR_BIT(SPI[Local_u8SPINum] -> CR1 ,SPI_CR1_RXONLY );


	/*Set SS software management */
	SET_BIT(SPI[Local_u8SPINum] -> CR1 , SPI_CR1_SSM);
	SET_BIT(SPI[Local_u8SPINum] -> CR1 , SPI_CR1_SSI);


	/*Enable SPI*/
	SET_BIT( SPI[ Local_u8SPINum ]->CR1, SPI_CR1_SPE );


}
u8 SPI_u8TranceiveByte(u8 Copy_u8DataTx , u8* Copy_ptrDataRx , u8 Copy_u8SPIType)
{
	u8 Local_u8ErrorStatus = OK;
	if (Copy_u8SPIType < 2 )
	{
		SPI[Copy_u8SPIType] -> DR = Copy_u8DataTx ;

		while(!GET_BIT(SPI[Copy_u8SPIType] -> SR, SPI_SR_TXE));
		while(GET_BIT(SPI[Copy_u8SPIType] -> SR, SPI_SR_BSY));

		*Copy_ptrDataRx = SPI [Copy_u8SPIType] -> DR ;
	}
	else
	{
		Local_u8ErrorStatus = NOK;
	}
	return Local_u8ErrorStatus ;

}

u8 SPI_u8TranceiveBuffer(u8* Copy_ptrDataTx,u8* Copy_ptrDataRx , u8 Copy_u8DataSize , u8 Copy_u8SPIType)
{
	u8 Local_u8ErrorStatus = OK;
	u8 Local_u8Iterator = 0;
	if (Copy_u8SPIType < 2 )
	{
		while( Local_u8Iterator < Copy_u8DataSize)
		{
			SPI[Copy_u8SPIType] -> DR = Copy_ptrDataTx [Local_u8Iterator] ;

			while(!GET_BIT(SPI[Copy_u8SPIType] -> SR, SPI_SR_TXE));
			while(GET_BIT(SPI[Copy_u8SPIType] -> SR, SPI_SR_BSY));

			Copy_ptrDataRx [Local_u8Iterator] = SPI[Copy_u8SPIType] -> DR ;

			Local_u8Iterator ++ ;
		}
	}
	else
	{
		Local_u8ErrorStatus = NOK ;
	}
	return Local_u8ErrorStatus;


}
