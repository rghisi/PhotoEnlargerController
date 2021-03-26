/*
 * BWPrinting.h
 *
 *  Created on: Aug 18, 2020
 *      Author: ghisi
 */

#ifndef BWPRINTING_H_
#include <stdint.h>
#include "../../peripheral/RGBLed.h"
#include "../../peripheral/WallClockListener.h"
#include "../../peripheral/WallClock.h"
#include "../../ui/Model.h"
#define BWPRINTING_H_

class BWPrintingModel: WallClockListener, public Model { // @suppress("Class has a virtual method and non-virtual destructor")
public:
	BWPrintingModel(RGBLed *rgb_led, WallClock *wall_clock);
	enum State {
		running, stopped, paused, starting
	};
	bool isLocked();
	void OnActivate();
  void OnDeactivate();
	void Start();
	void Stop();
	void Pause();
	void Resume();
	uint8_t GetGreenExposureTime();
	void SetGreenExposure(uint8_t seconds);
	uint8_t GetBlueExposureTime();
	void SetBlueExposure(uint8_t seconds);
	uint8_t GetTotalExposureTime();
	uint8_t GetTotalElapsedExposureTime();
	uint8_t GetGreenRemainingExposureTime();
	uint8_t GetBlueRemainingExposureTime();
	uint8_t GetTotalRemainingExposureTime();
	uint8_t GetRedPower();
	void SetRedPower(uint8_t power);
	uint8_t GetGreenPower();
	void SetGreenPower(uint8_t power);
	uint8_t GetBluePower();
	void SetBluePower(uint8_t power);

	void processClockTick();
	State getState();

private:
	void calculateTotalExposureTime();
	void TurnOnExposureLights();
	RGBLed *rgb_led;
	WallClock *wall_clock;
	State state;
	uint8_t total_exposure_time;
	uint8_t total_remaining_exposure_time;
	uint8_t green_exposure_time;
	uint8_t green_remaining_exposure_time;
	uint8_t blue_exposure_time;
	uint8_t blue_remaining_exposure_time;
};

#endif /* BWPRINTING_H_ */
