/*
 * RGBLed.cpp
 *
 *  Created on: Aug 18, 2020
 *      Author: ghisi
 */

#include "RGBLed.h"

RGBLed::RGBLed(SoftPWMOutput *redPWM, SoftPWMOutput *greenPWM, SoftPWMOutput *bluePWM) {
  this->redPWM = redPWM;
  this->greenPWM = greenPWM;
  this->bluePWM = bluePWM;
  redDutyCycle = 0;
  greenDutyCycle = 0;
  blueDutyCycle = 0;
  allOff();
  ConfigureRGBCalibratedPowerLevels();
}

void RGBLed::allOn() {
  red = true;
  green = true;
  blue = true;
  redPWM->SetDutyCycle(redDutyCycle);
  greenPWM->SetDutyCycle(greenDutyCycle);
  bluePWM->SetDutyCycle(blueDutyCycle);
}
void RGBLed::allOff() {
  red = false;
  green = false;
  blue = false;
  redPWM->SetDutyCycle(0);
  greenPWM->SetDutyCycle(0);
  bluePWM->SetDutyCycle(0);
}
void RGBLed::redOn() {
  red = true;
  redPWM->SetDutyCycle(redDutyCycle);
}
void RGBLed::greenOn() {
  green = true;
  greenPWM->SetDutyCycle(greenDutyCycle);
}
void RGBLed::blueOn() {
  blue = true;
  bluePWM->SetDutyCycle(blueDutyCycle);
}
void RGBLed::redOff() {
  red = false;
  redPWM->SetDutyCycle(0);
}
void RGBLed::greenOff() {
  green = false;
  greenPWM->SetDutyCycle(0);
}
void RGBLed::blueOff() {
  blue = false;
  bluePWM->SetDutyCycle(0);
}

void RGBLed::SetRedDutyCycle(uint8_t duty_cycle) {
  if (duty_cycle <= redPWM->GetPwmMax()) {
    redDutyCycle = duty_cycle;
    if (red)
      redPWM->SetDutyCycle(duty_cycle);
  }
}

uint8_t RGBLed::GetRedDutyCycle() {
  return redDutyCycle;
}

void RGBLed::SetGreenDutyCycle(uint8_t duty_cycle) {
  if (duty_cycle <= greenPWM->GetPwmMax()) {
    greenDutyCycle = duty_cycle;
    if (green)
      greenPWM->SetDutyCycle(duty_cycle);
  }
}

uint8_t RGBLed::GetGreenDutyCycle() {
  return greenDutyCycle;
}

void RGBLed::SetBlueDutyCycle(uint8_t duty_cycle) {
  if (duty_cycle <= bluePWM->GetPwmMax()) {
    blueDutyCycle = duty_cycle;
    if (blue)
      bluePWM->SetDutyCycle(duty_cycle);
  }
}

uint8_t RGBLed::GetBlueDutyCycle() {
  return blueDutyCycle;
}

void RGBLed::SetCalibratedPower(PowerLevel power_level) {
  RGBPowerCalibration calibrated_power = calibrated_power_levels[static_cast<uint8_t>(power_level)];
  SetRedDutyCycle(calibrated_power.red);
  SetGreenDutyCycle(calibrated_power.green);
  SetBlueDutyCycle(calibrated_power.blue);
}

void RGBLed::display(U8G2 *u8g2) {
  u8g2->setFont(u8g2_font_helvR08_tr);
  char buffer[3];
  sprintf(buffer, "%d %d %d", redDutyCycle, greenDutyCycle, blueDutyCycle);
  u8g2->drawStr(50, 9, buffer);
}

void RGBLed::ConfigureRGBCalibratedPowerLevels() {
  this->calibrated_power_levels[static_cast<uint8_t>(PowerLevel::low)].red = 39;
  this->calibrated_power_levels[static_cast<uint8_t>(PowerLevel::low)].green = 60;
  this->calibrated_power_levels[static_cast<uint8_t>(PowerLevel::low)].blue = 17;

  this->calibrated_power_levels[static_cast<uint8_t>(PowerLevel::medium)].red = 80;
  this->calibrated_power_levels[static_cast<uint8_t>(PowerLevel::medium)].green = 120;
  this->calibrated_power_levels[static_cast<uint8_t>(PowerLevel::medium)].blue = 30;

  this->calibrated_power_levels[static_cast<uint8_t>(PowerLevel::high)].red = 170;
  this->calibrated_power_levels[static_cast<uint8_t>(PowerLevel::high)].green = 255;
  this->calibrated_power_levels[static_cast<uint8_t>(PowerLevel::high)].blue = 50;
}
