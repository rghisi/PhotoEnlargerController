/*
 * LCDConfigView.h
 *
 *  Created on: Jan 1, 2021
 *      Author: ghisi
 */

#ifndef FEATURES_LCD_CONFIG_LCDCONFIGVIEW_H_
#include "../../ui/View.h"
#include "LCDConfigModel.h"
#define FEATURES_LCD_CONFIG_LCDCONFIGVIEW_H_

class LCDConfigView : public View {
public:
	LCDConfigView(LCDConfigModel* model);
	void display(U8G2 *u8g2);
	const char* GetTitle();
	bool isLocked();
private:
	LCDConfigModel* model;

	static const char* title;
};



#endif /* FEATURES_LCD_CONFIGURATION_LCDCONFIGVIEW_H_ */
