/*
 * DMA_private.h
 *
 *  Created on: Apr 29, 2023
 *      Author: Mohab Ahmed
 */

#ifndef DMA_PRIVATE_H_
#define DMA_PRIVATE_H_

#define DMA1_BASE_ADRESS 	0x40020000
#define DMA2_BASE_ADRESS 	0x40020400



typedef struct
{
	volatile u32 CCR;
	volatile u32 CNDTR;
	volatile u32 CPAR;
	volatile u32 CMAR;
	volatile u32 Reserved;

}DMA_Channels_t;

typedef struct
{
	volatile u32 ISR;
	volatile u32 IFCR;
	DMA_Channels_t Channel[7];

}DMA_t;


#define DMA ((volatile DMA_t*)(DMA1_BASE_ADRESS))




/*Channels*/
#define CH1 				1
#define CH2 				2
#define CH3 				3
#define CH4 				4
#define CH5 				5
#define CH6 				6
#define CH7 				7

/********************************/
#define ENABLED 			1
#define DISABLED 			2
/********************************/
#define PRIO_VERY_HIGH		4
#define PRIO_HIGH			3
#define PRIO_MEDIUM			2
#define PRIO_LOW			1
/********************************/
#define MEM_SIZE_8			1
#define MEM_SIZE_16			2
#define MEM_SIZE_32			3
/********************************/
#define PER_SIZE_8			1
#define PER_SIZE_16			2
#define PER_SIZE_32			3

/********************************/
#define DMA_MEM2MEM			14
#define DMA_PL1				13
#define DMA_PL0				12
#define DMA_MSIZE1			11
#define DMA_MSIZE0			10
#define DMA_PSIZE1			9
#define DMA_PSIZE0			8
#define DMA_MINC			7
#define DMA_PINC			6
#define DMA_CIRC			5
#define DMA_DIR				4
#define DMA_TEIE			3
#define DMA_HTIE			2
#define DMA_TCIE			1
#define DMA_EN				0
/********************************/
		/*Transfer Complete*/
#define DMA_TCIF_CH1		1
#define DMA_TCIF_CH2		5
#define DMA_TCIF_CH3		9
#define DMA_TCIF_CH4		13
#define DMA_TCIF_CH5		17
#define DMA_TCIF_CH6		21
#define DMA_TCIF_CH7		25
/********************************/
		/*Interrupt Flags*/
#define DMA_GIF_CH1			0
#define DMA_GIF_CH2			4
#define DMA_GIF_CH3			8
#define DMA_GIF_CH4			12
#define DMA_GIF_CH5			16
#define DMA_GIF_CH6			20
#define DMA_GIF_CH7			24
/********************************/
#define READ_PER			1
#define READ_MEM			2




#endif /* DMA_PRIVATE_H_ */
