/**************************************************************/
/****************** Name	: MOHAMED ELSAYED *****************/
/****************** Date	: 4/1/2021        *****************/
/****************** Version : 1.0V            *****************/
/****************** SWC		: PID             *****************/
/**************************************************************/


#ifndef PID_CONTROLLER_H
#define PID_CONTROLLER_H

#include"STD_TYPES.h"

typedef struct {

	/* Controller gains */
	f32 Kp;
	f32 Ki;
	f32 Kd;
	
	/* Controller "memory" */
	f32 PrevError;
	u32 PrevTime;
	f32 PrevIntgral;

	/* Controller output */
	f32 Control_Signal;

} PIDController;


/***************************************************************************************/
/* Description! Apply Initialization Sequence For PID controller                       */
/* Input      ! address of STRUCT contains PID Controller                              */
/* Output     ! Nothing                                                                */
/***************************************************************************************/
void  PID_voidInit(PIDController *Copy_ptrStructPID);


/***************************************************************************************/
/* Description! Update PID controller With Measurement                                 */
/* Input      ! address of  STRUCT contains  PID Controller, SetPiont, Position        */
/* Output     ! Error State                                                            */
/***************************************************************************************/
void PID_voidUpdate(PIDController *Copy_ptrStructPID, f32 Copy_f32setpoint, s32 Copy_s32measurement);

#endif
