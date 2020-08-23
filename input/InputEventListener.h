/*
 * ControlEventListener.h
 *
 *  Created on: Aug 22, 2020
 *      Author: ghisi
 */

#ifndef CONTROLS_CONTROLEVENTLISTENER_H_
#include "../input/InputEvent.h"
#define CONTROLS_CONTROLEVENTLISTENER_H_

class InputEventListener { // @suppress("Class has a virtual method and non-virtual destructor")
public:
	virtual void handle(InputEvent controlEvent) = 0;
};



#endif /* CONTROLS_CONTROLEVENTLISTENER_H_ */
