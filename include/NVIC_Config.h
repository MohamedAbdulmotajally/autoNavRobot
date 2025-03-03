/**************************************************************/
/****************** Name	: MOHAMED ELSAYED *****************/
/****************** Date	: 20/9/2021       *****************/
/****************** Version : 1.0V            *****************/
/****************** SWC		: NVIC            *****************/
/**************************************************************/

#ifndef NVIC_CONFIG_H
#define NVIC_CONFIG_H




/**************** CHOOSE FROM THIS OPTION :
 * SCP_U32_PRIORITY_FIELD_2_GROUP_2_SUB
 * SCP_U32_PRIORITY_FIELD_3_GROUP_1_SUB
 * SCP_U32_PRIORITY_FIELD_4_GROUP_0_SUB
 * SCP_U32_PRIORITY_FIELD_0_GROUP_4_SUB
  **/
#define NVIC_SCP_U32_PRIORITY_FIELD    SCP_U32_PRIORITY_FIELD_2_GROUP_2_SUB

















#if NVIC_SCP_U32_PRIORITY_FIELD == SCP_U32_PRIORITY_FIELD_2_GROUP_2_SUB
	#define NVIC_u8REG_GROUP_SHIFT    2
    #define NVIC_u8NO_OF_GROUP        4
    #define NVIC_u8NO_OF_SUB          4


#elif NVIC_SCP_U32_PRIORITY_FIELD == SCP_U32_PRIORITY_FIELD_3_GROUP_1_SUB
	#define NVIC_u8REG_GROUP_SHIFT    1
    #define NVIC_u8NO_OF_GROUP        8
    #define NVIC_u8NO_OF_SUB          2


#elif NVIC_SCP_U32_PRIORITY_FIELD == SCP_U32_PRIORITY_FIELD_4_GROUP_0_SUB
	#define NVIC_u8REG_GROUP_SHIFT    0
    #define NVIC_u8NO_OF_GROUP        16
    #define NVIC_u8NO_OF_SUB          1


#elif NVIC_SCP_U32_PRIORITY_FIELD == SCP_U32_PRIORITY_FIELD_0_GROUP_4_SUB
	#define NVIC_u8REG_GROUP_SHIFT    0
    #define NVIC_u8NO_OF_GROUP        1
    #define NVIC_u8NO_OF_SUB          16



#endif


#endif
