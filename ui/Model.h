/*
 * Model.h
 *
 *  Created on: Dec 30, 2020
 *      Author: ghisi
 */

#ifndef UI_MODEL_H_
#define UI_MODEL_H_

class Model {
public:
	virtual bool isLocked() = 0;
	virtual void OnActivate();
	virtual void OnDeactivate();
};




#endif /* UI_MODEL_H_ */
