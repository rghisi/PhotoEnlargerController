/*
 * BWPrintingUI.cpp
 *
 *  Created on: Aug 19, 2020
 *      Author: ghisi
 */

#include "BWPrintingView.h"

static const char *BWPrintingView::title = "B&W EXPOSURE";

BWPrintingView::BWPrintingView(BWPrintingModel *model,
		BWPrintingController *controller) {
	this->model = model;
	this->controller = controller;
	totalExposureTime = 0;
	greenExposureTime = 0;
	blueExposureTime = 0;
	highlightedMode = HighlightedMode::totalExposure;
	highlightBoxY = 16;
}

void BWPrintingView::highlightTotalExposure() {
	highlightedMode = HighlightedMode::totalExposure;
	highlightBoxY = 16;
}

void BWPrintingView::highlightGreenExposure() {
	highlightedMode = HighlightedMode::greenExposure;
	highlightBoxY = 32;
}

void BWPrintingView::highlightBlueExposure() {
	highlightedMode = HighlightedMode::blueExposure;
	highlightBoxY = 48;
}

void BWPrintingView::display(U8G2 *u8g2) {
	readModel();

	u8g2->setFont(u8g2_font_open_iconic_play_4x_t);
	u8g2->drawGlyph(5, 48, stateIcon);

	u8g2->setFont(u8g2_font_helvB12_tr);

	char buffer[10];
	sprintf(buffer, "%d%%", model->getRedPower());
	u8g2->drawStr(PWM_BASE_RIGHT, 30, buffer);

	sprintf(buffer, "%d%%", model->getGreenPower());
	u8g2->drawStr(PWM_BASE_RIGHT, 46, buffer);

	sprintf(buffer, "%d%%", model->getBluePower());
	u8g2->drawStr(PWM_BASE_RIGHT, 62, buffer);

	sprintf(buffer, "T: %d", totalExposureTime);
	u8g2->drawStr(TEXT_BASE_RIGHT, 30, buffer);

	sprintf(buffer, "G: %d", greenExposureTime);
	u8g2->drawStr(TEXT_BASE_RIGHT, 46, buffer);

	sprintf(buffer, "B: %d", blueExposureTime);
	u8g2->drawStr(TEXT_BASE_RIGHT, 62, buffer);

	highlightSelectedMode(u8g2);
}

void BWPrintingView::readModel() {
	switch (model->getState()) {
	case BWPrintingModel::State::starting:
		stateIcon = 69;
		greenExposureTime = model->getGreenRemainingExposureTime();
		blueExposureTime = model->getBlueRemainingExposureTime();
		totalExposureTime = model->getTotalRemainingExposureTime();
		break;
	case BWPrintingModel::State::running:
		stateIcon = 69;
		greenExposureTime = model->getGreenRemainingExposureTime();
		blueExposureTime = model->getBlueRemainingExposureTime();
		totalExposureTime = model->getTotalRemainingExposureTime();
		break;
	case BWPrintingModel::State::paused:
		stateIcon = 68;
		greenExposureTime = model->getGreenRemainingExposureTime();
		blueExposureTime = model->getBlueRemainingExposureTime();
		totalExposureTime = model->getTotalRemainingExposureTime();
		break;
	case BWPrintingModel::State::stopped:
		stateIcon = 75;
		greenExposureTime = model->getGreenExposureTime();
		blueExposureTime = model->getBlueExposureTime();
		totalExposureTime = model->getTotalExposureTime();
		break;
	}

	switch (controller->getMode()) {
	case BWPrintingController::Mode::combinedExposure:
		highlightTotalExposure();
		break;
	case BWPrintingController::Mode::greenExposure:
		highlightGreenExposure();
		break;
	case BWPrintingController::Mode::blueExposure:
		highlightBlueExposure();
		break;
	}
}

const char* BWPrintingView::GetTitle() {
	return title;
}

bool BWPrintingView::isLocked() {
	return model->isLocked();
}

void BWPrintingView::highlightSelectedMode(U8G2 *u8g2) {
	u8g2->drawBox(TEXT_BASE_RIGHT - 2, highlightBoxY, 50, 16);
}

