/*
 * WallClock.cpp
 *
 *  Created on: Aug 19, 2020
 *      Author: ghisi
 */

#include "WallClock.h"

WallClock::WallClock() {
	tickable = 0;
	count = 0;
}

void WallClock::setup() {
	TCCR1A = 0; // set entire TCCR1A register to 0
	TCCR1B = 0; // same for TCCR1B
	TCNT1  = 0; // initialize counter value to 0
	// set compare match register for 2000 Hz increments
	OCR1A = 124; // = 16000000 / (64 * 2000) - 1 (must be <65536)
	// turn on CTC mode
	TCCR1B |= (1 << WGM12);
	// Set CS12, CS11 and CS10 bits for 64 prescaler
	TCCR1B |= (0 << CS12) | (1 << CS11) | (1 << CS10);
	// enable timer compare interrupt
	TIMSK1 |= (1 << OCIE1A);
}

void WallClock::handleTimerInterrupt() {
	count++;
	if (count == 2000L) {
		count = 0;
		if (tickable != 0) {
			tickable->processClockTick();
		}
	}
}

void WallClock::run(WallClockTickable *tickable) {
	this->tickable = tickable;
}

