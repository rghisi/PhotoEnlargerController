/*
 * RGBLed.h
 *
 *  Created on: Aug 18, 2020
 *      Author: ghisi
 */

#ifndef RGBLED_H_
#include <stdio.h>
#include "../ui/Displayable.h"
#include "SoftPWMOutput.h"
#define RGBLED_H_

class RGBLed {
public:
	RGBLed(SoftPWMOutput* redPWM, SoftPWMOutput* greenPWM, SoftPWMOutput* bluePWM);
	void allOn();
	void allOff();
	void redOn();
	void greenOn();
	void blueOn();
	void redOff();
	void greenOff();
	void blueOff();
	void setRedPower(uint8_t power);
	uint8_t getRedPower();
	void setGreenPower(uint8_t power);
	uint8_t getGreenPower();
	void setBluePower(uint8_t power);
	uint8_t getBluePower();


	void display(U8G2 *u8g2);

private:
	bool red;
	bool green;
	bool blue;
	uint8_t redPower;
	uint8_t greenPower;
	uint8_t bluePower;
	SoftPWMOutput* redPWM;
	SoftPWMOutput* greenPWM;
	SoftPWMOutput* bluePWM;

};

#endif /* RGBLED_H_ */
