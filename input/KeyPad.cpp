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
	ADMUX = _BV(REFS0) | _BV(ADLAR);	//AVCC Reference + Left adjust result
	ADCSRA =
			_BV(ADEN) |		//Enable ADC
			_BV(ADSC) |		//Start conversion
			_BV(ADATE) |	//Auto Trigger
			_BV(ADPS2) | _BV(ADPS1) | _BV(ADPS0); //Set prescaler to 128 (max)
}

void KeyPad::poll() {
	newKeypadValue = getFilteredADCValue(getNormalizedValue(ADCH & 0x7F));
	if (keypadValue != newKeypadValue) {
		pass = newKeypadValue;
		if (keypadValue == KEYPAD_REST_VALUE) {
			switch (newKeypadValue) {
			case KEYPAD_UP_VALUE:
				inputHandler->Enqueue(InputEvent::padUpPressed);
				break;
			case KEYPAD_DOWN_VALUE:
				inputHandler->Enqueue(InputEvent::padDownPressed);
				break;
			case KEYPAD_LEFT_VALUE:
				inputHandler->Enqueue(InputEvent::padLeftPressed);
				break;
			case KEYPAD_RIGHT_VALUE:
				inputHandler->Enqueue(InputEvent::padRightPressed);
				break;
			case KEYPAD_ENTER_VALUE:
				inputHandler->Enqueue(InputEvent::padEnterPressed);
				break;
			}
		} else {
			switch (keypadValue) {
			case KEYPAD_UP_VALUE:
				inputHandler->Enqueue(InputEvent::padUpReleased);
				break;
			case KEYPAD_DOWN_VALUE:
				inputHandler->Enqueue(InputEvent::padDownReleased);
				break;
			case KEYPAD_LEFT_VALUE:
				inputHandler->Enqueue(InputEvent::padLeftReleased);
				break;
			case KEYPAD_RIGHT_VALUE:
				inputHandler->Enqueue(InputEvent::padRightReleased);
				break;
			case KEYPAD_ENTER_VALUE:
				inputHandler->Enqueue(InputEvent::padEnterReleased);
				break;
			}
		}
		keypadValue = newKeypadValue;
	}
}

uint8_t KeyPad::getFilteredADCValue(uint8_t value) {
	if (value != filteredAdcValue) {
		filteredAdcValue = value;
		adcEqualValuesCount = 0;
	}

	adcEqualValuesCount++;

	if (adcEqualValuesCount == FILTER_SIZE) {
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
