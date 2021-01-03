/*
 * LCD.cpp
 *
 *  Created on: Jan 1, 2021
 *      Author: ghisi
 */

#include "LCD.h"

LCD::LCD(SoftPWMOutput *backlight_pwm, Configurations *configurations) {
	this->backlight_pwm = backlight_pwm;
	this->configurations = configurations;
	this->backlight_pwm->setDutyCycle(configurations->GetLcdBrightness());
}

void LCD::IncreaseBrightness() {
	uint8_t brightness = backlight_pwm->getDutyCycle();
	if (brightness < 100) {
		brightness++;
		backlight_pwm->setDutyCycle(brightness);
	}
}

void LCD::DecreaseBrightness() {
	uint8_t brightness = backlight_pwm->getDutyCycle();
	if (brightness > 0) {
		brightness--;
		backlight_pwm->setDutyCycle(brightness);
	}
}

void LCD::SetBrightness(uint8_t brightness) {
	backlight_pwm->setDutyCycle(brightness);
}

uint8_t LCD::GetBrightness() {
	return backlight_pwm->getDutyCycle();
}

void LCD::SaveBrightness() {
	configurations->SetLcdBrightness(backlight_pwm->getDutyCycle());
}
