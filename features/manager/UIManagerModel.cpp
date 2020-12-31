/*
 * UIManagerModel.cpp
 *
 *  Created on: Dec 31, 2020
 *      Author: ghisi
 */

#include "../../features/manager/UIManagerModel.h"

UIManagerModel::UIManagerModel(FeatureBundle *featureBundles, uint8_t numberOfFeatures) {
	this->featureBundles = featureBundles;
	this->numberOfFeatures = numberOfFeatures;
	selectedFeatureIndex = FIRST;
	selectedFeature = &featureBundles[selectedFeatureIndex];
}

void UIManagerModel::selectPreviousFeature() {
	if (selectedFeatureIndex > FIRST) {
		selectedFeatureIndex--;
		selectedFeature = &featureBundles[selectedFeatureIndex];
	}
}

void UIManagerModel::selectNextFeature() {
	if (selectedFeatureIndex < (numberOfFeatures - 1)) {
		selectedFeatureIndex++;
		selectedFeature = &featureBundles[selectedFeatureIndex];
	}
}

FeatureBundle* UIManagerModel::getSelectedFeature() {
	return selectedFeature;
}

