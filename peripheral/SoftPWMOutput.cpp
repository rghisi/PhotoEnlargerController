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
	this->duty_cycle = 0;
}

void SoftPWMOutput::ProcessCycle() {
	counter++;
	if (counter == pwmMax) { //reset
		counter = 0;
	}

	if (counter >= duty_cycle) {
		*port &= ~pin; //turn off
	} else if (counter == 0) {
		*port |= pin; //turn on
	}
}

void SoftPWMOutput::Configure() {
	*(port - 1) |= pin; //set pin as output
	*port &= ~pin; //turn off pin
}

void SoftPWMOutput::SetDutyCycle(uint8_t dutyCycle) {
	if (dutyCycle > pwmMax) {
		this->duty_cycle = pwmMax;
	} else {
		this->duty_cycle = dutyCycle;
	}
}

uint8_t SoftPWMOutput::GetDutyCycle() {
	return duty_cycle;
}

uint8_t SoftPWMOutput::GetPwmMax() {
	return pwmMax;
}
