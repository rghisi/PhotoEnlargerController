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
	this->backlight_pwm->SetDutyCycle(configurations->GetLcdBrightness());
}

void LCD::IncreaseBrightness() {
	uint8_t brightness = backlight_pwm->GetDutyCycle();
	if (brightness < 100) {
		brightness++;
		backlight_pwm->SetDutyCycle(brightness);
	}
}

void LCD::DecreaseBrightness() {
	uint8_t brightness = backlight_pwm->GetDutyCycle();
	if (brightness > 0) {
		brightness--;
		backlight_pwm->SetDutyCycle(brightness);
	}
}

void LCD::SetBrightness(uint8_t brightness) {
	backlight_pwm->SetDutyCycle(brightness);
}

uint8_t LCD::GetBrightness() {
	return backlight_pwm->GetDutyCycle();
}

void LCD::SaveBrightness() {
	configurations->SetLcdBrightness(backlight_pwm->GetDutyCycle());
}
