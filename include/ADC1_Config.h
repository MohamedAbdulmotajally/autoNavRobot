/**************************************************************/
/****************** Name	: MOHAMED ELSAYED *****************/
/****************** Date	: 27/5/2022       *****************/
/****************** Version : 1.0V            *****************/
/****************** SWC		: ADC1            *****************/
/**************************************************************/
#ifndef ADC1_CONFIG_H
#define ADC1_CONFIG_H

/************************ Control Register 1 Configuration ********************************/
/**********************************************************************************/
/** bit 23 **/
/* SELECT FORM THIS OPTION:
 * 							ADC1_u8_REGULAR_AWD_DISABLE
 * 						    ADC1_u8_REGULAR_AWD_EN
 * */
#define ADC1_u8_R_AWD_EN	ADC1_u8_REGULAR_AWD_DISABLE

 /** bit 22 **/
 /* SELECT FORM THIS OPTION:
  * 							ADC1_u8_INJECT_AWD_DISABLE
  * 						    ADC1_u8_INJECT_AWD_EN
  * */
#define ADC1_u8_J_AWD_EN	ADC1_u8_INJECT_AWD_DISABLE

 /** bit 19:16  **/
 /* SELECT FORM THIS OPTION:
  * 							ADC1_u8_INDEPENDENT_MODE
  * 						    ADC1_u8_REGULAR_PLUS_INJECT_SIMULTANOUS_MODE
  *								ADC1_u8_REGULAR_SIMULTANOUS_PLUS_ALTER_TRIGGER_MODE
  *                             ADC1_u8_INJECT_SIMULTANOUS_PLUS_FAST_INTERLEAVED_MODE
  *                             ADC1_u8_INJECT_SIMULTANOUS_PLUS_SLOW_INTERLEAVED_MODE
  *                             ADC1_u8_INJECT_SIMULTANOUS_MODE_ONLY
  *                             ADC1_u8_REGULAR_SIMULTANOUS_MODE_ONLY
  *								ADC1_u8_FAST_INTERLEAVED_MODE_ONLY
  *								ADC1_u8_SLOW_INTERLEAVED_MODE_ONLY
  *								ADC1_u8_ALTER_TRIGGER_MODE_ONLY
  * 
  * */
#define ADC1_u8_DUAL_MODE_SEL		ADC1_u8_INDEPENDENT_MODE

 /** bit 15:13  **/
 /* SELECT FORM THIS OPTION:
  * 							ADC1_u8_DISCOUNTINOUS_MODE_COUNT_1_CHANNEL
  * 						    ADC1_u8_DISCOUNTINOUS_MODE_COUNT_2_CHANNEL
  *								ADC1_u8_DISCOUNTINOUS_MODE_COUNT_3_CHANNEL
  *                             ADC1_u8_DISCOUNTINOUS_MODE_COUNT_4_CHANNEL
  *                             ADC1_u8_DISCOUNTINOUS_MODE_COUNT_5_CHANNEL
  *                             ADC1_u8_DISCOUNTINOUS_MODE_COUNT_6_CHANNEL
  *                             ADC1_u8_DISCOUNTINOUS_MODE_COUNT_7_CHANNEL
  *								ADC1_u8_DISCOUNTINOUS_MODE_COUNT_8_CHANNEL
  *					
 * */
#define ADC1_u8_DISCONTINOUS_MODE_CH_COUNT		ADC1_u8_DISCOUNTINOUS_MODE_COUNT_1_CHANNEL

/** bit 12 **/
/* SELECT FORM THIS OPTION:
 * 							ADC1_u8_DISCOUNTINOUS_MODE_ON_INJECT_CH_DISABLE
 * 						    ADC1_u8_DISCOUNTINOUS_MODE_ON_INJECT_CH_EN
 * */
#define ADC1_u8_DCMON_J_CH_EN		ADC1_u8_DISCOUNTINOUS_MODE_ON_INJECT_CH_DISABLE

 /** bit 11 **/
 /* SELECT FORM THIS OPTION:
  * 							ADC1_u8_DISCOUNTINOUS_MODE_ON_REGULAR_CH_DISABLE
  * 						    ADC1_u8_DISCOUNTINOUS_MODE_ON_REGULAR_CH_EN
  * */
#define ADC1_u8_DCMON_R_CH_EN		ADC1_u8_DISCOUNTINOUS_MODE_ON_REGULAR_CH_DISABLE



/** bit 10 **/
/* SELECT FORM THIS OPTION:
 * 							ADC1_u8_AUTMATIC_INJECTED_GROUP_CONVERSION_DIABLE
 * 						    ADC1_u8_AUTMATIC_INJECTED_GROUP_CONVERSION_EN
 * */
#define ADC1_u8_AUTO_J_GROUP_EN			 ADC1_u8_AUTMATIC_INJECTED_GROUP_CONVERSION_DIABLE



/** bit 9 **/
/* SELECT FORM THIS OPTION:
 * 							ADC1_u8_ANALOG_WATCHD_EN_IN_ALL_CH
 * 						    ADC1_u8_ANALOG_WATCHD_EN_IN_SINGLE_CH
 * */
#define ADC1_u8_AWD_SGL             ADC1_u8_ANALOG_WATCHD_EN_IN_ALL_CH


/** bit 8 **/
//This bit is setand cleared by software to enable / disable Scan mode.In Scan mode, the
//inputs selected through the ADC_SQRx or ADC_JSQRx registers are converted.
/* SELECT FORM THIS OPTION:
 * 							ADC1_u8_SCAN_MODE_DISABLE
 * 						    ADC1_u8_SCAN_MODE_EN
 * */
#define ADC1_u8_SCAN			 ADC1_u8_SCAN_MODE_DISABLE


/** bit 7 **/
//nterrupt enable for injected channels
//This bit is setand cleared by software to enable / disable the end of conversion interrupt for
//injected channels.
/* SELECT FORM THIS OPTION:
 * 							ADC1_u8_JEOC_INTERRUPT_DIABLE
 * 						    ADC1_u8_JEOC_INTERRUPT_EN
 * */
#define ADC1_u8_JEOCIE         ADC1_u8_JEOC_INTERRUPT_DIABLE


/** bit 6 **/
/* SELECT FORM THIS OPTION:
 * 							ADC1_u8_ANALOG_WATCHD_INTERRUPT_DISABLE
 * 						    ADC1_u8_ANALOG_WATCHD_INTERRUPT_EN
 * */
#define ADC1_u8_AWDIE        ADC1_u8_ANALOG_WATCHD_INTERRUPT_DISABLE


/** bit 5 **/
/* SELECT FORM THIS OPTION:
 * 							ADC1_u8_EOC_INTERRUPT_DISABLE
 * 						    ADC1_u8_EOC_INTERRUPT_EN
 * */
#define ADC1_u8_EOCIE        ADC1_u8_EOC_INTERRUPT_DISABLE


/** bit 4:0  **/
//AWDCH[4:0]: Analog watchdog channel select bits
//These bits are setand cleared by software.They select the input channel to be guarded by
//the Analog watchdog
/* SELECT FORM THIS OPTION:
 * 							ADC1_u8_AWD_CH_0
 * 						    ADC1_u8_AWD_CH_1
 *							ADC1_u8_AWD_CH_3
 *								::::::::
 *							ADC1_u8_AWD_CH_15
 *							ADC1_u8_AWD_CH_16
 *                          ADC1_u8_AWD_CH_17
 * */
#define ADC1_u8_AWD_CH_SEL         ADC1_u8_AWD_CH_0

/**********************************************************************************/
#define ADC1_u8_CR1_REG_CONFIG			 (ADC1_u8_R_AWD_EN | ADC1_u8_J_AWD_EN | ADC1_u8_DUAL_MODE_SEL | ADC1_u8_DISCONTINOUS_MODE_CH_COUNT | ADC1_u8_DCMON_J_CH_EN | ADC1_u8_DCMON_R_CH_EN | ADC1_u8_AUTO_J_GROUP_EN | ADC1_u8_AWD_SGL | ADC1_u8_SCAN | ADC1_u8_JEOCIE | ADC1_u8_AWDIE | ADC1_u8_EOCIE )
/**********************************************************************************/







/************************ Control Register 2 Configuration ********************************/
/**********************************************************************************/
/** bit 23 **/
/* SELECT FORM THIS OPTION:
 * 							ADC1_u8_TEMP_SENSOR_VREFE_DISABLE
 * 						    ADC1_u8_TEMP_SENSOR_VREFE_EN
 * */
#define ADC1_u8_TMSV_EN       ADC1_u8_TEMP_SENSOR_VREFE_DISABLE

 /** bit 22 **/
//Start conversion of regular channels
//This bit is set by software to start conversionand cleared by hardware as soon as
//conversion starts.It starts a conversion of a group of regular channels if SWSTART is
//selected as trigger event by the EXTSEL[2:0] bits.
 /* SELECT FORM THIS OPTION:
  * 							ADC1_u8_SWSTART_REST_STATE
  * 						    ADC1_u8_SWSTART_START_CONVERSION
  * */
#define ADC1_u8_R_SWSTART       ADC1_u8_SWSTART_REST_STATE

 /** bit 21 **/
 /* SELECT FORM THIS OPTION:
   * 							ADC1_u8_JSWSTART_REST_STATE
   * 						    ADC1_u8_JSWSTART_START_CONVERSION
   * */
#define ADC1_u8_J_SWSTART       ADC1_u8_JSWSTART_REST_STATE


/** bit 20 **/
//EXTTRIG: External trigger conversion mode for regular channels
//This bit is setand cleared by software to enable / disable the external trigger used to start
//conversion of a regular channel group
/* SELECT FORM THIS OPTION:
	 * 							ADC1_u8_CONV_OF_EXTERNAL_EVENT_DISABLE
	 * 						    ADC1_u8_CONV_OF_EXTERNAL_EVENT_EN
	 * */
#define ADC1_u8_EXTTRIG       ADC1_u8_CONV_OF_EXTERNAL_EVENT_EN

/** bit 19:17 **/
//External event select for regular group
//These bits select the external event used to trigger the start of conversion of a regular group :
//For ADC1and ADC2.
/* SELECT FORM THIS OPTION:
 * 							ADC1_u8_TIM1_CC1_EVENT
 * 						    ADC1_u8_TIM1_CC2_EVENT
 *                          ADC1_u8_TIM1_CC3_EVENT
 *							ADC1_u8_TIM2_CC2_EVENT
 *                          ADC1_u8_TIM3_TRGO_EVENT
 *							ADC1_u8_TIM4_CC4_EVENT
 *							ADC1_u8_EXTI_LINE11_EVENT
 *							ADC1_u8_SW_START
 * */
#define ADC1_u8_EXTSEL       ADC1_u8_SW_START


/** bit 15 **/
/* SELECT FORM THIS OPTION:
 * 							ADC1_u8_CONV_OF_J_EXTERNAL_EVENT_DISABLE
 * 						    ADC1_u8_CONV_OF_J_EXTERNAL_EVENT_EN
 * */
#define ADC1_u8_JEXTTRIG      ADC1_u8_CONV_OF_J_EXTERNAL_EVENT_DISABLE

/** bit 14:12 **/
//External event select for injected group
//These bits select the external event used to trigger the start of conversion of an injected
//group :
//For ADC1and ADC2
/* SELECT FORM THIS OPTION:
  * 						ADC1_u8_J_TIM1_TRGO_EVENT
  * 					    ADC1_u8_J_TIM1_CC4_EVENT
  *                         ADC1_u8_J_TIM2_TRGO_EVENT
  *							ADC1_u8_J_TIM2_CC1_EVENT
  *                         ADC1_u8_J_TIM3_CC4_EVENT
  *							ADC1_u8_J_TIM4_TRGO_EVENT
  *							ADC1_u8_J_EXTI_LINE15_EVENT
  *							ADC1_u8_J_SW_START
  * */
#define ADC1_u8_JEXTSEL       ADC1_u8_J_SW_START

/** bit 11 **/
/* SELECT FORM THIS OPTION:
   * 							ADC1_u8_RIGHT_ALIGNMENTG
   * 						    ADC1_u8_LEFT_ALIGNMENTG
   * */
#define ADC1_u8_DATA_ALIGNMENT      ADC1_u8_RIGHT_ALIGNMENTG

/** bit 8 **/
/* SELECT FORM THIS OPTION:
 * 							ADC1_u8_DMA_DISABLE
 * 						    ADC1_u8_DMA_EN
 * */
#define ADC1_u8_DMAEN      ADC1_u8_DMA_DISABLE

/** bit 3 **/
//Note : If RSTCAL is set when conversion is ongoing, additional cycles are required to clear the
//calibration registers.
/* SELECT FORM THIS OPTION:
 * 							ADC1_u8_CALIBRATION_REG_INIT
 * 						    ADC1_u8_INIT_CALIBRATION_REG
 * */
#define ADC1_u8_RSTCAL       ADC1_u8_CALIBRATION_REG_INIT


/** bit 2 **/
//CAL: A / D Calibration
//This bit is set by software to start the calibration.It is reset by hardware after calibration is
//complete.
/* SELECT FORM THIS OPTION:
 * 							ADC1_u8_CALIBRATION_COMPLETED
 * 						    ADC1_u8_EN_CALIBRATION
 * */
#define ADC1_u8_CAL       ADC1_u8_CALIBRATION_COMPLETED


/** bit 1 **/
//CONT: Continuous conversion
//This bit is setand cleared by software.If set conversion takes place continuously till this bit is
//reset.
/* SELECT FORM THIS OPTION:
 * 							ADC1_u8_SINGLE_CONVERSION_MODE
 * 						    ADC1_u8_CONTINOUS_CONVERSION_MODE
 * */
#define ADC1_u8_CONT     ADC1_u8_CONTINOUS_CONVERSION_MODE


/** bit 0 **/
/* SELECT FORM THIS OPTION:
 * 							ADC1_u8_ADC_DISABLE
 * 						    ADC1_u8_ADC_EN
 * */
#define ADC1_u8_ADCEN     ADC1_u8_ADC_EN
/**********************************************************************************/
#define ADC1_u8_CR2_REG_CONFIG	 (ADC1_u8_ADCEN | ADC1_u8_CONT | ADC1_u8_CAL | ADC1_u8_RSTCAL | ADC1_u8_DMAEN | ADC1_u8_DATA_ALIGNMENT | ADC1_u8_JEXTSEL | ADC1_u8_JEXTTRIG | ADC1_u8_EXTSEL | ADC1_u8_EXTTRIG | ADC1_u8_J_SWSTART | ADC1_u8_R_SWSTART | ADC1_u8_TMSV_EN )
/**********************************************************************************/





/************************** ADC SAMPLE TIME REG ***************************************/
/* SELECT FORM THIS OPTION:
 * 							ADC1_u8_SMP_1_DOT_5_CYCLE
 * 						    ADC1_u8_SMP_7_DOT_5_CYCLE
 *							ADC1_u8_SMP_13_DOT_5_CYCLE
 *						    ADC1_u8_SMP_28_DOT_5_CYCLE
 *							ADC1_u8_SMP_41_DOT_5_CYCLE
 *							ADC1_u8_SMP_55_DOT_5_CYCLE
 *							ADC1_u8_SMP_71_DOT_5_CYCLE
 *							ADC1_u8_SMP_239_DOT_5_CYCLE
 * 
 * */
#define  ADC1_u8_SAMPLING_TIME_CH0		ADC1_u8_SMP_28_DOT_5_CYCLE
#define  ADC1_u8_SAMPLING_TIME_CH1		ADC1_u8_SMP_1_DOT_5_CYCLE
#define  ADC1_u8_SAMPLING_TIME_CH2		ADC1_u8_SMP_1_DOT_5_CYCLE
#define  ADC1_u8_SAMPLING_TIME_CH3		ADC1_u8_SMP_1_DOT_5_CYCLE
#define  ADC1_u8_SAMPLING_TIME_CH4		ADC1_u8_SMP_1_DOT_5_CYCLE
#define  ADC1_u8_SAMPLING_TIME_CH5		ADC1_u8_SMP_1_DOT_5_CYCLE
#define  ADC1_u8_SAMPLING_TIME_CH6		ADC1_u8_SMP_1_DOT_5_CYCLE
#define  ADC1_u8_SAMPLING_TIME_CH7		ADC1_u8_SMP_1_DOT_5_CYCLE
#define  ADC1_u8_SAMPLING_TIME_CH8		ADC1_u8_SMP_1_DOT_5_CYCLE
#define  ADC1_u8_SAMPLING_TIME_CH9		ADC1_u8_SMP_1_DOT_5_CYCLE
#define  ADC1_u8_SAMPLING_TIME_CH10	    ADC1_u8_SMP_1_DOT_5_CYCLE
#define  ADC1_u8_SAMPLING_TIME_CH11     ADC1_u8_SMP_1_DOT_5_CYCLE
#define  ADC1_u8_SAMPLING_TIME_CH12     ADC1_u8_SMP_1_DOT_5_CYCLE
#define  ADC1_u8_SAMPLING_TIME_CH13     ADC1_u8_SMP_1_DOT_5_CYCLE
#define  ADC1_u8_SAMPLING_TIME_CH14     ADC1_u8_SMP_1_DOT_5_CYCLE
#define  ADC1_u8_SAMPLING_TIME_CH15     ADC1_u8_SMP_1_DOT_5_CYCLE
#define  ADC1_u8_SAMPLING_TIME_CH16     ADC1_u8_SMP_1_DOT_5_CYCLE
#define  ADC1_u8_SAMPLING_TIME_CH17     ADC1_u8_SMP_1_DOT_5_CYCLE

/********************************************************************************/
/************************** ADC SQR1,2 ******************************************/
/* SELECT FORM THIS OPTION:
 * The Total No of conversion
 * 						    	1
 * 						        2
 *                              ::
 *						     	15
 *							    16
 *
 * */
#define  ADC1_u8_TOTAL_NO_OF_CONV		1



/* SELECT FORM THIS OPTION:
  * 							ADC1_u8_AWD_CH_0
  * 						    ADC1_u8_AWD_CH_1
  *							    ADC1_u8_AWD_CH_3
  *								    ::::::::
  *							   ADC1_u8_AWD_CH_15
  *							   ADC1_u8_AWD_CH_16
  *                            ADC1_u8_AWD_CH_17
* */
//These bits are written by software with the channel number (0..17) assigned as the 16th in
//the conversion sequence.
#define  ADC1_u8_16TH_CONV     ADC1_u8_AWD_CH_17
#define  ADC1_u8_15TH_CONV     ADC1_u8_AWD_CH_16
#define  ADC1_u8_14TH_CONV     ADC1_u8_AWD_CH_15
#define  ADC1_u8_13TH_CONV     ADC1_u8_AWD_CH_14
#define  ADC1_u8_12TH_CONV     ADC1_u8_AWD_CH_13
#define  ADC1_u8_11TH_CONV     ADC1_u8_AWD_CH_12
#define  ADC1_u8_10TH_CONV     ADC1_u8_AWD_CH_11
#define  ADC1_u8_9TH_CONV      ADC1_u8_AWD_CH_10
#define  ADC1_u8_8TH_CONV      ADC1_u8_AWD_CH_9
#define  ADC1_u8_7TH_CONV      ADC1_u8_AWD_CH_8
#define  ADC1_u8_6TH_CONV      ADC1_u8_AWD_CH_7
#define  ADC1_u8_5TH_CONV      ADC1_u8_AWD_CH_6
#define  ADC1_u8_4TH_CONV      ADC1_u8_AWD_CH_5
#define  ADC1_u8_3TH_CONV      ADC1_u8_AWD_CH_4
#define  ADC1_u8_2TH_CONV      ADC1_u8_AWD_CH_3
#define  ADC1_u8_1TH_CONV      ADC1_u8_AWD_CH_0
/********************************************************************************/
/********************************************************************************/

#endif
