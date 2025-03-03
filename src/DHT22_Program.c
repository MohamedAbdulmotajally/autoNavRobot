/**************************************************************/
/****************** Name	: MOHAMED ELSAYED *****************/
/****************** Date	: 12/12/2021      *****************/
/****************** Version : 1.0V            *****************/
/****************** SWC		: DHT22           *****************/
/**************************************************************/

/* LIB */
#include "STD_TYPES.h"
#include "BITMATH.h"

/* MCAL */
#include"RCC_Interface.h"
#include"GPIO_Interface.h"
#include"STK_Interface.h"
#include"NVIC_Interface.h"
#include"EXTI_Interface.h"


/*HAL*/
#include "DHT22_Interface.h"
#include "DHT22_Private.h"
#include "DHT22_Config.h"

/* GLOPAL VAR*/
u8 DHT22_u8StartFlag = 0;
u8 DHT22_u8Counter = 0;
volatile u32 DHT22_u32Frame[40];
volatile u8* Copy_pu8TempData;


/***************************************************************************************/
/* Description! Apply initialization sequence for DHT22 RECEIVER                       */
/* Input      ! Address of THE VARIABLE That Will RECEIVE FRAME DATA                   */
/* Output     ! Error State                                                            */
/***************************************************************************************/
u8 DHT22_u8Init(u8* Copy_pu8ReturnedData)
{
	u8 Local_u8ErrorState = STD_TYPES_OK;
	if ((DHT22_u8PORT <= GPIO_PORTC) && (DHT22_u8PIN <= GPIO_PIN15))
	{
		/*Take a Copy of The Address of THE VARIABLE That Will RECEIVE FRAME DATA*/
		Copy_pu8TempData = Copy_pu8ReturnedData;


		/* Send Start Pulse */
		DHT22_u8SendStartPuls();

		/* INTT EXTI */
		EXTI_Cofig_t Local_strDHT22_EXTI = { DHT22_u8EXTI_PIN_CONFIG,EXTI_FALLING_EDGE,&DHT22_u8GetgFrame };
		EXTI_u8Init(&Local_strDHT22_EXTI);
		EXTI_u8IntEnable(&Local_strDHT22_EXTI);

		/* NVIC INIT */
		NVIC_u8InitPriorityField();
		NVIC_u8EnableInterrupt(DHT22_u8NVIC_DHT22Q);



	}
	else Local_u8ErrorState = STD_TYPES_NOK;
	return Local_u8ErrorState;
}


/***************************************************************************************/
/* Description! Send Start puls to DHT22                                               */
/* Input      ! NONE                                                                   */
/* Output     ! Error State                                                            */
/***************************************************************************************/
u8 DHT22_u8SendStartPuls(void)
{
	u8 Local_u8ErrorState = STD_TYPES_OK;
	if ((DHT22_u8PORT <= GPIO_PORTC) && (DHT22_u8PIN <= GPIO_PIN15))
	{
		u8 Local_u8TempVar;

		/*Configure Pins For Start bits*/
		GPIO_PinConfig_t DHT22_strConfigSendStartPuls = { DHT22_u8PORT,DHT22_u8PIN, GPIO_u8OUTPUT_PUSH_PULL_SPEED_2MHZ };
		GPIO_u8PinInit(&DHT22_strConfigSendStartPuls);

		/*Wake Up The Sensor*/
		GPIO_u8SetPinValue(&DHT22_strConfigSendStartPuls, GPIO_u8HIGH);
		STK_u8SetBusyWait(250000);
		/*
		To Send Start puls :
							  1-clear bit
							  2-wait 20msec
							  3-set bit
							  4-wait 40msec
		 */

		GPIO_u8SetPinValue(&DHT22_strConfigSendStartPuls, GPIO_u8LOW);
		STK_u8SetBusyWait(18000);
		GPIO_u8SetPinValue(&DHT22_strConfigSendStartPuls, GPIO_u8HIGH);
		//STK_u8SetBusyWait(40000);

		/*Configure Pins for Recive Response*/
		GPIO_PinConfig_t DHT22_strConfigReciveResponse = { DHT22_u8PORT,DHT22_u8PIN,GPIO_u8INPUT_FLOATIG };
		GPIO_u8PinInit(&DHT22_strConfigReciveResponse);

		/*
		To KNOW REspond :
							  1-HIGH level        _________              __________
							  2-Low Level                  |             |
							  3-HIGH level                 |_____________|
		 */

		GPIO_u8GetPinValue(&DHT22_strConfigReciveResponse, &Local_u8TempVar);
		while(Local_u8TempVar == GPIO_u8HIGH){GPIO_u8GetPinValue(&DHT22_strConfigReciveResponse, &Local_u8TempVar);}
		while(Local_u8TempVar == GPIO_u8LOW){ GPIO_u8GetPinValue(&DHT22_strConfigReciveResponse, &Local_u8TempVar); }
		while(Local_u8TempVar == GPIO_u8HIGH){ GPIO_u8GetPinValue(&DHT22_strConfigReciveResponse, &Local_u8TempVar); }

	}
	else Local_u8ErrorState = STD_TYPES_NOK;
	return Local_u8ErrorState;
}



/***************************************************************************************/
/* Description! Interface to Get the Frame From The DHT22 Receiver                     */
/* Input      ! Nothing                                                                */
/* Output     ! Nothing                                                                */
/***************************************************************************************/
void DHT22_u8GetgFrame(void)
{


	if (DHT22_u8StartFlag == 0)
	{

		/*START TIMER*/
		STK_u8SetIntervalPeriodic(5000000, &DHT22_VoidGetgFrameData);

		/*FLAG ON*/
		DHT22_u8StartFlag = 1;

	}
	else
	{
		/*SAVE FRAME Bit*/
		STK_u8GetElapsedTime(&DHT22_u32Frame[DHT22_u8Counter]);
		/*RESTART The Timer*/
		STK_u8StopTimer();
		STK_u8SetIntervalPeriodic(5000000, &DHT22_VoidGetgFrameData);

		DHT22_u8Counter++;


	}


}




/***************************************************************************************/
/* Description! Interface to Get the Frame Data From The DHT22 Receiver                */
/* Input      ! Nothing  											                   */
/* Output     ! Nothing                                                                */
/***************************************************************************************/
void DHT22_VoidGetgFrameData(void)
{
	u8 Local_u8Counter = 0;
	u8 Local_u8Temp=0;
	u8 Local_u8Temp2=0;
	for (Local_u8Counter = 0; Local_u8Counter <40; Local_u8Counter++)
	{
		/*
		 * Don't care I'm only human
		 * */
		Local_u8Temp=Local_u8Counter%8;
		Local_u8Temp2=Local_u8Counter/8;

		/*
		Dear Shokr and Mina I putted  two range for noise occurred
		 */
		if (((DHT22_u32Frame[Local_u8Counter]) >= DHT22_u8LOGICAL_ONE_MIN) && ((DHT22_u32Frame[Local_u8Counter]) < DHT22_u8LOGICAL_ONE_MAX))
		{
			SET_BIT((*(Copy_pu8TempData+Local_u8Temp2)), Local_u8Temp);
		}
		else if (((DHT22_u32Frame[Local_u8Counter]) >= DHT22_u8LOGICAL_ZERO_MIN) && ((DHT22_u32Frame[Local_u8Counter]) < DHT22_u8LOGICAL_ZERO_MAX))
		{
			CLEAR_BIT((*(Copy_pu8TempData+Local_u8Temp2)), Local_u8Temp);
		}
		else
		{
			asm("NOP");
		}

	}
	DHT22_u8StartFlag = 0;
	DHT22_u8Counter = 0;


}
