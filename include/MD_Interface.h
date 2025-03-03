/**************************************************************/
/****************** Name	: MOHAMED ELSAYED *****************/
/****************** Date	: 24/1/2021       *****************/
/****************** Version : 1.0V            *****************/
/****************** SWC		: MD              *****************/
/**************************************************************/
#ifndef MD_INTERFACE_H
#define MD_INTERFACE_H



typedef enum {
	MD_MOVE_FORWARD=0b00000101,
	MD_MOVE_BACK=0b00001010,
	MD_MOVE_FORWORD_RIGHT=0b00000100,
	MD_MOVE_FORWORD_LEFT=0b00000001,
	MD_MOVE_BACK_RIGHT=0b00001000,
	MD_MOVE_BACK_LEFT=0b00000010,
	MD_MOVE_ROTATE_LEFT=0b00000110,
	MD_MOVE_ROTATE_RIGHT=0b00001001,
	MD_NO_MOVE=0

}MD_enumDirection;


/***************************************************************************************/
/********************************** Function Definition ********************************/
/***************************************************************************************/

/***************************************************************************************/
/* Description! Apply initialization sequence for Motor Driver Pins                    */
/* Input      ! Nothing                                                                */
/* Output     ! Error State                                                            */
/***************************************************************************************/
u8 MD_u8PinInit(void);

/***************************************************************************************/
/* Description! Apply motion													       */
/* Input      ! Direction && Duty Cycle                                                */
/* Output     ! Error State                                                            */
/***************************************************************************************/
u8 MD_u8Move(MD_enumDirection Copy_enumDirection,u8 Copy_u8DutyCycle_R,u8 Copy_u8DutyCycle_L);





















#endif
