/*
 * Controls.cpp
 *
 *  Created on: Aug 20, 2020
 *      Author: ghisi
 */

#include "../input/InputHandler.h"

InputHandler::InputHandler(InputEventListener *inputEventListener) {
	this->inputEventListener = inputEventListener;
}

//void InputHandler::addListener(InputEventListener *controlEventListener) {
//	if (numberOfListeners < MAX_LISTENERS) {
//		listeners[numberOfListeners] = controlEventListener;
//		numberOfListeners++;
//	}
//}

void InputHandler::notify(InputEvent controlEvent) {
//	for (uint8_t i = 0; i < numberOfListeners; i++) {
//		listeners[i]->handle(controlEvent);
//	}
	inputEventListener->handle(controlEvent);
	lastInputEvent = controlEvent;
}

void InputHandler::display(U8G2 *u8g2) {
	u8g2->setFontMode(1);
	u8g2->setFont(u8g2_font_helvR08_tr);
	u8g2->setCursor(25, 9);
	u8g2->print((int)lastInputEvent);
}

