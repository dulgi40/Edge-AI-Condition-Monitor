/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2026 STMicroelectronics.
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
#include "gpio.h"

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

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
volatile uint32_t cnt = 0;
volatile int count = 0;
volatile uint8_t flag = 0;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
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
  /* USER CODE BEGIN 2 */

  // GPIO ON/OFF TEST
  *(uint32_t*)0x40021018 |= (1<<3);
  *(uint32_t*)0x40010C04 &= ~(0xF << 16);
  *(uint32_t*)0x40010C04 |= (2<<16);
 // *(uint32_t*)0x40010C10 |= 1<<12;
  // GPIO ON/OFF TEST END





  // I2C Software Reset
  *(uint32_t*)0x40005400 |= (1 << 15);
  *(uint32_t*)0x40005400 &= ~(1 << 15);

  // I2C Init
  *(uint32_t*)0x4002101C |= 1 << 21;

  *(uint32_t*)0x40010C00 |= (0xFF000000);  // 그 자리에 0xEE (1110 1110)를 삽입
  *(uint32_t *)0x40021018 |= (1 << 0);





  // I2C Setting
  *(uint32_t*)0x40005404 |= (0b001000) << 0;
  *(uint32_t*)0x40005404 |= (1 << 8);
  *(uint32_t*)0x4000541C |= (0b101000) << 0;
  *(uint32_t*)0x40005420 = 9;                   // TRISE: 9

  //*(uint32_t*)0x40005400 |= 1 << 15;
  *(uint32_t*)0x40005400 |= (1 << 0);

  *(uint32_t*)0x40005400 |= (1 << 10); // ACK


  // TIM2 EN
  *(uint32_t*)0x4002101C |= 1 << 0; // RCC APB1 EN

  // TIM2 Setting
  *(uint32_t*)0x40000028 = 7; // TIM2 PSC
  *(uint32_t*)0x4000002C = 999; // TIM2 ARR
 // *(uint32_t*)0x40000014 |= 1<<0; // EGR Update
//  *(volatile uint32_t*)0x40000010 &= ~(1 << 0); // SR Flag Clear


  *(uint32_t*)0x4000000C |= (1 << 0); // DIER
  *(uint32_t*)0xE000E100 |= (1<<28); // NVIC ON

  *(volatile uint32_t*)0x40000000 = 1; // CR1 (CEN)



  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
	  if(count>=500){
		  if(flag == 0){
			  *(uint32_t*)0x40010C10 |= 1<<12;
			  count = 0;
			  flag = 1;
		  }
		  else{
			  *(uint32_t*)0x40010C10 |= 1<<28;
			  count = 0;
			  flag = 0;
		  }

	  }

	  /*
	  // Communication Start

	  *(uint32_t*)0x40005400 |=  (1 << 8); // PE=1 AND START=1
	  while(!(*(uint32_t*)0x40005414 & (1<<0)));
	  *(uint32_t*)0x40005410 = (0x48 << 1);

	  while(!(*(uint32_t*)0x40005414 & (1 << 1)));
	  uint32_t temp = *(volatile uint32_t*)0x40005414; // SR1 읽기 (이미 while에서 함)
	  temp = *(volatile uint32_t*)0x40005418;          // SR2 읽기 (이게 핵심!)

	  // 2. 전송할 레지스터 주소 쓰기 (예: 온도 센서의 Pointer Register 0x00)
	  *(volatile uint32_t*)0x40005410 = 0x00;

	  // 3. 데이터가 전송 완료(TXE=1)될 때까지 대기
	  while(!(*(volatile uint32_t*)0x40005414 & (1 << 7))); // TXE: Data register empty

*/


	  uint8_t pData[2];

	  // --- 1. Write Sequence (어떤 레지스터를 읽을지 지정: 0x00) ---
	  *(volatile uint32_t*)0x40005400 |= (1 << 8);            // START 생성
	  while(!(*(volatile uint32_t*)0x40005414 & (1 << 0)));    // SB(Start Bit) 확인

	  *(volatile uint32_t*)0x40005410 = (0x48 << 1);          // Address + Write(0)
	  while(!(*(volatile uint32_t*)0x40005414 & (1 << 1)));    // ADDR 확인 (수신 대기)

	  // [ADDR 클리어] SR1은 위 while에서 읽었으니 SR2만 읽어주면 됨
	  (void)*(volatile uint32_t*)0x40005418;

	  *(volatile uint32_t*)0x40005410 = 0x00;                 // Pointer Register (0x00)
	  while(!(*(volatile uint32_t*)0x40005414 & (1 << 7)));    // TXE 확인 (데이터 비워짐)

	  // --- 2. Read Sequence (실제 데이터 2바이트 가져오기) ---
	  *(volatile uint32_t*)0x40005400 |= (1 << 8);            // Re-START 생성
	  while(!(*(volatile uint32_t*)0x40005414 & (1 << 0)));    // SB 확인

	  *(volatile uint32_t*)0x40005410 = (0x48 << 1) | 1;      // Address + Read(1)
	  while(!(*(volatile uint32_t*)0x40005414 & (1 << 1)));    // ADDR 확인

	  // [중요] 2바이트 읽기 준비: ADDR 클리어 전 ACK를 켜둬야 함
	  *(volatile uint32_t*)0x40005400 |= (1 << 10);           // ACK=1
	  (void)*(volatile uint32_t*)0x40005418;                  // ADDR 클리어 (SR2 읽기)

	  // 첫 번째 바이트 수신 대기
	  while(!(*(volatile uint32_t*)0x40005414 & (1 << 6)));    // RXNE 확인
	  pData[0] = *(volatile uint32_t*)0x40005410;             // MSB 읽기

	  // 두 번째 바이트 수신 전 NACK와 STOP 세팅 (마지막 바이트니까!)
	  *(volatile uint32_t*)0x40005400 &= ~(1 << 10);          // NACK 세팅 (ACK=0)
	  *(volatile uint32_t*)0x40005400 |= (1 << 9);            // STOP 생성

	  // 두 번째 바이트 수신 대기
	  while(!(*(volatile uint32_t*)0x40005414 & (1 << 6)));    // RXNE 확인
	  pData[1] = *(volatile uint32_t*)0x40005410;             // LSB 읽기


	  HAL_Delay(100);
    /* USER CODE END WHILE */

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

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */
void TIM2_IRQHandler(void) {
    // 1. UIF 플래그를 지웁니다 (이걸 안 하면 계속 인터럽트가 발생함)
    *(volatile uint32_t*)0x40000010 &= ~(1 << 0);

    // 2. 여기에 동준님이 원하는 코드 (예: LED 토글, 변수 증가)를 넣으세요

    count++;
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
#ifdef USE_FULL_ASSERT
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
