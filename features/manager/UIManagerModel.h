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
	bool SelectPreviousFeature();
	bool SelectNextFeature();
	FeatureBundle* getSelectedFeature();

	bool isLocked();
	void OnActivate();
	void OnDeactivate();

private:
	bool hasPreviousFeature();
	bool hasNextFeature();
	uint8_t selectedFeatureIndex;
	uint8_t numberOfFeatures;
	FeatureBundle* featureBundles;
	FeatureBundle* selectedFeature;
	static const uint8_t FIRST = 0;
};




#endif /* MODES_MANAGER_UIMANAGERMODEL_H_ */
