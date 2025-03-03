/**************************************************************/
/****************** Name	: MOHAMED ELSAYED *****************/
/****************** Date	: 20/9/2021       *****************/
/****************** Version : 1.0V            *****************/
/****************** SWC		: STK            *****************/
/**************************************************************/

/************************* INCLUDES ************************************/
/* LIB */
#include "STD_TYPES.h"
#include "BITMATH.h"
#include "stm32f103c8.h"

/* MACAL */
#include "STK_Interface.h"
#include "STK_Private.h"
#include "STK_Config.h"
/**********************************************************************/

static void (*STK_pfun)(void) =  NULL ;
static u8 STK_u8ModeOfInterval ;
static u8 STK_u8BussyFlag = STK_u8_FREE ;


u8 STK_u8Init(void)
{
	u8 Local_u8ErrorState = STD_TYPES_OK;
#if STK_u8CLK_SOURCE == STK_u8CLK_SOURCE_AHP
	STK->CTRL = STK_u8CLK_SOURCE_AHP;
#elif STK_u8CLK_SOURCE == STK_u8CLK_SOURCE_AHP_8
	STK->CTRL = STK_u8CLK_SOURCE_AHP_8;
#else
	Local_u8ErrorState = STD_TYPES_NOK;
#endif
	return Local_u8ErrorState;
}


u8 STK_u8SetBusyWait(u32 Copy_u32Ticks)
{
	u8 Local_u8ErrorState = STD_TYPES_OK;
	if (Copy_u32Ticks <= STK_u32RESOLUTION)
	{
		/*Set Tick TO LOAD REG */
		STK->LOAD = Copy_u32Ticks;

		/* Start Counting*/
		SET_BIT(STK->CTRL, 0);

		/* WAIT UNTILE FLAG */
		while ((GET_BIT(STK->CTRL, 16)) == 0)
		{
			asm("NOP");
		}
		/* Stop Counting*/
		CLEAR_BIT(STK->CTRL, 0);
		STK->LOAD = 0;
		STK->VAL = 0;


	}
	else Local_u8ErrorState = STD_TYPES_NOK;

	return Local_u8ErrorState;
}



u8 STK_u8SetIntervalSingle(u32 Copy_u32Ticks, void (*Copy_pfun)(void))
{
	u8 Local_u8ErrorState = STD_TYPES_OK;
	if ((Copy_u32Ticks <= STK_u32RESOLUTION) && (Copy_pfun != NULL) && (STK_u8BussyFlag != STK_u8_BUSSY))
	{
		/*Set Tick TO LOAD REG */
		STK->LOAD = Copy_u32Ticks;

		/* Start Counting*/
		SET_BIT(STK->CTRL, 0);

		/* Save Function and MOde*/
		STK_pfun = Copy_pfun;
        STK_u8ModeOfInterval =STK_u8_SINGLE_INTERVAL;

		/* EN Exception */
		SET_BIT(STK->CTRL, 1);




	}
	else Local_u8ErrorState = STD_TYPES_NOK;

	return Local_u8ErrorState;
}




u8 STK_u8SetIntervalPeriodic(u32 Copy_u32Ticks, void (*Copy_pfun)(void))
{
	u8 Local_u8ErrorState = STD_TYPES_OK;
	if ((Copy_u32Ticks <= STK_u32RESOLUTION) && (Copy_pfun != NULL) && (STK_u8BussyFlag != STK_u8_BUSSY))
	{
		/*Set Tick TO LOAD REG */
		STK->LOAD = (Copy_u32Ticks-1);

		/* Start Counting*/
		STK->CTRL |= 1;

		/* Save Function and MOde*/
		STK_pfun = Copy_pfun;
		STK_u8ModeOfInterval =STK_u8_PERIODIC_INTERVAL;

		/* EN Exception */
		SET_BIT(STK->CTRL, 1);




	}
	else Local_u8ErrorState = STD_TYPES_NOK;

	return Local_u8ErrorState;
}




u8 STK_u8StopTimer(void)
{
	u8 Local_u8ErrorState = STD_TYPES_OK;

	/* Stop Timer*/
	STK->CTRL |= 0;
	STK->LOAD = 0;
	STK->VAL = 0;
	/* DIS Exception */
	CLEAR_BIT(STK->CTRL, 1);

	return Local_u8ErrorState;
}



u8 STK_u8GetElapsedTime(u32* Copy_pu32ReturnedElapsedTime)
{
	u8 Local_u8ErrorState = STD_TYPES_OK;

	/* Read Elapsed Time*/
	*Copy_pu32ReturnedElapsedTime = ((STK->LOAD) - (STK->VAL));

	return Local_u8ErrorState;
}



u8 STK_u8GetRemainingTime(u32* Copy_pu32ReturnedRemainingTime)
{
	u8 Local_u8ErrorState = STD_TYPES_OK;

	/* Read Remaining Time*/
	*Copy_pu32ReturnedRemainingTime = STK->VAL;

	return Local_u8ErrorState;
}



u8 STK_u8ReadTimerFlag(u8* Copy_pu32ReturnedFlagValue)
{
	u8 Local_u8ErrorState = STD_TYPES_OK;

	/* Read Timer Flag*/
	*Copy_pu32ReturnedFlagValue = GET_BIT(STK->CTRL, 16);

	return Local_u8ErrorState;
}


/**************** Handler ********************/
void SysTick_Handler(void)
{
	//Set BUSSY FLAG
	STK_u8BussyFlag = STK_u8_BUSSY ;

	u8 Local_u8Cls;

	/* Single Interval*/
	if (STK_u8ModeOfInterval == STK_u8_SINGLE_INTERVAL)
	{
		/* DIS Exception */
		CLEAR_BIT(STK->CTRL, 1);
		/* Stop Counting*/
		STK->CTRL |= 0;
		STK->LOAD = 0;
		STK->VAL = 0;

	}

	/* Periodic Interval*/
	if (STK_pfun != NULL)
	{
		STK_pfun();
	}

	/* Clear Flag */
	Local_u8Cls = GET_BIT(STK->CTRL,16);

	/*Set Free Flag*/
	STK_u8BussyFlag = STK_u8_FREE;

}
