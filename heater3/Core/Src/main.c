/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "adc.h"
#include "dma.h"
#include "tim.h"
#include "gpio.h"
#include "SSD_Interface.h"


#include "stm32f1xx_hal.h"



/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */
#define NORMAL_MODE     1
#define TEMP_SET_MODE   2

#define MAX_TEMP 		60
#define	MIN_TEMP		35
/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
uint32_t adc_data;

volatile uint8_t ssd_3_dig[3];
volatile uint8_t data ;
volatile uint8_t up_flag;
volatile uint8_t down_flag;
volatile uint8_t set_flag; // on off
volatile uint8_t time_out;

uint8_t MODE_STAT ;

uint8_t set_temp	= 60;

uint8_t on_of_mode = 0;
uint8_t until_flag = 0;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);

void temp_control(void);

void on_of_control(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_DMA_Init();
  MX_ADC1_Init();
  MX_TIM3_Init();
  MX_TIM2_Init();
  /* USER CODE BEGIN 2 */
  // START THE TIMEER INTERUPY
  HAL_TIM_Base_Start_IT(&htim2);
  HAL_TIM_Base_Start_IT(&htim3);
  HAL_ADC_Start_DMA(&hadc1, &adc_data, 1); //cimsis
  //H_LCD_void_Init();
  // this function take data from adc and put it in adc_data
  /* USER CODE END 2 */

	HAL_NVIC_DisableIRQ(TIM2_IRQn);
  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */
	  switch (MODE_STAT)
	  {
	  case NORMAL_MODE :

		  	ssd_3_dig[0] = ( (adc_data/100) %10);
		  	ssd_3_dig[1] = ( (adc_data/10) %10);
		    ssd_3_dig[2] = (  adc_data %10);
		    temp_control();
	  break ;

	  case TEMP_SET_MODE :
		  ssd_3_dig[0] = (10);  // F
		  ssd_3_dig[1] = ( (set_temp/10) %10);
		  ssd_3_dig[2] = (  set_temp %10);
	  break ;

	  }





	  if(set_flag == 1) // set button
	  {
		  on_of_control();
		  set_flag = 0;
		  HAL_Delay(400); // for debunce
	  }


	  if(up_flag == 1) //  up button
	  {
		  if(MODE_STAT == TEMP_SET_MODE )
		  {
			if(set_temp != MAX_TEMP)
			{
				set_temp+=5 ;
			}
		  }
		  else
		  {
			  MODE_STAT = TEMP_SET_MODE;
		  }

		  time_out = 20;

		  HAL_Delay(400);
		  up_flag = 0;
	  }
	  if(down_flag == 1)// down button
	  {
		 if(MODE_STAT == TEMP_SET_MODE)
		 {
			if(set_temp != MIN_TEMP)
			{
				set_temp-=5 ;
			}
		 }
		 else
		 {

			 MODE_STAT = TEMP_SET_MODE;
		 }
		 time_out = 20;

		  HAL_Delay(400);
	  	 down_flag = 0;
	  }




	  if(time_out == 0)
	  {
		  MODE_STAT = NORMAL_MODE;
		  time_out = 0;
	  }

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
  RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
  PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_ADC;
  PeriphClkInit.AdcClockSelection = RCC_ADCPCLK2_DIV6;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	if(htim->Instance == TIM2) //10ms for multyplexing ssd
	{
		  switch(data)
		  {
		  case 1:

			  HAL_GPIO_WritePin(COM1_GPIO_Port, COM1_Pin, GPIO_PIN_SET);
			  HAL_GPIO_WritePin(COM3_GPIO_Port, COM3_Pin, GPIO_PIN_RESET);
			  SSD_voidDisplay( ssd_3_dig[0]);


			  break ;
		  case 2 :

			  HAL_GPIO_WritePin(COM2_GPIO_Port, COM2_Pin, GPIO_PIN_SET);
			  HAL_GPIO_WritePin(COM1_GPIO_Port, COM1_Pin, GPIO_PIN_RESET);
			  SSD_voidDisplay( ssd_3_dig[1]);
			  break ;

		  case 3 :

			  HAL_GPIO_WritePin(COM3_GPIO_Port, COM3_Pin, GPIO_PIN_SET);
			  HAL_GPIO_WritePin(COM2_GPIO_Port, COM2_Pin, GPIO_PIN_RESET);
			  SSD_voidDisplay( ssd_3_dig[2]);

			  data = 0 ;
			  break ;
		  }
	   data++ ;
	}

  if(htim->Instance == TIM3) //100ms
  {
	  if(time_out > 0)
	  {
		  time_out--;
	  }
  }

}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	if(GPIO_Pin == GPIO_PIN_11)
	{
		set_flag = 1;
	}
	if(GPIO_Pin == GPIO_PIN_10)
	{
		up_flag = 1;
	}
	if(GPIO_Pin == GPIO_PIN_1)
	{
		down_flag = 1;
	}

}

void temp_control(void)
{

	if(on_of_mode == 1)
	{
		if(adc_data <= (set_temp - 5))
		{
			HAL_GPIO_WritePin(red_GPIO_Port, red_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(yellow_GPIO_Port, yellow_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(blue_GPIO_Port, blue_Pin, GPIO_PIN_RESET);
			until_flag = 1;
		}
		else if(adc_data >= (set_temp + 5))
		{
			HAL_GPIO_WritePin(blue_GPIO_Port, blue_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(yellow_GPIO_Port, yellow_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(red_GPIO_Port, red_Pin, GPIO_PIN_RESET);
			until_flag = 1;
		}
		else if(until_flag == 0)
		{
			HAL_GPIO_WritePin(yellow_GPIO_Port, yellow_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(red_GPIO_Port, red_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(blue_GPIO_Port, blue_Pin, GPIO_PIN_RESET);

		}
		else if(adc_data == set_temp)
		{
			until_flag = 0;
		}
	}
}

void on_of_control(void)
{

	if(on_of_mode == 1)
	{
		ssd_3_dig[0] = (11);
		ssd_3_dig[1] = (11);
		ssd_3_dig[2] = (11);
		HAL_Delay(400);
		HAL_NVIC_DisableIRQ(TIM2_IRQn);
		HAL_GPIO_WritePin(red_GPIO_Port, red_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(blue_GPIO_Port, blue_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(yellow_GPIO_Port, yellow_Pin, GPIO_PIN_RESET);

		on_of_mode = 0;
	}
	else
	{
		on_of_mode = 1;
		HAL_NVIC_EnableIRQ(TIM2_IRQn);
	}

}

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
