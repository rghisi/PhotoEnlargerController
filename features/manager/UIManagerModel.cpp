/*
 * UIManagerModel.cpp
 *
 *  Created on: Dec 31, 2020
 *      Author: ghisi
 */

#include "../../features/manager/UIManagerModel.h"

UIManagerModel::UIManagerModel(FeatureBundle *featureBundles,
		uint8_t numberOfFeatures) {
	this->featureBundles = featureBundles;
	this->numberOfFeatures = numberOfFeatures;
	selectedFeatureIndex = FIRST;
	selectedFeature = &featureBundles[selectedFeatureIndex];
	OnDeactivate();
}

bool UIManagerModel::SelectPreviousFeature() {
	if (!isLocked() && hasPreviousFeature()) {
	  OnDeactivate();
		selectedFeatureIndex--;
		selectedFeature = &featureBundles[selectedFeatureIndex];
		OnActivate();
		return true;
	}
	return false;
}

bool UIManagerModel::SelectNextFeature() {
	if (!isLocked() && hasNextFeature()) {
	  OnDeactivate();
		selectedFeatureIndex++;
		selectedFeature = &featureBundles[selectedFeatureIndex];
		OnActivate();
		return true;
	}
	return false;
}

bool UIManagerModel::hasPreviousFeature() {
	return selectedFeatureIndex > FIRST;
}

bool UIManagerModel::hasNextFeature() {
	return selectedFeatureIndex < (numberOfFeatures - 1);
}

FeatureBundle* UIManagerModel::getSelectedFeature() {
	return selectedFeature;
}

bool UIManagerModel::isLocked() {
	return selectedFeature->model->isLocked();
}

void UIManagerModel::OnActivate() {
  selectedFeature->model->OnActivate();
}

void UIManagerModel::OnDeactivate() {
  selectedFeature->model->OnDeactivate();
}
