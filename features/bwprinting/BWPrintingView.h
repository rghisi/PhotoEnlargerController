/*
 * BWPrintingUI.h
 *
 *  Created on: Aug 19, 2020
 *      Author: ghisi
 */

#ifndef UI_BWPRINTINGUI_H_
#include "../../ui/View.h"
#include "BWPrintingModel.h"
#include "BWPrintingController.h"
#include <stdio.h>
#define UI_BWPRINTINGUI_H_

class BWPrintingView : public View { // @suppress("Class has a virtual method and non-virtual destructor")
public:
	BWPrintingView(BWPrintingModel* model, BWPrintingController* controller);
	void display(U8G2 *u8g2);
	const char* GetTitle();
	bool isLocked();
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
	void BWPrintingView::readModel();

	HighlightedMode highlightedMode;
	uint8_t highlightBoxY;
	uint8_t stateIcon;
	BWPrintingModel* model;
	BWPrintingController* controller;

	static const uint8_t PWM_BASE_RIGHT = 38;
	static const uint8_t TEXT_BASE_RIGHT = 78;
	static const char* title;
};

#endif /* UI_BWPRINTINGUI_H_ */
