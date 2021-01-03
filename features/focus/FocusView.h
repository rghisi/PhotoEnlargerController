/*
 * FocusView.h
 *
 *  Created on: Dec 31, 2020
 *      Author: ghisi
 */

#ifndef MODES_FOCUS_FOCUSVIEW_H_
#include "../../ui/View.h"
#include "../../features/focus/FocusModel.h"
#define MODES_FOCUS_FOCUSVIEW_H_

class FocusView : public View {
public:
	FocusView(FocusModel* model);
	void display(U8G2 *u8g2);
	const char* GetTitle();
	bool isLocked();
private:
	FocusModel* model;
	static const char* title;
};




#endif /* MODES_FOCUS_FOCUSVIEW_H_ */
