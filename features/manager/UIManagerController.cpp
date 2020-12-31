/*
 * UIManagerController.cpp
 *
 *  Created on: Dec 30, 2020
 *      Author: ghisi
 */


#include "../../features/manager/UIManagerController.h"

UIManagerController::UIManagerController(UIManagerModel* model, UIManagerView* view) {
	this->model = model;
	this->view = view;
	view->setView(model->getSelectedFeature()->view);
}

void UIManagerController::handle(InputEvent controlEvent) {
	switch (controlEvent) {
		case InputEvent::padLeftReleased:
			model->selectPreviousFeature();
			view->setView(model->getSelectedFeature()->view);
			break;
		case InputEvent::padRightReleased:
			model->selectNextFeature();
			view->setView(model->getSelectedFeature()->view);
			break;
		default:
			model->getSelectedFeature()->controller->handle(controlEvent);
			break;
		}
}

void UIManagerController::readModel() {
	model->getSelectedFeature()->controller->readModel();
}

