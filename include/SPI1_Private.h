/**************************************************************/
/****************** Name	: MOHAMED ELSAYED *****************/
/****************** Date	: 31/10/2021       *****************/
/****************** Version : 1.0V            *****************/
/****************** SWC		: SPI1             *****************/
/**************************************************************/
#ifndef SPI1_PRIVATE_H
#define SPI1_PRIVATE_H



/************************ Control Register 1 MACROS ********************************/
/**********************************************************************************/
#define SPI1_u8_UNIDIRECTIONAL_DATA_MODE                (0<<15)
#define SPI1_u8_BIDIRECTIONAL_DATA_MODE                 (1<<15)

#define SPI1_u8_BIDIOE_DISABLE_RECEIVE_ONLY             (0<<14)
#define SPI1_u8_BIDIOE_ENABLE_TRANSMIT_ONLY             (1<<14)

#define SPI1_u8_CRC_DISABLE           					(0<<13)
#define SPI1_u8_CRC_ENABLE             					(1<<13)

#define SPI1_u8_NO_CRC_PHASE           					(0<<12)
#define SPI1_u8_CRC_PHASE             					(1<<12)

#define SPI1_u8_8BIT_DATA_FRAME_FORMAT           	    (0<<11)
#define SPI1_u8_16BIT_DATA_FRAME_FORMAT             	(1<<11)

#define SPI1_u8_RXONLY_DISABLE_FULL_DUPLEX           	(0<<10)
#define SPI1_u8_RXONLY_ENABLE_RECEIVE_ONLY             	(1<<10)

#define SPI1_u8_SW_SLAVE_MANAGEMENT_DISABLE          	(0<<9)             //SWITCH IS CLOSED
#define SPI1_u8_SW_SLAVE_MANAGEMENT_EN               	(1<<9)             //SWITCH IS OPEND SSI Controls The Value of NSS

#define SPI1_u8_NSS_FORCE_GND_SLAVE_MODE         	    (0<<8)
#define SPI1_u8_NSS_FORCE_VCC_MASTER_MODE               (1<<8)

#define SPI1_u8_MSB_TRANSMIT_FIRST         	    		(0<<7)
#define SPI1_u8_LSB_TRANSMIT_FIRST              	    (1<<7)

#define SPI1_u8_PERIPHERAL_DISABLE         	    		(0<<6)
#define SPI1_u8_PERIPHERAL_ENABLE             	        (1<<6)

#define SPI1_u8_CLCK_DIIDED_BY_2        	    		(0<<3)
#define SPI1_u8_CLCK_DIIDED_BY_4             	        (1<<3)
#define SPI1_u8_CLCK_DIIDED_BY_8         	    		(2<<3)
#define SPI1_u8_CLCK_DIIDED_BY_16             	        (3<<3)
#define SPI1_u8_CLCK_DIIDED_BY_32        	    		(4<<3)
#define SPI1_u8_CLCK_DIIDED_BY_64             	        (5<<3)
#define SPI1_u8_CLCK_DIIDED_BY_128         	    		(6<<3)
#define SPI1_u8_CLCK_DIIDED_BY_256             	        (7<<3)

#define SPI1_u8_SLAVE_CONFIGURATION         	        (0<<2)
#define SPI1_u8_MASTER_CONFIGURATION             	    (1<<2)

#define SPI1_u8_CPOL_TRALLING_EDGE         	            (0<<1)
#define SPI1_u8_CPOL_LEADING_EDGE             	        (1<<1)

#define SPI1_u8_CPHA_READ_WRITE        	                0
#define SPI1_u8_CPHA_WRITE_READ             	        1

/**********************************************************************************/



/************************ Control Register 2 MACROS ********************************/
/**********************************************************************************/
#define SPI1_u8_TX_INT_MASKED         	    						(0<<7)
#define SPI1_u8_TX_INT_NOT_MASKED              	   				    (1<<7)

#define SPI1_u8_RX_INT_MASKED         	    						(0<<6)
#define SPI1_u8_RX_INT_NOT_MASKED             	    				(1<<6)

#define SPI1_u8_ERROR_INT_MASKED         	        				(0<<5)
#define SPI1_u8_ERROR_INT_NOT_MASKED             					(1<<5)



#define SPI1_u8_SS_OUTPUT_DISABLE_MULTI_MASTER_WORK        	        (0<<2)
#define SPI1_u8_SS_OUTPUT_EN_MULTI_MASTER_NOT_WORK             	    (1<<2)

#define SPI1_u8_TX_BUFFER_DMA_DISABLE         	                	(0<<1)
#define SPI1_u8_TX_BUFFER_DMA_EN             	                	(1<<1)

#define SPI1_u8_RX_BUFFER_DMA_DISABLE        	               	    0
#define SPI1_u8_RX_BUFFER_DMA_EN             	                	1

/**********************************************************************************/

/************************** REMAP PIN SPI1 ***************************************/
#define SPI1_u8_PIN_REMAP               1
#define SPI1_u8_PIN_NOT_REMAP           0
/********************************************************************************/
#endif

