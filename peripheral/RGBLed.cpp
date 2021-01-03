/*
 * RGBLed.cpp
 *
 *  Created on: Aug 18, 2020
 *      Author: ghisi
 */

#include "RGBLed.h"

RGBLed::RGBLed(SoftPWMOutput *redPWM, SoftPWMOutput *greenPWM, SoftPWMOutput *bluePWM) {
	this->redPWM = redPWM;
	this->greenPWM = greenPWM;
	this->bluePWM = bluePWM;
	redPower = 0;
	greenPower = 0;
	bluePower = 0;
	allOff();
}

void RGBLed::allOn() {
	red = true;
	green = true;
	blue = true;
	redPWM->setDutyCycle(redPower);
	greenPWM->setDutyCycle(greenPower);
	bluePWM->setDutyCycle(bluePower);
}
void RGBLed::allOff() {
	red = false;
	green = false;
	blue = false;
	redPWM->setDutyCycle(0);
	greenPWM->setDutyCycle(0);
	bluePWM->setDutyCycle(0);
}
void RGBLed::redOn() {
	red = true;
	redPWM->setDutyCycle(redPower);
}
void RGBLed::greenOn() {
	green = true;
	greenPWM->setDutyCycle(greenPower);
}
void RGBLed::blueOn() {
	blue = true;
	bluePWM->setDutyCycle(bluePower);
}
void RGBLed::redOff() {
	red = false;
	redPWM->setDutyCycle(0);
}
void RGBLed::greenOff() {
	green = false;
	greenPWM->setDutyCycle(0);
}
void RGBLed::blueOff() {
	blue = false;
	bluePWM->setDutyCycle(0);
}

void RGBLed::setRedPower(uint8_t power) {
	redPower = power;
	if (red)
		redPWM->setDutyCycle(power);
}

uint8_t RGBLed::getRedPower() {
	return redPower;
}

void RGBLed::setGreenPower(uint8_t power) {
	greenPower = power;
	if (green)
		greenPWM->setDutyCycle(power);
}

uint8_t RGBLed::getGreenPower() {
	return greenPower;
}

void RGBLed::setBluePower(uint8_t power) {
	bluePower = power;
	if (blue)
		bluePWM->setDutyCycle(power);
}

uint8_t RGBLed::getBluePower() {
	return bluePower;
}

void RGBLed::display(U8G2 *u8g2) {
	u8g2->setFont(u8g2_font_helvR08_tr);
	char buffer[3];
	sprintf(buffer, "%d %d %d", redPWM->getDutyCycle(), greenPWM->getDutyCycle(), bluePWM->getDutyCycle());
	u8g2->drawStr(50, 9, buffer);
}
