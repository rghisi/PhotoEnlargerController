/*
 * LCDConfigView.cpp
 *
 *  Created on: Jan 1, 2021
 *      Author: ghisi
 */

#include "LCDConfigView.h"

static const char *LCDConfigView::title = "LCD Config";

LCDConfigView::LCDConfigView(LCDConfigModel* model) {
	this->model = model;
}

void LCDConfigView::display(U8G2 *u8g2) {
//	u8g2->setFont(u8g2_font_open_iconic_thing_4x_t);
//	u8g2->drawGlyph(5, 52, 74);

	u8g2->setFont(u8g2_font_helvB12_tr);
	u8g2->drawStr(60, 44, u8x8_u8toa(model->GetBrightness(), 3));
}

const char* LCDConfigView::GetTitle() {
	return LCDConfigView::title;
}

bool LCDConfigView::isLocked() {
	return false;
}
