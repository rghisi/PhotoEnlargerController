/*
 * WallClock.h
 *
 *  Created on: Aug 19, 2020
 *      Author: ghisi
 */

#ifndef WALLCLOCK_H_
#include "WallClockTickable.h"
#include <stdint.h>
#include <stdio.h>
#include <avr/io.h>
#define WALLCLOCK_H_

class WallClock {
public:
	WallClock();
	void setup();
	void handleTimerInterrupt();
	void reset();
	void run(WallClockTickable *tickable);
	void stop();
private:
	WallClockTickable *tickable;
	uint16_t count;
};

#endif /* WALLCLOCK_H_ */
