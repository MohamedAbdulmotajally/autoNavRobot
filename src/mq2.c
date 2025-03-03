/*
 * mq2.c
 *
 *  Created on: Apr 22, 2022
 *      Author: mena shehata
 */


#include <STK_Interface.h>
#include "ADC1_Interface.h"
#include "mq2.h"


float           LPGCurve[3]  = {2.3,0.20,-0.45};   //two points from LPG curve are taken point1:(200,1.6) point2(10000,0.26)
                                                    //take log of each point (lg200, lg 1.6)=(2.3,0.20)  (lg10000,lg0.26)=(4,-0.58)
                                                    //find the slope using these points. take point1 as reference
                                                    //data format:{ x, y, slope};

float           SmokeCurve[3] ={2.3,0.53,-0.43};    //two points from smoke curve are taken point1:(200,3.4) point2(10000,0.62)
                                                    //take log of each point (lg200, lg3.4)=(2.3,0.53)  (lg10000,lg0.63)=(4,-0.20)
                                                    //find the slope using these points. take point1 as reference
                                                    //data format:{ x, y, slope};






float ReadSensor()
{
  int i,res,volt;
  float rs=0;

  ADC1_u8GetResult(&res);
  volt=(res*(5/4096.0));

  for (i=0;i<5;i++) {                                 // take multiple readings and average it.
    rs += (((RL_VALUE*5)/volt)-RL_VALUE);   // rs changes according to gas concentration.
    STK_u8SetBusyWait(50000);
  }

  rs = rs/5;

  return rs;
}


int GetGasPercentage(float rs_ro_ratio, int gas_id)
{
  if ( gas_id == LPG ) {
     return GetPercentage(rs_ro_ratio,LPGCurve);

  } else if ( gas_id == SMOKE ) {
     return GetPercentage(rs_ro_ratio,SmokeCurve);
  }

  return 0;
}


int  GetPercentage(float rs_ro_ratio, float *curve)
{                                                                          //Using slope,ratio(y2) and another point(x1,y1) on line we will find
  return (pow(10,( ((log(rs_ro_ratio)-curve[1])/curve[2]) + curve[0])));   // gas concentration(x2) using x2 = [((y2-y1)/slope)+x1]
                                                                          // as in curves are on logarithmic coordinate, power of 10 is taken to convert result to non-logarithmic.
}
