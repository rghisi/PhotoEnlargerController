/*
 * UIManagerModel.h
 *
 *  Created on: Dec 31, 2020
 *      Author: ghisi
 */

#ifndef MODES_MANAGER_UIMANAGERMODEL_H_
#include "../../ui/FeatureBundle.h"
#define MODES_MANAGER_UIMANAGERMODEL_H_
class UIManagerModel : public Model {
public:
	UIManagerModel(FeatureBundle* featureBundles, uint8_t numberOfFeatures);
	void selectPreviousFeature();
	void selectNextFeature();
	bool hasPreviousFeature();
	bool hasNextFeature();
	FeatureBundle* getSelectedFeature();

	bool isLocked();

private:
	uint8_t selectedFeatureIndex;
	uint8_t numberOfFeatures;
	FeatureBundle* featureBundles;
	FeatureBundle* selectedFeature;
	static const uint8_t FIRST = 0;
};




#endif /* MODES_MANAGER_UIMANAGERMODEL_H_ */
