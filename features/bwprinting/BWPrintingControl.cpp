/*
 * BWPrintingControl.cpp
 *
 *  Created on: Aug 19, 2020
 *      Author: ghisi
 */

#include "../../features/bwprinting/BWPrintingControl.h"

BWPrintingControl::BWPrintingControl(BWPrinting *bwPrinting,
		BWPrintingUI *bwPrintingUI) {
	this->bwPrinting = bwPrinting;
	this->bwPrintingUI = bwPrintingUI;
	mode = Mode::combinedExposure;
}

void BWPrintingControl::updateUI() {
	bwPrintingUI->greenExposureTime = bwPrinting->getGreenExposureTime();
	bwPrintingUI->blueExposureTime = bwPrinting->getBlueExposureTime();
	bwPrintingUI->totalExposureTime = bwPrinting->getTotalExposureTime();
	switch (mode) {
	case Mode::combinedExposure:
		bwPrintingUI->highlightTotalExposure();
		break;
	case Mode::greenExposure:
		bwPrintingUI->highlightGreenExposure();
		break;
	case Mode::blueExposure:
		bwPrintingUI->highlightBlueExposure();
		break;
	}
}

void BWPrintingControl::incrementExposureTime() {
	uint8_t blueExposure = bwPrinting->getBlueExposureTime();
	uint8_t greenExposure = bwPrinting->getGreenExposureTime();
	uint8_t blueIncrement = blueExposure < MAXIMUM_EXPOSURE_TIME ? 1 : 0;
	uint8_t greenIncrement = greenExposure < MAXIMUM_EXPOSURE_TIME ? 1 : 0;
	switch (mode) {
	case Mode::combinedExposure:
		blueExposure += blueIncrement;
		greenExposure += greenIncrement;
		break;
	case Mode::greenExposure:
		greenExposure += greenIncrement;
		break;
	case Mode::blueExposure:
		blueExposure += blueIncrement;
		break;
	}
	bwPrinting->setBlueExposure(blueExposure);
	bwPrinting->setGreenExposure(greenExposure);
}

void BWPrintingControl::decrementExposureTime() {
	uint8_t blueExposure = bwPrinting->getBlueExposureTime();
	uint8_t greenExposure = bwPrinting->getGreenExposureTime();
	uint8_t blueDecrement = blueExposure > MINIMUM_EXPOSURE_TIME ? 1 : 0;
	uint8_t greenDecrement = greenExposure > MINIMUM_EXPOSURE_TIME ? 1 : 0;
	switch (mode) {
	case Mode::combinedExposure:
		blueExposure -= blueDecrement;
		greenExposure -= greenDecrement;
		break;
	case Mode::greenExposure:
		greenExposure -= greenDecrement;
		break;
	case Mode::blueExposure:
		blueExposure -= blueDecrement;
		break;
	}
	bwPrinting->setBlueExposure(blueExposure);
	bwPrinting->setGreenExposure(greenExposure);
}

void BWPrintingControl::cycleHightlightedMode() {
	switch (mode) {
	case Mode::combinedExposure:
		mode = Mode::greenExposure;
		break;
	case Mode::greenExposure:
		mode = Mode::blueExposure;
		break;
	case Mode::blueExposure:
		mode = Mode::combinedExposure;
		break;
	}
}

void BWPrintingControl::handle(InputEvent controlEvent) {
	switch (controlEvent) {
	case InputEvent::dialPlus:
		incrementExposureTime();
		updateUI();
		break;
	case InputEvent::dialMinus:
		decrementExposureTime();
		updateUI();
		break;
	case InputEvent::dialPushButtonPressed:
		cycleHightlightedMode();
		updateUI();
		break;
	case InputEvent::padEnterReleased:
		bwPrinting->start();
		updateUI();
		break;
	}
}

void BWPrintingControl::readModel() {
	if (bwPrinting->getState() == BWPrinting::running) {
		bwPrintingUI->greenExposureTime = bwPrinting->getGreenRemainingExposureTime();
		bwPrintingUI->blueExposureTime = bwPrinting->getBlueRemainingExposureTime();
		bwPrintingUI->totalExposureTime = bwPrinting->getTotalRemainingExposureTime();
	} else if (bwPrinting->getState() == BWPrinting::stopped) {
		updateUI();
	}
}

