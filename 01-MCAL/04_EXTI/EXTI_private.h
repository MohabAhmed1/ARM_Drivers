/*
 * EXTI_private.h
 *
 *  Created on: Dec 16, 2022
 *      Author: speedTECH
 */

#ifndef EXTI_PRIVATE_H_
#define EXTI_PRIVATE_H_

#define MEXTI_BASE_ADDRESS 	0x40010400
typedef struct
{
	volatile u32 MEXTI_IMR;
	volatile u32 MEXTI_EMR;
	volatile u32 MEXTI_RTSR;
	volatile u32 MEXTI_FTSR;
	volatile u32 MEXTI_SWIER;
	volatile u32 MEXTI_PR;

} MEXTI_t;

#define MEXTI ((volatile MEXTI_t *)MEXTI_BASE_ADDRESS)
/*we define pointer with type of the given struct and
  this pointer store the base address of EXTI and the offset
  between each address will be 4 bytes so all the variables
   in the struct their addresses will be an offsets from the base address
  */


#endif /* EXTI_PRIVATE_H_ */
