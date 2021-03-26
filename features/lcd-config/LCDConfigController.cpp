/*
 * LCDConfigController.cpp
 *
 *  Created on: Jan 1, 2021
 *      Author: ghisi
 */

#include "LCDConfigController.h"

LCDConfigController::LCDConfigController(LCDConfigModel* model) {
	this->model = model;
}

void LCDConfigController::handle(InputEvent controlEvent) {
	switch (controlEvent) {
		case InputEvent::dialPlus:
			model->IncreaseBrightness();
			break;
		case InputEvent::dialMinus:
			model->DecreaseBrightness();
			break;
		}
}


