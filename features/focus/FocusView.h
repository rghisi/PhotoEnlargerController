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
private:
	FocusModel* model;
};




#endif /* MODES_FOCUS_FOCUSVIEW_H_ */
