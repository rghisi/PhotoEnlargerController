/*
 * UIManager.cpp
 *
 *  Created on: Dec 30, 2020
 *      Author: ghisi
 */

#include "../../features/manager/UIManagerView.h"

UIManagerView::UIManagerView() {
	title_offset = lcdWidth;
}

void UIManagerView::display(U8G2 *u8g2) {
	if (delegateView) {
		DrawFeatureTitle(u8g2);
		delegateView->display(u8g2);

		u8g2->setFont(u8g2_font_open_iconic_thing_1x_t);
		if (delegateView->isLocked()) {
			u8g2->drawGlyph(120, 9, 79);
		} else {
			u8g2->drawGlyph(120, 9, 68);
		}
	}
}

void UIManagerView::DrawFeatureTitle(U8G2 *u8g2) {
	u8g2->setFont(u8g2_font_helvR08_tr);
	if (title_offset == lcdWidth) {
		 title_offset = (lcdWidth - u8g2->getStrWidth(GetTitle())) >> 1;
	}
	u8g2->drawBox(0, 0, 128, 10);
	u8g2->setCursor(5, 9);
	u8g2->drawStr(title_offset, 9, GetTitle());
}

void UIManagerView::setView(View *view) {
	delegateView = view;
	title_offset = lcdWidth;
}

const char* UIManagerView::GetTitle() {
	return delegateView->GetTitle();
}

bool UIManagerView::isLocked() {
	return false;
}
