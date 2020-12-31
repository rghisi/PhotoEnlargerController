/*
 * BWPrinting.h
 *
 *  Created on: Aug 18, 2020
 *      Author: ghisi
 */

#ifndef BWPRINTING_H_
#include <stdint.h>
#include "../../peripheral/RGBLed.h"
#include "../../WallClockTickable.h"
#include "../../ui/Model.h"
#define BWPRINTING_H_

class BWPrinting: WallClockTickable, public Model { // @suppress("Class has a virtual method and non-virtual destructor")
public:
	BWPrinting(RGBLed *rgbLed);
	enum State {
		running, stopped, paused
	};
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

	void processClockTick();
	State getState();

private:
	void calculateTotalExposureTime();
	RGBLed *rgbLed;
	State state;
	uint8_t totalExposureTime;
	uint8_t totalRemainingExposureTime;
	uint8_t greenExposureTime;
	uint8_t greenRemainingExposureTime;
	uint8_t blueExposureTime;
	uint8_t blueRemainingExposureTime;
};

#endif /* BWPRINTING_H_ */
