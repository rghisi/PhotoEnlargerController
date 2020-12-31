/*
 * Controls.h
 *
 *  Created on: Aug 20, 2020
 *      Author: ghisi
 */

#ifndef CONTROLS_H_
#include <stdint.h>
#include <stdio.h>
#include <avr/io.h>
#include <U8g2lib.h>
#include "InputEventListener.h"
#include "../ui/Displayable.h"
#define CONTROLS_H_

class InputHandler : public Displayable {
public:
	InputHandler(InputEventListener* inputEventListener);
//	void addListener(InputEventListener *controlEventListener);
	void display(U8G2 *u8g2);
	void notify(InputEvent controlEvent);
private:
//	static const uint8_t MAX_LISTENERS = 5;
//	InputEventListener *listeners[MAX_LISTENERS];
//	uint8_t numberOfListeners;
	InputEventListener* inputEventListener;

	volatile InputEvent lastInputEvent;//debug only, remove
};

#endif /* CONTROLS_H_ */
