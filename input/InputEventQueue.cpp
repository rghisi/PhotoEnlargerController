/*
 * InputEventQueue.cpp
 *
 *  Created on: Mar 22, 2021
 *      Author: ghisi
 */

#include "InputEventQueue.h"

InputEventQueue::InputEventQueue() {
	this->poll_pointer = 0;
	this->offer_pointer = 0;
	this->is_empty = true;
	this->is_full = false;
}

bool InputEventQueue::HasEvents() {
	return !is_empty;
}

void InputEventQueue::Offer(InputEvent inputEvent) {
	eventQueue[offer_pointer] = inputEvent;
	IncrementOfferPointer();
	is_empty = false;
	if (PollAndOfferPointsToTheSameElement()) {
		is_full = true;
	}
}

InputEvent InputEventQueue::Poll() {
	if (is_empty) {
		return InputEvent::none;
	}
	InputEvent event = eventQueue[poll_pointer];
	IncrementPollPointer();
	if (PollAndOfferPointsToTheSameElement()) {
		is_empty = true;
	}
	is_full = false;
	return event;
}

void InputEventQueue::IncrementPollPointer() {
	poll_pointer++;
	if (poll_pointer == QUEUE_SIZE) {
		poll_pointer = 0;
	}
}

void InputEventQueue::IncrementOfferPointer() {
	offer_pointer++;
	if (offer_pointer == QUEUE_SIZE) {
		offer_pointer = 0;
	}
	if (is_full) {
		poll_pointer = offer_pointer;
	}
}

bool InputEventQueue::PollAndOfferPointsToTheSameElement() {
	return offer_pointer == poll_pointer;
}

/*
 * Queue Size = 4	n=3
 * Initial state	[0, 0, 0, 0]				p=0 o=0	(empty)
 * Offer 1			p=0 o=0	[1, 0, 0, 0]		p=0 o=1
 * Offer 2			p=0 o=1	[1, 2, 0, 0]		p=0 o=2
 * Poll				p=0 o=2	[0, 2, 0, 0]=>1		p=1 o=2
 * Poll 			p=1 o=2	[0, 0, 0, 0]=>2		p=2 o=2	(empty)
 * Offer 3 			p=2 o=2	[0, 0, 3, 0]		p=2 o=3
 * Offer 4			p=2 o=3	[0, 0, 3, 4]		p=2 o=0	(Offer overflow)
 * Offer 5			p=2 o=0	[5, 0, 3, 4]		p=2 o=1
 * Offer 6			p=2 o=1	[5, 6, 3, 4]		p=2 o=2	(queue full)
 * Offer 7			p=2 o=2	[5, 6, 7, 4]		p=3 o=3 (queue full, overwrites)
 * Poll				p=3 o=3	[5, 6, 7, 0]=>4		p=0	o=3	(Poll overflow)
 * Poll				p=0	o=3	[0, 6, 7, 0]=>5		p=1 o=3
 * Poll				p=1 o=3	[0, 0, 7, 0]=>6		p=2 o=3
 * Poll				p=2 o=3	[0, 0, 0, 0]=>7		p=3 o=3 (empty)
 *
 *
 */
