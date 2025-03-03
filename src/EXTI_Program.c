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
#include "EXTI_Interface.h"
#include "EXTI_Private.h"
#include "EXTI_Config.h"
/**********************************************************************/

static void (* EXTI_APFun[16])(void)={NULL};


u8 EXTI_u8Init(const EXTI_Cofig_t * Copy_pstrInit)
{
	u8 Local_u8ErrorState = STD_TYPES_OK;
	/* Check 1- IF Copy_pfunCallBackFun EQUAL NULL   2- PORT && PIN WITHIN THE RANGE */
	if((Copy_pstrInit->Copy_pfunCallBackFun != NULL) && (Copy_pstrInit->PortId <= EXTI_PORTC) && (Copy_pstrInit->PinId <= EXTI_PIN15))
	{
		/* Create Local Variables To Select LINE */

		u8 Local_u8Index =  ((int)(Copy_pstrInit->LineId)/ 4);
		u8 Local_u8ShiftValue =  ((int)(Copy_pstrInit->LineId)/ 4);

		/* Clear the source INT bit range in AF */
		AFIO->EXTICR[Local_u8Index] &= ~((0b1111) << (Local_u8ShiftValue * 4));

		/* SET the source INT */
		AFIO->EXTICR[Local_u8Index] |= ((Copy_pstrInit->PortId) << (Local_u8ShiftValue * 4));

		/* SEL SENSE MODE: 1-FALLING  2-RISING 3-ONCHANGE */
		switch(Copy_pstrInit->TriggerLevel)
		{
		case EXTI_RISING_EDGE:
		{
			/* Clear Other Trigger*/
			CLEAR_BIT(EXTI->FTSR,Copy_pstrInit->LineId);
			/* Set Trigger Mode*/
			SET_BIT(EXTI->RTSR,Copy_pstrInit->LineId);
		}
		break;
		case EXTI_FALLING_EDGE:
		{
			/* Clear Other Trigger*/
			CLEAR_BIT(EXTI->RTSR,Copy_pstrInit->LineId);
			/* Set Trigger Mode*/
			SET_BIT(EXTI->FTSR,Copy_pstrInit->LineId);
		}
		break;
		case EXTI_ON_CHANGE:
		{
			/* Set Trigger Mode*/
			SET_BIT(EXTI->RTSR,Copy_pstrInit->LineId);
			SET_BIT(EXTI->FTSR,Copy_pstrInit->LineId);
		}
		break;
		/* Default value is ON change Mode*/
		default :
		{
			/* Set Trigger Mode*/
			SET_BIT(EXTI->RTSR,Copy_pstrInit->LineId);
			SET_BIT(EXTI->FTSR,Copy_pstrInit->LineId);
		}
		break;
		}

		/* Set CallBack fun*/
		EXTI_APFun[Copy_pstrInit->LineId]=Copy_pstrInit->Copy_pfunCallBackFun;
	}
	else Local_u8ErrorState = STD_TYPES_NOK;

	return Local_u8ErrorState;
}


u8 EXTI_u8IntEnable(const EXTI_Cofig_t * Copy_pstrInit)
{
	u8 Local_u8ErrorState = STD_TYPES_OK;
	/* CHEECK 1- IF Copy_pfunCallBackFun EQUAL NULL   2- PORT && PIN WITHIN THE RANGE */
	if((Copy_pstrInit->Copy_pfunCallBackFun != NULL) && (Copy_pstrInit->PortId <= EXTI_PORTC) && (Copy_pstrInit->PinId <= EXTI_PIN15))
	{
		SET_BIT(EXTI->IMR,Copy_pstrInit->LineId);
	}
	else Local_u8ErrorState = STD_TYPES_NOK;

	return Local_u8ErrorState;
}

u8 EXTI_u8IntDisable(const EXTI_Cofig_t * Copy_pstrInit)
{
	u8 Local_u8ErrorState = STD_TYPES_OK;
	/* CHEECK 1- IF Copy_pfunCallBackFun EQUAL NULL   2- PORT && PIN WITHIN THE RANGE */
	if((Copy_pstrInit->Copy_pfunCallBackFun != NULL) && (Copy_pstrInit->PortId <= EXTI_PORTC) && (Copy_pstrInit->PinId <= EXTI_PIN15))
	{
		CLEAR_BIT(EXTI->IMR,Copy_pstrInit->LineId);
	}
	else Local_u8ErrorState = STD_TYPES_NOK;

	return Local_u8ErrorState;
}


u8 EXTI_u8SoftWareTrigger(const EXTI_Cofig_t * Copy_pstrInit)
{
	u8 Local_u8ErrorState = STD_TYPES_OK;
	/* CHEECK 1- IF Copy_pfunCallBackFun EQUAL NULL   2- PORT && PIN WITHIN THE RANGE */
	if((Copy_pstrInit->Copy_pfunCallBackFun != NULL) && (Copy_pstrInit->PortId <= EXTI_PORTC) && (Copy_pstrInit->PinId <= EXTI_PIN15))
	{
		/* EN Interrupt Line */
		SET_BIT(EXTI->IMR, Copy_pstrInit->LineId);
		/* Clear Pending Flag */
		SET_BIT(EXTI->PR, Copy_pstrInit->LineId);
		/* Create SWE */
		SET_BIT(EXTI->SWIER, Copy_pstrInit->LineId);
	}
	else Local_u8ErrorState = STD_TYPES_NOK;

	return Local_u8ErrorState;
}





u8 EXTI_u8SetCallBack(const EXTI_Cofig_t * Copy_pstrInit)
{
	u8 Local_u8ErrorState = STD_TYPES_OK;
	/* CHEECK 1- IF Copy_pfunCallBackFun EQUAL NULL   2- PORT && PIN WITHIN THE RANGE */
	if((Copy_pstrInit->Copy_pfunCallBackFun != NULL) && (Copy_pstrInit->PortId <= EXTI_PORTC) && (Copy_pstrInit->PinId <= EXTI_PIN15))
	{
		EXTI_APFun[Copy_pstrInit->LineId]=Copy_pstrInit->Copy_pfunCallBackFun;
	}
	else Local_u8ErrorState = STD_TYPES_NOK;

	return Local_u8ErrorState;
}


/********************************************** IRQ *******************************************************/
EXTI0_IRQHandler(void)
{
	if (EXTI_APFun[EXTI_LINE0] != NULL)
	{
       EXTI_APFun[EXTI_LINE0]();
	}
	/* Clear Pending Flag*/
	SET_BIT(EXTI->PR,EXTI_LINE0);
}

EXTI1_IRQHandler(void)
{
	if (EXTI_APFun[EXTI_LINE1] != NULL)
	{
       EXTI_APFun[EXTI_LINE1]();
	}
	/* Clear Pending Flag*/
	SET_BIT(EXTI->PR,EXTI_LINE1);
}

EXTI2_IRQHandler(void)
{
	if (EXTI_APFun[EXTI_LINE2] != NULL)
	{
       EXTI_APFun[EXTI_LINE2]();
	}
	/* Clear Pending Flag*/
	SET_BIT(EXTI->PR,EXTI_LINE2);
}

EXTI3_IRQHandler(void)
{
	if (EXTI_APFun[EXTI_LINE3] != NULL)
	{
       EXTI_APFun[EXTI_LINE3]();
	}
	/* Clear Pending Flag*/
	SET_BIT(EXTI->PR,EXTI_LINE3);
}

EXTI4_IRQHandler(void)
{
	if (EXTI_APFun[EXTI_LINE4] != NULL)
	{
       EXTI_APFun[EXTI_LINE4]();
	}
	/* Clear Pending Flag*/
	SET_BIT(EXTI->PR,EXTI_LINE4);
}

EXTI9_5_IRQHandler(void)
{
	if (EXTI_APFun[EXTI_LINE5] != NULL)
	{
		EXTI_APFun[EXTI_LINE5]();
		/* Clear Pending Flag*/
		SET_BIT(EXTI->PR,EXTI_LINE5);
	}

	if (EXTI_APFun[EXTI_LINE6] != NULL)
	{
		EXTI_APFun[EXTI_LINE6]();
		/* Clear Pending Flag*/
		SET_BIT(EXTI->PR,EXTI_LINE6);
	}

	if (EXTI_APFun[EXTI_LINE7] != NULL)
	{
		EXTI_APFun[EXTI_LINE7]();
		/* Clear Pending Flag*/
		SET_BIT(EXTI->PR,EXTI_LINE7);
	}

	if (EXTI_APFun[EXTI_LINE8] != NULL)
	{
		EXTI_APFun[EXTI_LINE8]();
		/* Clear Pending Flag*/
		SET_BIT(EXTI->PR,EXTI_LINE8);
	}
	if (EXTI_APFun[EXTI_LINE9] != NULL)
	{
		EXTI_APFun[EXTI_LINE9]();
		/* Clear Pending Flag*/
		SET_BIT(EXTI->PR,EXTI_LINE9);
	}
}


EXTI15_10_IRQHandler(void)
{
	if (EXTI_APFun[EXTI_LINE10] != NULL)
	{
		EXTI_APFun[EXTI_LINE10]();
		/* Clear Pending Flag*/
		SET_BIT(EXTI->PR,EXTI_LINE10);
	}

	if (EXTI_APFun[EXTI_LINE11] != NULL)
	{
		EXTI_APFun[EXTI_LINE11]();
		/* Clear Pending Flag*/
		SET_BIT(EXTI->PR,EXTI_LINE11);
	}

	if (EXTI_APFun[EXTI_LINE12] != NULL)
	{
		EXTI_APFun[EXTI_LINE12]();
		/* Clear Pending Flag*/
		SET_BIT(EXTI->PR,EXTI_LINE12);
	}

	if (EXTI_APFun[EXTI_LINE13] != NULL)
	{
		EXTI_APFun[EXTI_LINE13]();
		/* Clear Pending Flag*/
		SET_BIT(EXTI->PR,EXTI_LINE13);
	}
	if (EXTI_APFun[EXTI_LINE14] != NULL)
	{
		EXTI_APFun[EXTI_LINE14]();
		/* Clear Pending Flag*/
		SET_BIT(EXTI->PR,EXTI_LINE14);
	}
	if (EXTI_APFun[EXTI_LINE15] != NULL)
	{
		EXTI_APFun[EXTI_LINE15]();
		/* Clear Pending Flag*/
		SET_BIT(EXTI->PR,EXTI_LINE15);
	}
}
/**********************************************************************************************************/

