/*
 * BWPrintingControl.h
 *
 *  Created on: Aug 19, 2020
 *      Author: ghisi
 */

#ifndef BWPRINTING_BWPRINTINGCONTROL_H_
#include "BWPrintingModel.h"
#include "../../ui/Controller.h"
#include "../../peripheral/WallClockListener.h"
#define BWPRINTING_BWPRINTINGCONTROL_H_

class BWPrintingController: public Controller { // @suppress("Class has a virtual method and non-virtual destructor")
public:
	enum Mode {
		combinedExposure, greenExposure, blueExposure
	};

	BWPrintingController(BWPrintingModel *model);
	void handle(InputEvent controlEvent);
	void OnActivate();
	void OnDeactivate();
	BWPrintingController::Mode getMode();
private:
	void incrementExposureTime();
	void decrementExposureTime();
	void cycleHightlightedMode();

	BWPrintingModel *model;
	BWPrintingController::Mode mode;

	static const uint8_t MINIMUM_EXPOSURE_TIME = 0;
	static const uint8_t MAXIMUM_EXPOSURE_TIME = 240;
};

#endif /* BWPRINTING_BWPRINTINGCONTROL_H_ */
