/**************************************************************/
/****************** Name	: MOHAMED ELSAYED *****************/
/****************** Date	: 18/9/2021       *****************/
/****************** Version : 1.0V            *****************/
/****************** SWC		: GPIO             *****************/
/**************************************************************/

/* LIB */
#include "STD_TYPES.h"
#include "BITMATH.h"
#include "stm32f103c8.h"

/*MCAL*/
#include "GPIO_Interface.h"
#include "GPIO_Private.h"
#include "GPIO_Config.h"

static GPIO_RegDef_t * GPIO_APtrStr[3]={GPIOA,GPIOB,GPIOC};

u8 GPIO_u8PinInit(const GPIO_PinConfig_t * Copy_pstrPinConfig)
{
	u8 Local_u8ErorrState=STD_TYPES_OK;
	u8 Local_u8PinMode;
	if(Copy_pstrPinConfig != NULL)
	{
		//Initialize LocalPinMode VAR
		Local_u8PinMode = Copy_pstrPinConfig->PinMode;
		//CHECK PORT AND PIN WITHIN THE RING
		if ((Copy_pstrPinConfig->PortId <= GPIO_PORTC) && (Copy_pstrPinConfig->PinId <= GPIO_PIN15))
		{
			//CHEECK PIN MODE IS PULL UP
			if (Copy_pstrPinConfig->PinMode == GPIO_u8INPUT_PULL_UP)
			{
				//SET ODR VALUE WITH 1
				GPIO_APtrStr[Copy_pstrPinConfig->PortId]->ODR |= (1 << Copy_pstrPinConfig->PinId);
				//MOdify The Value OF PULL UP MACRO
				Local_u8PinMode &= ~(1 << 4);

			}
			//CHEECK PIN MODE IS PULL DOWN
			else if(Copy_pstrPinConfig->PinMode == GPIO_u8INPUT_PULL_DOWN)
			{
				//SET ODR WITH VALUE 0
				GPIO_APtrStr[Copy_pstrPinConfig->PortId]->ODR &= ~(1 << Copy_pstrPinConfig->PinId);
			}
			//CHEEK IF PIN IS IN CRH OR CRL
			if (Copy_pstrPinConfig->PinId <= GPIO_PIN7)//CRL REG
			{
				//Clear CNF AND MODE REGION
				GPIO_APtrStr[Copy_pstrPinConfig->PortId]->CRL &= ~((0b1111) << (4 * (Copy_pstrPinConfig->PinId)));
				//SET PIN MODE
				GPIO_APtrStr[Copy_pstrPinConfig->PortId]->CRL |= ( (Local_u8PinMode) << (4 * (Copy_pstrPinConfig->PinId)) );
			}
			else if((Copy_pstrPinConfig->PinId > GPIO_PIN7) && (Copy_pstrPinConfig->PinId <= GPIO_PIN15))//CRH REG
			{
				//Clear CNF AND MODE REGION
				GPIO_APtrStr[Copy_pstrPinConfig->PortId]->CRH &= ~((0b1111) << (4 * ((Copy_pstrPinConfig->PinId) - 8) ) );
				//SET PIN MODE
				GPIO_APtrStr[Copy_pstrPinConfig->PortId]->CRH |= ( (Local_u8PinMode) << (4 * ((Copy_pstrPinConfig->PinId) - 8) ) );
			}
			else Local_u8ErorrState = STD_TYPES_NOK;

		}
		else Local_u8ErorrState = STD_TYPES_NOK;
	}
	else Local_u8ErorrState = STD_TYPES_NOK;
	return Local_u8ErorrState;
}




u8 GPIO_u8SetPinValue(const GPIO_PinConfig_t * Copy_pstrPinConfig, u8 Copy_u8PinValue)
{
	u8 Local_u8ErorrState=STD_TYPES_OK;
	if(Copy_pstrPinConfig != NULL)
	{
		//CHECK PORT AND PIN WITHIN THE RING
		if ((Copy_pstrPinConfig->PortId <= GPIO_PORTC) && (Copy_pstrPinConfig->PinId <= GPIO_PIN15))
		{
			//CHEECK PIN VALUE IF HIGH OR LOW
			if (Copy_u8PinValue == GPIO_u8HIGH)//Access BSRR REG
			{
				GPIO_APtrStr[Copy_pstrPinConfig->PortId]->BSRR = (1<<Copy_pstrPinConfig->PinId);
			}
			else if (Copy_u8PinValue == GPIO_u8LOW)//Access BRR REG
			{
				GPIO_APtrStr[Copy_pstrPinConfig->PortId]->BRR = (1<<Copy_pstrPinConfig->PinId);
			}
			else Local_u8ErorrState = STD_TYPES_NOK;

		}
		else Local_u8ErorrState = STD_TYPES_NOK;

	}
	else Local_u8ErorrState = STD_TYPES_NOK;

	return Local_u8ErorrState;

}

u8 GPIO_u8SetPortValue(u8 Copy_u8PortId,u16 Copy_u8PortValue)
{
	u8 Local_u8ErorrState=STD_TYPES_OK;
	if(Copy_u8PortId <= GPIO_PORTC)
	{
		GPIO_APtrStr[Copy_u8PortId]->ODR = Copy_u8PortValue;
	}
	else Local_u8ErorrState = STD_TYPES_NOK;

	return Local_u8ErorrState;

}

u8 GPIO_u8GetPinValue(const GPIO_PinConfig_t * Copy_pstrPinConfig,u8 * Copy_pu8ReturnedValue)
{
	u8 Local_u8ErorrState=STD_TYPES_OK;
	if(Copy_pstrPinConfig != NULL)
	{
		//CHECK PORT AND PIN WITHIN THE RING
		if ((Copy_pstrPinConfig->PortId <= GPIO_PORTC) && (Copy_pstrPinConfig->PinId <= GPIO_PIN15))
		{
			*Copy_pu8ReturnedValue = GET_BIT(GPIO_APtrStr[Copy_pstrPinConfig->PortId]->IDR , Copy_pstrPinConfig->PinId);
		}
		else Local_u8ErorrState = STD_TYPES_NOK;

	}
	else Local_u8ErorrState = STD_TYPES_NOK;

	return Local_u8ErorrState;
}



u8 GPIO_u8GetPortValue(u8 Copy_u8PortId,u16 * Copy_pu8ReturnedValue)
{
	u8 Local_u8ErorrState=STD_TYPES_OK;
	if(Copy_u8PortId <= GPIO_PORTC)
	{

	   *Copy_pu8ReturnedValue = READ_BYTE(GPIO_APtrStr[Copy_u8PortId]->IDR );

	}
	else Local_u8ErorrState = STD_TYPES_NOK;

	return Local_u8ErorrState;
}


u8 GPIO_u8TogllePin(const GPIO_PinConfig_t * Copy_pstrPinConfig)
{
	u8 Local_u8ErorrState=STD_TYPES_OK;
	if(Copy_pstrPinConfig != NULL)
	{
		//CHECK PORT AND PIN WITHIN THE RING
		if ((Copy_pstrPinConfig->PortId <= GPIO_PORTC) && (Copy_pstrPinConfig->PinId <= GPIO_PIN15))
		{
			TOGGLE_BIT(GPIO_APtrStr[Copy_pstrPinConfig->PortId]->ODR,Copy_pstrPinConfig->PinId);
		}
		else Local_u8ErorrState = STD_TYPES_NOK;
	}
	else Local_u8ErorrState = STD_TYPES_NOK;

	return Local_u8ErorrState;
}




u8 GPIO_u8PortInit(const GPIO_PinConfig_t * Copy_pstrPinConfig)
{
	u8 Local_u8ErorrState=STD_TYPES_OK;
	u8 Local_u8PinMode,Local_u8Counter;
	if(Copy_pstrPinConfig != NULL)
	{
		//Initialize LocalPinMode VAR
		Local_u8PinMode = Copy_pstrPinConfig->PinMode;
		//CHECK PORT  WITHIN THE RING
		if (Copy_pstrPinConfig->PortId <= GPIO_PORTC )
		{
			//CHEECK PIN MODE IS PULL UP
			if (Copy_pstrPinConfig->PinMode == GPIO_u8INPUT_PULL_UP)
			{
				//SET ODR VALUE WITH 1
				GPIO_APtrStr[Copy_pstrPinConfig->PortId]->ODR |= 0x1111;
				//MOdify The Value OF PULL UP MACRO
				Local_u8PinMode &= ~(1 << 4);

			}
			//CHEECK PIN MODE IS PULL DOWN
			else if(Copy_pstrPinConfig->PinMode == GPIO_u8INPUT_PULL_DOWN)
			{
				//SET ODR WITH VALUE 0
				GPIO_APtrStr[Copy_pstrPinConfig->PortId]->ODR &= ~(0x1111);
			}
			//SET IF PIN IN CRH AND CRL
			 for(Local_u8Counter=0;Local_u8Counter<=7;Local_u8Counter++)
			 {
				 //Clear CNF AND MODE REGION
				 GPIO_APtrStr[Copy_pstrPinConfig->PortId]->CRL &= ~((0b1111) << (4 * (Local_u8Counter)));
				 //SET PIN MODE
				 GPIO_APtrStr[Copy_pstrPinConfig->PortId]->CRL |= ( (Local_u8PinMode) << (4 * (Local_u8Counter)) );
				 //Clear CNF AND MODE REGION
				 GPIO_APtrStr[Copy_pstrPinConfig->PortId]->CRH &= ~((0b1111) << (4 * (Local_u8Counter) ) );
				 //SET PIN MODE
				 GPIO_APtrStr[Copy_pstrPinConfig->PortId]->CRH |= ( (Local_u8PinMode) << (4 * (Local_u8Counter ) ));
			 }

		}
		else Local_u8ErorrState = STD_TYPES_NOK;
	}
	else Local_u8ErorrState = STD_TYPES_NOK;
	return Local_u8ErorrState;
}
