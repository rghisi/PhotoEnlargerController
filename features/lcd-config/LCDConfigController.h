/*
 * LCDConfigController.h
 *
 *  Created on: Jan 1, 2021
 *      Author: ghisi
 */

#ifndef FEATURES_LCD_CONFIG_LCDCONFIGCONTROLLER_H_
#include "../../ui/Controller.h"
#include "LCDConfigModel.h"
#define FEATURES_LCD_CONFIG_LCDCONFIGCONTROLLER_H_

class LCDConfigController: public Controller {
public:
	LCDConfigController(LCDConfigModel* model);
	void handle(InputEvent controlEvent);

private:
	LCDConfigModel* model;
};

#endif /* FEATURES_LCD_CONFIG_LCDCONFIGCONTROLLER_H_ */
