/*
 * exposure_calculator.h
 *
 *  Created on: Mar 25, 2021
 *      Author: ghisi
 */

#ifndef MODELS_EXPOSURE_CALCULATOR_H_
#include <stdint.h>
#include "ev_step.h"
#define MODELS_EXPOSURE_CALCULATOR_H_

class ExposureCalculator {
 public:
  ExposureCalculator();
  static uint16_t GetExposureTime(EVStep ev_step, uint16_t baseCentiseconds, int8_t steps);
  static void WriteExposureValueOffsetLabel(char* buffer, EVStep ev_step, int8_t offset_exposure_value);

 private:
  static const uint8_t number_of_steps_between_full_steps[4] = {1, 2, 3, 4};
};

#endif /* MODELS_EXPOSURE_CALCULATOR_H_ */
