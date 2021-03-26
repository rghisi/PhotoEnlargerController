/*
 * Controls.cpp
 *
 *  Created on: Aug 20, 2020
 *      Author: ghisi
 */

#include "../input/InputHandler.h"

InputHandler::InputHandler(InputEventListener *input_event_listener) {
	this->input_event_listener = input_event_listener;
	this->input_event_queue = InputEventQueue();
	this->last_input_event = InputEvent::none;
}

void InputHandler::Enqueue(InputEvent event) {
	input_event_queue.Offer(event);
	last_input_event = event;
}

void InputHandler::ProcessQueue() {
	while (input_event_queue.HasEvents()) {
		InputEvent event = input_event_queue.Poll();
		input_event_listener->handle(event);
		last_input_event = event;
	}
}

void InputHandler::display(U8G2 *u8g2) {
	u8g2->setFontMode(1);
	u8g2->setFont(u8g2_font_helvR08_tr);
	u8g2->setCursor(1, 9);
	u8g2->print((int)last_input_event);
}

