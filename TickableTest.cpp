/*
 * TickableTest.cpp
 *
 *  Created on: Aug 19, 2020
 *      Author: ghisi
 */

#include "TickableTest.h"

TickableTest::TickableTest() {
	clock = 0;
}

void TickableTest::processClockTick() {
	clock++;
}

void TickableTest::display(U8G2 *u8g2) {
	u8g2->setFontMode(1);
	u8g2->setFont(u8g2_font_helvR08_tr);
	u8g2->setCursor(1, 9);
	u8g2->print(clock);
}
