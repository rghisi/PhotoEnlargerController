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
	model->getSelectedFeature()->controller->OnActivate();
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

void UIManagerController::OnActivate() {
	model->getSelectedFeature()->controller->OnActivate();
}

void UIManagerController::OnDeactivate() {
	model->getSelectedFeature()->controller->OnDeactivate();
}

void UIManagerController::SelectPreviousFeature() {
	if (!model->isLocked() && model->hasPreviousFeature()) {
		OnDeactivate();
		model->selectPreviousFeature();
		OnActivate();
		view->setView(model->getSelectedFeature()->view);
	}
}

void UIManagerController::selectNextFeature() {
	if (!model->isLocked() && model->hasNextFeature()) {
		OnDeactivate();
		model->selectNextFeature();
		OnActivate();
		view->setView(model->getSelectedFeature()->view);
	}
}
