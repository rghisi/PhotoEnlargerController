/*
 * LCDConfigModel.cpp
 *
 *  Created on: Jan 1, 2021
 *      Author: ghisi
 */

#include "LCDConfigModel.h"

LCDConfigModel::LCDConfigModel(LCD *lcd) {
	this->lcd = lcd;
}

bool LCDConfigModel::isLocked() {
	return false;
}

void LCDConfigModel::IncreaseBrightness() {
	lcd->IncreaseBrightness();
}

void LCDConfigModel::DecreaseBrightness() {
	lcd->DecreaseBrightness();
}

uint8_t LCDConfigModel::GetBrightness() {
	return lcd->GetBrightness();
}

void LCDConfigModel::SaveBrightness() {
	lcd->SaveBrightness();
}

void LCDConfigModel::OnActivate() {

}

void LCDConfigModel::OnDeactivate() {
  SaveBrightness();
}
