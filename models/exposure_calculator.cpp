/*
 * exposure_calculator.cpp
 *
 *  Created on: Mar 25, 2021
 *      Author: ghisi
 */

#include "exposure_calculator.h"
#include <stdlib.h>
#include <stdio.h>


ExposureCalculator::ExposureCalculator() {
}

static uint16_t ExposureCalculator::GetExposureTime(EVStep ev_step, uint16_t base_centiseconds, int8_t steps) {
  int8_t interval = (uint8_t) ev_step + 1;
  int8_t full_steps = steps / interval;
  uint16_t full_steps_time = base_centiseconds;

  if (full_steps > 0) {
    full_steps_time = base_centiseconds << full_steps;
  } else if (full_steps < 0) {
    full_steps_time = base_centiseconds >> -full_steps;
  }

  uint16_t micro_steps_time = 0;
  int8_t micro_steps = steps % interval;
  if (micro_steps > 0) {
    uint16_t next_full_steps_time = base_centiseconds << full_steps + 1;
    micro_steps_time = (next_full_steps_time - full_steps_time) / interval * micro_steps;
  } else if (micro_steps < 0) {
    uint16_t next_full_steps_time = base_centiseconds >> -full_steps + 1;
    micro_steps_time = (full_steps_time - next_full_steps_time) / interval * micro_steps;
  }

  return full_steps_time + micro_steps_time;
}

static void ExposureCalculator::WriteExposureValueOffsetLabel(char* buffer, EVStep ev_step, int8_t offset_exposure_value) {
  uint8_t interval = (uint8_t) ev_step + 1;
  int8_t full_stop = offset_exposure_value / interval;
  int8_t remainder = offset_exposure_value % interval;
  char sign = '+';
  if (offset_exposure_value < 0 || remainder < 0) {
    sign = '-';
  }
  if (remainder != 0) {
    sprintf(buffer, "%c%d %d/%d", sign, abs(full_stop), abs(remainder), interval);
  } else {
    sprintf(buffer, "%c%d", sign, abs(full_stop));
  }
}
