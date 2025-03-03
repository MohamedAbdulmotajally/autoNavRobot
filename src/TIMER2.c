/**************************************************************/
/****************** Name	: MOHAMED ELSAYED *****************/
/****************** Date	: 20/9/2021       *****************/
/****************** Version : 1.0V            *****************/
/****************** SWC		: EXTI            *****************/
/**************************************************************/

/************************* INCLUDES ************************************/
/* LIB */
#include "STD_TYPES.h"
#include "BITMATH.h"
#include "stm32f103c8.h"

/* MACAL */
#include "TIMER2.h"


/******************** Global Variable *********************************/
void (*Copy_Timer2pfun)(void);
/**********************************************************************/



/***************************************************************************************/
/********************************** Function Definition ********************************/
/***************************************************************************************/

/***************************************************************************************/
/* Description! Apply initialization sequence for TIM4                                 */
/* Input      ! Nothing                                                                */
/* Output     ! Nothing                                                                */
/***************************************************************************************/
void TIM4_voidInit()
{

	// Set Auto reload value
	TIM4->ARR = 100;

	// Set Prescalar value
	TIM4->PSC = 1;


	/* Output Compare Mode, ENABLE Preload,PWM  mode:1   Channel 2*/
	TIM4->CCMR1  = 0x00007800;
	CLEAR_BIT(TIM4->CCMR1 ,12);



	// ENABLE update generation
	SET_BIT(TIM4->EGR,0);

	/*CC2E : channel 2 enabled; polarity : active high*/
	TIM4->CCER = 0x00000010;

	//autoPreload EN
	TIM4->CR1 |= 0b10000000;

	// ENABLE Timer counter
	TIM4->CR1 |= 1;
}


/***************************************************************************************/
/* Description! Set PWM for TIM4                                                       */
/* Input      ! PWM value                                                              */
/* Output     ! Error State                                                            */
/***************************************************************************************/
u8 TIM4_u8SetDuttyCycle(u8 Copy_u8DuttyCycle)
{
	u8 Local_u8ErrorState=STD_TYPES_OK;
	if ((Copy_u8DuttyCycle >= 0) && (Copy_u8DuttyCycle < 255))
	{
		/*SET Duty Cycle*/
		TIM4->CCR2=Copy_u8DuttyCycle;
	}
	else Local_u8ErrorState=STD_TYPES_NOK;
	return Local_u8ErrorState;

}

/***************************************************************************************/
/* Description! Apply initialization sequence for TIM3                                 */
/* Input      ! Nothing                                                                */
/* Output     ! Nothing                                                                */
/***************************************************************************************/
void TIM3_voidInit()
{

	// Set Auto reload value
	TIM3->ARR = 100;

	// Set Prescalar value
	TIM3->PSC = 1;


	/* Output Compare Mode, ENABLE Preload,PWM  mode:1   Channel 2*/
	TIM3->CCMR1  = 0x00007800;
	CLEAR_BIT(TIM3->CCMR1 ,12);



	// ENABLE update generation
	SET_BIT(TIM3->EGR,0);

	/*CC2E : channel 3 enabled; polarity : active high*/
	TIM3->CCER = 0x00000001;

	//autoPreload EN
	TIM3->CR1 |= 0b10000000;

	// ENABLE Timer counter
	TIM3->CR1 |= 1;
}

/***************************************************************************************/
/* Description! Set PWM for TIM3                                                       */
/* Input      ! PWM value                                                              */
/* Output     ! Error State                                                            */
/***************************************************************************************/
u8 TIM3_u8SetDuttyCycle(u8 Copy_u8DuttyCycle)
{
	u8 Local_u8ErrorState=STD_TYPES_OK;
	if ((Copy_u8DuttyCycle >= 0) && (Copy_u8DuttyCycle < 255))
	{
		/*SET Duty Cycle*/
		TIM3->CCR1=Copy_u8DuttyCycle;
	}
	else Local_u8ErrorState=STD_TYPES_NOK;
	return Local_u8ErrorState;

}


/***************************************************************************************/
/* Description! Set Interval Periodic For TIM2                                         */
/* Input      ! Interval Value                                                         */
/* Output     ! Error State                                                            */
/***************************************************************************************/
u8 TIM2_u8SetIntervalPeriodic(u32 Copy_u32Ticks, void (*Copy_pfun)(void))
{
	u8 Local_u8ErrorState = STD_TYPES_OK;
	if ((Copy_u32Ticks <= 655340) && (Copy_pfun != NULL) )
	{
		/*Set Tick TO LOAD REG */
		TIM2->ARR = (Copy_u32Ticks-1);

		// Set Prescalar value
		TIM2->PSC = 8;
		/*


		// ENABLE update generation
		SET_BIT(TIM4->EGR,0);

		//autoPreload EN
		TIM2->CR1 |= 0b10010000;
		 */

		// ENABLE Timer counter
		TIM2->CR1 |= 0b00010001;

		/* Save Function and MOde*/
		Copy_Timer2pfun = Copy_pfun;

		/* EN Exception8*/
		TIM2->DIER |= 0b00000001;

	}
	else Local_u8ErrorState = STD_TYPES_NOK;

	return Local_u8ErrorState;
}






TIM2_IRQHandler(void)
{
	Copy_Timer2pfun();
	TIM2->SR = 0;	/* cancel the interrupt */
}
