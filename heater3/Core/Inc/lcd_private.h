/*
 * LCD_priv.h
 *
 *  Created on: Feb 5, 2023
 *      Author: aya_enan
 */

#ifndef LCD_LCD_PRIV_H_
#define LCD_LCD_PRIV_H_
/****************************************/
/************Private Macros**************/
/****************************************/
#define  LCD_4BIT_MODE_   0
#define  LCD_8BIT_MODE_   1


#define LCD_8BIT_MODE_2LINES_5X7 0x38

#define LCD_4BIT_MODE_2LINES_5X7 0x28

#define LCD_CLEAR_DISPALY  0x01// 0b0000 0001

#define LCD_DISPON_CURSON_BLINKOFF 0x0E

#define LCD_ENTRY_MODE_SET  0x06 // increment position and disable shift

#define LCD_SET_R0C0_  0x80 // command to set address to row 0 col 0
#define LCD_SET_R1C0_  0xC0 // command to set address to row 1 col 0
/************************************************************/
/************Private Functions Prototypes********************/
/************************************************************/
static void H_LCD_void_writeNlatch(unsigned char copy_u8Byte);//done




#endif /* LCD_LCD_PRIV_H_ */
