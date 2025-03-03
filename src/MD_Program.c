/*********************************************************************************
 * @file      cda.h
 * @author    Mohamed Elsayed Abdel-Motagally <mohamed.abedlmutajally@gmail.com>
 * @version   v1.0
 * @date      15-March-2023
 * @breif     Src code of the motor driver module
 *
 * which will contain a collection of facilities to assist us
 * in controlling motors via motor driver CIT.
 * This contains the implementation of  the MD module.
 * @bugs      No bugs known
 ********************************************************************************/

/*********************************************************************************
 * @attention
 *
 * Copyright (c) 2023 QS Academi.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
**********************************************************************************/

/* LIB */
#include "STD_TYPES.h"
#include "BITMATH.h"



/*MCAL*/
#include "GPIO_Interface.h"
#include "STK_Interface.h"


/*HAL*/
#include "MD_Interface.h"
#include "MD_Private.h"
#include "MD_Config.h"
#include "TIMER2.h"


/************************************************* INIT MD PINS ******************************************/
/*
  -----------                   ----------
 | STM_32F1  |                 |   MD     |
 |           |                 |          |
 |       PB12|---------------->|IN0       |
 |       PB13|---------------->|IN1       |
 |       PB14|---------------->|IN2       |
 |       PB15|---------------->|IN3       |
 |           |                 |          |
  -----------                   ----------
 */

GPIO_PinConfig_t Motor_IN0_strConfig = { MD_u8_IN0_PIN,GPIO_u8OUTPUT_PUSH_PULL_SPEED_10MHZ };
GPIO_PinConfig_t Motor_IN1_strConfig = { MD_u8_IN1_PIN,GPIO_u8OUTPUT_PUSH_PULL_SPEED_10MHZ };
GPIO_PinConfig_t Motor_IN2_strConfig = { MD_u8_IN2_PIN,GPIO_u8OUTPUT_PUSH_PULL_SPEED_10MHZ };
GPIO_PinConfig_t Motor_IN3_strConfig = { MD_u8_IN3_PIN,GPIO_u8OUTPUT_PUSH_PULL_SPEED_10MHZ };
/***********************************************************************************************************/












/***************************************************************************************/
/* Description! Apply initialization sequence for Motor Driver Pins                    */
/* Input      ! Nothing                                                                */
/* Output     ! Error State                                                            */
/***************************************************************************************/
u8 MD_u8PinInit(void)
{
	u8 Local_u8ErrorState = STD_TYPES_OK;
	if (Motor_IN0_strConfig && Motor_IN1_strConfig && Motor_IN2_strConfig && Motor_IN3_strConfig)
	{
		GPIO_u8PinInit(&Motor_IN0_strConfig);
		GPIO_u8PinInit(&Motor_IN1_strConfig);
		GPIO_u8PinInit(&Motor_IN2_strConfig);
		GPIO_u8PinInit(&Motor_IN3_strConfig);
	}
	else Local_u8ErrorState = STD_TYPES_NOK;
	
	return Local_u8ErrorState;
}





/***************************************************************************************/
/* Description! Apply motion													       */
/* Input      ! Direction && Duty Cycle                                                */
/* Output     ! Error State                                                            */
/***************************************************************************************/
u8 MD_u8Move(MD_enumDirection Copy_enumDirection,u8 Copy_u8DutyCycle_L,u8 Copy_u8DutyCycle_R)
{
	u8 Local_u8ErrorState = STD_TYPES_OK;

	if ((Copy_enumDirection <= MD_MOVE_BACK) && (Copy_u8DutyCycle_R <= MD_MAX_DUTTY_CYCLE) && (Copy_u8DutyCycle_L <= MD_MAX_DUTTY_CYCLE))
	{
		
		GPIO_u8SetPinValue(&Motor_IN0_strConfig, GET_BIT(Copy_enumDirection, BIT0));
		GPIO_u8SetPinValue(&Motor_IN1_strConfig, GET_BIT(Copy_enumDirection, BIT1));
		GPIO_u8SetPinValue(&Motor_IN2_strConfig, GET_BIT(Copy_enumDirection, BIT2));
		GPIO_u8SetPinValue(&Motor_IN3_strConfig, GET_BIT(Copy_enumDirection, BIT3));

		/*SET Duty Cycle*/
		TIM4_u8SetDuttyCycle(Copy_u8DutyCycle_L);
		TIM3_u8SetDuttyCycle(Copy_u8DutyCycle_R);
	}
	else Local_u8ErrorState = STD_TYPES_NOK;
	return Local_u8ErrorState;
}
