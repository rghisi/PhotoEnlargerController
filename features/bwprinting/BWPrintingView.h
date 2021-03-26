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
	uint8_t totalExposureTime;
	uint8_t blueExposureTime;
	uint8_t greenExposureTime;
private:
	void BWPrintingView::readModel();

	uint8_t highlight_box_x;
	uint8_t highlight_box_y;
	uint8_t highlight_box_width;
	uint8_t state_icon;
	BWPrintingModel* model;
	BWPrintingController* controller;

	static const char* title;
	static const uint8_t pwmBaseRight = 37;
	static const uint8_t textBaseRight = 79;
	static const uint8_t highlightBoxHeight = 16;
	static const uint8_t powerBoxX = pwmBaseRight - 2;
	static const uint8_t powerBoxWidth = 44;
	static const uint8_t textBoxX = textBaseRight - 2;
	static const uint8_t textBoxWidth = 49;

	static const uint8_t lineOneBoxY = 16;
	static const uint8_t lineTwoBoxY = 32;
	static const uint8_t lineThreeBoxY = 48;
	static const uint8_t lineOneBaseTop = 30;
	static const uint8_t lineTwoBaseTop = 46;
	static const uint8_t lineThreeBaseTop = 62;
};

#endif /* UI_BWPRINTINGUI_H_ */
