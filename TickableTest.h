/*
 * TickableTest.h
 *
 *  Created on: Aug 19, 2020
 *      Author: ghisi
 */

#ifndef TICKABLETEST_H_
#include "WallClockTickable.h"
#include "ui/Displayable.h"
#define TICKABLETEST_H_

class TickableTest : WallClockTickable, Displayable { // @suppress("Class has a virtual method and non-virtual destructor")
public:
	TickableTest();
	void processClockTick();
	void display(U8G2 *u8g2);
private:
	volatile uint8_t clock;
};

#endif /* TICKABLETEST_H_ */
