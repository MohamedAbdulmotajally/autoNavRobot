/**************************************************************/
/****************** Name	: MOHAMED ELSAYED *****************/
/****************** Date	: 27/5/2022       *****************/
/****************** Version : 1.0V            *****************/
/****************** SWC		: ADC1            *****************/
/**************************************************************/

/* LIB */
#include "STD_TYPES.h"
#include "BITMATH.h"
#include "stm32f103c8.h"




/*HAL*/
#include "ADC1_Interface.h"
#include "ADC1_Private.h"
#include "ADC1_Config.h"

/* GLOPAL VAR*/
static void (* Global_PFunTemp)(void) = NULL;
/*************/






/***************************************************************************************/
/* Description! Apply initialization sequence for ADC1                                 */
/* Input      ! Nothing                                                                */
/* Output     ! Nothing                                                                */
/***************************************************************************************/
void ADC1_voidInit(void)
{
	/*INIT CR1*/
	ADC1->CR1= ADC1_u8_CR1_REG_CONFIG;

	/*INIT CR2*/
	ADC1->CR2= ADC1_u8_CR2_REG_CONFIG;

    /* INIT SMPR1 */
	ADC1->SMPR1 = 0;
	ADC1->SMPR1 |= (ADC1_u8_SAMPLING_TIME_CH17 << 21);
	ADC1->SMPR1 |= (ADC1_u8_SAMPLING_TIME_CH16 << 18);
	ADC1->SMPR1 |= (ADC1_u8_SAMPLING_TIME_CH15 << 15);
	ADC1->SMPR1 |= (ADC1_u8_SAMPLING_TIME_CH14 << 12);
	ADC1->SMPR1 |= (ADC1_u8_SAMPLING_TIME_CH13 << 9);
	ADC1->SMPR1 |= (ADC1_u8_SAMPLING_TIME_CH12 << 6);
	ADC1->SMPR1 |= (ADC1_u8_SAMPLING_TIME_CH11 << 3);
	ADC1->SMPR1 |= (ADC1_u8_SAMPLING_TIME_CH10 << 0);

	/* INIT SMPR2 */
	ADC1->SMPR2 = 0;
	ADC1->SMPR2 |= (ADC1_u8_SAMPLING_TIME_CH9 << 27);
	ADC1->SMPR2 |= (ADC1_u8_SAMPLING_TIME_CH8 << 24);
	ADC1->SMPR2 |= (ADC1_u8_SAMPLING_TIME_CH7 << 21);
	ADC1->SMPR2 |= (ADC1_u8_SAMPLING_TIME_CH6 << 18);
	ADC1->SMPR2 |= (ADC1_u8_SAMPLING_TIME_CH5 << 15);
	ADC1->SMPR2 |= (ADC1_u8_SAMPLING_TIME_CH4 << 12);
	ADC1->SMPR2 |= (ADC1_u8_SAMPLING_TIME_CH3 << 9);
	ADC1->SMPR2 |= (ADC1_u8_SAMPLING_TIME_CH2 << 6);
	ADC1->SMPR2 |= (ADC1_u8_SAMPLING_TIME_CH1 << 3);
	ADC1->SMPR2 |= (ADC1_u8_SAMPLING_TIME_CH0 << 0);


	/*SET TOTAL NO OF CONV && INIT SQR1 */
	ADC1->SQR1 &= ~(0b1111<<20);
	ADC1->SQR1 |= (ADC1_u8_TOTAL_NO_OF_CONV<<20);
	ADC1->SQR1 |= ((ADC1_u8_16TH_CONV << 15) | (ADC1_u8_15TH_CONV << 10) | (ADC1_u8_14TH_CONV << 5) | (ADC1_u8_13TH_CONV));

	/* INIT SQR2 */
	ADC1->SQR2 |= ((ADC1_u8_12TH_CONV << 25) | (ADC1_u8_11TH_CONV << 20) | (ADC1_u8_10TH_CONV << 15) | (ADC1_u8_9TH_CONV << 10) | (ADC1_u8_8TH_CONV << 5) | (ADC1_u8_7TH_CONV) );

	/* INIT SQR3 */
	ADC1->SQR3 |= ((ADC1_u8_6TH_CONV << 25) | (ADC1_u8_5TH_CONV << 20) | (ADC1_u8_4TH_CONV << 15) | (ADC1_u8_3TH_CONV << 10) | (ADC1_u8_2TH_CONV << 5) | (ADC1_u8_1TH_CONV));

	/* CLEAR ALL FLAGS IN  SR  REG*/
	ADC1->SR = 0;
	
}


/***************************************************************************************/
/* Description! Interface TO  ENABLE ADC1                                              */
/* Input      ! Nothing                                                                */
/* Output     ! Nothing                                                                */
/***************************************************************************************/
void ADC1_u8Enable(void)
{
	ADC1->CR2 |= ADC1_u8_ADC_EN;
}


/***************************************************************************************/
/* Description! Interface TO  Disable ADC1                                             */
/* Input      ! Nothing                                                                */
/* Output     ! Nothing                                                                */
/***************************************************************************************/
void ADC1_u8Disable(void)
{
	ADC1->CR2 &= ~ADC1_u8_ADC_EN;
}

/***************************************************************************************/
/* Description! Interface TO  Disable ADC1 INTERRUPT                                   */
/* Input      ! Nothing                                                                */
/* Output     ! Nothing                                                                */
/***************************************************************************************/
void ADC1_u8InterruptDisaple(void)
{
	ADC1->CR1 &= ~ADC1_u8_EOC_INTERRUPT_EN;
}

/***************************************************************************************/
/* Description! Interface TO  ENABLE ADC1 INTERRUPT                                    */
/* Input      ! Nothing                                                                */
/* Output     ! Nothing                                                                */
/***************************************************************************************/
void ADC1_u8InterruptEnable(void)
{
	ADC1->CR1 |= ADC1_u8_EOC_INTERRUPT_EN;
}

/***************************************************************************************/
/* Description! Interface TO  Start Conversation                                       */
/* Input      ! Nothing                                                                */
/* Output     ! Nothing                                                                */
/***************************************************************************************/
void ADC1_u8StartConv(void)
{
	ADC1->CR2 |= ADC1_u8_SWSTART_START_CONVERSION;
}

/***************************************************************************************/
/* Description! Interface to get the result of conv  From ADC1                         */
/* Input      ! Pointer to variable that Receive The ADC result 		               */
/* Output     ! Error State                                                            */
/***************************************************************************************/
u8 ADC1_u8GetResult(u32 *Copy_ptr_u16DataRecived)
{
	u8 Local_u8ErrorState = STD_TYPES_OK;
	if (Copy_ptr_u16DataRecived != NULL) {
		/* Start Conversion */
		ADC1->CR2 |= ADC1_u8_SWSTART_START_CONVERSION;

		/* Wait untill end of Conv And Flag Rising */
		while (GET_BIT(ADC1->SR, ADC1_u8_EOC_FLAG) == 0) { asm("NOP"); }

		/* Read DR REG  Note that the flag is cleared by reading DR REG*/
		*Copy_ptr_u16DataRecived = ADC1->DR;
	}
	else{ Local_u8ErrorState = STD_TYPES_NOK; }
	return Local_u8ErrorState;
	
}

/***************************************************************************************/
/* Description! Interface to  Set ADC CALLBACK FUN                                     */
/* Input      ! Pointer to fun   											           */
/* Output     ! Error State                                                            */
/***************************************************************************************/
u8 ADC1_u8SetCallBackFun(void (*Copy_pfunCallBackFun) (void))
{
	u8 Local_u8ErrorState = STD_TYPES_OK;
	if (Copy_pfunCallBackFun != NULL)
	{
		/* Save FeedBack */
		Global_PFunTemp = Copy_pfunCallBackFun;
	}
	else { Local_u8ErrorState = STD_TYPES_NOK; }
	return Local_u8ErrorState;
}


/***************************** ADC IRQ *************************************************/
/***************************************************************************************/
ADC1_2_IRQHandler(void)
{
	if (Global_PFunTemp != NULL)
	{
		Global_PFunTemp();
	}
}
