/*
 * Focus.cpp
 *
 *  Created on: Aug 18, 2020
 *      Author: ghisi
 */

#include "../../features/focus/FocusModel.h"

FocusModel::FocusModel(RGBLed *rgbLed) {
	this->rgb_led = rgbLed;
	light_power = 2;
}

void FocusModel::ToggleFocusLight() {
	if (state == LIGHT_OFF) {
		rgb_led->allOn();
		state = LIGHT_ON;
	} else if (state == LIGHT_ON) {
		rgb_led->allOff();
		state = LIGHT_OFF;
	}
}

void FocusModel::SetLightPower(uint8_t light_power) {
	this->light_power = light_power;
  rgb_led->SetCalibratedPower(static_cast<RGBLed::PowerLevel>(light_power));
}

uint8_t FocusModel::GetLightPower() {
	return light_power;
}

uint8_t FocusModel::GetState() {
	return state;
}

bool FocusModel::isLocked() {
	return state;
}

void FocusModel::IncreaseLightPower() {
  if (light_power < static_cast<uint8_t>(RGBLed::PowerLevel::max)) {
		light_power++;
    rgb_led->SetCalibratedPower(static_cast<RGBLed::PowerLevel>(light_power));
	}
}

void FocusModel::DecreaseLightPower() {
	if (light_power > 0) {
		light_power--;
    rgb_led->SetCalibratedPower(static_cast<RGBLed::PowerLevel>(light_power));
	}
}

void FocusModel::OnActivate() {

}

void FocusModel::OnDeactivate() {

}

