/*
 * RGBLed.h
 *
 *  Created on: Aug 18, 2020
 *      Author: ghisi
 */

#ifndef RGBLED_H_
#include <stdio.h>
#include "../ui/Displayable.h"
#define RGBLED_H_

class RGBLed {
public:
	RGBLed();
	void allOn();
	void allOff();
	void redOn();
	void greenOn();
	void blueOn();
	void redOff();
	void greenOff();
	void blueOff();
	void display(U8G2 *u8g2);

private:
	bool red;
	bool green;
	bool blue;
};

#endif /* RGBLED_H_ */
