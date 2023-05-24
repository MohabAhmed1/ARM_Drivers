/*
 * NVIC_interface.h
 *
 *  Created on: Dec 15, 2022
 *      Author: speedTECH
 */

#ifndef NVIC_INTERFACE_H_
#define NVIC_INTERFACE_H_

#define PRIORITY_GROUP3 0x05FA0300		/*4 Bits for group 0 bits for sub priority*/
#define PRIORITY_GROUP4 0x05FA0400		/*3 Bits for group 1 bits for sub priority*/
#define PRIORITY_GROUP5 0x05FA0500		/*2 Bits for group 2 bits for sub priority*/
#define PRIORITY_GROUP6 0x05FA0600		/*1 Bits for group 3 bits for sub priority*/
#define PRIORITY_GROUP7 0x05FA0700		/*0 Bits for group 4 bits for sub priority*/

u8 MNVIC_u8EnableInterrupt(u8 Copy_u8IntNumber);
u8 MNVIC_u8DisableInterrupt(u8 Copy_u8IntNumber);

u8 MNVIC_u8SetPendingFlag(u8 Copy_u8IntNumber);
u8 MNVIC_u8ClearPendingFlag(u8 Copy_u8IntNumber);

u8 MNVIC_u8GetActiveFlag(u8 Copy_u8IntNumber);

u8 MNVIC_u8SetPriority(s8 Copy_s8IntID, u8 Copy_u8GroupPriority , u8 Copy_u8SubPriority, u32 Copy_u32GroupingType);


#endif /* NVIC_INTERFACE_H_ */
