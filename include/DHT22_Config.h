/**************************************************************/
/****************** Name	: MOHAMED ELSAYED *****************/
/****************** Date	: 12/12/2021      *****************/
/****************** Version : 1.0V            *****************/
/****************** SWC		: DHT22           *****************/
/**************************************************************/

#ifndef DHT22_CONFIG_H
#define DHT22_CONFIG_H


/*****************************************************************************************************************/
/*****************************************************************************************************************/
/******************************************	      CONFIG        **************************************************/


/*SELECT FROM OPTION:
*	EXTI_PORTA,EXTI_PIN0,EXTI_LINE0
*	EXTI_PORTB,EXTI_PIN0,EXTI_LINE0
*   EXTI_PORTC,EXTI_PIN0,EXTI_LINE0
*	EXTI_PORTA,EXTI_PIN1,EXTI_LINE1
*	EXTI_PORTB,EXTI_PIN1,EXTI_LINE1
*	EXTI_PORTC,EXTI_PIN1,EXTI_LINE1
*	EXTI_PORTA,EXTI_PIN2,EXTI_LINE2
*	EXTI_PORTB,EXTI_PIN2,EXTI_LINE2
*	EXTI_PORTC,EXTI_PIN2,EXTI_LINE2
*	EXTI_PORTA,EXTI_PIN3,EXTI_LINE3
*	EXTI_PORTB,EXTI_PIN3,EXTI_LINE3
*	EXTI_PORTC,EXTI_PIN3,EXTI_LINE3
*	EXTI_PORTA,EXTI_PIN5,EXTI_LINE4
*	EXTI_PORTB,EXTI_PIN5,EXTI_LINE4
*	EXTI_PORTC,EXTI_PIN5,EXTI_LINE4
*	EXTI_PORTA,EXTI_PIN5,EXTI_LINE5
*   EXTI_PORTB,EXTI_PIN5,EXTI_LINE5
*   EXTI_PORTC,EXTI_PIN5,EXTI_LINE5
*   EXTI_PORTA,EXTI_PIN6,EXTI_LINE6.
*   EXTI_PORTB,EXTI_PIN6,EXTI_LINE6
*   EXTI_PORTC,EXTI_PIN6,EXTI_LINE6
*   EXTI_PORTA,EXTI_PIN7,EXTI_LINE7
*   EXTI_PORTB,EXTI_PIN7,EXTI_LINE7
*   EXTI_PORTC,EXTI_PIN7,EXTI_LINE7
*   EXTI_PORTA,EXTI_PIN8,EXTI_LINE8
*   EXTI_PORTB,EXTI_PIN8,EXTI_LINE8
*   EXTI_PORTC,EXTI_PIN8,EXTI_LINE8
*   EXTI_PORTA,EXTI_PIN9,EXTI_LINE9
*   EXTI_PORTB,EXTI_PIN9,EXTI_LINE9
*   EXTI_PORTC,EXTI_PIN9,EXTI_LINE9
*   EXTI_PORTA,EXTI_PIN10,EXTI_LINE10
*   EXTI_PORTB,EXTI_PIN10,EXTI_LINE10
*   EXTI_PORTC,EXTI_PIN10,EXTI_LINE10
*   EXTI_PORTA,EXTI_PIN11,EXTI_LINE11
*   EXTI_PORTB,EXTI_PIN11,EXTI_LINE11
*   EXTI_PORTC,EXTI_PIN11,EXTI_LINE11
*   EXTI_PORTA,EXTI_PIN12,EXTI_LINE12
*   EXTI_PORTB,EXTI_PIN12,EXTI_LINE12
*   EXTI_PORTC,EXTI_PIN12,EXTI_LINE12
*   EXTI_PORTA,EXTI_PIN13,EXTI_LINE13
*   EXTI_PORTB,EXTI_PIN13,EXTI_LINE13
*   EXTI_PORTC,EXTI_PIN13,EXTI_LINE13
*   EXTI_PORTA,EXTI_PIN14,EXTI_LINE14
*   EXTI_PORTB,EXTI_PIN14,EXTI_LINE14
*   EXTI_PORTC,EXTI_PIN14,EXTI_LINE14
*   EXTI_PORTA,EXTI_PIN15,EXTI_LINE15
*   EXTI_PORTB,EXTI_PIN15,EXTI_LINE15
*   EXTI_PORTC,EXTI_PIN15,EXTI_LINE15

*/
#define DHT22_u8EXTI_PIN_CONFIG         EXTI_PORTA,EXTI_PIN11,EXTI_LINE11

/****  THEN Separate The Value  In This Macros
 *  Example:- if your choice is  *** EXTI_PORTA,EXTI_PIN0,EXTI_LINE0 *** then
 *  DHT22_u8PORT  must be represents as  EXTI_PORTA and
 *  DHT22_u8PIN   must be represents as  EXTI_PIN0
 *
 *  *****/
#define DHT22_u8PORT          EXTI_PORTA
#define DHT22_u8PIN           EXTI_PIN11
#define  DHT22_u8NVIC_DHT22Q      NVIC_EXTI15_10




 /**** Don't Touch This Code  *****/
 /*
  *
  *      **                   		          ***********
  *      **   **                   ********        **
  *      **      **     **  **     **    **        **
  *      **      **   **      **   **    **        **
  *      **      **      ** **     **    **        **
  *      **   **
  *
  *
  * */

/*
#if DHT22_u8PIN == EXTI_PIN0
#define DHT22_u8NVIC_DHT22Q      NVIC_EXTI11
#elif DHT22_u8PIN == EXTI_PIN1
#define DHT22_u8NVIC_DHT22Q      NVIC_EXTI1
#elif DHT22_u8PIN == EXTI_PIN2
#define DHT22_u8NVIC_DHT22Q      NVIC_EXTI2
#elif DHT22_u8PIN == EXTI_PIN3
#define DHT22_u8NVIC_DHT22Q      NVIC_EXTI3
#elif DHT22_u8PIN == EXTI_PIN4
#define DHT22_u8NVIC_DHT22Q      NVIC_EXTI4
#elif (DHT22_u8PIN >= EXTI_PIN5) && (DHT22_u8PIN <= EXTI_PIN9)
#define DHT22_u8NVIC_DHT22Q      NVIC_EXTI9_5
#elif (DHT22_u8PIN >= EXTI_PIN10) && (DHT22_u8PIN <= EXTI_PIN515)
#define DHT22_u8NVIC_DHT22Q      NVIC_EXTI15_10
#else #warning"Wrong"
#endif

*/



/*****************************************************************************************************************/
/*****************************************************************************************************************/

#endif

