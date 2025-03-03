/**************************************************************/
/****************** Name	: Mohamed Elsayed *****************/
/****************** Date	: 15/9/2021       *****************/
/****************** Version : 1.0V            *****************/
/****************** SWC		: RCC             *****************/
/**************************************************************/
#ifndef RCC_PRIVATE_H
#define RCC_PRIVATE_H


/**************************************************** RCC SYSCLCK Part **************************************/
// MicroController O/P CLK MACROS FOR OPTION
typedef enum
{
	RCC_MCO_NO_OUTPUT_CLK              = (0b0001 << 24)  ,
	RCC_MCO_SYSTEM_CLK                 = (0b0100 << 24)  ,
	RCC_MCO_HSI_CLK                    = (0b0101 << 24)  ,
	RCC_MCO_HSE_CLK                    = (0b0110 << 24)  ,
	RCC_MCO_PLL_CLK_DIVIDED_BY2        = (0b0111 << 24)  ,
	RCC_MCO_PLL2_CLK                   = (0b1000 << 24)  ,
	RCC_MCO_PLL3_CLK_DIVIDED_BY2       = (0b1001 << 24)  ,
	RCC_MCO_EXT1_FOR_ETHERNET_CLK      = (0b1010 << 24)  ,
	RCC_MCO_PLL3_CLK                   = (0b1011 << 24)  ,

}RCC_enumMCO_CLK;

typedef enum
{
	RCC_PLL_DIVIDED_BY3  = 0,     //PLL must be configured to output 72 MHz
	RCC_PLL_DIVIDED_BY2  = 1      //PLL must be configured to output 48 MHz
}RCC_enumOTGFS_PRESCALLER;

typedef enum
{
	RCC_PLL_MUL_X4  = (0b0010 << 18),
	RCC_PLL_MUL_X5  = (0b0011 << 18),
	RCC_PLL_MUL_X6  = (0b0100 << 18),
	RCC_PLL_MUL_X7  = (0b0101 << 18),
	RCC_PLL_MUL_X8  = (0b0110 << 18),
	RCC_PLL_MUL_X9  = (0b0111 << 18),
	RCC_PLL_MUL_X6POINT5  = (0b1101 << 18) // MUL BY 6.5

}RCC_enumPLL_MUL_FACTOR;

typedef enum
{
	RCC_PLL_SOURCE_FROM_HSI_DIVIDED_BY2  = (0 << 16)             ,
	RCC_PLL_SOURCE_FROM_HSE_DIVIDED_BY2  = ((1 << 16)|(1<<17))   ,
	RCC_PLL_SOURCE_FROM_HSE              = ((1 << 16)|(0<<17))

}RCC_enumPLL_ENTRY_CLK_SOURCE;

typedef enum
{
	RCC_ADC_PRESCALER_DIVIDED_BY2  = (0b00 << 14),
	RCC_ADC_PRESCALER_DIVIDED_BY4  = (0b01 << 14),
	RCC_ADC_PRESCALER_DIVIDED_BY6  = (0b10 << 14),
	RCC_ADC_PRESCALER_DIVIDED_BY8  = (0b11 << 14)

}RCC_enumADC_PRESCALER;

typedef enum
{
	RCC_APB2_PRESCALER_NOT_DIVIDED  = (0b001 << 11),
	RCC_APB2_PRESCALER_DIVIDED_BY2  = (0b100 << 11),
	RCC_APB2_PRESCALER_DIVIDED_BY4  = (0b101 << 11),
	RCC_APB2_PRESCALER_DIVIDED_BY8  = (0b110 << 11),
	RCC_APB2_PRESCALER_DIVIDED_BY16  = (0b111 << 11)
}RCC_enumAPB2_PRESCALER;

typedef enum
{
	RCC_APB1_PRESCALER_NOT_DIVIDED  = (0b001 << 8),
	RCC_APB1_PRESCALER_DIVIDED_BY2  = (0b100 << 8),
	RCC_APB1_PRESCALER_DIVIDED_BY4  = (0b101 << 8),
	RCC_APB1_PRESCALER_DIVIDED_BY8  = (0b110 << 8),
	RCC_APB1_PRESCALER_DIVIDED_BY16 = (0b111 << 8)
}RCC_enumAPB1_PRESCALER;

typedef enum
{
	RCC_AHP_PRESCALER_NOT_DIVIDED    = (0b0111 << 4),
	RCC_AHP_PRESCALER_DIVIDED_BY2    = (0b1000 << 4),
	RCC_AHP_PRESCALER_DIVIDED_BY4    = (0b1001 << 4),
	RCC_AHP_PRESCALER_DIVIDED_BY8    = (0b1010 << 4),
	RCC_AHP_PRESCALER_DIVIDED_BY16   = (0b1011 << 4),
	RCC_AHP_PRESCALER_DIVIDED_BY64   = (0b1100 << 4),
	RCC_AHP_PRESCALER_DIVIDED_BY128  = (0b1101 << 4),
	RCC_AHP_PRESCALER_DIVIDED_BY256  = (0b1110 << 4),
	RCC_AHP_PRESCALER_DIVIDED_BY512  = (0b1111 << 4)
}RCC_enumAHP_PRESCALER;
/*****************************************************************************************************************/




#endif
