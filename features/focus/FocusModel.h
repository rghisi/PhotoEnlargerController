/*
 * Focus.h
 *
 *  Created on: Aug 18, 2020
 *      Author: ghisi
 */

#ifndef FOCUS_H_
#include "../../peripheral/RGBLed.h"
#include "../../ui/Model.h"
#define FOCUS_H_

class FocusModel : public Model {
public:
	FocusModel(RGBLed *rgbLed);
	void ToggleFocusLight();
	uint8_t GetState();
	void SetLightPower(uint8_t lightPower);
	uint8_t GetLightPower();
	void IncreaseLightPower();
	void DecreaseLightPower();
	bool isLocked();
	void OnActivate();
  void OnDeactivate();
private:
	uint8_t state = LIGHT_OFF;
	RGBLed *rgb_led;
	uint8_t light_power;
	static const uint8_t LIGHT_OFF = 0;
	static const uint8_t LIGHT_ON = 1;
};

#endif /* FOCUS_H_ */
