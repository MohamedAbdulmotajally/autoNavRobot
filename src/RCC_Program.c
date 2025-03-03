/********************  INCLUDES  **************************/
// LIB
#include "STD_TYPES.h"
#include "BITMATH.h"
#include "stm32f103c8.h"

//RCC INCLUDES
#include "RCC_Interface.h"
#include "RCC_Private.h"
#include "RCC_Config.h"

/**********************************************************/

u8 RCC_u8InitSysClk(void)
{
	u8 Local_u8ErrorState = STD_TYPES_OK;
	u16 Local_u8TimeOut = 0;

	//Clear System Clock Bits
	RCC->CFGR &= ~(0b11);

	if (RCC_SYSTEM_CLK == RCC_PLL_CLK)
	{
		// Clear PLL MUL Factor BITS
		RCC->CFGR &= ~(0b1111 << 18);

		//Configure  System clock
		RCC->CFGR |= RCC_PLL_CLK_SOURCE | RCC_SYSTEM_CLK | RCC_PLL_MUL_FACTOR;

		// Enable PLL CLK
		SET_BIT(RCC->CR, RCC_PLLON_BIT);

		// check PLL Ready flag
		while (GET_BIT(RCC->CR, RCC_PLLRDY_BIT) == 0)
		{
			Local_u8TimeOut++;
			if (Local_u8TimeOut >= 1000)
			{
				Local_u8ErrorState = STD_TYPES_NOK;
				break;
			}
		}
	}

	else if (RCC_SYSTEM_CLK == RCC_HSE_CLK)
	{
		//Configure  System clock
		RCC->CFGR |= RCC_SYSTEM_CLK;

		//active BYP BIn
		SET_BIT(RCC->CR, RCC_HSEBYP_BIT);

		//Enable HSE CLK
		SET_BIT(RCC->CR, RCC_HSEON_BIT);

		// check HSE Ready flag
		while (GET_BIT(RCC->CR, RCC_HSERDY_BIT) == 0)
		{
			Local_u8TimeOut++;
			if (Local_u8TimeOut >= 1000)
			{
				Local_u8ErrorState = STD_TYPES_NOK;
				break;
			}
		}

	}

	else if (RCC_SYSTEM_CLK == RCC_HSI_CLK)
	{
		//Configure  System clock
		RCC->CFGR |= RCC_SYSTEM_CLK;

		// Enable HSI CLK
		SET_BIT(RCC->CR, RCC_HSION_BIT);

		// check HSI Ready flag
		while (GET_BIT(RCC->CR, RCC_HSIRDY_BIT) == 0)
		{
			Local_u8TimeOut++;
			if (Local_u8TimeOut >= 1000)
			{
				Local_u8ErrorState = STD_TYPES_NOK;
				break;
			}
		}
	}

	else Local_u8ErrorState = STD_TYPES_NOK;



	/************** PRESCALLER COIG *************/
	//clear PRE BITS
	RCC->CFGR &= ~(0b1111111111 << 4);
	//Configure PRE
	RCC->CFGR |= RCC_ADC_PRESCALER | RCC_APB2_PRESCALER | RCC_APB1_PRESCALER | RCC_AHP_PRESCALER;
	/**********************************************/

	/************** MC clock output MCO CONFIG *************/
		//clear MCO BITS
	RCC->CFGR &= ~(0b1111 << 24);
	//Configure MCO
	RCC->CFGR |= RCC_MCO_CLK_OUTPUT;
	/*******************************************************/


	return Local_u8ErrorState;
}





u8 RCC_u8EnablePeripheralClk(RCC_enumBUS Copy_u8BusId, RCC_enumPERIPHERAL Copy_PeripheralId)
{
	u8 Local_u8ErrorState = STD_TYPES_OK;

	if (Copy_PeripheralId < 32)
	{
		switch (Copy_u8BusId)
		{
		case RCC_AHP_BUS:
			SET_BIT(RCC->AHBENR, Copy_PeripheralId);
			break;
		case RCC_APB1_BUS:
			SET_BIT(RCC->APB1ENR, Copy_PeripheralId);
			break;
		case RCC_APB2_BUS:
			SET_BIT(RCC->APB2ENR, Copy_PeripheralId);
			break;
		default:
			Local_u8ErrorState = STD_TYPES_NOK;
		}
	}
	else Local_u8ErrorState = STD_TYPES_NOK;

	return Local_u8ErrorState;
}

u8 RCC_u8DisablePeripheralClk(RCC_enumBUS Copy_u8BusId, RCC_enumPERIPHERAL Copy_PeripheralId)
{
	u8 Local_u8ErrorState = STD_TYPES_OK;

	if (Copy_PeripheralId < 32)
	{
		switch (Copy_u8BusId)
		{
		case RCC_AHP_BUS: CLEAR_BIT(RCC->AHBENR, Copy_PeripheralId); break;
		case RCC_APB1_BUS: CLEAR_BIT(RCC->APB1ENR, Copy_PeripheralId); break;
		case RCC_APB2_BUS: CLEAR_BIT(RCC->APB2ENR, Copy_PeripheralId); break;
		default:Local_u8ErrorState = STD_TYPES_NOK; break;
		}
	}
	else Local_u8ErrorState = STD_TYPES_NOK;

	return Local_u8ErrorState;
}
