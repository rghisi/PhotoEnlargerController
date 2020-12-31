/*
 * Focus.h
 *
 *  Created on: Aug 18, 2020
 *      Author: ghisi
 */

#ifndef FOCUS_H_
#include "../../peripheral/RGBLed.h"
#include "../../ui/Model.h"
#define FOCUS_H_

class FocusModel : public Model {
public:
	FocusModel(RGBLed *rgbLed);
	void toggleFocusLight();
	uint8_t getState();
private:
	uint8_t state = LIGHT_OFF;
	RGBLed *rgbLed;
	static const uint8_t LIGHT_OFF = 0;
	static const uint8_t LIGHT_ON = 1;
};

#endif /* FOCUS_H_ */
