/**************************************************************/
/****************** Name	: Mohamed Elsayed *****************/
/****************** Date	: 15/9/2021       *****************/
/****************** Version : 1.0V            *****************/
/****************** SWC		: RCC             *****************/
/**************************************************************/
#ifndef RCC_INTERFACE_H
#define RCC_INTERFACE_H



typedef enum
{
	RCC_HSI_CLK  =0 ,
	RCC_HSE_CLK   ,
	RCC_PLL_CLK
}RCC_enumSYSTEM_CLOCK;

/************************************* RCC Control  REgister MACROS ************************/
#define RCC_HSION_BIT        0
#define RCC_HSIRDY_BIT       1
#define RCC_HSEON_BIT        16
#define RCC_HSERDY_BIT   	 17
#define RCC_HSEBYP_BIT       18           //he HSEBYP bit can be written only if the HSE oscillator is disabled.
#define RCC_CSSON_BIT        19
#define RCC_PLLON_BIT        24
#define RCC_PLLRDY_BIT       25
#define RCC_PLL2ON_BIT       26
#define RCC_PLL2RDY_BIT      27
#define RCC_PLL3ON_BIT       28
#define RCC_PLL3RDY_BIT      29
/***********************************************************************************************/



/********************************************* RCC EN Peripheral CLK Part ****************************************/
// ENUM for RCC BUS
typedef enum
{
	RCC_AHP_BUS   ,
	RCC_APB1_BUS  ,
	RCC_APB2_BUS
}RCC_enumBUS;

typedef enum
{
	RCC_DMA1        	 ,
	RCC_DMA2        	 ,
	RCC_SRAM        	 ,
	RCC_FLITF      = 4   ,
	RCC_CRC        = 6   ,
	RCC_OTGFS      = 12  ,
	RCC_ETHMAC     = 16  ,
	RCC_ETHMACTX   	 	 ,
	RCC_ETHMACRX    	 ,
	RCC_AFIOEN     = 0   ,
	RCC_IOPA       = 2   ,
	RCC_IOPB             ,
	RCC_IOPC             ,
	RCC_IOPD             ,
	RCC_IOPE             ,
	RCC_ADC1       = 9   ,
	RCC_ADC2             ,
	RCC_TIM1             ,
	RCC_SPI1             ,
	RCC_USART1     =14   ,
	RCC_TIM2       = 0   ,
	RCC_TIM3             ,
	RCC_TIM4             ,
	RCC_TIM5             ,
	RCC_TIM6             ,
	RCC_TIM7             ,
	RCC_WWDG       = 11  ,
	RCC_SPI2       = 14  ,
	RCC_SPI3             ,
	RCC_USART2     = 17  ,
	RCC_USART3           ,
	RCC_USART4           ,
	RCC_USART5           ,
	RCC_I2C1             ,
	RCC_I2C2             ,
	RCC_CAN1       = 25  ,
	RCC_CAN2             ,
	RCC_BKP              ,
	RCC_PWR              ,
	RCC_DAC

}RCC_enumPERIPHERAL;
/***********************************************************************************************************************/

/******************* RCC SYSCLCK Part *************************/


/**************************************************************/




u8 RCC_u8InitSysClk(void);
u8 RCC_u8EnablePeripheralClk(RCC_enumBUS Copy_u8BusId,RCC_enumPERIPHERAL Copy_PeripheralId);
u8 RCC_u8DisablePeripheralClk(RCC_enumBUS Copy_u8BusId,RCC_enumPERIPHERAL Copy_PeripheralId);

#endif
