/*
 * FocusController.cpp
 *
 *  Created on: Dec 31, 2020
 *      Author: ghisi
 */

#include "../../features/focus/FocusController.h"

FocusController::FocusController(FocusModel *model) {
	this->model = model;
}

void FocusController::handle(InputEvent controlEvent) {
	switch (controlEvent) {
	case InputEvent::padEnterReleased:
		model->ToggleFocusLight();
		break;
	case InputEvent::dialPlus:
		model->IncreaseLightPower();
		break;
	case InputEvent::dialMinus:
		model->DecreaseLightPower();
		break;
	}
}
