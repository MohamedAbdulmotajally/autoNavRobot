/* LIB */
#include"STD_TYPES.h"
#include"BITMATH.h"
#include"stm32f103c8.h"


/* MCAL */
#include"RCC_Interface.h"
#include"GPIO_Interface.h"
#include"STK_Interface.h"
#include"SPI1_Interface.h"
#include"NVIC_Interface.h"
#include"EXTI_Interface.h"
#include"TIMER2.h"
#include"STK_Interface.h"
#include"USART_INTERFACE.h"
#include"USART_REG.h"

/* HAL */
#include"MD_Interface.h"
#include"PID.h"
#include"DHT22_Interface.h"
#include"ADC1_Interface.h"
#include"mq2.h"


void updatePosition(void);
void GetCurrentTime(void);
void APP_voidBluetoothControll(void);
void APP_voidSPIControll(void);
void APP_voidGPS(void);

/******** Global VAR ***************/
s32 Global_s32Position=0;
f32 MQ2_u8RO =10;
f32 Global_f32Setpoint = 0.0;
u32 Global_u32CurrentTime=1;
u8 Local_u8Flag1 =1;
u8 Global_u8Direction=MD_MOVE_FORWARD;
f32 KP = 20.0;
f32 KI =  0.00000;
f32 KD  =  0.0;
u8 Global_u8Counter=1;
volatile u8 App_u8Data=0;
volatile u8 App_ARRu8Data[5]={0};
f64 APP_Af64MQ2[2]={0};
u8 Global_u8GAS_Couter=0;
u8 Global_u8GPS_Couter=0;
u8 Global_u8UARTRECIVE=0;
PIDController PID_strControlDC;
f32 MQ2_Local_Res[16]={0},MQ2_Local_LBG[16]={0},MQ2_LocalSmoke[16]={0};
u8 GPS_Global_BUF[100]={0};
volatile u8 GPS_Global_Index=0;
u8 GPS_gpgga[]={'$','G','P','G','G','A'};
/************************************/

/******** App Macros ***************/
#define R_u8FORWORD           1
#define R_u8BACK              2
#define R_u8LEFT              3
#define R_u8RIGHT             4
#define R_u8FORWORD_RIGHT     5
#define R_u8FORWORD_LEFT      6
#define R_u8BACK_RIGHT        7
#define R_u8BACK_LEFT         8
#define R_u8STOP              9
#define R_u8TEMP              10
#define R_u8HUMIDITY          11
#define R_u8GAS_LPG           12
#define R_u8GAS_SMOKE         13
#define R_u8GPSLAT            14
#define R_u8GPSLONG           15
#define REINIT_PID()          Global_u8Counter=1;           \
		Global_s32Position=0;          \
		Global_u32CurrentTime=1;        \
		PID_voidInit(&PID_strControlDC); \
		App_u8Data=255;                   \
		Local_u8Flag1 =0
/************************************/

int main(void)
{

	/********************************************************************/
	/***************************  Local variable ************************/
	/********************************************************************/
	s32 Motor_PWM=0;
	/********************************************************************/


	/********************************************************************/
	/****************************  EN CLK *******************************/
	/********************************************************************/
	/* INTT SYS CLK */
	RCC_u8InitSysClk();

	/* EN GPIOA CLK */
	RCC_u8EnablePeripheralClk(RCC_APB2_BUS,RCC_IOPA);

	/* EN GPIOB CLK */
	RCC_u8EnablePeripheralClk(RCC_APB2_BUS,RCC_IOPB);

	/* EN SPI1 CLK */
	RCC_u8EnablePeripheralClk(RCC_APB2_BUS,RCC_SPI1);

	/* EN TIM4 CLK */
	RCC_u8EnablePeripheralClk(RCC_APB1_BUS,RCC_TIM4);

	/* EN TIM3 CLK */
	//RCC_u8EnablePeripheralClk(RCC_APB1_BUS,RCC_TIM3);

	/* EN TIM2 CLK */
	//RCC_u8EnablePeripheralClk(RCC_APB1_BUS,RCC_TIM2);

	/* EN USART1 CLK */
	RCC_u8EnablePeripheralClk(RCC_APB2_BUS,RCC_USART1);

	/* EN USART3 CLK */
	RCC_u8EnablePeripheralClk(RCC_APB1_BUS,RCC_USART3);

	/* EN ADC1 CLK */
	RCC_u8EnablePeripheralClk(RCC_APB2_BUS,RCC_ADC1);
	/********************************************************************/

	/********************************************************************/
	/***********************  INTERRUPT CONFIG  *************************/
	/********************************************************************/
	//iNIT PRIORITY FEILD
	NVIC_u8InitPriorityField();


	//Assigned Priority to NVIC_EXTI1
	NVIC_u8SetPriority(NVIC_EXTI1,1,1);

	//Assigned Priority TO SPI1
	NVIC_u8SetPriority(NVIC_SPI1,2,2);

	//Assigned Priority TO UART
	NVIC_u8SetPriority(NVIC_USART1,1,2);

	//Enable NVIC_EXTI1
	NVIC_u8EnableInterrupt(NVIC_EXTI1);

	//Enable NVIC_SPI1
	NVIC_u8EnableInterrupt(NVIC_SPI1);

	//Enable NVIC_UART1
	NVIC_u8EnableInterrupt(NVIC_USART1);

	//Enable NVIC_UART3
	NVIC_u8EnableInterrupt(NVIC_USART3);

	//Enable NVIC_TIM4
	NVIC_u8EnableInterrupt(NVIC_TIM4);

	//Enable NVIC_ADC
	//NVIC_u8EnableInterrupt(NVIC_ADC1_2);

	//Enable NVIC_TIM2
	//NVIC_u8EnableInterrupt(NVIC_TIM2);
	/********************************************************************/

	/*******************************************************************************************************/
	/************************************************* INIT  PINS ******************************************/
	/*******************************************************************************************************/
	/*
	  -----------                   ----------
	 | STM_32F1  |                 |   MD     |
	 |           |                 |          |
	 |       PB12|---------------->|IN0       |
	 |       PB13|---------------->|IN1       |
	 |       PB14|---------------->|IN2       |
	 |       PB15|---------------->|IN3       |
	 |           |                 |          |
	  -----------                   ----------

      -----------                   ----------
	 | STM_32F1  |                 | Raspberry|
	 |           |                 |          |
	 |       PA5 |---------------->|SCLK 23   |
	 |       PA6 |---------------->|MISO 21   |
	 |       PA7 |---------------->|MOSI 19   |
	 |       PA4 |---------------->|NSS  24   |
	 |           |                 |          |
	  -----------                   ----------

	   -----------                   ----------
	 | STM_32F1  |                 |SH_Encoder|
	 |           |                 |          |
	 |       PA1 |---------------->|DecoderA  |
	 |       PA2 |---------------->|DecoderB  |
	 |      PA11 |---------------->|DHT22     |
	 |      PA0  |---------------->|MQ2       |
	 |           |                 |          |
	  -----------                   ----------

	   -----------                   ----------
	 | STM_32F1  |                 |  UART    |
	 |           |                 |          |
	 |      PA10 |---------------->|RX        |
	 |       PA9 |---------------->|TX        |
	 |           |---------------->|          |
	 |       b    |---------------->|          |
	 |       gs    |                 |          |
	  -----------                   ----------
	 */

	/*Configure Pins*/
	GPIO_PinConfig_t MOSI_strConfig ={GPIO_PORTA,GPIO_PIN7,GPIO_u8OUTPUT_ALTFUN_OPEN_DRAIN_SPEED_50MHZ};
	GPIO_PinConfig_t MISO_strConfig ={GPIO_PORTA,GPIO_PIN6,GPIO_u8OUTPUT_ALTFUN_PUSH_PULL_SPEED_50MHZ};
	GPIO_PinConfig_t SCLK_strConfig ={GPIO_PORTA,GPIO_PIN5,GPIO_u8OUTPUT_ALTFUN_PUSH_PULL_SPEED_10MHZ};
	GPIO_PinConfig_t DecoderA_strConfig={GPIO_PORTA,GPIO_PIN1,GPIO_u8INPUT_FLOATIG};
	GPIO_PinConfig_t DecoderB_strConfig={GPIO_PORTA,GPIO_PIN2,GPIO_u8INPUT_FLOATIG};
	GPIO_PinConfig_t USART1_strConfig_RX={GPIO_PORTA,GPIO_PIN10,GPIO_u8INPUT_FLOATIG};
	GPIO_PinConfig_t USART1_strConfig_TX={GPIO_PORTA,GPIO_PIN9,GPIO_u8OUTPUT_ALTFUN_PUSH_PULL_SPEED_10MHZ};
	GPIO_PinConfig_t USART3_strConfig_RX={GPIO_PORTB,GPIO_PIN11,GPIO_u8INPUT_FLOATIG};
	GPIO_PinConfig_t USART3_strConfig_TX={GPIO_PORTB,GPIO_PIN10,GPIO_u8OUTPUT_ALTFUN_PUSH_PULL_SPEED_10MHZ};
	GPIO_PinConfig_t TIM4Channel2_strConfig={GPIO_PORTB,GPIO_PIN7,GPIO_u8OUTPUT_ALTFUN_PUSH_PULL_SPEED_50MHZ};
	GPIO_PinConfig_t ADCChannel0_strConfig={GPIO_PORTA,GPIO_PIN0,GPIO_u8INPUT_ANALOG};

	//GPIO_PinConfig_t TIM3Channel3_strConfig={GPIO_PORTB,GPIO_PIN4,GPIO_u8OUTPUT_ALTFUN_PUSH_PULL_SPEED_50MHZ};
	/*GPIO_PinConfig_t MOSI_strConfig ={SPI1_u8_MOSI_PIN_STR_COFIG};
	GPIO_PinConfig_t MISO_strConfig ={SPI1_u8_MISO_PIN_STR_COFIG};
	GPIO_PinConfig_t SCLK_strConfig ={SPI1_u8_SCLK_PIN_STR_COFIG};*/
	GPIO_u8PinInit(&MOSI_strConfig);
	GPIO_u8PinInit(&MISO_strConfig);
	GPIO_u8PinInit(&SCLK_strConfig);
	GPIO_u8PinInit(&USART1_strConfig_RX);
	GPIO_u8PinInit(&USART1_strConfig_TX);
	GPIO_u8PinInit(&USART3_strConfig_RX);
	GPIO_u8PinInit(&USART3_strConfig_TX);
	GPIO_u8PinInit(&DecoderA_strConfig);
	GPIO_u8PinInit(&DecoderB_strConfig);
	GPIO_u8PinInit(&TIM4Channel2_strConfig);
	GPIO_u8PinInit(&ADCChannel0_strConfig);
	//GPIO_u8PinInit(&TIM3Channel3_strConfig);
	/*******************************************************************************************************/
	/*******************************************************************************************************/
	/*******************************************************************************************************/


	/*******************************************************************************************************/
	/**********************************   SYSTEM INIT     **************************************************/
	/*******************************************************************************************************/
	/* INIT STK TIMER */
	STK_u8Init();

	/*INIT Motor Driver*/
	MD_u8PinInit();
	MD_u8Move(MD_NO_MOVE,0,0);

	/* INIT TIM4 Channel 1*/
	TIM4_voidInit();

	/* INIT TIM3 Channel 1*/
	//TIM3_voidInit();

	/* Timer2 INIT */
	//TIM2_u8SetIntervalPeriodic(10000,&GetCurrentTime);

	/* INIT EXTI1 */
	EXTI_Cofig_t EXTI1_Config={EXTI_PORTA,EXTI_PIN1,EXTI_LINE1,EXTI_FALLING_EDGE,&updatePosition};
	EXTI_u8Init(&EXTI1_Config);
	EXTI_u8IntEnable(&EXTI1_Config);

	/*INIT SPI1*/
	SPI1_voidInit();

	/* INTT DHT22 */
	DHT22_u8Init(App_ARRu8Data);

	/* USART1 INIT */
	MUSART_VidInit();
	MUSART1_VidSetCallBack(&APP_voidBluetoothControll);


	/* USART3 INIT */
	MUSART3_VidInit();
	MUSART3_VidSetCallBack(&APP_voidGPS);

	/*PID INIT*/
	PID_strControlDC.Control_Signal=0.0;
	PID_strControlDC.Kp=KP;
	PID_strControlDC.Ki=KI;
	PID_strControlDC.Kd=KD;
	PID_strControlDC.PrevError=0.0;
	PID_strControlDC.PrevIntgral=0.0;
	PID_strControlDC.PrevTime=0.0;

	PID_voidInit(&PID_strControlDC);

	/*Spi Set Call Back*/
	SPI1_u8SetCallBack(&APP_voidSPIControll);

	/* ADC INIT*/
	ADC1_voidInit();
	ADC1_u8Enable();
	ADC1_u8StartConv();

	MQ2_u8RO=ReadSensor()/RO_CLEAN_AIR_FACTOR;
	/*******************************************************************************************************/
	/*******************************************************************************************************/
	/*******************************************************************************************************/

	while(1)
	{
		/*Gas READ*/
		itoa(GetGasPercentage((ReadSensor()/MQ2_u8RO),SMOKE),MQ2_LocalSmoke,10);
		for(Global_u8GAS_Couter=0;Global_u8GAS_Couter<10;Global_u8GAS_Couter++)
		{
			if(MQ2_LocalSmoke[Global_u8GAS_Couter] != 0) APP_Af64MQ2[1]=1;
		}
		itoa(GetGasPercentage((ReadSensor()/MQ2_u8RO),LPG),MQ2_Local_LBG,10);
		for(Global_u8GAS_Couter=0;Global_u8GAS_Couter<10;Global_u8GAS_Couter++)
		{
			if(MQ2_Local_LBG[Global_u8GAS_Couter] != 0) APP_Af64MQ2[0]=1;
		}

		/*APP_Af64MQ2[1]=GetGasPercentage((ReadSensor()/MQ2_u8RO),SMOKE);
		if(APP_Af64MQ2[1] != 0) APP_Af64MQ2[1]=1;
		APP_Af64MQ2[0]=GetGasPercentage((ReadSensor()/MQ2_u8RO),LPG);
		if(APP_Af64MQ2[0] != 0) APP_Af64MQ2[0]=1;*/
		/******************************************************************************************************************************/
		/******************************************************************************************************************************/
		/**************************************************    PID APP     ************************************************************/
		/******************************************************************************************************************************/
		/******************************************************************************************************************************/
		if(App_u8Data == 255 )
		{
			/* Update PID */
			PID_voidUpdate(&PID_strControlDC,Global_f32Setpoint,Global_s32Position);

			/* MOTOR PWR*/
			Motor_PWM=(PID_strControlDC.Control_Signal);
			if(Motor_PWM<0){Motor_PWM *= -1;}
			if(Motor_PWM>100){Motor_PWM=100;}
			/*if( (Global_u32CurrentTime <=100) && (Global_s32Position <= (Global_f32Setpoint / 4.0)))
			{
				Motor_PWM = Global_u32CurrentTime;
			}*/

			/* Motor Direction */
			if(PID_strControlDC.Control_Signal >0)
			{
				if(Global_u8Direction==MD_MOVE_FORWARD){MD_u8Move(MD_MOVE_FORWARD,Motor_PWM,Motor_PWM);}
				else if(Global_u8Direction==MD_MOVE_BACK){MD_u8Move(MD_MOVE_BACK,Motor_PWM,Motor_PWM);}
				else if(Global_u8Direction==MD_MOVE_ROTATE_RIGHT){MD_u8Move(MD_MOVE_ROTATE_RIGHT,Motor_PWM,Motor_PWM);}
				else if(Global_u8Direction==MD_MOVE_ROTATE_LEFT){MD_u8Move(MD_MOVE_ROTATE_LEFT,Motor_PWM,Motor_PWM);}
			}
			else if(PID_strControlDC.Control_Signal <0)
			{
				if(Global_u8Direction==MD_MOVE_FORWARD){MD_u8Move(MD_MOVE_BACK,Motor_PWM,Motor_PWM);}
				else if(Global_u8Direction==MD_MOVE_BACK){MD_u8Move(MD_MOVE_FORWARD,Motor_PWM,Motor_PWM);}
				else if(Global_u8Direction==MD_MOVE_ROTATE_RIGHT){MD_u8Move(MD_MOVE_ROTATE_LEFT,Motor_PWM,Motor_PWM);}
				else if(Global_u8Direction==MD_MOVE_ROTATE_LEFT){MD_u8Move(MD_MOVE_ROTATE_RIGHT,Motor_PWM,Motor_PWM);}
			}
			else
			{
				App_u8Data = 0;
				MD_u8Move(MD_NO_MOVE,0,0);
				Global_u8Direction = MD_NO_MOVE;
			}

		}

		/******************************************************************************************************************************/

	}
	return 0;
}

void updatePosition(void)
{
	u8 Local_u8Check;
	GPIO_PinConfig_t DecoderB1_strConfig={GPIO_PORTA,GPIO_PIN2,GPIO_u8INPUT_FLOATIG};
	GPIO_u8GetPinValue(&DecoderB1_strConfig,&Local_u8Check);
	if(Local_u8Check == GPIO_u8HIGH)
	{
		if(Global_u8Direction==MD_MOVE_FORWARD || Global_u8Direction==MD_MOVE_ROTATE_RIGHT){Global_s32Position -=1;}
		else if(Global_u8Direction==MD_MOVE_BACK || Global_u8Direction==MD_MOVE_ROTATE_LEFT){Global_s32Position +=1;}
	}
	else
	{
		if(Global_u8Direction==MD_MOVE_FORWARD || Global_u8Direction==MD_MOVE_ROTATE_RIGHT){Global_s32Position +=1;}
		else if(Global_u8Direction==MD_MOVE_BACK || Global_u8Direction==MD_MOVE_ROTATE_LEFT){Global_s32Position -=1;}
	}

}

void GetCurrentTime(void)
{
	if(Global_u32CurrentTime < 0xFFFFFFFF)
	{
		Global_u32CurrentTime +=1;
	}
	else {Global_u32CurrentTime =0;}

}


void APP_voidBluetoothControll(void)
{
	/*******************************************************************************************/
	/**************************    Bluetooth polling Control      ******************************/
	/*******************************************************************************************/

	NVIC_u8ClearPendingFlag(NVIC_USART1);
	u8 LOC_u8Data=0;
	LOC_u8Data = MUSART1 -> DR;

	switch(LOC_u8Data)
	{
	case 'F':
	{
		MD_u8Move(MD_MOVE_FORWARD,100,100);
	}
	break;
	case 'B':
	{
		MD_u8Move(MD_MOVE_BACK,100,100);
	}
	break;
	case 'R':
	{
		MD_u8Move(MD_MOVE_ROTATE_RIGHT,100,100);

	}
	break;
	case 'L':
	{
		MD_u8Move(MD_MOVE_ROTATE_LEFT,100,100);
	}
	break;
	case 'S':
	{
		MD_u8Move(MD_NO_MOVE,0,0);
	}
	break;
	default:{MD_u8Move(MD_NO_MOVE,0,0);}
	}


}
void APP_voidSPIControll(void)
{
	/*******************************************************************************************/
	/**************************    SPI               Control      ******************************/
	/*******************************************************************************************/

	NVIC_u8ClearPendingFlag(NVIC_SPI1);
	u8 LOC_u8Data=0;
	LOC_u8Data = SPI1 -> SPI_DR;

	switch(LOC_u8Data)
	{
	case R_u8FORWORD:
	{
		/*Assign Target Position*/
		Global_f32Setpoint=60.0;

		/*SET  The direction*/
		Global_u8Direction=MD_MOVE_FORWARD;

		/*ReIntialize the System*/
		REINIT_PID();
	}
	break;
	case R_u8BACK:
	{
		/*Assign Target Position*/
		Global_f32Setpoint=60.0;

		/*SET  The direction*/
		Global_u8Direction=MD_MOVE_BACK;

		/*ReIntialize the System*/
		REINIT_PID();
	}
	break;
	case R_u8LEFT:
	{
		/*Assign Target Position*/
		Global_f32Setpoint=60.0;

		/*SET  The direction*/
		Global_u8Direction=MD_MOVE_ROTATE_LEFT;

		/*ReIntialize the System*/
		REINIT_PID();

	}
	break;
	case R_u8RIGHT:
	{
		/*Assign Target Position*/
		Global_f32Setpoint=60.0;

		/*SET  The direction*/
		Global_u8Direction=MD_MOVE_ROTATE_RIGHT;

		/*ReIntialize the System*/
		REINIT_PID();
	}
	break;
	case R_u8FORWORD_RIGHT:
	{
		asm("NOP");
	}
	break;
	case R_u8FORWORD_LEFT:
	{
		asm("NOP");
	}
	break;
	case R_u8BACK_RIGHT:
	{
		asm("NOP");
	}
	break;
	case R_u8BACK_LEFT:
	{
		asm("NOP");
	}
	break;
	case R_u8STOP:
	{
		/*Assign Target Position*/
		Global_f32Setpoint=0;

		/*SET  The direction*/
		Global_u8Direction=MD_NO_MOVE;

		/*ReIntialize the System*/
		REINIT_PID();
	}
	break;
	case R_u8TEMP:
	{
		/* Send TEMP Value */
		SPI1_u8SlaveTransmit(App_ARRu8Data[0]);
		SPI1_u8SlaveTransmit(R_u8TEMP);
	}
	break;
	case R_u8HUMIDITY:
	{
		/* Send HUMIDITY Value */
		SPI1_u8SlaveTransmit(App_ARRu8Data[2]);
		SPI1_u8SlaveTransmit(R_u8HUMIDITY);
	}
	break;
	case R_u8GAS_LPG:
	{
		/* Send LPG Value */
		SPI1_u8SlaveTransmit((u8)(APP_Af64MQ2[0]));
		SPI1_u8SlaveTransmit(R_u8GAS_LPG);


	}
	break;
	case R_u8GAS_SMOKE:
	{
		/* Send SMOKE Value */
		SPI1_u8SlaveTransmit((u8)(APP_Af64MQ2[1]));
		SPI1_u8SlaveTransmit(R_u8GAS_SMOKE);
	}
	break;
	case R_u8GPSLAT:
	{
		/* Send Longtud */
		for(Global_u8GPS_Couter=17;Global_u8GPS_Couter<27;Global_u8GPS_Couter++)
		{
			SPI1_u8SlaveTransmit(GPS_Global_BUF[Global_u8GPS_Couter]);
		}
	}
	break;
	case R_u8GPSLONG:
		{
			/* Send Latitud */
			for(Global_u8GPS_Couter=30;Global_u8GPS_Couter<41;Global_u8GPS_Couter++)
			{
				SPI1_u8SlaveTransmit(GPS_Global_BUF[Global_u8GPS_Couter]);
			}
		}
		break;

	default:{asm("NOP");}
	}


}

void APP_voidGPS(void)
{
	/*RECIVE FRAME FORM GPS MODULE*/
	GPS_Global_BUF[GPS_Global_Index]=MUSART3->DR;

	GPS_Global_Index++;

	if(GPS_Global_Index<7)
	{
		if((GPS_Global_BUF[GPS_Global_Index-1]) != (GPS_gpgga[GPS_Global_Index-1]))               // $GPGGA
			GPS_Global_Index=0;
	}
	if(GPS_Global_Index >50)
	{
		GPS_Global_Index=0;
	}
}
