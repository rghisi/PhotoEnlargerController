/*
 * BWPrintingControl.h
 *
 *  Created on: Aug 19, 2020
 *      Author: ghisi
 */

#ifndef BWPRINTING_BWPRINTINGEVCONTROL_H_
#include "bw_printing_ev_model.h"
#include "../../ui/Controller.h"
#include "../../peripheral/WallClockListener.h"
#define BWPRINTING_BWPRINTINGEVCONTROL_H_

class BWPrintingEVController: public Controller { // @suppress("Class has a virtual method and non-virtual destructor")
public:
	enum Mode {
		exposure, greenOffset, blueOffset, lightPower, evSteps, max = evSteps
	};

	BWPrintingEVController(BWPrintingEVModel *model);
	void handle(InputEvent controlEvent);
	BWPrintingEVController::Mode GetMode();
private:
	void PreviousMode();
	void NextMode();
	void IncrementSelection();
	void DecrementSelection();
	void IncrementExposureTime();
	void DecrementExposureTime();

	BWPrintingEVModel *model;
	BWPrintingEVController::Mode mode;
};

#endif /* BWPRINTING_BWPRINTINGCONTROL_H_ */
