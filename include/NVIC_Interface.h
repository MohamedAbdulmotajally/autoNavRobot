/**************************************************************/
/****************** Name	: MOHAMED ELSAYED *****************/
/****************** Date	: 20/9/2021       *****************/
/****************** Version : 1.0V            *****************/
/****************** SWC		: NVIC            *****************/
/**************************************************************/

#ifndef NVIC_INTERFACE_H
#define NVIC_INTERFACE_H
#include"stdarg.h"
#include "STD_TYPES.h"

/************************ NVIC IQRN MACROS ********************************************************/
typedef enum
{
	NVIC_WWDG               ,
	NVIC_PVD                ,
	NVIC_TAMPER             ,
	NVIC_RTC                ,
	NVIC_FLASH              ,
	NVIC_RCC                ,
	NVIC_EXTI0              ,
	NVIC_EXTI1              ,
	NVIC_EXTI2              ,
	NVIC_EXTI3              ,
	NVIC_EXTI4              ,
	NVIC_DMA1_Channel1      ,
	NVIC_DMA1_Channel2      ,
	NVIC_DMA1_Channel3      ,
	NVIC_DMA1_Channel4      ,
	NVIC_DMA1_Channel5      ,
	NVIC_DMA1_Channel6      ,
	NVIC_DMA1_Channel7      ,
	NVIC_ADC1_2             ,
	NVIC_USB_HP_CAN_TX      ,
	NVIC_USB_LP_CAN_RX0     ,
	NVIC_CAN_RX1            ,
	NVIC_CAN_SCE            ,
	NVIC_EXTI9_5            ,
	NVIC_TIM1_BRK           ,
	NVIC_TIM1_UP            ,
	NVIC_TIM1_TRG_COM       ,
	NVIC_TIM1_CC            ,
	NVIC_TIM2               ,
	NVIC_TIM3               ,
	NVIC_TIM4               ,
	NVIC_I2C1_EV            ,// NO 31
	NVIC_I2C1_ER            ,
	NVIC_I2C2_EV            ,
	NVIC_I2C2_ER            ,
	NVIC_SPI1               ,
	NVIC_SPI2               ,
	NVIC_USART1             ,
	NVIC_USART2             ,
	NVIC_USART3             ,
	NVIC_EXTI15_10          ,
	NVIC_RTCAlarm           ,
	NVIC_USBWakeup          ,
	NVIC_TIM8_BRK           ,
	NVIC_TIM8_UP            ,
	NVIC_TIM8_TRG_COM       ,
	NVIC_TIM8_CC            ,
	NVIC_ADC3               ,
	NVIC_FSMC               ,
	NVIC_SDIO               ,
	NVIC_TIM5               ,
	NVIC_SPI3               ,
	NVIC_UART4              ,
	NVIC_UART5              ,
	NVIC_TIM6               ,
	NVIC_TIM7               ,
	NVIC_DMA2_Channel1      ,
	NVIC_DMA2_Channel2      ,
	NVIC_DMA2_Channel3      ,
	NVIC_DMA2_Channel4_5
}NVIC_enumPerirpheral_IQRN;
/****************************************************************************************************/

/*SCP_u32_AIRCR_REG Macros*/
#define SCP_u32_AIRCR_REG_PASSWORD                0x05FA0000


#define SCP_U32_PRIORITY_FIELD_2_GROUP_2_SUB      0x00000500
#define SCP_U32_PRIORITY_FIELD_3_GROUP_1_SUB      0x00000400
#define SCP_U32_PRIORITY_FIELD_4_GROUP_0_SUB      0x00000300
#define SCP_U32_PRIORITY_FIELD_0_GROUP_4_SUB      0x00000600



/************* NVIC APIS ****************/
u8 NVIC_u8EnableInterrupt(NVIC_enumPerirpheral_IQRN Copy_enumIRQN);
u8 NVIC_u8DisableInterrupt(NVIC_enumPerirpheral_IQRN Copy_enumIRQN);
u8 NVIC_u8SetPendingFlag(NVIC_enumPerirpheral_IQRN Copy_enumIRQN);
u8 NVIC_u8ClearPendingFlag(NVIC_enumPerirpheral_IQRN Copy_enumIRQN);
u8 NVIC_u8GetActiveFlag(NVIC_enumPerirpheral_IQRN Copy_enumIRQN, u8 * Copy_pu8ReturnedFlagState);
u8 NVIC_u8EnableXInterrupt(u8 Copy_u8NumberOfParam,...);
u8 NVIC_u8SetPriority(NVIC_enumPerirpheral_IQRN Copy_enumIRQN, u8 Copy_u8GroupPriority, u8 Copy_u8SubPriority);
u8 NVIC_u8InitPriorityField(void);
/****************************************/













#endif
