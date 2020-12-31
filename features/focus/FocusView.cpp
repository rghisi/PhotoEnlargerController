/*
 * FocusView.cpp
 *
 *  Created on: Dec 31, 2020
 *      Author: ghisi
 */

#include "../../features/focus/FocusView.h"

FocusView::FocusView(FocusModel* model) {
	this->model = model;
}

void FocusView::display(U8G2 *u8g2) {
	u8g2->setFont(u8g2_font_open_iconic_thing_4x_t);
	u8g2->drawGlyph(5, 48, 0x51);
	if (model->getState() == 0) {
		u8g2->drawStr(78, 46, "ON");
	} else {
		u8g2->drawStr(78, 46, "OFF");
	}
}
