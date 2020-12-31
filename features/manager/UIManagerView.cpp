/*
 * UIManager.cpp
 *
 *  Created on: Dec 30, 2020
 *      Author: ghisi
 */

#include "../../features/manager/UIManagerView.h"

void UIManagerView::display(U8G2* u8g2) {
	if (delegateView) {
		delegateView->display(u8g2);
	}
}

void UIManagerView::setView(View* view) {
	delegateView = view;
}

