/*
 * LCDConfigModel.h
 *
 *  Created on: Jan 1, 2021
 *      Author: ghisi
 */

#ifndef FEATURES_LCD_CONFIG_LCDCONFIGMODEL_H_
#include "../../ui/Model.h"
#include "../../peripheral/LCD.h"
#define FEATURES_LCD_CONFIG_LCDCONFIGMODEL_H_

class LCDConfigModel : public Model {
public:
	LCDConfigModel(LCD* lcd);
	bool isLocked();
	void OnActivate();
  void OnDeactivate();
	void IncreaseBrightness();
	void DecreaseBrightness();
	uint8_t GetBrightness();
	void SaveBrightness();

private:
	LCD* lcd;
};




#endif /* FEATURES_LCD_CONFIG_LCDCONFIGMODEL_H_ */
