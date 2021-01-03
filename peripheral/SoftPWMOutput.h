/*
 * SoftPWMOutput.h
 *
 *  Created on: Dec 29, 2020
 *      Author: ghisi
 */

#ifndef PERIPHERAL_SOFTPWMOUTPUT_H_
#include <stdio.h>
#define PERIPHERAL_SOFTPWMOUTPUT_H_

class SoftPWMOutput {

public:
	SoftPWMOutput(volatile uint8_t *port, uint8_t pin, uint8_t pwmMax);
	void processCycle();
	void configure();
	void setDutyCycle(uint8_t dutyCycle);
	uint8_t getDutyCycle();

private:
	volatile uint8_t counter;
	volatile uint8_t *port;
	volatile uint8_t pin;
	uint8_t pwmMax;
	volatile uint8_t dutyCycle;
};

#endif /* PERIPHERAL_SOFTPWMOUTPUT_H_ */
