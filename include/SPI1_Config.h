/**************************************************************/
/****************** Name	: MOHAMED ELSAYED *****************/
/****************** Date	: 31/10/2021       *****************/
/****************** Version : 1.0V            *****************/
/****************** SWC		: SPI1         *****************/
/**************************************************************/
#ifndef SPI1_CONFIG_H
#define SPI1_CONFIG_H

/************************ Control Register 1 Configuration ********************************/
/**********************************************************************************/
/** bit 15 **/
/* SELECT FORM THIS OPTION:
 * 							SPI1_u8_UNIDIRECTIONAL_DATA_MODE
 * 						    SPI1_u8_BIDIRECTIONAL_DATA_MODE
 * */
#define SPI1_u8_DATA_DIRECTION_MODE            SPI1_u8_UNIDIRECTIONAL_DATA_MODE


/** bit 14 **/
/* SELECT FORM THIS OPTION:
 * 							SPI1_u8_BIDIOE_DISABLE_RECEIVE_ONLY
 * 						    SPI1_u8_BIDIOE_ENABLE_TRANSMIT_ONLY
 * */
#define SPI1_u8_BIDIOE			 SPI1_u8_BIDIOE_DISABLE_RECEIVE_ONLY



/** bit 13 **/
/* SELECT FORM THIS OPTION:
 * 							SPI1_u8_CRC_DISABLE
 * 						    SPI1_u8_CRC_ENABLE
 * */
#define SPI1_u8_CRC             SPI1_u8_CRC_DISABLE


/** bit 12 **/
/* SELECT FORM THIS OPTION:
 * 							SPI1_u8_NO_CRC_PHASE
 * 						    SPI1_u8_CRC_PHASE
 * */
#define SPI1_u8_CRC_NEXT			 SPI1_u8_NO_CRC_PHASE



/** bit 11 **/
/* SELECT FORM THIS OPTION:
 * 							SPI1_u8_8BIT_DATA_FRAME_FORMAT
 * 						    SPI1_u8_16BIT_DATA_FRAME_FORMAT
 * */
#define SPI1_u8_DFF         SPI1_u8_8BIT_DATA_FRAME_FORMAT


/** bit 10 **/
/* SELECT FORM THIS OPTION:
 * 							SPI1_u8_RXONLY_DISABLE_FULL_DUPLEX
 * 						    SPI1_u8_RXONLY_ENABLE_RECEIVE_ONLY
 * */
#define SPI1_u8_RXONLY         SPI1_u8_RXONLY_DISABLE_FULL_DUPLEX


/** bit 9 **/
/* SELECT FORM THIS OPTION:
 * 							SPI1_u8_SW_SLAVE_MANAGEMENT_DISABLE
 * 						    SPI1_u8_SW_SLAVE_MANAGEMENT_EN
 * */
#define SPI1_u8_SSM         SPI1_u8_SW_SLAVE_MANAGEMENT_EN


/** bit 8 **/
/* SELECT FORM THIS OPTION:
 * 							SPI1_u8_NSS_FORCE_GND_SLAVE_MODE
 * 						    SPI1_u8_NSS_FORCE_VCC_MASTER_MODE
 * */
#define SPI1_u8_SSI         SPI1_u8_NSS_FORCE_GND_SLAVE_MODE


/** bit 7 **/
/* SELECT FORM THIS OPTION:
 * 							SPI1_u8_MSB_TRANSMIT_FIRST
 * 						    SPI1_u8_LSB_TRANSMIT_FIRST
 * */
#define SPI1_u8_LSBFIRST         SPI1_u8_MSB_TRANSMIT_FIRST


/** bit 6 **/
/* SELECT FORM THIS OPTION:
 * 							SPI1_u8_PERIPHERAL_DISABLE
 * 						    SPI1_u8_PERIPHERAL_ENABLE
 * */
#define SPI1_u8_SPE         SPI1_u8_PERIPHERAL_ENABLE


/** bit 5 to 3 **/
/* SELECT FORM THIS OPTION:
 * 							SPI1_u8_CLCK_DIIDED_BY_2
 * 						    SPI1_u8_CLCK_DIIDED_BY_4
 * 						    SPI1_u8_CLCK_DIIDED_BY_8
 * 						    SPI1_u8_CLCK_DIIDED_BY_16
 * 						    SPI1_u8_CLCK_DIIDED_BY_32
 * 						    SPI1_u8_CLCK_DIIDED_BY_64
 * 						    SPI1_u8_CLCK_DIIDED_BY_128
 * 						    SPI1_u8_CLCK_DIIDED_BY_256
 *
 * */
#define SPI1_u8_BAUD_RATE         SPI1_u8_CLCK_DIIDED_BY_2


/** bit 2 **/
/* SELECT FORM THIS OPTION:
 * 							SPI1_u8_SLAVE_CONFIGURATION
 * 						    SPI1_u8_MASTER_CONFIGURATION
 * */
#define SPI1_u8_MASTER_SELEC         SPI1_u8_SLAVE_CONFIGURATION


/** bit 1 **/
/* SELECT FORM THIS OPTION:
 * 							SPI1_u8_CPOL_TRALLING_EDGE
 * 						    SPI1_u8_CPOL_LEADING_EDGE
 * */
#define SPI1_u8_CPOL         SPI1_u8_CPOL_LEADING_EDGE


/** bit 0 **/
/* SELECT FORM THIS OPTION:
 * 							SPI1_u8_CPHA_READ_WRITE
 * 						    SPI1_u8_CPHA_WRITE_READ
 * */
#define SPI1_u8_CPHA         SPI1_u8_CPHA_WRITE_READ
/**********************************************************************************/
#define SPI1_u8_CR1_REG_CONFIG			 (SPI1_u8_DATA_DIRECTION_MODE | SPI1_u8_BIDIOE | SPI1_u8_CRC | SPI1_u8_CRC_NEXT | SPI1_u8_DFF | SPI1_u8_RXONLY | SPI1_u8_SSM | SPI1_u8_SSI | SPI1_u8_LSBFIRST | SPI1_u8_SPE | SPI1_u8_BAUD_RATE | SPI1_u8_MASTER_SELEC | SPI1_u8_CPOL | SPI1_u8_CPHA)
/**********************************************************************************/







/************************ Control Register 2 Configuration ********************************/
/**********************************************************************************/
/** bit 7 **/
/* SELECT FORM THIS OPTION:
 * 							SPI1_u8_TX_INT_MASKED
 * 						    SPI1_u8_TX_INT_NOT_MASKED
 * */
#define SPI1_u8_TXEIE       SPI1_u8_TX_INT_MASKED


/** bit 6 **/
/* SELECT FORM THIS OPTION:
 * 							SPI1_u8_RX_INT_MASKED
 * 						    SPI1_u8_RX_INT_NOT_MASKED
 * */
#define SPI1_u8_RXNEIE      SPI1_u8_RX_INT_NOT_MASKED



/** bit 5 **/
/* SELECT FORM THIS OPTION:
 * 							SPI1_u8_ERROR_INT_MASKED
 * 						    SPI1_u8_ERROR_INT_NOT_MASKED
 * */
#define SPI1_u8_ERRIE       SPI1_u8_ERROR_INT_NOT_MASKED


/** bit 2 **/
/* SELECT FORM THIS OPTION:
 * 							SPI1_u8_SS_OUTPUT_DISABLE_MULTI_MASTER_WORK
 * 						    SPI1_u8_SS_OUTPUT_EN_MULTI_MASTER_NOT_WORK
 * */
#define SPI1_u8_SSOE        SPI1_u8_SS_OUTPUT_EN_MULTI_MASTER_NOT_WORK


/** bit 1 **/
/* SELECT FORM THIS OPTION:
 * 							SPI1_u8_TX_BUFFER_DMA_DISABLE
 * 						    SPI1_u8_TX_BUFFER_DMA_EN
 * */
#define SPI1_u8_TXDMAEN     SPI1_u8_TX_BUFFER_DMA_DISABLE


/** bit 0 **/
/* SELECT FORM THIS OPTION:
 * 							SPI1_u8_RX_BUFFER_DMA_DISABLE
 * 						    SPI1_u8_RX_BUFFER_DMA_EN
 * */
#define SPI1_u8_RXDMAEN     SPI1_u8_RX_BUFFER_DMA_DISABLE
/**********************************************************************************/
#define SPI1_u8_CR2_REG_CONFIG	 (SPI1_u8_TXEIE | SPI1_u8_RXNEIE | SPI1_u8_ERRIE | SPI1_u8_SSOE | SPI1_u8_TXDMAEN | SPI1_u8_RXDMAEN)
/**********************************************************************************/





/************************** REMAP PIN SPI1 ***************************************/
/* SELECT FORM THIS OPTION:
 * 							SPI1_u8_PIN_REMAP
 * 						    SPI1_u8_PIN_NOT_REMAP
 * */
#define SPI1_u8_PIN_REMAPEN     SPI1_u8_PIN_NOT_REMAP

/********************************************************************************/



/********************************************************************************/
/********************************************************************************/
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
#if SPI1_u8_PIN_REMAPEN == SPI1_u8_PIN_NOT_REMAP
/** if PIN NOT REMAP **/

#if SPI1_u8_MASTER_SELEC == SPI1_u8_MASTER_CONFIGURATION
/** if PIN NOT REMAP AND MASTER  **/
#define SPI1_SCK_PIN_CONFIG 		 GPIO_PORTA,GPIO_PIN5,GPIO_u8OUTPUT_ALTFUN_PUSH_PULL_SPEED_10MHZ

#if SPI1_u8_DATA_DIRECTION_MODE == SPI1_u8_BIDIRECTIONAL_DATA_MODE
/** if pin NOt REMAP AND MASTER AND FULL DUPLEX **/
#define SPI1_MOSI_PIN_CONFIG        GPIO_PORTA,GPIO_PIN7,GPIO_u8OUTPUT_ALTFUN_PUSH_PULL_SPEED_10MHZ
#define SPI1_MISO_PIN_CONFIG        GPIO_PORTA,GPIO_PIN6,GPIO_u8INPUT_FLOATIG

#elif SPI1_u8_DATA_DIRECTION_MODE == SPI1_u8_UNIDIRECTIONAL_DATA_MODE
/** if pin NOt REMAP AND MASTER AND H/f  DUPLEX **/
#define SPI1_MOSI_PIN_CONFIG        GPIO_PORTA,GPIO_PIN7,GPIO_u8OUTPUT_ALTFUN_PUSH_PULL_SPEED_10MHZ

#endif
#elif SPI1_u8_MASTER_SELEC == SPI1_u8_SLAVE_CONFIGURATION
/*  if PIN NOT REMAP AND  slave */
#define SPI1_SCK_PIN_CONFIG 		 GPIO_PORTA,GPIO_PIN5,GPIO_u8INPUT_FLOATIG

#if SPI1_u8_DATA_DIRECTION_MODE == SPI1_u8_BIDIRECTIONAL_DATA_MODE
/** if pin NOt REMAP AND SLAVE AND FULL DUPLEX **/
#define SPI1_MOSI_PIN_CONFIG        GPIO_PORTA,GPIO_PIN7,GPIO_u8INPUT_FLOATIG
#define SPI1_MISO_PIN_CONFIG        GPIO_PORTA,GPIO_PIN6,GPIO_u8OUTPUT_ALTFUN_OPEN_DRAIN_SPEED_10MHZ

#elif SPI1_u8_DATA_DIRECTION_MODE == SPI1_u8_UNIDIRECTIONAL_DATA_MODE
/** if pin NOt REMAP AND SLAVE AND H/f  DUPLEX **/
#define SPI1_MISO_PIN_CONFIG        GPIO_PORTA,GPIO_PIN6,GPIO_u8OUTPUT_ALTFUN_OPEN_DRAIN_SPEED_10MHZ

#endif
#endif
#elif SPI1_u8_PIN_REMAPEN == SPI1_u8_PIN_REMAP
/** if PIN REMAP **/

#if SPI1_u8_MASTER_SELEC == SPI1_u8_MASTER_CONFIGURATION
/** if PIN REMAP AND MASTER  **/
#define SPI1_SCK_PIN_CONFIG 		 GPIO_PORTB,GPIO_PIN3,GPIO_u8OUTPUT_ALTFUN_PUSH_PULL_SPEED_10MHZ

#if SPI1_u8_DATA_DIRECTION_MODE == SPI1_u8_BIDIRECTIONAL_DATA_MODE
/** if pin  REMAP AND MASTER AND FULL DUPLEX **/
#define SPI1_MOSI_PIN_CONFIG        GPIO_PORTB,GPIO_PIN4,GPIO_u8OUTPUT_ALTFUN_PUSH_PULL_SPEED_10MHZ
#define SPI1_MISO_PIN_CONFIG        GPIO_PORTB,GPIO_PIN5,GPIO_u8INPUT_FLOATIG

#elif SPI1_u8_DATA_DIRECTION_MODE == SPI1_u8_UNIDIRECTIONAL_DATA_MODE
/** if pin  REMAP AND MASTER AND H/f  DUPLEX **/
#define SPI1_MOSI_PIN_CONFIG        GPIO_PORTB,GPIO_PIN4,GPIO_u8OUTPUT_ALTFUN_PUSH_PULL_SPEED_10MHZ

#endif

#elif SPI1_u8_MASTER_SELEC == SPI1_u8_SLAVE_CONFIGURATION
/*  if PIN REMAP AND  slave */
#define SPI1_SCK_PIN_CONFIG 		 GPIO_PORTB,GPIO_PIN3,GPIO_u8INPUT_FLOATIG

#if SPI1_u8_DATA_DIRECTION_MODE == SPI1_u8_BIDIRECTIONAL_DATA_MODE
/** if pin REMAP AND SLAVE AND FULL DUPLEX **/
#define SPI1_MOSI_PIN_CONFIG        GPIO_PORTB,GPIO_PIN4,GPIO_u8INPUT_FLOATIG
#define SPI1_MISO_PIN_CONFIG        GPIO_PORTB,GPIO_PIN5,GPIO_u8OUTPUT_ALTFUN_OPEN_DRAIN_SPEED_10MHZ

#elif SPI1_u8_DATA_DIRECTION_MODE == SPI1_u8_UNIDIRECTIONAL_DATA_MODE
/** if pin REMAP AND SLAVE AND H/f  DUPLEX **/
#define SPI1_MISO_PIN_CONFIG        GPIO_PORTB,GPIO_PIN5,GPIO_u8OUTPUT_ALTFUN_OPEN_DRAIN_SPEED_10MHZ

#endif

#endif
#endif
/********************************************************************************/
/********************************************************************************/

#endif
