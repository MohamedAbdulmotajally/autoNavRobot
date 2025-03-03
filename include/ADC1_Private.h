/**************************************************************/
/****************** Name	: MOHAMED ELSAYED *****************/
/****************** Date	: 27/5/2022       *****************/
/****************** Version : 1.0V            *****************/
/****************** SWC		: ADC1            *****************/
/**************************************************************/
#ifndef ADC1_PRIVATE_H
#define ADC1_PRIVATE_H



/************************ Control Register 1 MACROS ********************************/
/**********************************************************************************/
#define ADC1_u8_REGULAR_AWD_DISABLE                                 (0<<23)
#define ADC1_u8_REGULAR_AWD_EN                                      (1<<23)

#define ADC1_u8_INJECT_AWD_DISABLE                                  (0<<22)
#define ADC1_u8_INJECT_AWD_EN									    (1<<22)

#define ADC1_u8_INDEPENDENT_MODE         	    	             	(0<<16)
#define ADC1_u8_REGULAR_PLUS_INJECT_SIMULTANOUS_MODE                (1<<16)
#define ADC1_u8_REGULAR_SIMULTANOUS_PLUS_ALTER_TRIGGER_MODE         (2<<16)
#define ADC1_u8_INJECT_SIMULTANOUS_PLUS_FAST_INTERLEAVED_MODE       (3<<16)
#define ADC1_u8_INJECT_SIMULTANOUS_PLUS_SLOW_INTERLEAVED_MODE       (4<<16)
#define ADC1_u8_INJECT_SIMULTANOUS_MODE_ONLY             	        (5<<16)
#define ADC1_u8_REGULAR_SIMULTANOUS_MODE_ONLY         	    		(6<<16)
#define ADC1_u8_FAST_INTERLEAVED_MODE_ONLY              	        (7<<16)
#define ADC1_u8_SLOW_INTERLEAVED_MODE_ONLY              	        (8<<16)
#define ADC1_u8_ALTER_TRIGGER_MODE_ONLY              	            (9<<16)

#define ADC1_u8_DISCOUNTINOUS_MODE_COUNT_1_CHANNEL        	        (0<<13)
#define ADC1_u8_DISCOUNTINOUS_MODE_COUNT_2_CHANNEL                  (1<<13)
#define ADC1_u8_DISCOUNTINOUS_MODE_COUNT_3_CHANNEL         	     	(2<<13)
#define ADC1_u8_DISCOUNTINOUS_MODE_COUNT_4_CHANNEL          	    (3<<13)
#define ADC1_u8_DISCOUNTINOUS_MODE_COUNT_5_CHANNEL        	        (4<<13)
#define ADC1_u8_DISCOUNTINOUS_MODE_COUNT_6_CHANNEL             	    (5<<13)
#define ADC1_u8_DISCOUNTINOUS_MODE_COUNT_7_CHANNEL         	        (6<<13)
#define ADC1_u8_DISCOUNTINOUS_MODE_COUNT_8_CHANNEL             	    (7<<13)


#define ADC1_u8_DISCOUNTINOUS_MODE_ON_INJECT_CH_DISABLE     		(0<<12)
#define ADC1_u8_DISCOUNTINOUS_MODE_ON_INJECT_CH_EN             		(1<<12)

#define ADC1_u8_DISCOUNTINOUS_MODE_ON_REGULAR_CH_DISABLE            (0<<11)
#define ADC1_u8_DISCOUNTINOUS_MODE_ON_REGULAR_CH_EN                 (1<<11)

#define ADC1_u8_AUTMATIC_INJECTED_GROUP_CONVERSION_DIABLE          	(0<<10)
#define ADC1_u8_AUTMATIC_INJECTED_GROUP_CONVERSION_EN             	(1<<10)

#define ADC1_u8_ANALOG_WATCHD_EN_IN_ALL_CH                       	(0<<9)            
#define ADC1_u8_ANALOG_WATCHD_EN_IN_SINGLE_CH                    	(1<<9)             

#define ADC1_u8_SCAN_MODE_DISABLE         	                        (0<<8)
#define ADC1_u8_SCAN_MODE_EN                                        (1<<8)

#define ADC1_u8_JEOC_INTERRUPT_DIABLE        	    	         	(0<<7)
#define ADC1_u8_JEOC_INTERRUPT_EN              	                    (1<<7)

#define ADC1_u8_ANALOG_WATCHD_INTERRUPT_DISABLE         	        (0<<6)
#define ADC1_u8_ANALOG_WATCHD_INTERRUPT_EN            	            (1<<6)

#define ADC1_u8_EOC_INTERRUPT_DISABLE       	                    (0<<5)
#define ADC1_u8_EOC_INTERRUPT_EN             	                    (1<<5)

#define ADC1_u8_AWD_CH_0                                             0 
#define ADC1_u8_AWD_CH_1                                             1 
#define ADC1_u8_AWD_CH_2                                             2 
#define ADC1_u8_AWD_CH_3                                             3 
#define ADC1_u8_AWD_CH_4                                             4 
#define ADC1_u8_AWD_CH_5                                             5 
#define ADC1_u8_AWD_CH_6                                             6 
#define ADC1_u8_AWD_CH_7                                             7 
#define ADC1_u8_AWD_CH_8                                             8 
#define ADC1_u8_AWD_CH_9                                             9 
#define ADC1_u8_AWD_CH_10                                            10 
#define ADC1_u8_AWD_CH_11                                            11 
#define ADC1_u8_AWD_CH_12                                            12
#define ADC1_u8_AWD_CH_13                                            13
#define ADC1_u8_AWD_CH_14                                            14
#define ADC1_u8_AWD_CH_15                                            15
#define ADC1_u8_AWD_CH_16                                            16
#define ADC1_u8_AWD_CH_17                                            17
/**********************************************************************************/
/**********************************************************************************/



/************************ Control Register 2 MACROS ********************************/
/**********************************************************************************/
#define ADC1_u8_TEMP_SENSOR_VREFE_DISABLE       	    			(0<<23)
#define ADC1_u8_TEMP_SENSOR_VREFE_EN              	   			    (1<<23)

#define ADC1_u8_SWSTART_REST_STATE         	    					(0<<22)
#define ADC1_u8_SWSTART_START_CONVERSION             	    		(1<<22)

#define ADC1_u8_JSWSTART_REST_STATE         	    				(0<<21)
#define ADC1_u8_JSWSTART_START_CONVERSION             	    		(1<<21)

#define ADC1_u8_CONV_OF_EXTERNAL_EVENT_DISABLE         	    		(0<<20)
#define ADC1_u8_CONV_OF_EXTERNAL_EVENT_EN             	    		(1<<20)

#define ADC1_u8_TIM1_CC1_EVENT         	    	             	    (0<<17)
#define ADC1_u8_TIM1_CC2_EVENT                                      (1<<17)
#define ADC1_u8_TIM1_CC3_EVENT										(2<<17)
#define ADC1_u8_TIM2_CC2_EVENT									    (3<<17)
#define ADC1_u8_TIM3_TRGO_EVENT									    (4<<17)
#define ADC1_u8_TIM4_CC4_EVENT					          	        (5<<17)
#define ADC1_u8_EXTI_LINE11_EVENT         	    	             	(6<<17)
#define ADC1_u8_SW_START					            	        (7<<17)

/* J FOR INJECTION CHANNEL */
#define ADC1_u8_CONV_OF_J_EXTERNAL_EVENT_DISABLE        	        (0<<15)
#define ADC1_u8_CONV_OF_J_EXTERNAL_EVENT_EN             	        (1<<15)

#define ADC1_u8_J_TIM1_TRGO_EVENT         	    	                (0<<12)
#define ADC1_u8_J_TIM1_CC4_EVENT                                    (1<<12)
#define ADC1_u8_J_TIM2_TRGO_EVENT									(2<<12)
#define ADC1_u8_J_TIM2_CC1_EVENT									(3<<12)
#define ADC1_u8_J_TIM3_CC4_EVENT							        (4<<12)
#define ADC1_u8_J_TIM4_TRGO_EVENT					                (5<<12)
#define ADC1_u8_J_EXTI_LINE15_EVENT         	    	           	(6<<12)
#define ADC1_u8_J_SW_START					                        (7<<12)

#define ADC1_u8_RIGHT_ALIGNMENTG       	                            (0<<11)
#define ADC1_u8_LEFT_ALIGNMENTG                            	        (1<<11)

#define ADC1_u8_DMA_DISABLE       	                                (0<<8)
#define ADC1_u8_DMA_EN                                 	            (1<<8)

#define ADC1_u8_CALIBRATION_REG_INIT       	                        (0<<3)
#define ADC1_u8_INIT_CALIBRATION_REG                                (1<<3)

#define ADC1_u8_CALIBRATION_COMPLETED         	                	(0<<2)
#define ADC1_u8_EN_CALIBRATION             	                    	(1<<2)


#define ADC1_u8_SINGLE_CONVERSION_MODE       	                    (0<<1)
#define ADC1_u8_CONTINOUS_CONVERSION_MODE                           (1<<1)


#define ADC1_u8_ADC_DISABLE        	               	                0
#define ADC1_u8_ADC_EN             	                	            1
/**********************************************************************************/
/**********************************************************************************/



/************************** ADC SAMPLE TIME REG ***************************************/
#define ADC1_u8_SMP_1_DOT_5_CYCLE                                            0 
#define ADC1_u8_SMP_7_DOT_5_CYCLE                                            1 
#define ADC1_u8_SMP_13_DOT_5_CYCLE                                           2 
#define ADC1_u8_SMP_28_DOT_5_CYCLE                                           3 
#define ADC1_u8_SMP_41_DOT_5_CYCLE                                           4 
#define ADC1_u8_SMP_55_DOT_5_CYCLE                                           5 
#define ADC1_u8_SMP_71_DOT_5_CYCLE                                           6 
#define ADC1_u8_SMP_239_DOT_5_CYCLE                                          7 
/********************************************************************************/
#endif

