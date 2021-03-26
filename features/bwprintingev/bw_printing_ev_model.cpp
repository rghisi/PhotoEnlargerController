/*
 * BWPrinting.cpp
 *
 *  Created on: Aug 18, 2020
 *      Author: ghisi
 */

#include "bw_printing_ev_model.h"

BWPrintingEVModel::BWPrintingEVModel(RGBLed *rgb_led, WallClock *wall_clock) {
  this->rgb_led = rgb_led;
  this->wall_clock = wall_clock;
  green_exposure_time = 0;
  blue_exposure_time = 0;
  state = State::stopped;
  rgb_led->allOff();
  rgb_led->SetCalibratedPower(RGBLed::PowerLevel::medium);

  power_level = RGBLed::PowerLevel::medium;
  base_exposure_time_centiseconds = 500;
  green_offset = 0;
  blue_offset = 0;
  ev_step = EVStep::fourth;
  CalculateExposureTimes();
}

void BWPrintingEVModel::RunStop() {
  switch (state) {
    case BWPrintingEVModel::State::stopped:
      Start();
      break;
    case BWPrintingEVModel::State::running:
      Stop();
      break;
    case BWPrintingEVModel::State::paused:
      Stop();
      break;
  }
}

void BWPrintingEVModel::PauseResume() {
  switch (state) {
    case BWPrintingEVModel::State::running:
      Pause();
      break;
    case BWPrintingEVModel::State::paused:
      Resume();
      break;
  }
}

void BWPrintingEVModel::IncreaseLightPowerLevel() {
  if (power_level < RGBLed::PowerLevel::max) {
    power_level = power_level + 1;
    rgb_led->SetCalibratedPower(power_level);
  }
}

void BWPrintingEVModel::DecreaseLightPowerLevel() {
  if (power_level > RGBLed::PowerLevel::min) {
    power_level = power_level - 1;
    rgb_led->SetCalibratedPower(power_level);
  }
}

void BWPrintingEVModel::IncreaseExposure() {
  base_exposure_time_centiseconds += 10;
  CalculateExposureTimes();
}

void BWPrintingEVModel::DecreaseExposure() {
  base_exposure_time_centiseconds -= 10;
  CalculateExposureTimes();
}

void BWPrintingEVModel::IncreaseGreenOffset() {
  green_offset++;
  CalculateExposureTimes();
}

void BWPrintingEVModel::DecreaseGreenOffset() {
  green_offset--;
  CalculateExposureTimes();
}

void BWPrintingEVModel::IncreaseBlueOffset() {
  blue_offset++;
  CalculateExposureTimes();
}

void BWPrintingEVModel::DecreaseBlueOffset() {
  blue_offset--;
  CalculateExposureTimes();
}

void BWPrintingEVModel::IncreaseEVStep() {
  if (ev_step < EVStep::max) {
    ev_step = ev_step + 1;
    CalculateExposureTimes();
  }
}

void BWPrintingEVModel::DecreaseEVStep() {
  if (ev_step > EVStep::min) {
    ev_step = ev_step - 1;
    CalculateExposureTimes();
  }
}

uint16_t BWPrintingEVModel::GetBaseExposureTime() {
  return base_exposure_time_centiseconds;
}

int8_t BWPrintingEVModel::GetGreenOffset() {
  return green_offset;
}

int8_t BWPrintingEVModel::GetBlueOffset() {
  return blue_offset;
}

uint16_t BWPrintingEVModel::GetGreenExposureTime() {
  return green_exposure_time;
}

uint16_t BWPrintingEVModel::GetBlueExposureTime() {
  return blue_exposure_time;
}

EVStep BWPrintingEVModel::GetEVStep() {
  return ev_step;
}

RGBLed::PowerLevel BWPrintingEVModel::GetLightPowerLevel() {
  return power_level;
}

BWPrintingEVModel::State BWPrintingEVModel::getState() {
  return state;
}

void BWPrintingEVModel::Start() {
  CalculateExposureTimes();
  wall_clock->Attach(this);
  TurnOnExposureLights();
  wall_clock->Run();
  state = State::running;
}

void BWPrintingEVModel::Stop() {
  state = State::stopped;
  rgb_led->allOff();
  wall_clock->Detach();
}

void BWPrintingEVModel::Pause() {
  state = State::paused;
  wall_clock->Stop();
  rgb_led->allOff();
}

void BWPrintingEVModel::Resume() {
  TurnOnExposureLights();
  wall_clock->Run();
  state = State::running;
}

void BWPrintingEVModel::processClockTick() {
  switch (state) {
    case State::running:
      if (green_exposure_time > 0) {
        green_exposure_time--;
      } else {
        rgb_led->greenOff();
      }

      if (blue_exposure_time > 0) {
        blue_exposure_time--;
      } else {
        rgb_led->blueOff();
      }

      if (green_exposure_time == 0 && blue_exposure_time == 0) {
        Stop();
        CalculateExposureTimes();
      }
      break;
    default:
      break;
  }
}

void BWPrintingEVModel::CalculateExposureTimes() {
  green_exposure_time = ExposureCalculator::GetExposureTime(ev_step, base_exposure_time_centiseconds, green_offset);
  blue_exposure_time = ExposureCalculator::GetExposureTime(ev_step, base_exposure_time_centiseconds, blue_offset);
}

bool BWPrintingEVModel::isLocked() {
  return state == State::running;
}

void BWPrintingEVModel::TurnOnExposureLights() {
  rgb_led->redOn();
  if (green_exposure_time > 0) {
    rgb_led->greenOn();
  }
  if (blue_exposure_time > 0) {
    rgb_led->blueOn();
  }
}

void BWPrintingEVModel::OnActivate() {

}

void BWPrintingEVModel::OnDeactivate() {

}
