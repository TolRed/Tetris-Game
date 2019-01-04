* C source, ISO-8859 text, with CRLF line terminators

/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * This notice applies to any and all portions of this file
  * that are not between comment pairs USER CODE BEGIN and
  * USER CODE END. Other portions of this file, whether 
  * inserted by the user or by software development tools
  * are owned by their respective copyright owners.
  *
  * Copyright (c) 2018 STMicroelectronics International N.V. 
  * All rights reserved.
  *
  * Redistribution and use in source and binary forms, with or without 
  * modification, are permitted, provided that the following conditions are met:
  *
  * 1. Redistribution of source code must retain the above copyright notice, 
  *    this list of conditions and the following disclaimer.
  * 2. Redistributions in binary form must reproduce the above copyright notice,
  *    this list of conditions and the following disclaimer in the documentation
  *    and/or other materials provided with the distribution.
  * 3. Neither the name of STMicroelectronics nor the names of other 
  *    contributors to this software may be used to endorse or promote products 
  *    derived from this software without specific written permission.
  * 4. This software, including modifications and/or derivative works of this 
  *    software, must execute solely and exclusively on microcontroller or
  *    microprocessor devices manufactured by or for STMicroelectronics.
  * 5. Redistribution and use of this software other than as permitted under 
  *    this license is void and will automatically terminate your rights under 
  *    this license. 
  *
  * THIS SOFTWARE IS PROVIDED BY STMICROELECTRONICS AND CONTRIBUTORS "AS IS" 
  * AND ANY EXPRESS, IMPLIED OR STATUTORY WARRANTIES, INCLUDING, BUT NOT 
  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A 
  * PARTICULAR PURPOSE AND NON-INFRINGEMENT OF THIRD PARTY INTELLECTUAL PROPERTY
  * RIGHTS ARE DISCLAIMED TO THE FULLEST EXTENT PERMITTED BY LAW. IN NO EVENT 
  * SHALL STMICROELECTRONICS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, 
  * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF 
  * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING 
  * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
  * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "stm32f4xx_hal.h"
#include "tol_tft.h"
#include "stdlib.h"
#include "Tahoma10x11.h"
#include "Tahoma18x16.h"
#include "tetris_engine.h"
#include "tetris_bloklar.h"
#include "tetris_bmp.h"
#include "stmpe811_driver.h"



/* Private variables ---------------------------------------------------------*/
I2C_HandleTypeDef hi2c1;
NOR_HandleTypeDef hnor1;
SRAM_HandleTypeDef hsram2;
SRAM_HandleTypeDef hsram3;

tetrisTypeDef tetris_reg;

uint8_t buton_adres=0x88;
uint8_t buton=0;

uint16_t hiz=0;

char txt[20];
char version[7]="V.1.01";

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_FSMC_Init(void);
static void MX_I2C1_Init(void);
static void buton_init(void);
static void buton_kontrol(void);


int main(void){

  HAL_Init();
  SystemClock_Config();

  MX_GPIO_Init();
  MX_FSMC_Init();
  MX_I2C1_Init();
  tft_ili9325_init();
  buton_init();
  tft_ili9325_tarama_yonu(4);

  tetris_genel_ayar();
  basla_bekleme();

  while (1){

	  tetris_reg.buton=0;
	  buton_kontrol();

	  if(tetris_reg.buton==1){	// blok bir kare aşağı
	  	tetris_hareket(1,0);
	  }
	  if(tetris_reg.buton==2){	// blok bir kare sağa
		  tetris_hareket(2,0);
	  }
	  if(tetris_reg.buton==3){	// blok bir kare sola
		  tetris_hareket(3,0);
	  }
	  if(tetris_reg.buton==5){	// blok dönme
		  tetris_reg.blok_yon++;
		  if(tetris_reg.blok_yon==5) tetris_reg.blok_yon=1;
		  tetris_hareket(4,tetris_reg.blok_yon);
	  }

	  // oyun sonraki adımı için sayıcı
	  hiz++;
	  if(tetris_reg.oyun_hiz<=hiz){
		  hiz=0;
		  tetris_hareket(1,0); // blok bir kare aşağı

	  }

	  if(tetris_reg.oyun_bitti==1){
		  //oyun bitti animasyonu yap
		  tetris_reg.oyun_bitti=0;
		  HAL_Delay(2000);
		  tetris_ekran_dose();
	  }

	  // sonraki gelecek olan blok tipini ve rengini belirlicek sayıcılar (bu işlem için timer'da kullanılabilir)
	  tetris_reg.s_b_s++;
	  if(tetris_reg.s_b_s==7) tetris_reg.s_b_s=0;
	  tetris_reg.s_r_s++;
	  if(tetris_reg.s_r_s==6) tetris_reg.s_r_s=1;
	  tetris_reg.s_y_s++;
	  if(tetris_reg.s_y_s==5) tetris_reg.s_y_s=1;
	  // 1 milisaniyelik main döngü beklemesi
	  HAL_Delay(1);

  }

}

void buton_init(void){

	  stmpe811_Init(buton_adres);
	  HAL_Delay(50);
	  stmpe811_Reset(buton_adres);
	  HAL_Delay(50);
	  stmpe811_Init(buton_adres);
	  HAL_Delay(50);

	  stmpe811_IO_Start(buton_adres,7);
	  stmpe811_IO_Start(buton_adres,6);
	  stmpe811_IO_Start(buton_adres,5);
	  stmpe811_IO_Start(buton_adres,4);
	  stmpe811_IO_Start(buton_adres,3);

	  IOE_Write(buton_adres,0x13,0b00000111);	// ilgili pinler girişe ayarlandı
	  IOE_Write(buton_adres,0x16,0b11111000);	// ilgili pinler düşen kenar seçildi
	  IOE_Write(buton_adres,0x17,0b11111000);	// ilgili pinlerin af fonksyonu gpio seçildi

	  //buton = stmpe811_ReadID(buton_adres);	// stmpe811 ID adresini ekrana yazar
	  //itoa(buton,txt,10);
	  //tft_ili9325_yaziyaz(10,10,txt,Tahoma18x16,renk_beyaz);

}

void buton_kontrol(void){

	buton=  IOE_Read(buton_adres,0x12);

	if(buton==232){
		 kucuk_ses();
		 HAL_Delay(10);
		 hiz=hiz+10;
		 tetris_reg.buton=1;
	}
	if(buton==240){
		 tus_sesi();
		 HAL_Delay(100);
		 hiz=hiz+100;
		 tetris_reg.buton=2;
	}
	if(buton==184){
		 tus_sesi();
		 HAL_Delay(10);
		 hiz=hiz+100;
		 tetris_reg.buton=3;
	}
	if(HAL_GPIO_ReadPin(User_Button_GPIO_Port,User_Button_Pin)==0){
		 tus_sesi();
		 HAL_Delay(150);
		 hiz=hiz+100;
		 tetris_reg.buton=5;
	}

	//tft_ili9325_dolukare(0,150,25,40,renk_siyah);
	//buton=  IOE_Read(buton_adres,0x12);
	//itoa(buton,txt,10);
	//tft_ili9325_yaziyaz(10,25,txt,Tahoma18x16,renk_beyaz);

}

void basla_bekleme(void){

	 tft_ili9325_bmpciz(0,0,tetris_bmp);
	 tft_ili9325_yaziyaz(2,255,"Donanım : STM3240G-EVAL",Tahoma10x11,renk_beyaz);
	 tft_ili9325_yaziyaz(2,270,"MCU           : STM32F407IG 168MHz",Tahoma10x11,renk_beyaz);
	 tft_ili9325_yaziyaz(2,285,"Ekran        : 3.2 İnc 240x320 TFT LCD ili9325 Driver",Tahoma10x11,renk_beyaz);
	 tft_ili9325_yaziyaz(200,305,version,Tahoma10x11,renk_beyaz);

	 while (1){
		 tetris_reg.buton=0;
		 buton_kontrol();
		 if(tetris_reg.buton==1 || tetris_reg.buton==2 || tetris_reg.buton==3 || tetris_reg.buton==5){
			 break;
		 }
		 // sonraki gelecek olan blok tipini ve rengini belirlicek sayıcılar (bu işlem için timer'da kullanılabilir)
		 tetris_reg.s_b_s++;
		 if(tetris_reg.s_b_s==7) tetris_reg.s_b_s=0;
		 tetris_reg.s_r_s++;
		 if(tetris_reg.s_r_s==6) tetris_reg.s_r_s=1;
		 tetris_reg.s_y_s++;
		 if(tetris_reg.s_y_s==5) tetris_reg.s_y_s=1;
		 // 1 milisaniyelik main döngü beklemesi
		 HAL_Delay(1);
	  }
	  tetris_ekran_dose();
}

void tus_sesi(void){

	HAL_GPIO_WritePin(LED2_GPIO_Port,LED2_Pin,1);
	HAL_Delay(50);
	HAL_GPIO_WritePin(LED2_GPIO_Port,LED2_Pin,0);
}

void hata_sesi(void){

	HAL_GPIO_WritePin(LED2_GPIO_Port,LED2_Pin,1);
	HAL_Delay(300);
	HAL_GPIO_WritePin(LED2_GPIO_Port,LED2_Pin,0);
	HAL_Delay(200);
	HAL_GPIO_WritePin(LED2_GPIO_Port,LED2_Pin,1);
	HAL_Delay(300);
	HAL_GPIO_WritePin(LED2_GPIO_Port,LED2_Pin,0);

}

void patlama_sesi(void){

	HAL_GPIO_WritePin(LED2_GPIO_Port,LED2_Pin,1);
	HAL_Delay(50);
	HAL_GPIO_WritePin(LED2_GPIO_Port,LED2_Pin,0);
	HAL_Delay(50);
	HAL_GPIO_WritePin(LED2_GPIO_Port,LED2_Pin,1);
	HAL_Delay(50);
	HAL_GPIO_WritePin(LED2_GPIO_Port,LED2_Pin,0);
	HAL_Delay(50);
	HAL_GPIO_WritePin(LED2_GPIO_Port,LED2_Pin,1);
	HAL_Delay(50);
	HAL_GPIO_WritePin(LED2_GPIO_Port,LED2_Pin,0);
}

void kucuk_ses(void){

	HAL_GPIO_WritePin(LED2_GPIO_Port,LED2_Pin,1);
	HAL_Delay(1);
	HAL_GPIO_WritePin(LED2_GPIO_Port,LED2_Pin,0);
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{

  RCC_OscInitTypeDef RCC_OscInitStruct;
  RCC_ClkInitTypeDef RCC_ClkInitStruct;

    /**Configure the main internal regulator output voltage 
    */
  __HAL_RCC_PWR_CLK_ENABLE();

  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

    /**Initializes the CPU, AHB and APB busses clocks 
    */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 25;
  RCC_OscInitStruct.PLL.PLLN = 336;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 7;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

    /**Initializes the CPU, AHB and APB busses clocks 
    */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

  HAL_RCC_MCOConfig(RCC_MCO1, RCC_MCO1SOURCE_HSE, RCC_MCODIV_1);

    /**Configure the Systick interrupt time 
    */
  HAL_SYSTICK_Config(HAL_RCC_GetHCLKFreq()/1000);

    /**Configure the Systick 
    */
  HAL_SYSTICK_CLKSourceConfig(SYSTICK_CLKSOURCE_HCLK);

  /* SysTick_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(SysTick_IRQn, 0, 0);
}

/* I2C1 init function */
static void MX_I2C1_Init(void)
{

  hi2c1.Instance = I2C1;
  hi2c1.Init.ClockSpeed = 100000;
  hi2c1.Init.DutyCycle = I2C_DUTYCYCLE_2;
  hi2c1.Init.OwnAddress1 = 0;
  hi2c1.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
  hi2c1.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
  hi2c1.Init.OwnAddress2 = 0;
  hi2c1.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
  hi2c1.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
  if (HAL_I2C_Init(&hi2c1) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

}
/** Configure pins as 
        * Analog 
        * Input 
        * Output
        * EVENT_OUT
        * EXTI
     PI3   ------> I2S2_SD
     PI0   ------> I2S2_WS
     PA8   ------> RCC_MCO_1
     PG7   ------> USART6_CK
*/
static void MX_GPIO_Init(void)
{

  GPIO_InitTypeDef GPIO_InitStruct;

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOE_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOG_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOI_CLK_ENABLE();
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOF_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOG, SmartCard_CMDVCC_Pin|LED2_Pin|LED1_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(LED3_GPIO_Port, LED3_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOH, SmartCard_3_5V_Pin|OTG_FS_PowerSwitchOn_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(LED4_GPIO_Port, LED4_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(SmartCard_RST_GPIO_Port, SmartCard_RST_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin : User_Button_Pin */
  GPIO_InitStruct.Pin = User_Button_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_EVT_RISING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(User_Button_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : SmartCard_CMDVCC_Pin LED2_Pin LED1_Pin */
  GPIO_InitStruct.Pin = SmartCard_CMDVCC_Pin|LED2_Pin|LED1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOG, &GPIO_InitStruct);

  /*Configure GPIO pins : I2S_SD_Pin I2S_WS_Pin */
  GPIO_InitStruct.Pin = I2S_SD_Pin|I2S_WS_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  GPIO_InitStruct.Alternate = GPIO_AF5_SPI2;
  HAL_GPIO_Init(GPIOI, &GPIO_InitStruct);

  /*Configure GPIO pin : IO_Expander_INT_Pin */
  GPIO_InitStruct.Pin = IO_Expander_INT_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_EVT_RISING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(IO_Expander_INT_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : LED3_Pin */
  GPIO_InitStruct.Pin = LED3_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(LED3_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : SmartCard_3_5V_Pin OTG_FS_PowerSwitchOn_Pin */
  GPIO_InitStruct.Pin = SmartCard_3_5V_Pin|OTG_FS_PowerSwitchOn_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOH, &GPIO_InitStruct);

  /*Configure GPIO pin : MicroSDCard_Detect_Pin */
  GPIO_InitStruct.Pin = MicroSDCard_Detect_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(MicroSDCard_Detect_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : MCO_Pin */
  GPIO_InitStruct.Pin = MCO_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  GPIO_InitStruct.Alternate = GPIO_AF0_MCO;
  HAL_GPIO_Init(MCO_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : LED4_Pin */
  GPIO_InitStruct.Pin = LED4_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(LED4_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : SmartCard_CLK_Pin */
  GPIO_InitStruct.Pin = SmartCard_CLK_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  GPIO_InitStruct.Alternate = GPIO_AF8_USART6;
  HAL_GPIO_Init(SmartCard_CLK_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : SmartCard_RST_Pin */
  GPIO_InitStruct.Pin = SmartCard_RST_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(SmartCard_RST_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : SmartCard_OFF_Pin */
  GPIO_InitStruct.Pin = SmartCard_OFF_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(SmartCard_OFF_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : SW1_Pin */
  GPIO_InitStruct.Pin = SW1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(SW1_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : OTG_FS_OverCurrent_Pin */
  GPIO_InitStruct.Pin = OTG_FS_OverCurrent_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_EVT_RISING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(OTG_FS_OverCurrent_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : MII_INT_Pin */
  GPIO_InitStruct.Pin = MII_INT_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_EVT_RISING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(MII_INT_GPIO_Port, &GPIO_InitStruct);

}

/* FSMC initialization function */
static void MX_FSMC_Init(void)
{
  FSMC_NORSRAM_TimingTypeDef Timing;

  /** Perform the NOR1 memory initialization sequence
  */
  hnor1.Instance = FSMC_NORSRAM_DEVICE;
  hnor1.Extended = FSMC_NORSRAM_EXTENDED_DEVICE;
  /* hnor1.Init */
  hnor1.Init.NSBank = FSMC_NORSRAM_BANK1;
  hnor1.Init.DataAddressMux = FSMC_DATA_ADDRESS_MUX_DISABLE;
  hnor1.Init.MemoryType = FSMC_MEMORY_TYPE_NOR;
  hnor1.Init.MemoryDataWidth = FSMC_NORSRAM_MEM_BUS_WIDTH_16;
  hnor1.Init.BurstAccessMode = FSMC_BURST_ACCESS_MODE_DISABLE;
  hnor1.Init.WaitSignalPolarity = FSMC_WAIT_SIGNAL_POLARITY_LOW;
  hnor1.Init.WrapMode = FSMC_WRAP_MODE_DISABLE;
  hnor1.Init.WaitSignalActive = FSMC_WAIT_TIMING_BEFORE_WS;
  hnor1.Init.WriteOperation = FSMC_WRITE_OPERATION_DISABLE;
  hnor1.Init.WaitSignal = FSMC_WAIT_SIGNAL_DISABLE;
  hnor1.Init.ExtendedMode = FSMC_EXTENDED_MODE_DISABLE;
  hnor1.Init.AsynchronousWait = FSMC_ASYNCHRONOUS_WAIT_DISABLE;
  hnor1.Init.WriteBurst = FSMC_WRITE_BURST_DISABLE;
  hnor1.Init.PageSize = FSMC_PAGE_SIZE_NONE;
  /* Timing */
  Timing.AddressSetupTime = 15;
  Timing.AddressHoldTime = 15;
  Timing.DataSetupTime = 255;
  Timing.BusTurnAroundDuration = 15;
  Timing.CLKDivision = 16;
  Timing.DataLatency = 17;
  Timing.AccessMode = FSMC_ACCESS_MODE_A;
  /* ExtTiming */

  if (HAL_NOR_Init(&hnor1, &Timing, NULL) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

  /** Perform the SRAM2 memory initialization sequence
  */
  hsram2.Instance = FSMC_NORSRAM_DEVICE;
  hsram2.Extended = FSMC_NORSRAM_EXTENDED_DEVICE;
  /* hsram2.Init */
  hsram2.Init.NSBank = FSMC_NORSRAM_BANK2;
  hsram2.Init.DataAddressMux = FSMC_DATA_ADDRESS_MUX_DISABLE;
  hsram2.Init.MemoryType = FSMC_MEMORY_TYPE_SRAM;
  hsram2.Init.MemoryDataWidth = FSMC_NORSRAM_MEM_BUS_WIDTH_16;
  hsram2.Init.BurstAccessMode = FSMC_BURST_ACCESS_MODE_DISABLE;
  hsram2.Init.WaitSignalPolarity = FSMC_WAIT_SIGNAL_POLARITY_LOW;
  hsram2.Init.WrapMode = FSMC_WRAP_MODE_DISABLE;
  hsram2.Init.WaitSignalActive = FSMC_WAIT_TIMING_BEFORE_WS;
  hsram2.Init.WriteOperation = FSMC_WRITE_OPERATION_DISABLE;
  hsram2.Init.WaitSignal = FSMC_WAIT_SIGNAL_DISABLE;
  hsram2.Init.ExtendedMode = FSMC_EXTENDED_MODE_DISABLE;
  hsram2.Init.AsynchronousWait = FSMC_ASYNCHRONOUS_WAIT_DISABLE;
  hsram2.Init.WriteBurst = FSMC_WRITE_BURST_DISABLE;
  hsram2.Init.PageSize = FSMC_PAGE_SIZE_NONE;
  /* Timing */
  Timing.AddressSetupTime = 15;
  Timing.AddressHoldTime = 15;
  Timing.DataSetupTime = 255;
  Timing.BusTurnAroundDuration = 15;
  Timing.CLKDivision = 16;
  Timing.DataLatency = 17;
  Timing.AccessMode = FSMC_ACCESS_MODE_A;
  /* ExtTiming */

  if (HAL_SRAM_Init(&hsram2, &Timing, NULL) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

  /** Perform the SRAM3 memory initialization sequence
  */
  hsram3.Instance = FSMC_NORSRAM_DEVICE;
  hsram3.Extended = FSMC_NORSRAM_EXTENDED_DEVICE;
  /* hsram3.Init */
  hsram3.Init.NSBank = FSMC_NORSRAM_BANK3;
  hsram3.Init.DataAddressMux = FSMC_DATA_ADDRESS_MUX_DISABLE;
  hsram3.Init.MemoryType = FSMC_MEMORY_TYPE_SRAM;
  hsram3.Init.MemoryDataWidth = FSMC_NORSRAM_MEM_BUS_WIDTH_16;
  hsram3.Init.BurstAccessMode = FSMC_BURST_ACCESS_MODE_DISABLE;
  hsram3.Init.WaitSignalPolarity = FSMC_WAIT_SIGNAL_POLARITY_LOW;
  hsram3.Init.WrapMode = FSMC_WRAP_MODE_DISABLE;
  hsram3.Init.WaitSignalActive = FSMC_WAIT_TIMING_BEFORE_WS;
  hsram3.Init.WriteOperation = FSMC_WRITE_OPERATION_DISABLE;
  hsram3.Init.WaitSignal = FSMC_WAIT_SIGNAL_DISABLE;
  hsram3.Init.ExtendedMode = FSMC_EXTENDED_MODE_DISABLE;
  hsram3.Init.AsynchronousWait = FSMC_ASYNCHRONOUS_WAIT_DISABLE;
  hsram3.Init.WriteBurst = FSMC_WRITE_BURST_DISABLE;
  hsram3.Init.PageSize = FSMC_PAGE_SIZE_NONE;
  /* Timing */
  Timing.AddressSetupTime = 15;
  Timing.AddressHoldTime = 15;
  Timing.DataSetupTime = 255;
  Timing.BusTurnAroundDuration = 15;
  Timing.CLKDivision = 16;
  Timing.DataLatency = 17;
  Timing.AccessMode = FSMC_ACCESS_MODE_A;
  /* ExtTiming */

  if (HAL_SRAM_Init(&hsram3, &Timing, NULL) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @param  file: The file name as string.
  * @param  line: The line in file as a number.
  * @retval None
  */
void _Error_Handler(char *file, int line)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  while(1)
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
void assert_failed(uint8_t* file, uint32_t line)
{ 
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/

