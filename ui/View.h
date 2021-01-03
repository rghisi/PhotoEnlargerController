/*
 * View.h
 *
 *  Created on: Dec 30, 2020
 *      Author: ghisi
 */

#ifndef UI_VIEW_H_
#include "Displayable.h"
#define UI_VIEW_H_

class View : public Displayable {
public:
	virtual const char* GetTitle() = 0;
	virtual bool isLocked() = 0;
};




#endif /* UI_VIEW_H_ */
