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
	void display(U8G2 *u8g2);
	void setView(View* view);
private:
	View* delegateView;
};



#endif /* MODES_MANAGER_UIMANAGERUI_H_ */
