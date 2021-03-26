/*
 * Controls.h
 *
 *  Created on: Aug 20, 2020
 *      Author: ghisi
 */

#ifndef CONTROLS_H_
#include <stdint.h>
#include <stdio.h>
#include <avr/io.h>
#include <U8g2lib.h>
#include "InputEventListener.h"
#include "InputEventQueue.h"
#include "../ui/Displayable.h"
#define CONTROLS_H_

class InputHandler : public Displayable {
public:
	InputHandler(InputEventListener* input_event_listener);
	void display(U8G2 *u8g2);
	void Enqueue(InputEvent control_event);
	void ProcessQueue();
private:
	InputEventQueue input_event_queue;
	InputEventListener* input_event_listener;

	volatile InputEvent last_input_event;//debug only, remove
};

#endif /* CONTROLS_H_ */
