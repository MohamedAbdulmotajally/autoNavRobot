#ifndef TIMER2_H
#define TIMER2_H



/***************************************************************************************/
/********************************** MACROS *********************************************/
/***************************************************************************************/
#define	CR1_ENABLE	1	/* enable the counter */
#define	CR1_URS		0x04
#define	CR1_ARPE	0x80

#define ONE_PULSE	0x08	/* no autoreload */
#define DIR_DOWN	0x10	/* count down (only valid in certain modes) */

#define	UPDATE_IE	1	/* enable update interrupts */

#define	EGR_UG		1
#define	EGR_CC1		2
#define	EGR_CC2		4
#define	EGR_CC3		8
#define	EGR_CC4		0x10

#define CHAN1		0
#define CHAN2		1
#define CHAN3		2
#define CHAN4		3

#define TOGGLE		0x30	/* for ccmr register */




/***************************************************************************************/
/********************************** Function Definition ********************************/
/***************************************************************************************/

/***************************************************************************************/
/* Description! Apply initialization sequence for TIM4                                 */
/* Input      ! Nothing                                                                */
/* Output     ! Nothing                                                                */
/***************************************************************************************/
void TIM4_voidInit();

/***************************************************************************************/
/* Description! Set PWM for TIM4                                                       */
/* Input      ! PWM value                                                              */
/* Output     ! Error State                                                            */
/***************************************************************************************/
u8 TIM4_u8SetDuttyCycle(u8 Copy_u8DuttyCycle);

/***************************************************************************************/
/* Description! Apply initialization sequence for TIM3                                 */
/* Input      ! Nothing                                                                */
/* Output     ! Nothing                                                                */
/***************************************************************************************/
void TIM3_voidInit();

/***************************************************************************************/
/* Description! Set PWM for TIM3                                                       */
/* Input      ! PWM value                                                              */
/* Output     ! Error State                                                            */
/***************************************************************************************/
u8 TIM3_u8SetDuttyCycle(u8 Copy_u8DuttyCycle);

/***************************************************************************************/
/* Description! Set Interval Periodic For TIM2                                         */
/* Input      ! Interval Value                                                         */
/* Output     ! Error State                                                            */
/***************************************************************************************/
u8 TIM2_u8SetIntervalPeriodic(u32 Copy_u32Ticks, void (*Copy_pfun)(void));




































#endif
