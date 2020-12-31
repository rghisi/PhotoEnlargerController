/*
 * SoftPWM.h
 *
 *  Created on: Dec 29, 2020
 *      Author: ghisi
 */

#ifndef PERIPHERAL_SOFTPWM_H_
#include <stdio.h>
#include "SoftPWMOutput.h"
#define PERIPHERAL_SOFTPWM_H_

class SoftPWM {

public:
//	struct Output {
//		volatile uint8_t *port;
//		uint8_t pin;
//		uint8_t pwmMax;
//		uint8_t counter;
//		uint8_t dutyCycle;
//	};
	SoftPWM(SoftPWMOutput *softPwmOutputs, uint8_t numberOfOutputs);
	void setup();
	void handleTimerInterrupt();
private:
	void configureTimer();
	void configureOutputs();
	SoftPWMOutput *softPwmOutputs;
	uint8_t numberOfOutputs;
};

#endif /* PERIPHERAL_SOFTPWM_H_ */
