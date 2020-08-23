/*
 * BWPrintingUI.h
 *
 *  Created on: Aug 19, 2020
 *      Author: ghisi
 */

#ifndef UI_BWPRINTINGUI_H_
#include "../../ui/Displayable.h"
#include <stdio.h>
#define UI_BWPRINTINGUI_H_

class BWPrintingUI : Displayable { // @suppress("Class has a virtual method and non-virtual destructor")
public:
	BWPrintingUI();
	void display(U8G2 *u8g2);
	void setRunning();
	void setStopped();
	void setPaused();
	void highlightTotalExposure();
	void highlightGreenExposure();
	void highlightBlueExposure();
	uint8_t totalExposureTime;
	uint8_t blueExposureTime;
	uint8_t greenExposureTime;
private:
	enum HighlightedMode {
		totalExposure,
		greenExposure,
		blueExposure
	};
	void highlightSelectedMode(U8G2 *u8g2);
	HighlightedMode highlightedMode;
	uint8_t highlightBoxY;
	static const uint8_t TEXT_BASE_RIGHT = 78;
};

#endif /* UI_BWPRINTINGUI_H_ */
