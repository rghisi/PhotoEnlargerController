/*
 * BWPrintingControl.cpp
 *
 *  Created on: Aug 19, 2020
 *      Author: ghisi
 */

#include "BWPrintingController.h"

BWPrintingController::BWPrintingController(BWPrintingModel *model) {
	this->model = model;
	mode = Mode::combinedExposure;
}

BWPrintingController::Mode BWPrintingController::getMode() {
	return mode;
}

void BWPrintingController::incrementExposureTime() {
	uint8_t blueExposure = model->getBlueExposureTime();
	uint8_t greenExposure = model->getGreenExposureTime();
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
	model->setBlueExposure(blueExposure);
	model->setGreenExposure(greenExposure);
}

void BWPrintingController::decrementExposureTime() {
	uint8_t blueExposure = model->getBlueExposureTime();
	uint8_t greenExposure = model->getGreenExposureTime();
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
	model->setBlueExposure(blueExposure);
	model->setGreenExposure(greenExposure);
}

void BWPrintingController::cycleHightlightedMode() {
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

void BWPrintingController::handle(InputEvent controlEvent) {
	switch (controlEvent) {
	case InputEvent::dialPlus:
		incrementExposureTime();
		break;
	case InputEvent::dialMinus:
		decrementExposureTime();
		break;
	case InputEvent::dialPushButtonPressed:
		cycleHightlightedMode();
		break;
	case InputEvent::padEnterReleased:
		model->start();
		break;
	}
}

void BWPrintingController::OnActivate() {

}

void BWPrintingController::OnDeactivate() {

}

