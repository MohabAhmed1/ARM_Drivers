/*
 * DMA_interface.h
 *
 *  Created on: Apr 29, 2023
 *      Author: Mohab Ahmed
 */

#ifndef DMA_INTERFACE_H_
#define DMA_INTERFACE_H_


void DMA_voidInit(void);
void DMA_u8ChannelStart(u32 * Copy_pu32SourceAdress, u32 * Copy_pu32DestinationAdress, u16 Copy_u16BlockLength );
u8 DMA_voidSetCallBack(void (*Localptr2func)(void),u8 Local_u8ChannelNumber);



#endif /* DMA_INTERFACE_H_ */
