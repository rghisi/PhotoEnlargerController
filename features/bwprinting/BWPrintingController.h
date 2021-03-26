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
		combinedExposure, greenExposure, blueExposure, redPower, greenPower, bluePower
	};

	BWPrintingController(BWPrintingModel *model);
	void handle(InputEvent controlEvent);
	BWPrintingController::Mode GetMode();
private:
	void RunStop();
	void PauseResume();
	void PreviousMode();
	void NextMode();
	void IncrementSelection();
	void DecrementSelection();
	void IncrementExposureTime();
	void DecrementExposureTime();

	BWPrintingModel *model;
	BWPrintingController::Mode mode;

	static const uint8_t MINIMUM_EXPOSURE_TIME = 0;
	static const uint8_t MAXIMUM_EXPOSURE_TIME = 240;
	static const Mode modeSequence[];
	static const uint8_t numberOfModes;
};

#endif /* BWPRINTING_BWPRINTINGCONTROL_H_ */
