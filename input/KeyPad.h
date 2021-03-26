/*
 * KeyPad.h
 *
 *  Created on: Dec 29, 2020
 *      Author: ghisi
 */

#ifndef PERIPHERAL_KEYPAD_H_
#include <avr/io.h>
#include "InputEvent.h"
#include "InputHandler.h"
#define KEYPAD_VALUES_SIZE 6
#define PERIPHERAL_KEYPAD_H_

class KeyPad {
public:
	KeyPad(InputHandler *inputHandler);
	void setup();
	void poll();
	int8_t delta;
	uint8_t pass;
private:
	uint8_t getNormalizedValue(uint8_t value);
	uint8_t getFilteredADCValue(uint8_t value);
	uint8_t keypadValue;
	uint8_t newKeypadValue;
	uint8_t filteredAdcValue;
	uint8_t adcEqualValuesCount;
	InputHandler *inputHandler;
	static const uint8_t KEYPAD_UP_VALUE = 21;
	static const uint8_t KEYPAD_DOWN_VALUE = 7;
	static const uint8_t KEYPAD_LEFT_VALUE = 41;
	static const uint8_t KEYPAD_RIGHT_VALUE = 0;
	static const uint8_t KEYPAD_ENTER_VALUE = 88;
	static const uint8_t KEYPAD_REST_VALUE = 127; //Real value is 255 but we are using only the 7 least significant bits
	static const uint8_t KEYPAD_VALUES[];
	static const uint8_t FILTER_SIZE = 10;
	static const int8_t ACCEPTABLE_DELTA = 2;

};

#endif /* PERIPHERAL_KEYPAD_H_ */
