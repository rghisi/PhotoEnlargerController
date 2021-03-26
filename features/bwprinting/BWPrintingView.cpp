/*
 * BWPrintingUI.cpp
 *
 *  Created on: Aug 19, 2020
 *      Author: ghisi
 */

#include "BWPrintingView.h"

static const char *BWPrintingView::title = "B&W EXPOSURE";

BWPrintingView::BWPrintingView(BWPrintingModel *model, BWPrintingController *controller) {
	this->model = model;
	this->controller = controller;
	totalExposureTime = 0;
	greenExposureTime = 0;
	blueExposureTime = 0;
	highlight_box_y = lineOneBoxY;
	highlight_box_x = 0;
}

void BWPrintingView::display(U8G2 *u8g2) {
	readModel();

	u8g2->setFont(u8g2_font_open_iconic_play_4x_t);
	u8g2->drawGlyph(0, 56, state_icon);

	u8g2->setFont(u8g2_font_helvB12_tr);

	char buffer[10];
	sprintf(buffer, "%d%%", model->GetRedPower());
	u8g2->drawStr(pwmBaseRight, lineOneBaseTop, buffer);

	sprintf(buffer, "%d%%", model->GetGreenPower());
	u8g2->drawStr(pwmBaseRight, lineTwoBaseTop, buffer);

	sprintf(buffer, "%d%%", model->GetBluePower());
	u8g2->drawStr(pwmBaseRight, lineThreeBaseTop, buffer);

	sprintf(buffer, "T %d.%d", totalExposureTime / 10, totalExposureTime - (totalExposureTime / 10 * 10));
	u8g2->drawStr(textBaseRight, lineOneBaseTop, buffer);

	sprintf(buffer, "G %d.%d", greenExposureTime / 10, greenExposureTime - (greenExposureTime / 10 * 10));
	u8g2->drawStr(textBaseRight, lineTwoBaseTop, buffer);

	sprintf(buffer, "B %d.%d", blueExposureTime / 10, blueExposureTime - (blueExposureTime / 10 * 10));
	u8g2->drawStr(textBaseRight, lineThreeBaseTop, buffer);

	if (model->getState() == BWPrintingModel::State::stopped) {
		u8g2->drawBox(highlight_box_x, highlight_box_y, highlight_box_width, highlightBoxHeight);
	}
}

void BWPrintingView::readModel() {
	switch (model->getState()) {
		case BWPrintingModel::State::starting:
			state_icon = 69;
			greenExposureTime = model->GetGreenRemainingExposureTime();
			blueExposureTime = model->GetBlueRemainingExposureTime();
			totalExposureTime = model->GetTotalRemainingExposureTime();
			break;
		case BWPrintingModel::State::running:
			state_icon = 69;
			greenExposureTime = model->GetGreenRemainingExposureTime();
			blueExposureTime = model->GetBlueRemainingExposureTime();
			totalExposureTime = model->GetTotalRemainingExposureTime();
			break;
		case BWPrintingModel::State::paused:
			state_icon = 68;
			greenExposureTime = model->GetGreenRemainingExposureTime();
			blueExposureTime = model->GetBlueRemainingExposureTime();
			totalExposureTime = model->GetTotalRemainingExposureTime();
			break;
		case BWPrintingModel::State::stopped:
			state_icon = 75;
			greenExposureTime = model->GetGreenExposureTime();
			blueExposureTime = model->GetBlueExposureTime();
			totalExposureTime = model->GetTotalExposureTime();
			break;
	}

	switch (controller->GetMode()) {
		case BWPrintingController::Mode::combinedExposure:
			highlight_box_x = textBoxX;
			highlight_box_y = lineOneBoxY;
			highlight_box_width = textBoxWidth;
			break;
		case BWPrintingController::Mode::greenExposure:
			highlight_box_x = textBoxX;
			highlight_box_y = lineTwoBoxY;
			highlight_box_width = textBoxWidth;
			break;
		case BWPrintingController::Mode::blueExposure:
			highlight_box_x = textBoxX;
			highlight_box_y = lineThreeBoxY;
			highlight_box_width = textBoxWidth;
			break;
		case BWPrintingController::Mode::redPower:
			highlight_box_x = powerBoxX;
			highlight_box_y = lineOneBoxY;
			highlight_box_width = powerBoxWidth;
			break;
		case BWPrintingController::Mode::greenPower:
			highlight_box_x = powerBoxX;
			highlight_box_y = lineTwoBoxY;
			highlight_box_width = powerBoxWidth;
			break;
		case BWPrintingController::Mode::bluePower:
			highlight_box_x = powerBoxX;
			highlight_box_y = lineThreeBoxY;
			highlight_box_width = powerBoxWidth;
			break;
	}

}

const char* BWPrintingView::GetTitle() {
	return title;
}

bool BWPrintingView::isLocked() {
	return model->isLocked();
}
