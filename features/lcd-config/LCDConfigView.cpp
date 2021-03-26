/*
 * LCDConfigView.cpp
 *
 *  Created on: Jan 1, 2021
 *      Author: ghisi
 */

#include "LCDConfigView.h"

static const char *LCDConfigView::title = "LCD CONFIG";

LCDConfigView::LCDConfigView(LCDConfigModel* model) {
	this->model = model;
}

void LCDConfigView::display(U8G2 *u8g2) {
	u8g2->setFont(u8g2_font_helvB12_tr);
	u8g2->drawStr(60, 44, u8x8_u8toa(model->GetBrightness(), 3));
}

const char* LCDConfigView::GetTitle() {
	return LCDConfigView::title;
}

bool LCDConfigView::isLocked() {
	return false;
}
