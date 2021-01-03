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
	red_power = 90;
	green_power = 90;
	blue_power = 90;
}

uint8_t BWPrintingModel::getGreenExposureTime() {
	return green_exposure_time;
}

void BWPrintingModel::setGreenExposure(uint8_t seconds) {
	green_exposure_time = seconds;
	calculateTotalExposureTime();
}

uint8_t BWPrintingModel::getBlueExposureTime() {
	return blue_exposure_time;
}

void BWPrintingModel::setBlueExposure(uint8_t seconds) {
	blue_exposure_time = seconds;
	calculateTotalExposureTime();
}

uint8_t BWPrintingModel::getTotalExposureTime() {
	return total_exposure_time;
}

uint8_t BWPrintingModel::getGreenRemainingExposureTime() {
	return green_remaining_exposure_time;
}
uint8_t BWPrintingModel::getBlueRemainingExposureTime() {
	return blue_remaining_exposure_time;
}
uint8_t BWPrintingModel::getTotalRemainingExposureTime() {
	return total_remaining_exposure_time;
}

BWPrintingModel::State BWPrintingModel::getState() {
	return state;
}

void BWPrintingModel::start() {
	calculateTotalExposureTime();
	rgb_led->setRedPower(90);
	rgb_led->setGreenPower(90);
	rgb_led->setBluePower(90);
	rgb_led->redOn();
	if (green_exposure_time > 0) {
		rgb_led->greenOn();
	}
	if (blue_exposure_time > 0) {
		rgb_led->blueOn();
	}
	wall_clock->Attach(this);
	state = State::running;
}

void BWPrintingModel::stop() {
	state = State::stopped;
	rgb_led->redOff();
	rgb_led->greenOff();
	rgb_led->blueOff();
	wall_clock->Detach();
}

void BWPrintingModel::pause() {
	state = State::paused;
	rgb_led->allOff();
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
			stop();
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

uint8_t BWPrintingModel::getRedPower() {
	return red_power;
}
uint8_t BWPrintingModel::getGreenPower() {
	return green_power;
}
uint8_t BWPrintingModel::getBluePower() {
	return blue_power;
}

