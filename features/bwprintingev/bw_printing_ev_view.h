/*
 * BWPrintingUI.h
 *
 *  Created on: Aug 19, 2020
 *      Author: ghisi
 */

#ifndef UI_BWPRINTINEVGUI_H_
#include "../../ui/View.h"
#include "bw_printing_ev_model.h"
#include "bw_printing_ev_controller.h"
#include <stdio.h>
#define UI_BWPRINTINEVGUI_H_

class BWPrintingEVView : public View { // @suppress("Class has a virtual method and non-virtual destructor")
public:
	BWPrintingEVView(BWPrintingEVModel* model, BWPrintingEVController* controller);
	void display(U8G2 *u8g2);
	const char* GetTitle();
	bool isLocked();
	void setRunning();
	void setStopped();
	void setPaused();
private:
	void ReadModel();
	void DrawHighlightBox(U8G2 *u8g2);

	uint8_t highlight_box_x;
	uint8_t highlight_box_y;
	uint8_t highlight_box_width;
	uint8_t state_icon;
	BWPrintingEVModel* model;
	BWPrintingEVController* controller;

	char light_power_level_label[3] = { 'L', 'M', 'H' };
	char ev_step_labels[EVStep::max + 1][4] = { "1", "1/2", "1/3", "1/4" };
	char green_offset_label[8];
	char blue_offset_label[8];

	uint16_t base_exposure_seconds;
	uint8_t base_exposure_decimal;
	uint16_t green_exposure_seconds;
  uint8_t green_exposure_decimal;
  uint16_t blue_exposure_seconds;
  uint8_t blue_exposure_decimal;

	static const char* title;
	static const uint8_t columnOneBaseRight = 33;
	static const uint8_t columnTwoBaseRight = 57;
	static const uint8_t columnThreeBaseRight = 88;
	static const uint8_t lineOneBaseTop = 30;
	static const uint8_t lineTwoBaseTop = 46;
	static const uint8_t lineThreeBaseTop = 62;

	static const uint8_t columnOneHighlightBoxRight = columnOneBaseRight - 2;
  static const uint8_t columnTwoHighlightBoxRight = columnTwoBaseRight - 2;
	static const uint8_t columnThreeHighlightBoxRight = columnThreeBaseRight - 2;
	static const uint8_t highlightBoxHeight = 10;
	static const uint8_t columnOneHighlightBoxWidth = 23;
	static const uint8_t columnTwoHighlightBoxWidth = 30;
	static const uint8_t columnThreeHighlightBoxWidth = 49;

	static const uint8_t lineOneHighlightBoxTop = 21;
	static const uint8_t lineTwoHighlightBoxTop = 37;
	static const uint8_t lineThreeHighlightBoxTop = 53;


};

#endif /* UI_BWPRINTINGUI_H_ */
