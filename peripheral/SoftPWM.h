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
	SoftPWM(SoftPWMOutput softPwmOutputs[], uint8_t numberOfOutputs);
	void setup();
	void handleTimerInterrupt();
private:
	void configureTimer();
	void configureOutputs();
	SoftPWMOutput* softPwmOutputs;
	uint8_t numberOfOutputs;
};

#endif /* PERIPHERAL_SOFTPWM_H_ */
