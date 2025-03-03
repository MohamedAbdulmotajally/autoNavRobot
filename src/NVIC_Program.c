/**************************************************************/
/****************** Name	: MOHAMED ELSAYED *****************/
/****************** Date	: 20/9/2021       *****************/
/****************** Version : 1.0V            *****************/
/****************** SWC		: NVIC            *****************/
/**************************************************************/


/* LIB */
#include "STD_TYPES.h"
#include "BITMATH.h"
#include "stm32f103c8.h"

/* MACAL */
#include "NVIC_Interface.h"
#include "NVIC_Private.h"
#include "NVIC_Config.h"






u8 NVIC_u8EnableInterrupt(NVIC_enumPerirpheral_IQRN Copy_enumIRQN)
{
	u8 Local_u8ErrorState=STD_TYPES_OK;
	/* CHECK IF IQRN WITHIN THE RANGE*/
	if (Copy_enumIRQN <= NVIC_DMA2_Channel4_5)
	{
		u8 Local_u8RegIndexNumber = (Copy_enumIRQN/32);
		u8 Local_u8IQRNumber = (Copy_enumIRQN % 32);
		/* CHOOSE REG[7:0] */
		NVIC->ISER[Local_u8RegIndexNumber] = (1<<Local_u8IQRNumber);
	}
	else Local_u8ErrorState = STD_TYPES_NOK;

	return Local_u8ErrorState;
}





u8 NVIC_u8DisableInterrupt(NVIC_enumPerirpheral_IQRN Copy_enumIRQN)
{
	u8 Local_u8ErrorState=STD_TYPES_OK;
	/* CHECK IF IQRN WITHIN THE RANGE*/
	if (Copy_enumIRQN <= NVIC_DMA2_Channel4_5)
	{
		u8 Local_u8RegIndexNumber = (Copy_enumIRQN/32);
		u8 Local_u8IQRNumber = (Copy_enumIRQN % 32);
		/* CHOOSE REG[7:0] */
		NVIC->ICER[Local_u8RegIndexNumber] = (1<<Local_u8IQRNumber);
	}
	else Local_u8ErrorState = STD_TYPES_NOK;

	return Local_u8ErrorState;
}







u8 NVIC_u8SetPendingFlag(NVIC_enumPerirpheral_IQRN Copy_enumIRQN)
{
	u8 Local_u8ErrorState=STD_TYPES_OK;
	/* CHECK IF IQRN WITHIN THE RANGE*/
	if (Copy_enumIRQN <= NVIC_DMA2_Channel4_5)
	{
		u8 Local_u8RegIndexNumber = (Copy_enumIRQN/32);
		u8 Local_u8IQRNumber = (Copy_enumIRQN % 32);
		/* CHOOSE REG[7:0] */
	    NVIC->ISPR[Local_u8RegIndexNumber] = (1<<Local_u8IQRNumber);
	}
	else Local_u8ErrorState = STD_TYPES_NOK;

	return Local_u8ErrorState;
}









u8 NVIC_u8ClearPendingFlag(NVIC_enumPerirpheral_IQRN Copy_enumIRQN)
{
	u8 Local_u8ErrorState=STD_TYPES_OK;
	/* CHECK IF IQRN WITHIN THE RANGE*/
	if (Copy_enumIRQN <= NVIC_DMA2_Channel4_5)
	{
		u8 Local_u8RegIndexNumber = (Copy_enumIRQN/32);
		u8 Local_u8IQRNumber = (Copy_enumIRQN % 32);
		/* CHOOSE REG[7:0] */
		NVIC->ICPR[Local_u8RegIndexNumber] = (1<<Local_u8IQRNumber);
	}
	else Local_u8ErrorState = STD_TYPES_NOK;

	return Local_u8ErrorState;
}












u8 NVIC_u8GetActiveFlag(NVIC_enumPerirpheral_IQRN Copy_enumIRQN, u8 * Copy_pu8ReturnedFlagState)
{
	u8 Local_u8ErrorState=STD_TYPES_OK;
	/* CHECK IF IQRN WITHIN THE RANGE*/
	if (Copy_enumIRQN <= NVIC_DMA2_Channel4_5)
	{
		u8 Local_u8RegIndexNumber = (Copy_enumIRQN/32);
		u8 Local_u8IQRNumber = (Copy_enumIRQN % 32);
		/* CHOOSE REG[7:0] */
		*Copy_pu8ReturnedFlagState = GET_BIT( (NVIC->IABR[Local_u8RegIndexNumber]) ,Local_u8IQRNumber);
	}
	else Local_u8ErrorState = STD_TYPES_NOK;

	return Local_u8ErrorState;
}











u8 NVIC_u8EnableXInterrupt(u8 Copy_u8NumberOfParam,...)
{
	u8 Local_u8ErrorState=STD_TYPES_OK;
	u8 Local_u8Counter;
	u32 Local_u32CopyIQRN_va_list;

	//Take Object of VA_list
	va_list IQRN_va_list;
	va_start(IQRN_va_list,Copy_u8NumberOfParam);

	//loop ON Parameter
	for(Local_u8Counter=0;Local_u8Counter<=Copy_u8NumberOfParam;Local_u8Counter++)
	{
		//take copy of va_list
		Local_u32CopyIQRN_va_list=va_arg(IQRN_va_list,u32);

		/* CHECK IF IQRN WITHIN THE RANGE*/
		if (Local_u32CopyIQRN_va_list <= NVIC_DMA2_Channel4_5)
		{
			u32 Local_u8RegIndexNumber = (Local_u32CopyIQRN_va_list/32);
			u32 Local_u8IQRNumber = (Local_u32CopyIQRN_va_list % 32);
			/* CHOOSE REG[7:0] */
			NVIC->ISER[Local_u8RegIndexNumber] = (1 << (Local_u8IQRNumber));
		}
		else Local_u8ErrorState = STD_TYPES_NOK;
	}


    va_end(IQRN_va_list);
	return Local_u8ErrorState;
}














u8 NVIC_u8SetPriority(NVIC_enumPerirpheral_IQRN Copy_enumIRQN, u8 Copy_u8GroupPriority, u8 Copy_u8SubPriority)
{
	u8 Local_u8ErrorState=STD_TYPES_OK;

	/* CHECK IF IQRN WITHIN THE RANGE*/
	if (Copy_enumIRQN <= NVIC_DMA2_Channel4_5)
	{
		/* CHECK IF Group Priority AND SubPriority Number  WITHIN THE RANGE*/
		if ((Copy_u8GroupPriority <= NVIC_u8NO_OF_GROUP) && (Copy_u8SubPriority <= NVIC_u8NO_OF_SUB))
		{
            /* Set IPR register foe specific IRQN*/
			NVIC->IPR[Copy_enumIRQN] = ( ( (Copy_u8GroupPriority << NVIC_u8REG_GROUP_SHIFT) | Copy_u8SubPriority ) << 4 );
		}
		else Local_u8ErrorState = STD_TYPES_NOK;
	}
	else Local_u8ErrorState = STD_TYPES_NOK;

	return Local_u8ErrorState;
}












u8 NVIC_u8InitPriorityField(void)
{
	u8 Local_u8ErrorState=STD_TYPES_OK;
	/* 2bits G 2bits S 8*/
	SCP_u32_AIRCR_REG = (SCP_u32_AIRCR_REG_PASSWORD | NVIC_SCP_U32_PRIORITY_FIELD);

	return Local_u8ErrorState;
}
