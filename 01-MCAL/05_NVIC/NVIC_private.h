/*
 * NVIC_private.h
 *
 *  Created on: Dec 15, 2022
 *      Author: speedTECH
 */

#ifndef NVIC_PRIVATE_H_
#define NVIC_PRIVATE_H_

#define MNVIC_BASE_ADRESS 0xE000E100
#define MSCB_BASE_ADRESS  0xE000ED00

#define MNVIC_ISER0  *((volatile u32*)(MNVIC_BASE_ADRESS))		 /*Enable EXTI from 0 to 31*/
#define MNVIC_ISER1  *((volatile u32*)(MNVIC_BASE_ADRESS+0x004)) /*Enable EXTI from 32 to 63*/

#define MNVIC_ICER0  *((volatile u32*)(MNVIC_BASE_ADRESS+0x080)) /*Disable EXTI from 0 to 31*/
#define MNVIC_ICER1  *((volatile u32*)(MNVIC_BASE_ADRESS+0x084)) /*Disable EXTI from 32 to 63*/

#define MNVIC_ISPR0  *((volatile u32*)(MNVIC_BASE_ADRESS+0x100)) /*Enable EXTI Pending flag from 0 to 31*/
#define MNVIC_ISPR1  *((volatile u32*)(MNVIC_BASE_ADRESS+0x104)) /*Enable EXTI Pending flag from 32 to 63*/

#define MNVIC_ICPR0  *((volatile u32*)(MNVIC_BASE_ADRESS+0x180)) /*Disable EXTI Pending flag from 0 to 31*/
#define MNVIC_ICPR1  *((volatile u32*)(MNVIC_BASE_ADRESS+0x184)) /*Disable EXTI Pending flag from 32 to 63*/

#define MNVIC_IABR0  *((volatile u32*)(MNVIC_BASE_ADRESS+0x200)) /*Active bit register 0*/
#define MNVIC_IABR1  *((volatile u32*)(MNVIC_BASE_ADRESS+0x204)) /*Active bit register 1*/

#define MNVIC_IPR     ((volatile u8*)MNVIC_BASE_ADRESS+0x300)	/*address of IPR casting with u8 pointer to allow byte access */

#define MSCB_AIRCR	 *((volatile u32*)(MSCB_BASE_ADRESS+0x0C))
#endif /* NVIC_PRIVATE_H_ */
