/*
 * SoftPWMOutput.cpp
 *
 *  Created on: Dec 29, 2020
 *      Author: ghisi
 */

#include "SoftPWMOutput.h"
#include <avr/io.h>

SoftPWMOutput::SoftPWMOutput(volatile uint8_t *port, uint8_t pin,
		uint8_t pwmMax) {
	this->port = port;
	this->pin = _BV(pin);
	this->pwmMax = pwmMax;
	this->counter = 0;
	this->dutyCycle = 80;
}

void SoftPWMOutput::processCycle() {
	counter++;
	if (counter == pwmMax) { //reset and turn on
		counter = 0;
		*port |= pin;
	} else if (counter == dutyCycle) { //turn off
		*port &= !pin;
	}
}

void SoftPWMOutput::configure() {
	*(this->port - 1) |= this->pin; //set pin as output
	*this->port &= !pin; //turn off pin
}

void SoftPWMOutput::setDutyCycle(uint8_t dutyCycle) {
	if (dutyCycle > pwmMax) {
		this->dutyCycle = pwmMax;
	} else {
		this->dutyCycle = dutyCycle;
	}
}

uint8_t SoftPWMOutput::getDutyCycle() {
	return this->dutyCycle;
}
