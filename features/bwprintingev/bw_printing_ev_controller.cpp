/*
 * BWPrintingControl.cpp
 *
 *  Created on: Aug 19, 2020
 *      Author: ghisi
 */

#include "bw_printing_ev_controller.h"

BWPrintingEVController::BWPrintingEVController(BWPrintingEVModel *model) {
	this->model = model;
	mode = Mode::exposure;
}

void BWPrintingEVController::handle(InputEvent controlEvent) {
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
		model->RunStop();
		break;
	case InputEvent::dialPushButtonReleased:
	  model->PauseResume();
		break;
	}
}

BWPrintingEVController::Mode BWPrintingEVController::GetMode() {
	return mode;
}

void BWPrintingEVController::PreviousMode() {
  if (mode > 0) {
    mode = mode - 1;
  } else {
    mode = Mode::max;
  }
}

void BWPrintingEVController::NextMode() {
  if (mode < Mode::max) {
    mode = mode + 1;
  } else {
    mode = 0;
  }
}

void BWPrintingEVController::IncrementSelection() {
	if (model->getState() != BWPrintingEVModel::State::stopped) {
		return;
	}
	switch (mode) {
	case Mode::exposure:
		model->IncreaseExposure();
		break;
	case Mode::greenOffset:
	  model->IncreaseGreenOffset();
		break;
	case Mode::blueOffset:
	  model->IncreaseBlueOffset();
		break;
	case Mode::lightPower:
      model->IncreaseLightPowerLevel();
		break;
	case Mode::evSteps:
		model->IncreaseEVStep();
		break;
	}
}

void BWPrintingEVController::DecrementSelection() {
	if (model->getState() != BWPrintingEVModel::State::stopped) {
		return;
	}
	switch (mode) {
	case Mode::exposure:
	  model->DecreaseExposure();
		break;
	case Mode::greenOffset:
    model->DecreaseGreenOffset();
    break;
  case Mode::blueOffset:
    model->DecreaseBlueOffset();
    break;
	case Mode::lightPower:
	  model->DecreaseLightPowerLevel();
		break;
	case Mode::evSteps:
		model->DecreaseEVStep();
		break;
	}
}
