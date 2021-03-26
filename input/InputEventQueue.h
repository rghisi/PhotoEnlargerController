/*
 * InputEventQueue.h
 *
 *  Created on: Mar 22, 2021
 *      Author: ghisi
 */

#ifndef INPUT_INPUTEVENTQUEUE_H_
#include <stdint.h>
#include "InputEvent.h"
#define INPUT_INPUTEVENTQUEUE_H_


class InputEventQueue {
public:
	InputEventQueue();
	void Offer(InputEvent inputEvent);
	InputEvent Poll();
	bool HasEvents();
private:
	void IncrementPollPointer();
	void IncrementOfferPointer();
	bool PollAndOfferPointsToTheSameElement();
	uint8_t poll_pointer;
	uint8_t offer_pointer;
	bool is_full;
	bool is_empty;
	static const uint8_t QUEUE_SIZE = 10;
	InputEvent eventQueue[QUEUE_SIZE];
};


#endif /* INPUT_INPUTEVENTQUEUE_H_ */
