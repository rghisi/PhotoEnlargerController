/*
 * BWPrinting.h
 *
 *  Created on: Aug 18, 2020
 *      Author: ghisi
 */

#ifndef BWPRINTINGEV_H_
#include <stdint.h>
#include "../../peripheral/RGBLed.h"
#include "../../peripheral/WallClockListener.h"
#include "../../peripheral/WallClock.h"
#include "../../models/exposure_calculator.h"
#include "../../ui/Model.h"
#define BWPRINTINGEV_H_

class BWPrintingEVModel: WallClockListener, public Model { // @suppress("Class has a virtual method and non-virtual destructor")
public:
  BWPrintingEVModel(RGBLed* rgb_led, WallClock* wall_clock);
	enum State {
		running, stopped, paused, starting
	};
	bool isLocked();
	void OnActivate();
  void OnDeactivate();

  void RunStop();
  void PauseResume();
  void IncreaseLightPowerLevel();
  void DecreaseLightPowerLevel();
  void IncreaseExposure();
  void DecreaseExposure();
  void IncreaseGreenOffset();
  void DecreaseGreenOffset();
  void IncreaseBlueOffset();
  void DecreaseBlueOffset();
  void IncreaseEVStep();
  void DecreaseEVStep();
  uint16_t GetBaseExposureTime();
  int8_t GetGreenOffset();
  int8_t GetBlueOffset();
  uint16_t GetTotalExposureTime();
  uint16_t GetGreenExposureTime();
  uint16_t GetBlueExposureTime();
  EVStep GetEVStep();
  RGBLed::PowerLevel GetLightPowerLevel();

	uint8_t GetTotalElapsedExposureTime();

	void processClockTick();
	State getState();

private:
	void Start();
	void Stop();
  void Pause();
  void Resume();
	void CalculateExposureTimes();
	uint8_t GetMaxPositiveOffset();
	int8_t GetMinNegativeOffset();

	RGBLed::PowerLevel power_level;
	uint16_t base_exposure_time_centiseconds;
	int8_t green_offset;
	int8_t blue_offset;
	EVStep ev_step;

	void TurnOnExposureLights();
	RGBLed* rgb_led;
	WallClock* wall_clock;
	State state;
	uint16_t green_exposure_time;
	uint16_t blue_exposure_time;
};

#endif /* BWPRINTING_H_ */
