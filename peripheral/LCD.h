/*
 * LCD.h
 *
 *  Created on: Dec 29, 2020
 *      Author: ghisi
 */

#ifndef PERIPHERAL_LCD_H_
#include <stdio.h>

#include "SoftPWMOutput.h"
#include "Configurations.h"
#define PERIPHERAL_LCD_H_

class LCD {
public:
	LCD(SoftPWMOutput* backlightPWM, Configurations* configurations);
	void IncreaseBrightness();
	void DecreaseBrightness();
	void SetBrightness(uint8_t brightness);
	uint8_t GetBrightness();
	void SaveBrightness();
private:
	SoftPWMOutput* backlight_pwm;
	Configurations* configurations;

};




#endif /* PERIPHERAL_LCD_H_ */
