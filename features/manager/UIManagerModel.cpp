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
}

void UIManagerModel::selectPreviousFeature() {
	if (hasPreviousFeature()) {
		selectedFeatureIndex--;
		selectedFeature = &featureBundles[selectedFeatureIndex];
	}
}

void UIManagerModel::selectNextFeature() {
	if (hasNextFeature()) {
		selectedFeatureIndex++;
		selectedFeature = &featureBundles[selectedFeatureIndex];
	}
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

