/*
 * Controller.h
 *
 *  Created on: Dec 30, 2020
 *      Author: ghisi
 */

#ifndef UI_CONTROLLER_H_
#include "../input/InputEventListener.h"
#define UI_CONTROLLER_H_

class Controller : public InputEventListener {
public:
	virtual void readModel();
};



#endif /* UI_CONTROLLER_H_ */
