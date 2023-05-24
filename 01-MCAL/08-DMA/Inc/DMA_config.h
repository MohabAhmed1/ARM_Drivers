/*
 * DMA_config.h
 *
 *  Created on: Apr 29, 2023
 *      Author: Mohab Ahmed
 */

#ifndef DMA_CONFIG_H_
#define DMA_CONFIG_H_


#define CH_ID 				CH1

#define MEM_TO_MEM 			ENABLED


#define CH_PRIORITY			PRIO_VERY_HIGH

#define MEM_SIZE			MEM_SIZE_32
#define PER_SIZE 			PER_SIZE_32

#define MINC				ENABLED
#define PINC				ENABLED
#define CIRC				DISABLED
#define DIR					READ_MEM

#define TRANSFER_INTERRUPT	ENABLED


#endif /* DMA_CONFIG_H_ */
