/*
 * Focus.h
 *
 *  Created on: Aug 18, 2020
 *      Author: ghisi
 */

#ifndef FOCUS_H_
#include "../../peripheral/RGBLed.h"
#define FOCUS_H_

class Focus {
public:
	Focus(RGBLed *rgbLed);
	void start();
	void stop();
private:
	RGBLed *rgbLed;
};

#endif /* FOCUS_H_ */
