/*
 * UIBundle.h
 *
 *  Created on: Dec 30, 2020
 *      Author: ghisi
 */

#ifndef UI_UIBUNDLE_H_
#include "Model.h"
#include "View.h"
#include "Controller.h"
#define UI_UIBUNDLE_H_

struct FeatureBundle {
	Model* model;
	View* view;
	Controller* controller;
};


#endif /* UI_UIBUNDLE_H_ */
