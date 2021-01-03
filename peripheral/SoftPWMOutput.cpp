/*
 * SoftPWMOutput.cpp
 *
 *  Created on: Dec 29, 2020
 *      Author: ghisi
 */

#include "SoftPWMOutput.h"
#include <avr/io.h>

SoftPWMOutput::SoftPWMOutput(volatile uint8_t *port, volatile uint8_t pin, uint8_t pwmMax) {
	this->port = port;
	this->pin = _BV(pin);
	this->pwmMax = pwmMax;
	this->counter = 0;
	this->dutyCycle = 0;
}

void SoftPWMOutput::processCycle() {
	counter++;
	if (counter == pwmMax) { //reset
		counter = 0;
	}

	if (counter >= dutyCycle) {
		*port &= ~pin; //turn off
	} else if (counter == 0) {
		*port |= pin; //turn on
	}
}

void SoftPWMOutput::configure() {
	*(port - 1) |= pin; //set pin as output
	*port &= ~pin; //turn off pin
}

void SoftPWMOutput::setDutyCycle(uint8_t dutyCycle) {
	if (dutyCycle > pwmMax) {
		this->dutyCycle = pwmMax;
	} else {
		this->dutyCycle = dutyCycle;
	}
}

uint8_t SoftPWMOutput::getDutyCycle() {
	return dutyCycle;
}
