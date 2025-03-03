/**************************************************************/
/****************** Name	: MOHAMED ELSAYED *****************/
/****************** Date	: 27/5/2022       *****************/
/****************** Version : 1.0V            *****************/
/****************** SWC		: ADC1            *****************/
/**************************************************************/
#ifndef ADC1_INTERFACE_H
#define ADC1_INTERFACE_H


#include"ADC1_Config.h"


/*********************************************************************************************************/
/******************************************** MACROS  ****************************************************/
/*********************************************************************************************************/
#define ADC_u8_CH0	  0
#define ADC_u8_CH1	  1
#define ADC_u8_CH2    2
#define ADC_u8_CH3    3
#define ADC_u8_CH4    4
#define ADC_u8_CH5    5
#define ADC_u8_CH6    6
#define ADC_u8_CH7    7
#define ADC_u8_CH8    8
#define ADC_u8_CH9    9
#define ADC_u8_CH10   10
#define ADC_u8_CH11   11
#define ADC_u8_CH12   12
#define ADC_u8_CH13   13
#define ADC_u8_CH14   14
#define ADC_u8_CH15   15
#define ADC_u8_CH16   16
#define ADC_u8_CH17   17
/*********************************************************************************************************/
/*********************************************************************************************************/
/*********************************************************************************************************/



/*********************************************************************************************************/
/******************************************** Flags  *****************************************************/
/********************************************************************************************************/

//STRT: Regular channel Start flag
//This bit is set by hardware when regular channel conversion starts.It is cleared by software.
//0 : No regular channel conversion started
//1 : Regular channel conversion has started
#define ADC1_u8_STRT_FLAG     	    4

//JSTRT: Injected channel Start flag
//This bit is set by hardware when injected channel group conversion starts.It is cleared by
//software.
//0 : No injected group conversion started
//1 : Injected group conversion has started
#define ADC1_u8_JSTRT_FLAG           3

//JEOC: Injected channel end of conversion
//This bit is set by hardware at the end of all injected group channel conversion.It is cleared
//by software.
//0 : Conversion is not complete
//1 : Conversion complete
#define ADC1_u8_JEOC_FLAG            2

//EOC: End of conversion
//This bit is set by hardware at the end of a group channel conversion(regular or injected).It is
//cleared by software or by reading the ADC_DR.
//0 : Conversion is not complete
//1 : Conversion complete
#define ADC1_u8_EOC_FLAG     		  1

//AWD: Analog watchdog flag
//This bit is set by hardware when the converted voltage crosses the values programmed in
//the ADC_LTRand ADC_HTR registers.It is cleared by software.
//0 : No Analog watchdog event occurred
//1 : Analog watchdog event occurred
#define ADC1_u8_AWD_FLAG       		   0
/*********************************************************************************************************/
/********************************************************************************************************/
/*******************************************************************************************************/







/***************************************************************************************/
/********************************** Function Definition ********************************/
/***************************************************************************************/

/***************************************************************************************/
/* Description! Apply initialization sequence for ADC1                                 */
/* Input      ! Nothing                                                                */
/* Output     ! Nothing                                                                */
/***************************************************************************************/
void ADC1_voidInit(void);


/***************************************************************************************/
/* Description! Interface TO  ENABLE ADC1                                              */
/* Input      ! Nothing                                                                */
/* Output     ! Nothing                                                                */
/***************************************************************************************/
void ADC1_u8Enable(void);

/***************************************************************************************/
/* Description! Interface TO  ENABLE ADC1 INTERRUPT                                    */
/* Input      ! Nothing                                                                */
/* Output     ! Nothing                                                                */
/***************************************************************************************/
void ADC1_u8InterruptEnable(void);

/***************************************************************************************/
/* Description! Interface TO  Disable ADC1                                             */
/* Input      ! Nothing                                                                */
/* Output     ! Nothing                                                                */
/***************************************************************************************/
void ADC1_u8Disable(void);

/***************************************************************************************/
/* Description! Interface TO  Disable ADC1 INTERRUPT                                   */
/* Input      ! Nothing                                                                */
/* Output     ! Nothing                                                                */
/***************************************************************************************/
void ADC1_u8InterruptDisaple(void);

/***************************************************************************************/
/* Description! Interface TO  Start Conversation                                       */
/* Input      ! Nothing                                                                */
/* Output     ! Nothing                                                                */
/***************************************************************************************/
void ADC1_u8StartConv(void);

/***************************************************************************************/
/* Description! Interface to get the result of conv  From ADC1                         */
/* Input      ! Pointer to variable that Receive The ADC result 		               */
/* Output     ! Error State                                                            */
/***************************************************************************************/
u8 ADC1_u8GetResult(u32 *Copy_ptr_u16DataRecived);


/***************************************************************************************/
/* Description! Interface to  Set ADC CALLBACK FUN                                     */
/* Input      ! Pointer to fun   											           */
/* Output     ! Error State                                                            */
/***************************************************************************************/
u8 ADC1_u8SetCallBackFun(void (*Copy_pfunCallBackFun) (void));








#endif
