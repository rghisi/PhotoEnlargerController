/*
 * BWPrintingUI.cpp
 *
 *  Created on: Aug 19, 2020
 *      Author: ghisi
 */

#include "../../features/bwprinting/BWPrintingUI.h"

BWPrintingUI::BWPrintingUI() {
	totalExposureTime = 0;
	greenExposureTime = 0;
	blueExposureTime = 0;
	highlightedMode = HighlightedMode::totalExposure;
	highlightBoxY = 16;
}

void BWPrintingUI::highlightTotalExposure() {
	highlightedMode = HighlightedMode::totalExposure;
	highlightBoxY = 16;
}

void BWPrintingUI::highlightGreenExposure() {
	highlightedMode = HighlightedMode::greenExposure;
	highlightBoxY = 32;
}

void BWPrintingUI::highlightBlueExposure() {
	highlightedMode = HighlightedMode::blueExposure;
	highlightBoxY = 48;
}

void BWPrintingUI::display(U8G2 *u8g2) {
	highlightSelectedMode(u8g2);
//	u8g2->drawBox(0, 0, 128, 10);
//	u8g2->setFont(u8g2_font_helvR08_tf);
//	u8g2->setCursor(24, 9);
//	u8g2->print("B&W EXPOSURE");

	//0x51 stop
	//0x44 pause
	//0x45 play
	u8g2->setFont(u8g2_font_open_iconic_play_4x_t);
	u8g2->drawGlyph(5, 48, 0x51);

	u8g2->setFont(u8g2_font_helvB12_tf);

	char buffer[10];
	sprintf(buffer, "%d%%", 90);
	u8g2->drawStr(PWM_BASE_RIGHT, 46, buffer);

	sprintf(buffer, "%d%%", 90);
	u8g2->drawStr(PWM_BASE_RIGHT, 62, buffer);


	sprintf(buffer, "T: %ds", totalExposureTime);
	u8g2->drawStr(TEXT_BASE_RIGHT, 30, buffer);

	sprintf(buffer, "G: %ds", greenExposureTime);
	u8g2->drawStr(TEXT_BASE_RIGHT, 46, buffer);

	sprintf(buffer, "B: %ds", blueExposureTime);
	u8g2->drawStr(TEXT_BASE_RIGHT, 62, buffer);
}

void BWPrintingUI::highlightSelectedMode(U8G2 *u8g2) {
	u8g2->drawBox(TEXT_BASE_RIGHT - 2, highlightBoxY, 50, 16);
}

