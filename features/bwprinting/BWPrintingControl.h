/*
 * BWPrintingControl.h
 *
 *  Created on: Aug 19, 2020
 *      Author: ghisi
 */

#ifndef BWPRINTING_BWPRINTINGCONTROL_H_
#include "../../features/bwprinting/BWPrinting.h"
#include "../../features/bwprinting/BWPrintingUI.h"
#include "../../ui/Controller.h"
#include "../../WallClockTickable.h"
#define BWPRINTING_BWPRINTINGCONTROL_H_

class BWPrintingControl : public Controller { // @suppress("Class has a virtual method and non-virtual destructor")
public:
	BWPrintingControl(BWPrinting *bwPrinting, BWPrintingUI *bwPrintingUI);
	void handle(InputEvent controlEvent);
	void readModel();
private:
	static const uint8_t MINIMUM_EXPOSURE_TIME = 0;
	static const uint8_t MAXIMUM_EXPOSURE_TIME = 240;
	enum Mode {
		combinedExposure,
		greenExposure,
		blueExposure
	};
	BWPrinting *bwPrinting;
	BWPrintingUI *bwPrintingUI;
	Mode mode;

	void updateUI();
	void incrementExposureTime();
	void decrementExposureTime();
	void cycleHightlightedMode();
};

#endif /* BWPRINTING_BWPRINTINGCONTROL_H_ */