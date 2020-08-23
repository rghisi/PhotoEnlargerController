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
#include "../input/InputEventListener.h"
#define CONTROLS_H_

class InputHandler {
public:
	InputHandler(U8G2 *u8g2);
	void setup();
	void poll();
	void addListener(InputEventListener *controlEventListener);
private:
	static const uint8_t PORT_MASK = _BV(DDC1) | _BV(DDC2) | _BV(DDC3) | _BV(DDC4) | _BV(DDC5);

	static const uint8_t DIAL_MASK = _BV(DDC1) | _BV(DDC2);
	static const uint8_t DIAL_OFFSET = DDC1;
	uint8_t previousDialValue;

	static const uint8_t MAX_LISTENERS = 5;
	InputEventListener *listeners[MAX_LISTENERS];
	uint8_t numberOfListeners;


	static const uint8_t DIAL_PUSHBUTON_MASK = _BV(DDC3);
	static const uint8_t DIAL_PUSHBUTTON_OFFSET = DDC3;
	uint8_t pushButtonValue;

	U8G2 *u8g2;

	int8_t getDialIncrement(uint8_t rawValue);
	void notify(InputEvent controlEvent);
};

#endif /* CONTROLS_H_ */
