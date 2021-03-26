/*
 * SoftPWM.cpp
 *
 *  Created on: Dec 29, 2020
 *      Author: ghisi
 */

#include "SoftPWM.h"
#include <avr/io.h>

SoftPWM::SoftPWM(SoftPWMOutput softPwmOutputs[], uint8_t numberOfOutputs) {
	this->softPwmOutputs = softPwmOutputs;
	this->numberOfOutputs = numberOfOutputs;
}

void SoftPWM::setup() {
	configureTimer();
	configureOutputs();
}

void SoftPWM::handleTimerInterrupt() {
	for (uint8_t i = 0; i < numberOfOutputs; i++) {
		softPwmOutputs[i].ProcessCycle();
	}
}

void SoftPWM::configureTimer() {
	//Frequency: ~250,00Hz
	TCCR2A = 0;
	TCCR2B = 0;
	TCNT2 = 0;
	OCR2A = 10;
	TCCR2A = (1 << WGM21);	//CTC Mode
	TIMSK2 = (1 << OCIE2A); //Enable interrupt
	TCCR2B = (1 << CS22) | (0 << CS21) | (1 << CS20); //Set prescaler to 1/128 and start timer
}

void SoftPWM::configureOutputs() {
	for (uint8_t i = 0; i < numberOfOutputs; i++) {
		softPwmOutputs[i].Configure();
	}
}
