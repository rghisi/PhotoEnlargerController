/*
 * Controls.cpp
 *
 *  Created on: Aug 20, 2020
 *      Author: ghisi
 */

#include "../input/InputHandler.h"

InputHandler::InputHandler(U8G2 *u8g2) {
	pushButtonValue = 0;
	this->u8g2 = u8g2;
	previousDialValue = 0;
	numberOfListeners = 0;
}

void InputHandler::setup() {
	//input
	DDRC &= !PORT_MASK;
	//enable pull-up
	PORTC |= PORT_MASK;
}

void InputHandler::addListener(InputEventListener *controlEventListener) {
	if (numberOfListeners < MAX_LISTENERS) {
		listeners[numberOfListeners] = controlEventListener;
		numberOfListeners++;
	}
}

void InputHandler::poll() {
	uint8_t portcValue = ~(PINC & PORT_MASK);
	int8_t dialIncrement = getDialIncrement(portcValue);
	if (dialIncrement == 1) {
		notify(InputEvent::dialPlus);
	} else if (dialIncrement == -1) {
		notify(InputEvent::dialMinus);
	}

	uint8_t newPushButtonValue = (portcValue & DIAL_PUSHBUTON_MASK) >> DIAL_PUSHBUTTON_OFFSET;
	if (pushButtonValue != newPushButtonValue) {
		pushButtonValue = newPushButtonValue;
		if (pushButtonValue == 1) {
			notify(InputEvent::dialPushButtonUp);
		} else {
			notify(InputEvent::dialPushButtonDown);
		}
	}
}

void InputHandler::notify(InputEvent controlEvent) {
	for (uint8_t i = 0; i < numberOfListeners; i++) {
		listeners[i]->handle(controlEvent);
	}
}
//	u8g2->setFontMode(1);
//	u8g2->setFont(u8g2_font_helvR08_tf);
//	u8g2->setCursor(25, 9);
//	u8g2->print(toggle);

int8_t InputHandler::getDialIncrement(uint8_t rawValue) {
	uint8_t dialValue = (rawValue & DIAL_MASK) >> DIAL_OFFSET;
	if (previousDialValue == 0b00) {
		if (dialValue == 0b01) {
			previousDialValue = dialValue;
			return +1;
		} else if (dialValue == 0b10) {
			previousDialValue = dialValue;
			return -1;
		}
	} else if (dialValue == 0b00) {
		if (previousDialValue == 0b01 || previousDialValue == 0b10) {
			previousDialValue = dialValue;
		}
	}

	return 0;
}

