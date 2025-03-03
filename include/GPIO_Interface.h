/**************************************************************/
/****************** Name	: MOHAMED ELSAYED *****************/
/****************** Date	: 18/9/2021       *****************/
/****************** Version : 1.0V            *****************/
/****************** SWC		: GPIO             *****************/
/**************************************************************/
#ifndef GPIO_INTERFACE_H
#define GPIO_INTERFACE_H


/* GPIO VOLTAGE LEVEL MACROS */
#define GPIO_u8HIGH   1
#define GPIO_u8LOW    0
/*****************************/

/****************************** PORT MACROS **************************/
typedef enum
{
	GPIO_PORTA,
	GPIO_PORTB,
	GPIO_PORTC
}GPIO_enumPortId;
/*********************************************************************/


/****************************** PIN MACROS **************************/
typedef enum
{
	GPIO_PIN0	,
	GPIO_PIN1	,
	GPIO_PIN2	,
	GPIO_PIN3	,
	GPIO_PIN4	,
	GPIO_PIN5	,
	GPIO_PIN6	,
	GPIO_PIN7	,
	GPIO_PIN8	,
	GPIO_PIN9	,
	GPIO_PIN10	,
	GPIO_PIN11	,
	GPIO_PIN12	,
	GPIO_PIN13	,
	GPIO_PIN14	,
	GPIO_PIN15
}GPIO_enumPinId;
/*********************************************************************/


/****************************** PIN MODE MACROS **************************/
/* INPUT MODE */
#define GPIO_u8INPUT_FLOATIG		                    0b0100
#define GPIO_u8INPUT_PULL_UP                            0b11000
#define GPIO_u8INPUT_PULL_DOWN                          0b1000
#define GPIO_u8INPUT_ANALOG                             0b0000

/* OUTPUT SPEED 2MHZ */
#define GPIO_u8OUTPUT_PUSH_PULL_SPEED_2MHZ             0b0010
#define GPIO_u8OUTPUT_OPEN_DRAIN_SPEED_2MHZ            0b0110
#define GPIO_u8OUTPUT_ALTFUN_PUSH_PULL_SPEED_2MHZ      0b1010
#define GPIO_u8OUTPUT_ALTFUN_OPEN_DRAIN_SPEED_2MHZ     0b1110

/* OUTPUT SPEED 10MHZ */
#define GPIO_u8OUTPUT_PUSH_PULL_SPEED_10MHZ            0b0001
#define GPIO_u8OUTPUT_OPEN_DRAIN_SPEED_10MHZ           0b0101
#define GPIO_u8OUTPUT_ALTFUN_PUSH_PULL_SPEED_10MHZ     0b1001
#define GPIO_u8OUTPUT_ALTFUN_OPEN_DRAIN_SPEED_10MHZ    ob1101

/* OUTPUT SPEED 50MHZ */
#define GPIO_u8OUTPUT_PUSH_PULL_SPEED_50MHZ            0b0011
#define GPIO_u8OUTPUT_OPEN_DRAIN_SPEED_50MHZ           0b0111
#define GPIO_u8OUTPUT_ALTFUN_PUSH_PULL_SPEED_50MHZ     0b1011
#define GPIO_u8OUTPUT_ALTFUN_OPEN_DRAIN_SPEED_50MHZ    0b1111
/**************************************************************************/





/********************** GPIO Configuration Structure *******************/
typedef struct
{
	GPIO_enumPortId PortId;
	GPIO_enumPinId PinId;
	u8 PinMode;

}GPIO_PinConfig_t;
/*****************************************************************************/


/***************************  GPIO APIS   ***********************************/
u8 GPIO_u8PinInit(const GPIO_PinConfig_t * Copy_pstrPinConfig);
u8 GPIO_u8SetPinValue(const GPIO_PinConfig_t * Copy_pstrPinConfig, u8 Copy_u8PinValue);
u8 GPIO_u8SetPortValue(u8 Copy_u8PortId, u16 Copy_u8PortValue);
u8 GPIO_u8GetPinValue(const GPIO_PinConfig_t * Copy_pstrPinConfig, u8 * Copy_pu8ReturnedValue);
u8 GPIO_u8GetPortValue(u8 Copy_u8PortId,u16 * Copy_pu8ReturnedValue);
u8 GPIO_u8TogllePin(const GPIO_PinConfig_t * Copy_pstrPinConfig);
u8 GPIO_u8PortInit(const GPIO_PinConfig_t * Copy_pstrPinConfig);
/*****************************************************************************/





















#endif
