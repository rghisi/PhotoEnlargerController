/*
 * FocusView.cpp
 *
 *  Created on: Dec 31, 2020
 *      Author: ghisi
 */

#include "../../features/focus/FocusView.h"

static const char* FocusView::title = "FOCUS";

FocusView::FocusView(FocusModel *model) {
	this->model = model;
}

bool FocusView::isLocked() {
	return model->isLocked();
}

void FocusView::display(U8G2 *u8g2) {
	u8g2->setFont(u8g2_font_open_iconic_thing_4x_t);
	u8g2->drawGlyph(5, 52, 74);

	u8g2->setFont(u8g2_font_helvB12_tr);
	if (model->GetState() == 0) {
		u8g2->drawStr(60, 44, "OFF");
	} else {
		u8g2->drawStr(60, 44, "ON");
	}

	u8g2->setFont(u8g2_font_helvR08_tr);
	u8g2->setCursor(60, 60);
	u8g2->print(model->GetLightPower());
}

const char* FocusView::GetTitle() {
	return title;
}
