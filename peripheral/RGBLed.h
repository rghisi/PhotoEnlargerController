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
#include "RGBPowerCalibration.h"
#define RGBLED_H_

class RGBLed {
public:
	enum PowerLevel {low, medium, high, min = low, max = high};
	RGBLed(SoftPWMOutput* redPWM, SoftPWMOutput* greenPWM, SoftPWMOutput* bluePWM);
	void allOn();
	void allOff();
	void redOn();
	void greenOn();
	void blueOn();
	void redOff();
	void greenOff();
	void blueOff();
	void SetRedDutyCycle(uint8_t duty_cycle);
	uint8_t GetRedDutyCycle();
	void SetGreenDutyCycle(uint8_t duty_cycle);
	uint8_t GetGreenDutyCycle();
	void SetBlueDutyCycle(uint8_t duty_cycle);
	uint8_t GetBlueDutyCycle();
	void display(U8G2 *u8g2);
	void SetCalibratedPower(PowerLevel power_level);
private:
	void ConfigureRGBCalibratedPowerLevels();
	bool red;
	bool green;
	bool blue;
	uint8_t redDutyCycle;
	uint8_t greenDutyCycle;
	uint8_t blueDutyCycle;
	SoftPWMOutput* redPWM;
	SoftPWMOutput* greenPWM;
	SoftPWMOutput* bluePWM;
	struct RGBPowerCalibration calibrated_power_levels[3];

};

#endif /* RGBLED_H_ */
