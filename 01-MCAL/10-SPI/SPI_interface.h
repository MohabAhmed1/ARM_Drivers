/*******************************************************************************/
/******************      Author : Mohab Ahmed  		 ***********************/
/***********************   	Layer : MCAL 	         ***********************/
/************************ 	Version : 1.0            ***********************/
/**************************  SWC : SPI     	         ***********************/
/*******************************************************************************/
#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_

typedef enum
{
	SPI1 , SPI2
}SPI_Type_t;

typedef enum
{
	SPI_Phase_Leading_Edge,
	SPI_Phase_Trailing_Edge
}SPI_Clk_Phase_t;

typedef enum
{
	SPI_Phase_Idle_Low,
	SPI_Phase_Idle_High
}SPI_Clk_Polarity_t;

typedef enum
{
	SPI_Slave_Mode,
	SPI_Master_Mode
}SPI_Mode_t;

typedef enum
{
	SPI_BaudRate_Div2,
	SPI_BaudRate_Div4,
	SPI_BaudRate_Div8,
	SPI_BaudRate_Div16,
	SPI_BaudRate_Div32,
	SPI_BaudRate_Div64,
	SPI_BaudRate_Div128,
	SPI_BaudRate_Div256,
}SPI_Baud_Rate_t;

typedef enum
{
	SPI_Disable,
	SPI_Enable
}SPI_State_t;

typedef enum
{
	SPI_MSB_First,
	SPI_LSB_First
}SPI_FrameFormat_t;

typedef enum
{
	SPI_8BitData,
	SPI_16BitData
}SPI_DataLength_t;


typedef struct
{
	SPI_Type_t 			SPI_Type;
	SPI_Mode_t 			SPI_Mode;
	SPI_Clk_Phase_t 	SPI_Clk_Phase;
	SPI_Clk_Polarity_t 	SPI_Clk_Polarity;
	SPI_Baud_Rate_t 	SPI_Baud_Rate;
	SPI_FrameFormat_t 	SPI_FrameFormat;
	SPI_DataLength_t 	SPI_DataLength;

}SPI_Config_t;

void SPI_voidInit(SPI_Config_t* SPI_Ptr);
u8 SPI_u8TranceiveByte(u8 Copy_u8DataTx , u8* Copy_ptrDataRx , u8 Copy_u8SPIType);
u8 SPI_u8TranceiveBuffer(u8* Copy_ptrDataTx,u8* Copy_ptrDataRx , u8 Copy_u8DataSize , u8 Copy_u8SPIType);

#endif /* SPI_INTERFACE_H_ */
