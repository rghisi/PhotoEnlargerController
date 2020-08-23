/*
 * Focus.cpp
 *
 *  Created on: Aug 18, 2020
 *      Author: ghisi
 */

#include "Focus.h"

Focus::Focus(RGBLed *rgbLed) {
	this->rgbLed = rgbLed;

}

void Focus::start() {
	rgbLed->allOn();
}

void Focus::stop() {
	rgbLed->allOff();
}

