/*
 * LCD_prg.c
 *
 *  Created on: Feb 5, 2023
 *      Author: aya_enan
 */

#include "stm32f1xx_hal.h"
#include "stm32f1xx_hal_gpio.h"


#include "lcd_private.h"
#include "lcd_config.h"
#include "lcd_interface.h"



#define GET_BITt(reg ,bit)    (reg>>(bit))& 1




void H_LCD_void_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(LCD_RS_PORT, LCD_RS_PIN, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LCD_EN_PORT, LCD_EN_PIN, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LCD_D4_PORT, LCD_D4_PIN, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LCD_D5_PORT, LCD_D5_PIN, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LCD_D6_PORT, LCD_D6_PIN, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LCD_D7_PORT, LCD_D7_PIN, GPIO_PIN_RESET);

  /*Configure GPIO pin : LED_Pin */
  GPIO_InitStruct.Pin = LCD_RS_PIN;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(LCD_RS_PORT, &GPIO_InitStruct);
	GPIO_InitStruct.Pin = LCD_EN_PIN;
	HAL_GPIO_Init(LCD_EN_PORT, &GPIO_InitStruct);
	GPIO_InitStruct.Pin = LCD_D4_PIN;
	HAL_GPIO_Init(LCD_D4_PORT, &GPIO_InitStruct);
	GPIO_InitStruct.Pin = LCD_D5_PIN;
	HAL_GPIO_Init(LCD_D5_PORT, &GPIO_InitStruct);
	GPIO_InitStruct.Pin = LCD_D6_PIN;
	HAL_GPIO_Init(LCD_D6_PORT, &GPIO_InitStruct);
	GPIO_InitStruct.Pin = LCD_D7_PIN;
	HAL_GPIO_Init(LCD_D7_PORT, &GPIO_InitStruct);


	// send Init Sequence

	HAL_Delay(35);
	// Rs = command = 0
	HAL_GPIO_WritePin(LCD_RS_PORT,LCD_RS_PIN,GPIO_PIN_RESET);
	// EN = 0 disabled
	HAL_GPIO_WritePin(LCD_EN_PORT,LCD_EN_PIN,GPIO_PIN_RESET);
	// prepare data
	HAL_GPIO_WritePin(LCD_D7_PORT,LCD_D7_PIN,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LCD_D6_PORT,LCD_D6_PIN,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LCD_D5_PORT,LCD_D5_PIN,GPIO_PIN_SET);
	HAL_GPIO_WritePin(LCD_D4_PORT,LCD_D4_PIN,GPIO_PIN_RESET);
	//EN = 1
	HAL_GPIO_WritePin(LCD_EN_PORT,LCD_EN_PIN,GPIO_PIN_SET);
	// delay 1 msec (to allow latching)
	HAL_Delay(1);
	// EN = 0
	HAL_GPIO_WritePin(LCD_EN_PORT,LCD_EN_PIN,GPIO_PIN_RESET);
	// delay to allow processing
	HAL_Delay(5);
	H_LCD_void_sendCommand(LCD_4BIT_MODE_2LINES_5X7);





	// display ON/OFF
	H_LCD_void_sendCommand(LCD_DISPON_CURSON_BLINKOFF);
	// display Clear
	H_LCD_void_sendCommand(LCD_CLEAR_DISPALY);
	// Entry Mode Set
	H_LCD_void_sendCommand(LCD_ENTRY_MODE_SET);
	
	H_LCD_void_sendCommand(64);
	H_LCD_void_sendData(0b00000010);// alf  from (LCD Custom Character Generator)
	H_LCD_void_sendData(0b00000010);
	H_LCD_void_sendData(0b00000010);
	H_LCD_void_sendData(0b00000010);
	H_LCD_void_sendData(0b00000010);
	H_LCD_void_sendData(0b00000010);
	H_LCD_void_sendData(0b00000010);
	H_LCD_void_sendData(0b00000000);
	
	H_LCD_void_sendData(0b00000010); //Lam
	H_LCD_void_sendData(0b00000010);
	H_LCD_void_sendData(0b00000010);
	H_LCD_void_sendData(0b00000010);
	H_LCD_void_sendData(0b00000010);
	H_LCD_void_sendData(0b00000010);
	H_LCD_void_sendData(0b00011110);
	H_LCD_void_sendData(0b00000000);

	H_LCD_void_sendData(0b00000000);//seen
	H_LCD_void_sendData(0b00000000);
	H_LCD_void_sendData(0b00000000);
	H_LCD_void_sendData(0b00000000);
	H_LCD_void_sendData(0b00010101);
	H_LCD_void_sendData(0b00010101);
	H_LCD_void_sendData(0b00011111);
	H_LCD_void_sendData(0b00000000);

	H_LCD_void_sendData(0b00000001);//lam alf
	H_LCD_void_sendData(0b00000001);
	H_LCD_void_sendData(0b00010001);
	H_LCD_void_sendData(0b00001001);
	H_LCD_void_sendData(0b00000101);
	H_LCD_void_sendData(0b00000011);
	H_LCD_void_sendData(0b00011111);
	H_LCD_void_sendData(0b00000000);

  H_LCD_void_sendData(0b00000111);//meem
  H_LCD_void_sendData(0b00000101);
  H_LCD_void_sendData(0b00000111);
  H_LCD_void_sendData(0b00001000);
  H_LCD_void_sendData(0b00001000);
  H_LCD_void_sendData(0b00001000);
  H_LCD_void_sendData(0b00001000);
  H_LCD_void_sendData(0b00001000);
	
  H_LCD_void_sendData(0b00000000); //3een
  H_LCD_void_sendData(0b00000000);
  H_LCD_void_sendData(0b00000000);
  H_LCD_void_sendData(0b00000111);
  H_LCD_void_sendData(0b00000100);
  H_LCD_void_sendData(0b00000100);
  H_LCD_void_sendData(0b00011111);
  H_LCD_void_sendData(0b00000000);

  H_LCD_void_sendData(0b00000000);//ya2
  H_LCD_void_sendData(0b00000000);
  H_LCD_void_sendData(0b00000000);
  H_LCD_void_sendData(0b00000000);
  H_LCD_void_sendData(0b00000001);
  H_LCD_void_sendData(0b00000001);
  H_LCD_void_sendData(0b00011111);
  H_LCD_void_sendData(0b00000110);

	H_LCD_void_sendData(0b00000001); //kaf 
	H_LCD_void_sendData(0b00000010);
	H_LCD_void_sendData(0b00000100);
	H_LCD_void_sendData(0b00001000);
	H_LCD_void_sendData(0b00000100);
	H_LCD_void_sendData(0b00000010);
	H_LCD_void_sendData(0b00011111);
	H_LCD_void_sendData(0b00000000);
	
	H_LCD_void_gotXY(0, 0);
	

}
void H_LCD_void_sendData(unsigned char copy_u8data)
{
  // step 1 : select RS to be in data mode (RS = 1)
   HAL_GPIO_WritePin(LCD_RS_PORT,LCD_RS_PIN,GPIO_PIN_SET);
  // step 2 : write data
   H_LCD_void_writeNlatch(copy_u8data);
}
void H_LCD_void_sendCommand(unsigned char copy_u8Command)
{
	// step 1 : select RS to be in command mode (RS = 0)
	HAL_GPIO_WritePin(LCD_RS_PORT,LCD_RS_PIN,GPIO_PIN_RESET);
	// step 2 : write command
	H_LCD_void_writeNlatch(copy_u8Command);

}
void H_LCD_void_sendString(const signed char * pstr)
{
   while(*pstr)
   {
	   H_LCD_void_sendData(*pstr);
	   pstr++;
   }
}
void H_LCD_void_clear(void)
{
	H_LCD_void_sendCommand(LCD_CLEAR_DISPALY);
}
void H_LCD_void_sendIntNum(unsigned int copy_s32Num)
{
   unsigned char Loc_Arr[10]= {0};
   unsigned char i = 0;
   if(copy_s32Num == 0)
   {
	   H_LCD_void_sendData('0');
	   return ;
   }
   else if(copy_s32Num < 0)//negative
   {
		while(copy_s32Num != 0)
		{
			Loc_Arr[i] = copy_s32Num % 10;
			copy_s32Num = copy_s32Num /10 ;
			i++;
		}
		i--;
		while(i>=0)
		{
			H_LCD_void_sendData(Loc_Arr[i]+'0');
			i--;
		}
	}
}
void H_LCD_void_gotXY(unsigned char copy_u8Row,unsigned char copy_u8Col)
{
  if(copy_u8Row == 0 || copy_u8Row == 1) //check on row
  {
	  if(copy_u8Col >= 0 && copy_u8Col <= 15)// check on col
	  {
      switch(copy_u8Row)
      {
				case 0 :
					H_LCD_void_sendCommand(LCD_SET_R0C0_ + copy_u8Col);
				break;
				
				case 1 :
					H_LCD_void_sendCommand(LCD_SET_R1C0_ + copy_u8Col);
				break;
      }
	  }
  }
}
void H_LCD_void_creatCustomChar(const unsigned char * ArrPattern,unsigned char copy_u8charCode)
{

}
void H_LCD_void_displayCustomChar(unsigned char copy_u8charCode)
{

}
static void H_LCD_void_writeNlatch(unsigned char copy_u8Byte)
{

 	// EN = 0 disabled
 	HAL_GPIO_WritePin(LCD_EN_PORT,LCD_EN_PIN,GPIO_PIN_RESET);
 	// devide Byte to 2 (4 bits )
 	// step 1 :send high order bits on pins (D7 .. D4)
 	HAL_GPIO_WritePin(LCD_D4_PORT ,LCD_D4_PIN  , GET_BITt(copy_u8Byte,4));
 	HAL_GPIO_WritePin(LCD_D5_PORT ,LCD_D5_PIN  , GET_BITt(copy_u8Byte,5));
 	HAL_GPIO_WritePin(LCD_D6_PORT ,LCD_D6_PIN  , GET_BITt(copy_u8Byte,6));
 	HAL_GPIO_WritePin(LCD_D7_PORT ,LCD_D7_PIN  , GET_BITt(copy_u8Byte,7));
	//step 2 : Activate Enable ,( E = 1)
 	HAL_GPIO_WritePin(LCD_EN_PORT, LCD_EN_PIN,GPIO_PIN_SET);
 	// step 3 : delay for 1 msec 	to allow latching
  HAL_Delay(1);
  // step 4 : deactivate Enable (E = 0)
 	HAL_GPIO_WritePin(LCD_EN_PORT, LCD_EN_PIN,GPIO_PIN_RESET);
  // step 5 : delay to allow LCD to process
  HAL_Delay(5);
 	// step 6 :send Low order bits on pins (D7 .. D4)
 	HAL_GPIO_WritePin(LCD_D4_PORT ,LCD_D4_PIN  , GET_BITt(copy_u8Byte,0));
 	HAL_GPIO_WritePin(LCD_D5_PORT ,LCD_D5_PIN  , GET_BITt(copy_u8Byte,1));
 	HAL_GPIO_WritePin(LCD_D6_PORT ,LCD_D6_PIN  , GET_BITt(copy_u8Byte,2));
 	HAL_GPIO_WritePin(LCD_D7_PORT ,LCD_D7_PIN  , GET_BITt(copy_u8Byte,3));
 	//step 7 : Activate Enable ,( E = 1)
 	HAL_GPIO_WritePin(LCD_EN_PORT, LCD_EN_PIN,GPIO_PIN_SET);
 	// step 8 : delay for 1 msec 	to allow latching
 	HAL_Delay(1);
 	// HAL_Delay 9 : deactivate Enable (E = 0)
 	HAL_GPIO_WritePin(LCD_EN_PORT, LCD_EN_PIN,GPIO_PIN_RESET);
 	// step 10 : delay to allow LCD to process
 	HAL_Delay(5);


}
