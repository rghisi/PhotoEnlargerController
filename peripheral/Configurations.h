/*
 * Configurations.h
 *
 *  Created on: Jan 1, 2021
 *      Author: ghisi
 */

#ifndef PERIPHERAL_CONFIGURATIONS_H_
#include <avr/eeprom.h>
#define PERIPHERAL_CONFIGURATIONS_H_

class Configurations {
public:
	uint8_t GetLcdBrightness();
	void SetLcdBrightness(uint8_t lcdBrightness);

	static const uint8_t defaultLcdBrightness = 30;
private:
	static uint8_t lcdBrightnessAddress;

};

#endif /* PERIPHERAL_CONFIGURATIONS_H_ */
