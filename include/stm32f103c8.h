/**************************************************************/
/****************** Name	: Mohamed Elsayed *****************/
/****************** Date	: 15/9/2021       *****************/
/****************** Version : 1.0V            *****************/
/****************** SWC		: stm32f103c8.h   *****************/
/**************************************************************/
#ifndef STM32F103C8_H
#define STM32F103C8_H



/************************************ RCC Registers ******************************************/

#define RCC_u32_BASE_ADDRESS         0x40021000

typedef struct
{
	volatile u32 CR;
	volatile u32 CFGR;
	volatile u32 CIR;
	volatile u32 APB2RSTR;
	volatile u32 APB1RSTR;
	volatile u32 AHBENR;
	volatile u32 APB2ENR;
	volatile u32 APB1ENR;
	volatile u32 BDCR;
	volatile u32 CSR;
}RCC_RegDef_t;

#define RCC                     ((volatile RCC_RegDef_t*) RCC_u32_BASE_ADDRESS)

/*********************************************************************************************/

/************************************* GPIO Registers ****************************************/

#define GPIO_u32_GPIOA_BASE_ADDRESS    0x40010800
#define GPIO_u32_GPIOB_BASE_ADDRESS    0x40010C00
#define GPIO_u32_GPIOC_BASE_ADDRESS    0x40011000

typedef struct
{
	volatile u32 CRL;
	volatile u32 CRH;
	volatile u32 IDR;
	volatile u32 ODR;
	volatile u32 BSRR;
	volatile u32 BRR;
	volatile u32 LCKR;
}GPIO_RegDef_t;

#define GPIOA                         (( GPIO_RegDef_t*) GPIO_u32_GPIOA_BASE_ADDRESS)
#define GPIOB                         (( GPIO_RegDef_t*) GPIO_u32_GPIOB_BASE_ADDRESS)
#define GPIOC                         (( GPIO_RegDef_t*) GPIO_u32_GPIOC_BASE_ADDRESS)


/*********************************************************************************************/

/************************************ NVIC Registers *****************************************/

#define NVIC_u32_BASE_ADDRESS         0xE000E100

typedef struct
{
	volatile u32 ISER[8];
	volatile u32 Reserved1[24];
	volatile u32 ICER[8];
	volatile u32 Reserved2[24];
	volatile u32 ISPR[8];
	volatile u32 Reserved3[24];
	volatile u32 ICPR[8];
	volatile u32 Reserved4[24];
	volatile u32 IABR[8];
	volatile u32 Reserved5[56];
	volatile u8 IPR[240];
}NVIC_RegDef_t;

#define NVIC                       ((volatile NVIC_RegDef_t*) NVIC_u32_BASE_ADDRESS)




/*********************************************************************************************/



/************************************ EXTI Registers *****************************************/

#define EXTI_u32_BASE_ADDRESS         0x40010400

typedef struct
{
	volatile u32 IMR;
	volatile u32 EMR;
	volatile u32 RTSR;
	volatile u32 FTSR;
	volatile u32 SWIER;
	volatile u32 PR;

}EXTI_RegDef_t;

#define EXTI                       ((volatile EXTI_RegDef_t*) EXTI_u32_BASE_ADDRESS)

/*********************************************************************************************/


/************************************  AFIO Registers *****************************************/

#define  AFIO_u32_BASE_ADDRESS         0x40010000

typedef struct
{
	volatile u32 EVCR;
	volatile u32 MAPR;
	volatile u32 EXTICR[4];
	volatile u32 Reserved1[2];
	volatile u32 MAPR2;

}AFIO_RegDef_t;

#define  AFIO                       ((volatile AFIO_RegDef_t*)  AFIO_u32_BASE_ADDRESS)

/*********************************************************************************************/

/************************************ SYSTICK Registers *****************************************/

#define  STK_u32_BASE_ADDRESS         0xE000E010

typedef struct
{
	volatile u32 CTRL;
	volatile u32 LOAD;
	volatile u32 VAL;
	volatile u32 CALIB;
	volatile u32 MAPR2;

}STK_RegDef_t;

#define  STK                       ((volatile STK_RegDef_t*)  STK_u32_BASE_ADDRESS)

/*********************************************************************************************/

/************************************ SPI1 Registers *****************************************/

#define  SPI1_u32_BASE_ADDRESS         0x40013000 

typedef struct
{
	volatile u32 SPI_CR1;
	volatile u32 SPI_CR2;
	volatile u32 SPI_SR;
	volatile u32 SPI_DR;
	volatile u32 SPI_CRCPR;
	volatile u32 SPI_RXCRCR;
	volatile u32 SPI_TXCRCR;
	volatile u32 SPI_I2SCFGR;
	volatile u32 SPI_I2SPR;

}SPI1_RegDef_t;

#define  SPI1                       ((volatile SPI1_RegDef_t*)  SPI1_u32_BASE_ADDRESS)

/*********************************************************************************************/

/************************************ DMA Registers *****************************************/

#define  DMA_u32_BASE_ADDRESS         0x40020000

typedef struct
{
	volatile u32 CCR;
	volatile u32 CNDTR;
	volatile u32 CPAR;
	volatile u32 CMAR;
	volatile u32 RESERVED;

}CHANNEL_t;

typedef struct
{
	volatile u32 ISR;
	volatile u32 IFCR;
	CHANNEL_t  Channel[7];
}DMA_RegDef_t;

#define  DMA                       ((volatile DMA_RegDef_t*)  DMA_u32_BASE_ADDRESS)

/* to acces DMA->Channel[0].CCR */
/*********************************************************************************************/

/************************************ TIMER Registers *****************************************/

#define  TIM2_u32_BASE_ADDRESS         0x40000000
#define  TIM3_u32_BASE_ADDRESS         0x40000400
#define  TIM4_u32_BASE_ADDRESS         0x40000800

typedef struct
{
	volatile u32 CR1;
	volatile u32 CR2;
	volatile u32 SMCR;
	volatile u32 DIER;
	volatile u32 SR;
	volatile u32 EGR;
	volatile u32 CCMR1;
	volatile u32 CCMR2;
	volatile u32 CCER;
	volatile u32 CNT;
	volatile u32 PSC;
	volatile u32 ARR;
	volatile u32 RESERVED1;
	volatile u32 CCR1;
	volatile u32 CCR2;
	volatile u32 CCR3;
	volatile u32 CCR4;
	volatile u32 RESERVED2;
	volatile u32 DCR;
	volatile u32 DMAR;

}TIM_RegDef_t;

#define  TIM2                       ((volatile TIM_RegDef_t*)  TIM2_u32_BASE_ADDRESS)
#define  TIM3                       ((volatile TIM_RegDef_t*)  TIM3_u32_BASE_ADDRESS)
#define  TIM4                       ((volatile TIM_RegDef_t*)  TIM4_u32_BASE_ADDRESS)


/*********************************************************************************************/
/************************************ ADC Registers *****************************************/

#define  ADC1_u32_BASE_ADDRESS         0x40012400


typedef struct
{
	volatile u32 SR;
	volatile u32 CR1;
	volatile u32 CR2;
	volatile u32 SMPR1;
	volatile u32 SMPR2;
	volatile u32 JOFR1;
	volatile u32 JOFR2;
	volatile u32 JOFR3;
	volatile u32 JOFR4;
	volatile u32 HTR;
	volatile u32 LTR;
	volatile u32 SQR1;
	volatile u32 SQR2;
	volatile u32 SQR3;
	volatile u32 JSQR;
	volatile u32 JDR1;
	volatile u32 JDR2;
	volatile u32 JDR3;
	volatile u32 JDR4;
	volatile u32 DR;

}ADC_RegDef_t;


#define  ADC1                       ((volatile ADC_RegDef_t*)  ADC1_u32_BASE_ADDRESS)


/*********************************************************************************************/

#endif
