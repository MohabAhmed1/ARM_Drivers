/***************************************************************************/
/******************      Author : Mohab Ahmed  		 ***********************/
/***********************   	Layer : MCAL 			 ***********************/
/************************ 	Version : 1.0   		 ***********************/
/**************************  SWC : SPI     			 ***********************/
/***************************************************************************/


#ifndef SPI_PRIVATE_H_
#define SPI_PRIVATE_H_

#define SPI1_BASE_ADDRESS 	0x40013000
#define SPI2_BASE_ADDRESS 	0x40003800


typedef struct
{
	volatile u32 CR1;
	volatile u32 CR2;
	volatile u32 SR;
	volatile u32 DR;
	volatile u32 CRCPR;
	volatile u32 RXCRCR;
	volatile u32 TXCRCR;
	volatile u32 I2SCFGR;
	volatile u32 I2SPR;
}SPI_t;

#define SPI1 ((volatile SPI_t *)(SPI1_BASE_ADDRESS))
#define SPI2 ((volatile SPI_t *)(SPI2_BASE_ADDRESS))


typedef enum
{
	SPI_CR1_CPHA			,
	SPI_CR1_CPOL			,
	SPI_CR1_MSTR			,
	SPI_CR1_BR0				,
	SPI_CR1_BR1				,
	SPI_CR1_BR2				,
	SPI_CR1_SPE				,
	SPI_CR1_LSBFIRST		,
	SPI_CR1_SSI				,
	SPI_CR1_SSM				,
	SPI_CR1_RXONLY			,
	SPI_CR1_DFF				,
	SPI_CR1_CRCNEXT			,
	SPI_CR1_CRCEN			,
	SPI_CR1_BIDIOE			,
	SPI_CR1_BIDIMODE		,
	SPI_CR2_RXDMAEN = 0		,
	SPI_CR2_TXDMAEN 		,
	SPI_CR2_SSOE			,
	SPI_CR2_ERRIE 	= 5		,
	SPI_CR2_RXNEIE			,
	SPI_CR2_TXEIE			,
	SPI_SR_RXNE		= 0		,
	SPI_SR_TXE				,
	SPI_SR_CHSIDE			,
	SPI_SR_UDR				,
	SPI_SR_CRCERR			,
	SPI_SR_MODF				,
	SPI_SR_OVR				,
	SPI_SR_BSY				,
	SPI_I2SCFGR_CHLEN = 0	,
	SPI_I2SCFGR_DATLEN1		,
	SPI_I2SCFGR_DATLEN2		,
	SPI_I2SCFGR_CKPOL		,
	SPI_I2SCFGR_I2SSTD1		,
	SPI_I2SCFGR_I2SSTD2		,
	SPI_I2SCFGR_PCMSYNC = 7	,
	SPI_I2SCFGR_I2SCFG1		,
	SPI_I2SCFGR_I2SCFG2		,
	SPI_I2SCFGR_I2SE		,
	SPI_I2SCFGR_I2SMOD		,
	SPI_I2SPR_I2SDIV = 0 	,
	SPI_I2SPR_ODD = 8 		,
	SPI_I2SPR_MCKOE

}SPI_Bits_t;

#define BAUD_MASK 0xFFC7

#endif /* SPI_PRIVATE_H_ */
