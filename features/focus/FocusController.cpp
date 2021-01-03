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
		model->toggleFocusLight();
		break;
	case InputEvent::dialPlus:
		increaseLightPower();
		break;
	case InputEvent::dialMinus:
		decreaseLightPower();
		break;
	}
}

void FocusController::increaseLightPower() {
	if (lightPower < 100) {
		lightPower++;
		model->setLightPower(lightPower);
	}
}

void FocusController::decreaseLightPower() {
	if (lightPower > 0) {
		lightPower--;
		model->setLightPower(lightPower);
	}
}

void FocusController::OnActivate() {

}

void FocusController::OnDeactivate() {

}
