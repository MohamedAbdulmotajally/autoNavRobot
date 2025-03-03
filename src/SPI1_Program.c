/**************************************************************/
/****************** Name	: MOHAMED ELSAYED *****************/
/****************** Date	: 31/10/2021       *****************/
/****************** Version : 1.0V            *****************/
/****************** SWC		: SPI1        *****************/
/**************************************************************/

/* LIB */
#include "STD_TYPES.h"
#include "BITMATH.h"
#include "stm32f103c8.h"

/* MCAL */
#include"RCC_Interface.h"
#include"GPIO_Interface.h"
#include"STK_Interface.h"



/*HAL*/
#include "SPI1_Interface.h"
#include "SPI1_Private.h"
#include "SPI1_Config.h"

/* GLOPAL VAR*/
static void (*SPI1_pfun)(void) =  NULL ;
/*************/






/***************************************************************************************/
/* Description! Apply initialization sequence for SPI1 Communication Protocol          */
/* Input      ! Nothing                                                                */
/* Output     ! Nothing                                                                */
/***************************************************************************************/
void SPI1_voidInit(void)
{
	/*INIT CR1*/
	SPI1->SPI_CR1= SPI1_u8_CR1_REG_CONFIG;

	/*INIT CR2*/
	SPI1->SPI_CR2= SPI1_u8_CR2_REG_CONFIG;
	SET_BIT(SPI1->SPI_CR2,6);

	/* Re-map Pins*/
	if(SPI1_u8_PIN_REMAPEN == SPI1_u8_PIN_REMAP)
	{
		SET_BIT(AFIO->MAPR,0);
	}
}


/***************************************************************************************/
/* Description! Interface to Send And Receive Synchronized From SPI1                   */
/* Input      ! The Data to Send and Address of variable that Receive The Slave data   */
/* Output     ! Error State                                                            */
/***************************************************************************************/
u8 SPI1_u8MasterSendReceiveSync(u8 Copy_u8DataToSend, u8 * Copy_pu8ReturnedDataToReceive)
{
	u8 Local_u8ErrorState =STD_TYPES_OK;

	if (Copy_pu8ReturnedDataToReceive != NULL)
	{
		/*SEND DATA*/
		SPI1->SPI_DR = Copy_u8DataToSend;

		/*Wait Until Data Send*/
		while ((GET_BIT(SPI1->SPI_SR,SPI1_u8_BUSY_FLAG)) == 1){asm("NOP");}

		/*Read Data*/
		*Copy_pu8ReturnedDataToReceive = (u8)(SPI1->SPI_DR);

	}else Local_u8ErrorState =STD_TYPES_NOK;

	return Local_u8ErrorState;
}



/***************************************************************************************/
/* Description! Interface to Receive 1 byte  From SPI1 Master                          */
/* Input      ! variable that Receive The Master data  		                           */
/* Output     ! Error State                                                            */
/***************************************************************************************/
u8 SPI1_u8SlaveRecive(u8 *Copy_ptr_u8DataRecived)
{
	u8 Local_u8ErrorState =STD_TYPES_OK;

	if (Copy_ptr_u8DataRecived != NULL)
	{
		/* Wait Until Data Received */
		while ((GET_BIT(SPI1->SPI_SR,0)) == 0){asm("NOP");}

		/* Read Data REG */
		*Copy_ptr_u8DataRecived = (u8)(SPI1->SPI_DR);

	}else Local_u8ErrorState =STD_TYPES_NOK;

	return Local_u8ErrorState;
}



/***************************************************************************************/
/* Description! Interface to Transmit 1 byte  to SPI1 Master                           */
/* Input      ! The Data to Send  											           */
/* Output     ! Error State                                                            */
/***************************************************************************************/
u8 SPI1_u8SlaveTransmit(u8 Copy_u8DataToSend)
{
	u8 Local_u8ErrorState =STD_TYPES_OK;

	if (Copy_u8DataToSend != NULL)
	{
		/* Wait For TX Flag */
		while(GET_BIT(SPI1->SPI_SR , SPI1_u8_TXE_FLAG)==0);

		/*SEND DATA*/
		SPI1->SPI_DR = Copy_u8DataToSend;

	}else Local_u8ErrorState =STD_TYPES_NOK;

	return Local_u8ErrorState;
}

/***************************************************************************************/
/* Description! Interface to Receive 2 byte  From SPI1 Master                          */
/* Input      ! variable that Receive The Master data  		                           */
/* Output     ! Error State                                                            */
/***************************************************************************************/
u8 SPI1_u8SlaveRecive16(u16 *Copy_ptr_u16DataRecived)
{
	u8 Local_u8ErrorState =STD_TYPES_OK;

	if (Copy_ptr_u16DataRecived != NULL)
	{
		u8 Local_u8Temp=0;

		/* Wait Until Data Received */
		while ((GET_BIT(SPI1->SPI_SR,0)) == 0){asm("NOP");}

		/* Read 1st byte Data REG */
		*Copy_ptr_u16DataRecived = (u8)(SPI1->SPI_DR);

		/* Wait Until Data Received */
		while ((GET_BIT(SPI1->SPI_SR,0)) == 0){asm("NOP");}

		/* Read  2nd byte Data REG */
		Local_u8Temp=(u8)(SPI1->SPI_DR);
		*Copy_ptr_u16DataRecived |= (Local_u8Temp<<8);

	}else Local_u8ErrorState =STD_TYPES_NOK;

	return Local_u8ErrorState;
}

/*u8 SPI1_u8SlaveRecive16(u16 *Copy_ptr_u16DataRecived)
{
	u8 Local_u8ErrorState =STD_TYPES_OK;
	u16 Local_u16TimeOut = 0;

	if (Copy_ptr_u16DataRecived != NULL)
	{
		u8 Local_u8Temp=0;

		 Wait Until Data Received
		while (((GET_BIT(SPI1->SPI_SR,0)) == 0)  && ( Local_u16TimeOut < SPI1_u8_THRESHOLD_VALUE ))
		{
			Local_u16TimeOut++;
		}
		if(Local_u16TimeOut == SPI1_u8_THRESHOLD_VALUE )
		{
			Local_u8ErrorState =STD_TYPES_NOK;
		}
		else
		{
			 Read 1st byte Data REG
			*Copy_ptr_u16DataRecived = (u8)(SPI1->SPI_DR);

			 Wait Until Data Received
			while ((GET_BIT(SPI1->SPI_SR,0)) == 0){asm("NOP");}

			 Read  2nd byte Data REG
			Local_u8Temp=(u8)(SPI1->SPI_DR);
			*Copy_ptr_u16DataRecived |= (Local_u8Temp<<8);
		}

	}else Local_u8ErrorState =STD_TYPES_NOK;

	return Local_u8ErrorState;
}*/



/***************************************************************************************/
/* Description! Interface to Transmit 2 byte  to SPI1 Master                           */
/* Input      ! The Data to Send  											           */
/* Output     ! Error State                                                            */
/***************************************************************************************/
u8 SPI1_u8SlaveTransmit16(u16 Copy_u16DataToSend)
{
	u8 Local_u8ErrorState =STD_TYPES_OK;

	if (Copy_u16DataToSend != NULL)
	{
		u8 Local_u8Temp=0;

		/* Wait For TX Flag */
		while(GET_BIT(SPI1->SPI_SR , SPI1_u8_TXE_FLAG)==0);

		/*SEND DATA*/
		Local_u8Temp=(u8)(Copy_u16DataToSend>>8);
		SPI1->SPI_DR = Local_u8Temp;

		/* Wait For TX Flag */
		while(GET_BIT(SPI1->SPI_SR , SPI1_u8_TXE_FLAG)==0);

		/*SEND DATA*/
		Local_u8Temp=(u8)(Copy_u16DataToSend<<8);
		SPI1->SPI_DR = Local_u8Temp;

	}else Local_u8ErrorState =STD_TYPES_NOK;

	return Local_u8ErrorState;
}


/***************************************************************************************/
/* Description! Interface to Set CallBack FUNCTION                                     */
/* Input      ! Function                              		                           */
/* Output     ! Error State                                                            */
/***************************************************************************************/
u8 SPI1_u8SetCallBack(void (*Copy_ptr_Fun)(void))
{
	u8 Local_u8ErrorState=STD_TYPES_OK;
	if(Copy_ptr_Fun != NULL)
	{
		SPI1_pfun=Copy_ptr_Fun;
	}
	else Local_u8ErrorState=STD_TYPES_NOK;
	return Local_u8ErrorState;
}




SPI1_IRQHandler(void)
{
	SPI1 ->SPI_SR=0;
	if(SPI1_pfun != NULL)
	{
		SPI1_pfun();
	}
}
