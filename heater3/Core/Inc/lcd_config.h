/*
 * LCD_config.h
 *
 *  Created on: Feb 5, 2023
 *      Author: aya_enan
 */

#ifndef LCD_LCD_CONFIG_H_
#define LCD_LCD_CONFIG_H_

/*
 *  choose LCD_MODE:
 *  LCD_4BIT_MODE_
 *  LCD_8BIT_MODE_
 */
#define LCD_MODE   LCD_4BIT_MODE_

/*
 *  choose Control pins :
 *  RS, EN
 */
#define LCD_RS_PORT  GPIOA
#define LCD_RS_PIN   GPIO_PIN_11  //bpin1

#define LCD_EN_PORT  GPIOA
#define LCD_EN_PIN   GPIO_PIN_8
/*
 *  choose Data pins :
 *  D7.. D0
 */
#define LCD_D7_PORT   GPIOB
#define LCD_D7_PIN    GPIO_PIN_12

#define LCD_D6_PORT   GPIOB
#define LCD_D6_PIN    GPIO_PIN_13


#define LCD_D5_PORT   GPIOB
#define LCD_D5_PIN    GPIO_PIN_14

#define LCD_D4_PORT   GPIOB
#define LCD_D4_PIN    GPIO_PIN_15




// choose :
// LCD_8BIT_MODE_2LINES_5X7
//  LCD_4BIT_MODE_2LINES_5X7
 /*
#define FUNCTION_SET LCD_4BIT_MODE_2LINES_5X7
*/
#endif /* LCD_LCD_CONFIG_H_ */
