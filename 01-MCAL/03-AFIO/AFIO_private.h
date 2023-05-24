/*
 * AFIO_private.h
 *
 *  Created on: Dec 17, 2022
 *      Author: speedTECH
 */
#define MAFIO_BASE_ADDRESS 0x40010000

typedef struct
{
	volatile u32 MAFIO_EVCR;
	volatile u32 MAFIO_MAPR;
	volatile u32 MAFIO_EXTICR[4];
//	volatile u32 MAFIO_EXTICR1;
//	volatile u32 MAFIO_EXTICR2;
//	volatile u32 MAFIO_EXTICR3;
//	volatile u32 MAFIO_EXTICR4;
	volatile u32 MAFIO_MAPR2;
}AFIO_t;

#define MAFIO ((volatile AFIO_t*)0x40010000)


#define MAFIO_PORTA 0000
#define MAFIO_PORTB 0001
#define MAFIO_PORTC 0010
