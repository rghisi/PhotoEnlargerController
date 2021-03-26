/*
 * WallClock.h
 *
 *  Created on: Aug 19, 2020
 *      Author: ghisi
 */

#ifndef WALLCLOCK_H_
#include "WallClockListener.h"
#include <stdint.h>
#include <stdio.h>
#include <avr/io.h>
#define WALLCLOCK_H_

class WallClock {
public:
	enum State { running, stopped };
	WallClock();
	void Setup();
	void HandleTimerInterrupt();
	void Attach(WallClockListener *tickable);
	void Detach();
	void Run();
	void Stop();
	void Reset();
private:
	WallClockListener *listener;
	uint8_t count;
	State state;
};

#endif /* WALLCLOCK_H_ */
