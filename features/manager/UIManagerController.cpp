/*
 * UIManagerController.cpp
 *
 *  Created on: Dec 30, 2020
 *      Author: ghisi
 */

#include "../../features/manager/UIManagerController.h"

UIManagerController::UIManagerController(UIManagerModel *model,
		UIManagerView *view) {
	this->model = model;
	this->view = view;
	view->setView(model->getSelectedFeature()->view);
}

void UIManagerController::handle(InputEvent controlEvent) {
	switch (controlEvent) {
	case InputEvent::padLeftReleased:
		SelectPreviousFeature();
		break;
	case InputEvent::padRightReleased:
		selectNextFeature();
		break;
	default:
		model->getSelectedFeature()->controller->handle(controlEvent);
		break;
	}
}

void UIManagerController::SelectPreviousFeature() {
	if (model->SelectPreviousFeature()) {
		view->setView(model->getSelectedFeature()->view);
	}
}

void UIManagerController::selectNextFeature() {
  if (model->SelectNextFeature()) {
		view->setView(model->getSelectedFeature()->view);
	}
}
