/**************************************************************/
/****************** Name	: MOHAMED ELSAYED *****************/
/****************** Date	: 20/9/2021       *****************/
/****************** Version : 1.0V            *****************/
/****************** SWC		: EXTI            *****************/
/**************************************************************/

#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H

#include "STD_TYPES.h"


/************************ EXTI LINE MACROS ********************************************************/
typedef enum
{
	EXTI_LINE0	,
	EXTI_LINE1	,
	EXTI_LINE2	,
	EXTI_LINE3	,
	EXTI_LINE4	,
	EXTI_LINE5	,
	EXTI_LINE6	,
	EXTI_LINE7	,
	EXTI_LINE8	,
	EXTI_LINE9	,
	EXTI_LINE10	,
	EXTI_LINE11	,
	EXTI_LINE12	,
	EXTI_LINE13	,
	EXTI_LINE14	,
	EXTI_LINE15
}EXTI_enumLines;
/****************************************************************************************************/


/************************ EXTI SENSE EDGE MACROS ********************************************************/
typedef enum
{
	EXTI_FALLING_EDGE	,
	EXTI_RISING_EDGE	,
	EXTI_ON_CHANGE

}EXTI_enumSenseEdge;
/****************************************************************************************************/

/************************ EXTI PORT MACROS ********************************************************/
typedef enum
{
	EXTI_PORTA	,
	EXTI_PORTB	,
	EXTI_PORTC

}EXTI_enumPort;
/****************************************************************************************************/

/************************ EXTI PINS MACROS ********************************************************/
typedef enum
{
	EXTI_PIN0	,
	EXTI_PIN1	,
	EXTI_PIN2	,
	EXTI_PIN3	,
	EXTI_PIN4	,
	EXTI_PIN5	,
	EXTI_PIN6	,
	EXTI_PIN7	,
	EXTI_PIN8	,
	EXTI_PIN9	,
	EXTI_PIN10	,
	EXTI_PIN11	,
	EXTI_PIN12	,
	EXTI_PIN13	,
	EXTI_PIN14	,
	EXTI_PIN15

}EXTI_enumPins;
/****************************************************************************************************/


/************* EXTI STRUCT CONFIG  ****************/
typedef struct
{
	EXTI_enumPort PortId;
	EXTI_enumPins PinId;
	EXTI_enumLines LineId ;
	EXTI_enumSenseEdge TriggerLevel;
	void (* Copy_pfunCallBackFun) (void);
}EXTI_Cofig_t;
/****************************************/


/************* EXTI APIS ****************/
u8 EXTI_u8Init(const EXTI_Cofig_t * Copy_pstrInit);
u8 EXTI_u8IntEnable(const EXTI_Cofig_t * Copy_pstrInit);
u8 EXTI_u8IntDisable(const EXTI_Cofig_t * Copy_pstrInit);
u8 EXTI_u8SoftWareTrigger(const EXTI_Cofig_t * Copy_pstrInit);
u8 EXTI_u8SetCallBack(const EXTI_Cofig_t * Copy_pstrInit);
/****************************************/













#endif
