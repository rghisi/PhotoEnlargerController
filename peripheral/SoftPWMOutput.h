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
	void ProcessCycle();
	void Configure();
	void SetDutyCycle(uint8_t dutyCycle);
	uint8_t GetDutyCycle();
	uint8_t GetPwmMax();

private:
	volatile uint8_t counter;
	volatile uint8_t *port;
	volatile uint8_t pin;
	uint8_t pwmMax;
	volatile uint8_t duty_cycle;
};

#endif /* PERIPHERAL_SOFTPWMOUTPUT_H_ */
