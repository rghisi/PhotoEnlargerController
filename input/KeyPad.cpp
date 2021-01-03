/*
 * KeyPad.cpp
 *
 *  Created on: Dec 29, 2020
 *      Author: ghisi
 */

#include "KeyPad.h"

static const uint8_t KeyPad::KEYPAD_VALUES[] = {
		KeyPad::KEYPAD_UP_VALUE,
		KeyPad::KEYPAD_DOWN_VALUE,
		KeyPad::KEYPAD_LEFT_VALUE,
		KeyPad::KEYPAD_RIGHT_VALUE,
		KeyPad::KEYPAD_ENTER_VALUE,
		KeyPad::KEYPAD_REST_VALUE
};

KeyPad::KeyPad(InputHandler *inputHandler) {
	this->inputHandler = inputHandler;
	newKeypadValue = 0;
	keypadValue = KEYPAD_REST_VALUE;
	filteredAdcValue = 0;
	adcEqualValuesCount = 0;
	delta = 0;
	pass = 0;
}

void KeyPad::setup() {
	DDRC &= !_BV(DDC1);

	ADMUX = _BV(REFS0) | _BV(ADLAR);
	ADCSRA = _BV(
			ADEN) | _BV(ADSC) | _BV(ADATE) | _BV(ADIE) | _BV(ADPS2) | _BV(ADPS1)
			| _BV(ADPS0);
}

void KeyPad::handleADCInterrupt() {
	newKeypadValue = getFilteredADCValue(ADCH & 0x7F);
	if (keypadValue != newKeypadValue) {
		newKeypadValue = getNormalizedValue(newKeypadValue);
		pass = newKeypadValue;
		if (keypadValue == KEYPAD_REST_VALUE) {
			switch (newKeypadValue) {
			case KEYPAD_UP_VALUE:
				inputHandler->notify(InputEvent::padUpPressed);
				break;
			case KEYPAD_DOWN_VALUE:
				inputHandler->notify(InputEvent::padDownPressed);
				break;
			case KEYPAD_LEFT_VALUE:
				inputHandler->notify(InputEvent::padLeftPressed);
				break;
			case KEYPAD_RIGHT_VALUE:
				inputHandler->notify(InputEvent::padRightPressed);
				break;
			case KEYPAD_ENTER_VALUE:
				inputHandler->notify(InputEvent::padEnterPressed);
				break;
			}
		} else {
			switch (keypadValue) {
			case KEYPAD_UP_VALUE:
				inputHandler->notify(InputEvent::padUpReleased);
				break;
			case KEYPAD_DOWN_VALUE:
				inputHandler->notify(InputEvent::padDownReleased);
				break;
			case KEYPAD_LEFT_VALUE:
				inputHandler->notify(InputEvent::padLeftReleased);
				break;
			case KEYPAD_RIGHT_VALUE:
				inputHandler->notify(InputEvent::padRightReleased);
				break;
			case KEYPAD_ENTER_VALUE:
				inputHandler->notify(InputEvent::padEnterReleased);
				break;
			}
		}
		keypadValue = newKeypadValue;
	}
}

uint8_t KeyPad::getFilteredADCValue(uint8_t adcValue) {
	delta = filteredAdcValue - adcValue;
	if (delta <= ACCEPTABLE_DELTA && delta >= -ACCEPTABLE_DELTA) {
		adcEqualValuesCount++;
	} else {
		filteredAdcValue = adcValue;
		adcEqualValuesCount = 0;
	}
	if (adcEqualValuesCount == 5) {
		return filteredAdcValue;
	}
	return keypadValue;
}

uint8_t KeyPad::getNormalizedValue(uint8_t value) {
	for (uint8_t i = 0; i < KEYPAD_VALUES_SIZE; i++) {
		delta = KEYPAD_VALUES[i] - value;
		if (delta <= ACCEPTABLE_DELTA && delta >= -ACCEPTABLE_DELTA) {
			return KEYPAD_VALUES[i];
		}
	}
	return 0;
}
