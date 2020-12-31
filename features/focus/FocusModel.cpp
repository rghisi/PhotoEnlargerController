/*
 * Focus.cpp
 *
 *  Created on: Aug 18, 2020
 *      Author: ghisi
 */

#include "../../features/focus/FocusModel.h"

FocusModel::FocusModel(RGBLed *rgbLed) {
	this->rgbLed = rgbLed;
}

void FocusModel::toggleFocusLight() {
	if (state == LIGHT_OFF) {
		rgbLed->allOn();
		state = LIGHT_ON;
	} else if (state == LIGHT_ON) {
		rgbLed->allOff();
		state = LIGHT_OFF;
	}
}

uint8_t FocusModel::getState() {
	return state;
}
