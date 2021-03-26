/*
 * BWPrinting.cpp
 *
 *  Created on: Aug 18, 2020
 *      Author: ghisi
 */

#include "BWPrintingModel.h"

BWPrintingModel::BWPrintingModel(RGBLed *rgb_led, WallClock *wall_clock) {
	this->rgb_led = rgb_led;
	this->wall_clock = wall_clock;
	total_exposure_time = 0;
	total_remaining_exposure_time = 0;
	green_exposure_time = 0;
	blue_exposure_time = 0;
	blue_remaining_exposure_time = 0;
	green_remaining_exposure_time = 0;
	state = State::stopped;
	rgb_led->allOff();
	rgb_led->SetCalibratedPower(RGBLed::PowerLevel::medium);
}

uint8_t BWPrintingModel::GetGreenExposureTime() {
	return green_exposure_time;
}

void BWPrintingModel::SetGreenExposure(uint8_t seconds) {
	green_exposure_time = seconds;
	calculateTotalExposureTime();
}

uint8_t BWPrintingModel::GetBlueExposureTime() {
	return blue_exposure_time;
}

void BWPrintingModel::SetBlueExposure(uint8_t seconds) {
	blue_exposure_time = seconds;
	calculateTotalExposureTime();
}

uint8_t BWPrintingModel::GetTotalExposureTime() {
	return total_exposure_time;
}

uint8_t BWPrintingModel::GetGreenRemainingExposureTime() {
	return green_remaining_exposure_time;
}
uint8_t BWPrintingModel::GetBlueRemainingExposureTime() {
	return blue_remaining_exposure_time;
}
uint8_t BWPrintingModel::GetTotalRemainingExposureTime() {
	return total_remaining_exposure_time;
}

BWPrintingModel::State BWPrintingModel::getState() {
	return state;
}

void BWPrintingModel::Start() {
	calculateTotalExposureTime();
	wall_clock->Attach(this);
	TurnOnExposureLights();
	wall_clock->Run();
	state = State::running;
}

void BWPrintingModel::Stop() {
	state = State::stopped;
	rgb_led->allOff();
	wall_clock->Detach();
}

void BWPrintingModel::Pause() {
	state = State::paused;
	wall_clock->Stop();
	rgb_led->allOff();
}

void BWPrintingModel::Resume() {
	TurnOnExposureLights();
	wall_clock->Run();
	state = State::running;
}

void BWPrintingModel::processClockTick() {
	switch (state) {
	case State::running:
		if (total_remaining_exposure_time > 0)
			total_remaining_exposure_time--;
		if (green_remaining_exposure_time > 0)
			green_remaining_exposure_time--;
		if (blue_remaining_exposure_time > 0)
			blue_remaining_exposure_time--;
		if (green_remaining_exposure_time == 0) {
			rgb_led->greenOff();
		}
		if (blue_remaining_exposure_time == 0) {
			rgb_led->blueOff();
		}
		if (total_remaining_exposure_time == 0) {
			Stop();
		}
		break;
	default:
		break;
	}
}

void BWPrintingModel::calculateTotalExposureTime() {
	if (green_exposure_time > blue_exposure_time) {
		total_exposure_time = green_exposure_time;
	} else {
		total_exposure_time = blue_exposure_time;
	}
	green_remaining_exposure_time = green_exposure_time;
	blue_remaining_exposure_time = blue_exposure_time;
	total_remaining_exposure_time = total_exposure_time;
}

bool BWPrintingModel::isLocked() {
	return state == State::running;
}

uint8_t BWPrintingModel::GetRedPower() {
	return rgb_led->GetRedDutyCycle();
}
uint8_t BWPrintingModel::GetGreenPower() {
	return rgb_led->GetGreenDutyCycle();
}
uint8_t BWPrintingModel::GetBluePower() {
	return rgb_led->GetBlueDutyCycle();
}

void BWPrintingModel::SetRedPower(uint8_t power) {
	rgb_led->SetRedDutyCycle(power);
}

void BWPrintingModel::SetGreenPower(uint8_t power) {
	rgb_led->SetGreenDutyCycle(power);
}

void BWPrintingModel::SetBluePower(uint8_t power) {
	rgb_led->SetBlueDutyCycle(power);
}

void BWPrintingModel::TurnOnExposureLights() {
	rgb_led->redOn();
	if (green_exposure_time > 0) {
		rgb_led->greenOn();
	}
	if (blue_exposure_time > 0) {
		rgb_led->blueOn();
	}
}

void BWPrintingModel::OnActivate() {

}

void BWPrintingModel::OnDeactivate() {

}
