/*
 * Displayable.h
 *
 *  Created on: Aug 22, 2020
 *      Author: ghisi
 */

#ifndef UI_DISPLAYABLE_H_
#include <U8g2lib.h>
#define UI_DISPLAYABLE_H_

class Displayable { // @suppress("Class has a virtual method and non-virtual destructor")
public:
	virtual void display(U8G2 *u8g2) = 0;
};



#endif /* UI_DISPLAYABLE_H_ */
