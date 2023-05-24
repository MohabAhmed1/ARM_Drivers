/*
 * EXTI_interface.h
 *
 *  Created on: Dec 16, 2022
 *      Author: speedTECH
 */

#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_

u8 MEXTI_u8Init(u8 Copy_u8EXTILine,u8 Copy_u8EXTIMode);
u8 MEXTI_u8EnableEXTI(u8 Copy_u8EXTILine);
u8 MEXTI_u8DisableEXTI(u8 Copy_u8EXTILine);
u8 MEXTI_u8SWTrigger(u8 Copy_u8EXTILine);
u8 MEXTI_u8SetCallBackInt0(void (*Copy_pvCallBackFunc)(void));
u8 MEXTI_u8SetCallBackInt1(void (*Copy_pvCallBackFunc)(void));


#define MEXTI_LINE0  0
#define MEXTI_LINE1  1
#define MEXTI_LINE2  2
#define MEXTI_LINE3  3
#define MEXTI_LINE4  4
#define MEXTI_LINE5  5
#define MEXTI_LINE6  6
#define MEXTI_LINE7  7
#define MEXTI_LINE8  8
#define MEXTI_LINE9  9
#define MEXTI_LINE10 10
#define MEXTI_LINE11 11
#define MEXTI_LINE12 12
#define MEXTI_LINE13 13
#define MEXTI_LINE14 14
#define MEXTI_LINE15 15

#define RISING 	  0
#define FALLING   1
#define ON_CHANGE 2
#endif /* EXTI_INTERFACE_H_ */
