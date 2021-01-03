/*
 * Focus.cpp
 *
 *  Created on: Aug 18, 2020
 *      Author: ghisi
 */

#include "../../features/focus/FocusModel.h"

FocusModel::FocusModel(RGBLed *rgbLed) {
	this->rgbLed = rgbLed;
	lightPower = 90;
}

void FocusModel::toggleFocusLight() {
	if (state == LIGHT_OFF) {
		rgbLed->setRedPower(lightPower);
		rgbLed->setGreenPower(lightPower);
		rgbLed->setBluePower(lightPower);
		rgbLed->allOn();
		state = LIGHT_ON;
	} else if (state == LIGHT_ON) {
		rgbLed->allOff();
		state = LIGHT_OFF;
	}
}

void FocusModel::setLightPower(uint8_t lightPower) {
	this->lightPower = lightPower;
	rgbLed->setRedPower(lightPower);
	rgbLed->setGreenPower(lightPower);
	rgbLed->setBluePower(lightPower);
}

uint8_t FocusModel::getLightPower() {
	return lightPower;
}

uint8_t FocusModel::getState() {
	return state;
}

bool FocusModel::isLocked() {
	return state;
}
