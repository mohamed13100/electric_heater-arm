/*
 * LCD_int.h
 *
 *  Created on: Feb 5, 2023
 *      Author: aya_enan
 */

#ifndef LCD_LCD_INT_H_
#define LCD_LCD_INT_H_


void H_LCD_void_Init(void);   //done
void H_LCD_void_sendData(unsigned char copy_u8data);//done
void H_LCD_void_sendCommand(unsigned char copy_u8Command);//done
void H_LCD_void_sendString(const signed char * pstr);//done
void H_LCD_void_clear(void);//done
void H_LCD_void_sendIntNum(unsigned int copy_s32Num);
void H_LCD_void_gotXY(unsigned char copy_u8Row,unsigned char copy_u8Col);
void H_LCD_void_creatCustomChar(const unsigned char * ArrPattern,unsigned char copy_u8charCode);
void H_LCD_void_displayCustomChar(unsigned char copy_u8charCode);

#endif /* LCD_LCD_INT_H_ */
