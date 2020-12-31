/*
 * FocusController.h
 *
 *  Created on: Dec 31, 2020
 *      Author: ghisi
 */

#ifndef MODES_FOCUS_FOCUSCONTROLLER_H_
#include "../../ui/Controller.h"
#include "../../features/focus/FocusModel.h"
#include "../../features/focus/FocusView.h"
#define MODES_FOCUS_FOCUSCONTROLLER_H_

class FocusController : public Controller {
public:
	FocusController(FocusModel* model);
	void handle(InputEvent controlEvent);
	void readModel();
private:
	uint8_t state = 0;
	FocusModel* model;
};



#endif /* MODES_FOCUS_FOCUSCONTROLLER_H_ */
