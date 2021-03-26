/*
 * BWPrintingUI.cpp
 *
 *  Created on: Aug 19, 2020
 *      Author: ghisi
 */

#include "bw_printing_ev_view.h"
#include "../../models/exposure_calculator.h"

static const char *BWPrintingEVView::title = "B&W EXPOSURE";

BWPrintingEVView::BWPrintingEVView(BWPrintingEVModel *model, BWPrintingEVController *controller) {
  this->model = model;
  this->controller = controller;
  highlight_box_y = lineOneHighlightBoxTop;
  highlight_box_x = 0;
  base_exposure_seconds = 0;
  base_exposure_decimal = 0;
  green_exposure_seconds = 0;
  green_exposure_decimal = 0;
  blue_exposure_seconds = 0;
  blue_exposure_decimal = 0;
}

void BWPrintingEVView::display(U8G2 *u8g2) {
  ReadModel();

  u8g2->setFont(u8g2_font_open_iconic_play_4x_t);
  u8g2->drawGlyph(0, 56, state_icon);

  u8g2->setFont(u8g2_font_helvB08_tr);

  char buffer[11];
  sprintf(buffer, "P %c", light_power_level_label[model->GetLightPowerLevel()]);
  u8g2->drawStr(columnOneBaseRight, lineOneBaseTop, buffer);

  sprintf(buffer, "G %u.%us", green_exposure_seconds, green_exposure_decimal);
  u8g2->drawStr(columnOneBaseRight, lineTwoBaseTop, buffer);

  sprintf(buffer, "B %u.%us", blue_exposure_seconds, blue_exposure_decimal);
  u8g2->drawStr(columnOneBaseRight, lineThreeBaseTop, buffer);

  sprintf(buffer, "S %s", ev_step_labels[model->GetEVStep()]);
  u8g2->drawStr(columnTwoBaseRight, lineOneBaseTop, buffer);

  sprintf(buffer, "t %u.%us", base_exposure_seconds, base_exposure_decimal);
  u8g2->drawStr(columnThreeBaseRight, lineOneBaseTop, buffer);

  sprintf(buffer, "%s", green_offset_label);
  u8g2->drawStr(columnThreeBaseRight, lineTwoBaseTop, buffer);

  sprintf(buffer, "%s", blue_offset_label);
  u8g2->drawStr(columnThreeBaseRight, lineThreeBaseTop, buffer);

  DrawHighlightBox(u8g2);
}

void BWPrintingEVView::ReadModel() {
  uint16_t green_exposure_time;
  switch (model->getState()) {
    case BWPrintingEVModel::State::starting:
      state_icon = 69;
      break;
    case BWPrintingEVModel::State::running:
      state_icon = 69;
      break;
    case BWPrintingEVModel::State::paused:
      state_icon = 68;
      break;
    case BWPrintingEVModel::State::stopped:
      state_icon = 75;
      break;
  }

  ExposureCalculator::WriteExposureValueOffsetLabel(green_offset_label, model->GetEVStep(), model->GetGreenOffset());
  ExposureCalculator::WriteExposureValueOffsetLabel(blue_offset_label, model->GetEVStep(), model->GetBlueOffset());
  base_exposure_seconds = model->GetBaseExposureTime() / 100;
  base_exposure_decimal = (model->GetBaseExposureTime() - (model->GetBaseExposureTime() / 100 * 100)) / 10;

  green_exposure_seconds = model->GetGreenExposureTime() / 100;
  green_exposure_decimal = (model->GetGreenExposureTime() - (model->GetGreenExposureTime() / 100 * 100)) / 10;

  blue_exposure_seconds = model->GetBlueExposureTime() / 100;
  blue_exposure_decimal = (model->GetBlueExposureTime() - (model->GetBlueExposureTime() / 100 * 100)) / 10;
}

void BWPrintingEVView::DrawHighlightBox(U8G2 *u8g2) {
  if (model->getState() == BWPrintingEVModel::State::stopped) {
    switch (controller->GetMode()) {
      case BWPrintingEVController::Mode::exposure:
        highlight_box_x = columnThreeHighlightBoxRight;
        highlight_box_y = lineOneHighlightBoxTop;
        highlight_box_width = columnThreeHighlightBoxWidth;
        break;
      case BWPrintingEVController::Mode::greenOffset:
        highlight_box_x = columnThreeHighlightBoxRight;
        highlight_box_y = lineTwoHighlightBoxTop;
        highlight_box_width = columnThreeHighlightBoxWidth;
        break;
      case BWPrintingEVController::Mode::blueOffset:
        highlight_box_x = columnThreeHighlightBoxRight;
        highlight_box_y = lineThreeHighlightBoxTop;
        highlight_box_width = columnThreeHighlightBoxWidth;
        break;
      case BWPrintingEVController::Mode::lightPower:
        highlight_box_x = columnOneHighlightBoxRight;
        highlight_box_y = lineOneHighlightBoxTop;
        highlight_box_width = columnOneHighlightBoxWidth;
        break;
      case BWPrintingEVController::Mode::evSteps:
        highlight_box_x = columnTwoHighlightBoxRight;
        highlight_box_y = lineOneHighlightBoxTop;
        highlight_box_width = columnTwoHighlightBoxWidth;
        break;
    }

    u8g2->drawBox(highlight_box_x, highlight_box_y, highlight_box_width, highlightBoxHeight);
  }
}

const char* BWPrintingEVView::GetTitle() {
  return title;
}

bool BWPrintingEVView::isLocked() {
  return model->isLocked();
}
