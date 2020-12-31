/*
 * RGBLed.cpp
 *
 *  Created on: Aug 18, 2020
 *      Author: ghisi
 */

#include "RGBLed.h"

RGBLed::RGBLed() {
	red = false;
	green = false;
	blue = false;
}

void RGBLed::allOn() {
	red = true;
	green = true;
	blue = true;
}
void RGBLed::allOff() {
	red = false;
	green = false;
	blue = false;
}
void RGBLed::redOn() {
	red = true;
}
void RGBLed::greenOn() {
	green = true;
}
void RGBLed::blueOn() {
	blue = true;
}
void RGBLed::redOff() {
	red = false;
}
void RGBLed::greenOff() {
	green = false;
}
void RGBLed::blueOff() {
	blue = false;
}

void RGBLed::display(U8G2 *u8g2) {
	u8g2->setFont(u8g2_font_helvR08_tf);
	char buffer[3];
	sprintf(buffer, "%d%d%d", red, green, blue);
	u8g2->drawStr(80, 9, buffer);
}
