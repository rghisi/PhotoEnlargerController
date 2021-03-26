/*
 * WallClock.cpp
 *
 *  Created on: Aug 19, 2020
 *      Author: ghisi
 */

#include "WallClock.h"

WallClock::WallClock() {
	listener = 0;
	count = 0;
	state = State::stopped;
}

void WallClock::Setup() {
	TCCR1A = 0; // set entire TCCR1A register to 0
	TCCR1B = 0; // same for TCCR1B
	TCNT1 = 0; // initialize counter value to 0
	// set compare match register for 1000 Hz increments
	OCR1A = 249;
	// turn on CTC mode
	TCCR1B |= (1 << WGM12);
	// Set CS12, CS11 and CS10 bits for 64 prescaler
	TCCR1B |= (0 << CS12) | (1 << CS11) | (1 << CS10);
	// enable timer compare interrupt
	TIMSK1 |= (1 << OCIE1A);
}

void WallClock::HandleTimerInterrupt() {
	if (state == State::running && listener) {
		count++;
		if (count == 10) {
			count = 0;
			listener->processClockTick();
		}
	}
}

void WallClock::Attach(WallClockListener *listener) {
	this->listener = listener;
	Reset();
}

void WallClock::Detach() {
	this->listener = 0;
	Reset();
}

void WallClock::Run() {
	state = State::running;
}

void WallClock::Stop() {
	state = State::stopped;
}

void WallClock::Reset() {
	state = State::stopped;
	count = 0;
}
