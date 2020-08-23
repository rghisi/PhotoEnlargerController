/*
 * BWPrinting.cpp
 *
 *  Created on: Aug 18, 2020
 *      Author: ghisi
 */

#include "BWPrinting.h"

BWPrinting::BWPrinting(RGBLed *rgbLed) {
	this->rgbLed = rgbLed;
	totalExposureTime = 0;
	totalRemainingExposureTime = 0;
	greenExposureTime = 0;
	blueExposureTime = 0;
	blueRemainingExposureTime = 0;
	greenRemainingExposureTime = 0;
	state = State::stopped;
}

uint8_t BWPrinting::getGreenExposureTime() {
	return greenExposureTime;
}

void BWPrinting::setGreenExposure(uint8_t seconds) {
	greenExposureTime = seconds;
	calculateTotalExposureTime();
}

uint8_t BWPrinting::getBlueExposureTime() {
	return blueExposureTime;
}

void BWPrinting::setBlueExposure(uint8_t seconds) {
	blueExposureTime = seconds;
	calculateTotalExposureTime();
}

uint8_t BWPrinting::getTotalExposureTime() {
	return totalExposureTime;
}

void BWPrinting::start() {
	if (greenExposureTime > 0) {
		rgbLed->greenOn();
	}
	if (blueExposureTime > 0) {
		rgbLed->blueOn();
	}
	state = State::running;
}

void BWPrinting::stop() {
	state = State::stopped;
	rgbLed->allOff();
}

void BWPrinting::pause() {
	state = State::paused;
	rgbLed->allOff();
}

void BWPrinting::processClockTick() {
	if (state == State::running) {
		totalRemainingExposureTime--;
		greenRemainingExposureTime--;
		blueRemainingExposureTime--;
		if (greenRemainingExposureTime == 0) {
			rgbLed->greenOff();
		}
		if (blueRemainingExposureTime == 0) {
			rgbLed->blueOff();
		}
		if (totalRemainingExposureTime == 0) {
			stop();
		}
	}
}

void BWPrinting::calculateTotalExposureTime() {
	if (greenExposureTime > blueExposureTime) {
		totalExposureTime = greenExposureTime;
	} else {
		totalExposureTime = blueExposureTime;
	}
	totalRemainingExposureTime = totalExposureTime;
}

