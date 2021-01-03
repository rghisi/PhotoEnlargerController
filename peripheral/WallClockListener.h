/*
 * WallClockTickable.h
 *
 *  Created on: Aug 19, 2020
 *      Author: ghisi
 */

#ifndef PERIPHERAL_WALLCLOCKLISTENER_H_
#define PERIPHERAL_WALLCLOCKLISTENER_H_

class WallClockListener {
public:
	virtual void processClockTick() = 0;
};



#endif /* PERIPHERAL_WALLCLOCKLISTENER_H_ */
