/**************************************************************/
/****************** Name	: MOHAMED ELSAYED *****************/
/****************** Date	: 20/9/2021       *****************/
/****************** Version : 1.0V            *****************/
/****************** SWC		: STK            *****************/
/**************************************************************/

#ifndef STK_INTERFACE_H
#define STK_INTERFACE_H

#include "STD_TYPES.h"



/************************ STK MACROS *********************************************/
#define STK_u32RESOLUTION    16777215
/*********************************************************************************/

/************************ STK MACROS *********************************************/

/*********************************************************************************/



/************* STK APIS ****************/
u8 STK_u8Init(void);
u8 STK_u8SetBusyWait(u32 Copy_u32Ticks);
u8 STK_u8SetIntervalSingle(u32 Copy_u32Ticks, void (*Copy_pfun)(void));
u8 STK_u8SetIntervalPeriodic(u32 Copy_u32Ticks, void (*Copy_pfun)(void));
u8 STK_u8StopTimer(void);
u8 STK_u8GetElapsedTime(u32 * Copy_pu32ReturnedElapsedTime);
u8 STK_u8GetRemainingTime(u32 * Copy_pu32ReturnedRemainingTime);
u8 STK_u8ReadTimerFlag(u8 * Copy_pu32ReturnedFlagValue);
/****************************************/









#endif
