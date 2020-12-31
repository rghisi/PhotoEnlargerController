/*
 * UIManagerController.h
 *
 *  Created on: Dec 30, 2020
 *      Author: ghisi
 */

#ifndef MODES_MANAGER_UIMANAGERCONTROLLER_H_
#include "../../ui/FeatureBundle.h"
#include "../../features/manager/UIManagerModel.h"
#include "../../features/manager/UIManagerView.h"
#define MODES_MANAGER_UIMANAGERCONTROLLER_H_

class UIManagerController : public Controller {
public:
	UIManagerController(UIManagerModel* uiManagerModel, UIManagerView* view);
	void handle(InputEvent controlEvent);
	void readModel();
private:
	void selectPreviousUI();
	void selectNextUI();

	UIManagerModel* model;
	UIManagerView* view;
};



#endif /* MODES_MANAGER_UIMANAGERCONTROLLER_H_ */
