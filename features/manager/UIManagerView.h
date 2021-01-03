/*
 * UIManager.h
 *
 *  Created on: Dec 30, 2020
 *      Author: ghisi
 */

#ifndef MODES_MANAGER_UIMANAGERUI_H_
#include "../../ui/View.h"
#define MODES_MANAGER_UIMANAGERUI_H_

class UIManagerView : public View {
public:
	UIManagerView();
	void setView(View* view);

	void display(U8G2 *u8g2);
	const char* GetTitle();
	bool isLocked();

private:
	void DrawFeatureTitle(U8G2 *u8g2);
	View* delegateView;
	uint8_t title_offset;
	static const uint8_t lcdWidth = 128;
};



#endif /* MODES_MANAGER_UIMANAGERUI_H_ */
