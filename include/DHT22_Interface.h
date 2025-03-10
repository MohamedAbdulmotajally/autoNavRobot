/**************************************************************/
/****************** Name	: MOHAMED ELSAYED *****************/
/****************** Date	: 12/12/2021      *****************/
/****************** Version : 1.0V            *****************/
/****************** SWC		: DHT22           *****************/
/**************************************************************/

#ifndef DHT22_INTERFACE_H
#define DHT22_INTERFACE_H

/*****************************************************************************************************************/
/*****************************************************************************************************************/
/******************************************	    	MACROS	  ****************************************************/
#define DHT22_u8LOGICAL_ONE_MIN  100
#define DHT22_u8LOGICAL_ONE_MAX  140
#define DHT22_u8LOGICAL_ZERO_MIN 60
#define DHT22_u8LOGICAL_ZERO_MAX 95
/*****************************************************************************************************************/
/*****************************************************************************************************************/






/*****************************************************************************************************************/
/*****************************************************************************************************************/
/******************************************	    	APIS	  ****************************************************/


/***************************************************************************************/
/* Description! Apply initialization sequence for DHT22 RECEIVER                        */
/* Input      ! Address of THE VARIABLE That Will RECEIVE FRAME DATA                   */
/* Output     ! Error State                                                            */
/***************************************************************************************/
u8 DHT22_u8Init(u8* Copy_pu8ReturnedData);




/*****************************************************************************************************************/
/*****************************************************************************************************************/

#endif

