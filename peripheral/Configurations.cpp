/*
 * Configurations.cpp
 *
 *  Created on: Jan 1, 2021
 *      Author: ghisi
 */

#include "Configurations.h"

static uint8_t EEMEM Configurations::lcdBrightnessAddress =
		Configurations::defaultLcdBrightness;

uint8_t Configurations::GetLcdBrightness() {
	while (!eeprom_is_ready()) {
	}
	return eeprom_read_byte(&lcdBrightnessAddress);
}

void Configurations::SetLcdBrightness(uint8_t lcdBrightness) {
	while (!eeprom_is_ready()) {
	}
	eeprom_update_byte(&lcdBrightnessAddress, lcdBrightness);
	while (!eeprom_is_ready()) {
	}
}

