/**************************************************************/
/****************** Name	: MOHAMED ELSAYED *****************/
/****************** Date	: 30/10/2021      *****************/
/****************** Version : 1.0V            *****************/
/****************** SWC		: SPI1            *****************/
/**************************************************************/
#ifndef SPI1_INTERFACE_H
#define SPI1_INTERFACE_H


#include"SPI1_Config.h"




/***************************************************************************************/
/********************************** MACROS *********************************************/
/***************************************************************************************/
#define SPI1_u8_BUSY_FLAG     	  			   7
#define SPI1_u8_OVERRUN_FLAG        		   6
#define SPI1_u8_MODE_FAULT_FLAG                5
#define SPI1_u8_CRC_ERROR_FLAG     			   4
#define SPI1_u8_UNDERRUN_FLAG       		   3
#define SPI1_u8_CHSIDE_FLAG                    2
#define SPI1_u8_TXE_FLAG                       1
#define SPI1_u8_RXE_FLAG                       0


#define SPI1_u8_SCLK_PIN_STR_COFIG          SPI1_SCK_PIN_CONFIG
#define SPI1_u8_MISO_PIN_STR_COFIG			SPI1_MISO_PIN_CONFIG
#define SPI1_u8_MOSI_PIN_STR_COFIG          SPI1_MOSI_PIN_CONFIG
#define SPI1_u8_THRESHOLD_VALUE  		    9000000UL








/***************************************************************************************/
/********************************** Function Definition ********************************/
/***************************************************************************************/

/***************************************************************************************/
/* Description! Apply initialization sequence for SPI1 Communication Protocol          */
/* Input      ! Nothing                                                                */
/* Output     ! Nothing                                                                */
/***************************************************************************************/
void SPI1_voidInit(void);


/***************************************************************************************/
/* Description! Interface to Send And Receive Synchronized From SPI1                   */
/* Input      ! The Data to Send and Address of variable that Receive The Slave data   */
/* Output     ! Error State                                                            */
/***************************************************************************************/
u8 SPI1_u8MasterSendReceiveSync(u8 Copy_u8DataToSend, u8 * Copy_pu8ReturnedDataToReceive);


/***************************************************************************************/
/* Description! Interface to Send And Receive ASynchronized From SPI1                  */
/* Input      ! The Data to Send  											           */
/* Output     ! Error State                                                            */
/***************************************************************************************/
u8 SPI1_u8MasterSendReceiveASync(u8 Copy_u8DataToSend);


/***************************************************************************************/
/* Description! Interface to Receive 1 byte  From SPI1 Master                          */
/* Input      ! variable that Receive The Master data  		                           */
/* Output     ! Error State                                                            */
/***************************************************************************************/
u8 SPI1_u8SlaveRecive(u8 *Copy_ptr_u8DataRecived);

/***************************************************************************************/
/* Description! Interface to Transmit 1 byte  to SPI1 Master                           */
/* Input      ! The Data to Send  											           */
/* Output     ! Error State                                                            */
/***************************************************************************************/
u8 SPI1_u8SlaveTransmit(u8 Copy_u8DataToSend);

/***************************************************************************************/
/* Description! Interface to Receive 2 byte  From SPI1 Master                          */
/* Input      ! variable that Receive The Master data  		                           */
/* Output     ! Error State                                                            */
/***************************************************************************************/
u8 SPI1_u8SlaveRecive16(u16 *Copy_ptr_u8DataRecived);

/***************************************************************************************/
/* Description! Interface to Transmit 2 byte  to SPI1 Master                           */
/* Input      ! The Data to Send  											           */
/* Output     ! Error State                                                            */
/***************************************************************************************/
u8 SPI1_u8SlaveTransmit16(u16 Copy_u8DataToSend);

/***************************************************************************************/
/* Description! Interface to Set CallBack FUNCTION                                     */
/* Input      ! Function                              		                           */
/* Output     ! Error State                                                            */
/***************************************************************************************/
u8 SPI1_u8SetCallBack(void (*Copy_ptr_Fun)(void));
















#endif
