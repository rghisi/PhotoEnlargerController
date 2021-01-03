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
	BWPrintingModel(RGBLed* rgb_led, WallClock* wall_clock);
	enum State {
		running, stopped, paused, starting
	};
	bool isLocked();
	void start();
	void stop();
	void pause();
	uint8_t getGreenExposureTime();
	void setGreenExposure(uint8_t seconds);
	uint8_t getBlueExposureTime();
	void setBlueExposure(uint8_t seconds);
	uint8_t getTotalExposureTime();
	uint8_t getTotalElapsedExposureTime();
	uint8_t getGreenRemainingExposureTime();
	uint8_t getBlueRemainingExposureTime();
	uint8_t getTotalRemainingExposureTime();
	uint8_t getRedPower();
	uint8_t getGreenPower();
	uint8_t getBluePower();

	void processClockTick();
	State getState();

private:
	void calculateTotalExposureTime();
	RGBLed* rgb_led;
	WallClock* wall_clock;
	State state;
	uint8_t red_power;
	uint8_t green_power;
	uint8_t blue_power;
	uint8_t total_exposure_time;
	uint8_t total_remaining_exposure_time;
	uint8_t green_exposure_time;
	uint8_t green_remaining_exposure_time;
	uint8_t blue_exposure_time;
	uint8_t blue_remaining_exposure_time;
};

#endif /* BWPRINTING_H_ */
