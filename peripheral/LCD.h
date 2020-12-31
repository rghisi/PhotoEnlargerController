/*
 * LCD.h
 *
 *  Created on: Dec 29, 2020
 *      Author: ghisi
 */

#ifndef PERIPHERAL_LCD_H_
#include <stdio.h>
#define PERIPHERAL_LCD_H_

class LCD {
public:
	void setBrightness(uint8_t brightness);
	uint8_t getBrightness();
private:
	uint8_t brightness;

};




#endif /* PERIPHERAL_LCD_H_ */
