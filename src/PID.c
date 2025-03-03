/**************************************************************/
/****************** Name	: MOHAMED ELSAYED *****************/
/****************** Date	: 4/1/2021        *****************/
/****************** Version : 1.0V            *****************/
/****************** SWC		: PID             *****************/
/**************************************************************/


#include "PID.h"

extern u32 Global_u32CurrentTime;



/***************************************************************************************/
/* Description! Apply Initialization Sequence For PID controller                       */
/* Input      ! address of STRUCT contains PID Controller                              */
/* Output     ! Nothing                                                                */
/***************************************************************************************/
void PID_voidInit(PIDController *Copy_ptrStructPID) {

	/* Clear controller variables */
	Copy_ptrStructPID->PrevTime=0;
	Copy_ptrStructPID->PrevIntgral = 0;
	Copy_ptrStructPID->PrevError  = 0;


	Copy_ptrStructPID->Control_Signal =0;

}






/***************************************************************************************/
/* Description! Update PID controller With Measurement                                 */
/* Input      ! address of  STRUCT contains  PID Controller, SetPiont, Position        */
/* Output     ! Error State                                                            */
/***************************************************************************************/
void PID_voidUpdate(PIDController *Copy_ptrStructPID, f32 Copy_f32setpoint, s32 Copy_s32measurement) {

	/* calculate Delta T */
	f32 Local_f32Delta_T=(float)((Global_u32CurrentTime - Copy_ptrStructPID->PrevTime)/1000.0);

	if(Local_f32Delta_T== 0.0 ){Local_f32Delta_T=1;}

	/* Update Previous Time */
	Copy_ptrStructPID->PrevTime=Global_u32CurrentTime;

	/* Calculate Error signal e(t)*/
    f32 Error = (float)(Copy_f32setpoint - Copy_s32measurement);


    /* Calculate Proportional Term*/
    f32 Proportional = (float)(Copy_ptrStructPID->Kp * Error);

    /* Calculate Integral Term*/
     f32 Integral = (float)( (Copy_ptrStructPID->Ki) * ( (Copy_ptrStructPID->PrevIntgral) + (Error * Local_f32Delta_T) ) );

     /* Calculate Derivative Term*/
     f32 Derivative = (float)( (Copy_ptrStructPID->Kd) * (Error - Copy_ptrStructPID->PrevError) / (Local_f32Delta_T) );

     /* Generate Control Signal u(t)*/
     Copy_ptrStructPID->Control_Signal= (float)(Proportional + Integral + Derivative);

	 /* Update  Previous Error */
     Copy_ptrStructPID->PrevError = Error;

     /* Update  Previous Integral */
     Copy_ptrStructPID->PrevIntgral =(float) ( (Copy_ptrStructPID->PrevIntgral) + (Error * Local_f32Delta_T) );

}
