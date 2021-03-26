/*
 * BWPrintingControl.cpp
 *
 *  Created on: Aug 19, 2020
 *      Author: ghisi
 */

#include "BWPrintingController.h"

static const BWPrintingController::Mode BWPrintingController::modeSequence[] = {
		combinedExposure, greenExposure, blueExposure, redPower, greenPower,
		bluePower };

static const uint8_t BWPrintingController::numberOfModes = 6;

BWPrintingController::BWPrintingController(BWPrintingModel *model) {
	this->model = model;
	mode = Mode::combinedExposure;
}

void BWPrintingController::handle(InputEvent controlEvent) {
	switch (controlEvent) {
	case InputEvent::dialPlus:
		IncrementSelection();
		break;
	case InputEvent::dialMinus:
		DecrementSelection();
		break;
	case InputEvent::padUpReleased:
		PreviousMode();
		break;
	case InputEvent::padDownReleased:
		NextMode();
		break;
	case InputEvent::padEnterReleased:
		RunStop();
		break;
	case InputEvent::dialPushButtonReleased:
		PauseResume();
		break;
	}
}

BWPrintingController::Mode BWPrintingController::GetMode() {
	return mode;
}

void BWPrintingController::RunStop() {
	switch (model->getState()) {
	case BWPrintingModel::State::stopped:
		model->Start();
		break;
	case BWPrintingModel::State::running:
		model->Stop();
		break;
	case BWPrintingModel::State::paused:
		model->Stop();
		break;
	}
}

void BWPrintingController::PauseResume() {
	switch (model->getState()) {
	case BWPrintingModel::State::running:
		model->Pause();
		break;
	case BWPrintingModel::State::paused:
		model->Resume();
		break;
	}
}

void BWPrintingController::IncrementExposureTime() {
	uint8_t blueExposure = model->GetBlueExposureTime();
	uint8_t greenExposure = model->GetGreenExposureTime();
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
	model->SetBlueExposure(blueExposure);
	model->SetGreenExposure(greenExposure);
}

void BWPrintingController::DecrementExposureTime() {
	uint8_t blueExposure = model->GetBlueExposureTime();
	uint8_t greenExposure = model->GetGreenExposureTime();
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
	model->SetBlueExposure(blueExposure);
	model->SetGreenExposure(greenExposure);
}

void BWPrintingController::PreviousMode() {
	mode = mode - 1;
	if (mode == -1) {
		mode = numberOfModes - 1;
	}
}

void BWPrintingController::NextMode() {
	mode = mode + 1;
	if (mode == numberOfModes) {
		mode = 0;
	}
}

void BWPrintingController::IncrementSelection() {
	if (model->getState() != BWPrintingModel::State::stopped) {
		return;
	}
	switch (mode) {
	case Mode::combinedExposure:
		IncrementExposureTime();
		break;
	case Mode::greenExposure:
		IncrementExposureTime();
		break;
	case Mode::blueExposure:
		IncrementExposureTime();
		break;
	case Mode::redPower:
		model->SetRedPower(model->GetRedPower() + 1);
		break;
	case Mode::greenPower:
		model->SetGreenPower(model->GetGreenPower() + 1);
		break;
	case Mode::bluePower:
		model->SetBluePower(model->GetBluePower() + 1);
		break;
	}
}

void BWPrintingController::DecrementSelection() {
	if (model->getState() != BWPrintingModel::State::stopped) {
		return;
	}
	switch (mode) {
	case Mode::combinedExposure:
		DecrementExposureTime();
		break;
	case Mode::greenExposure:
		DecrementExposureTime();
		break;
	case Mode::blueExposure:
		DecrementExposureTime();
		break;
	case Mode::redPower:
		model->SetRedPower(model->GetRedPower() - 1);
		break;
	case Mode::greenPower:
		model->SetGreenPower(model->GetGreenPower() - 1);
		break;
	case Mode::bluePower:
		model->SetBluePower(model->GetBluePower() - 1);
		break;
	}
}
