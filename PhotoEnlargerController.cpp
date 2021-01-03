#include <avr/io.h>
#include <avr/interrupt.h>

#include <Arduino.h>
#include <U8g2lib.h>
#include <SPI.h>
#include <Wire.h>
#include <avr/io.h>

#include "peripheral/Configurations.h"
#include "peripheral/SoftPWM.h"
#include "features/bwprinting/BWPrintingController.h"
#include "features/bwprinting/BWPrintingModel.h"
#include "features/bwprinting/BWPrintingView.h"
#include "features/focus/FocusController.h"
#include "features/focus/FocusModel.h"
#include "features/focus/FocusView.h"
#include "features/lcd-config/LCDConfigModel.h"
#include "features/lcd-config/LCDConfigView.h"
#include "features/lcd-config/LCDConfigController.h"
#include "features/manager/UIManagerController.h"
#include "features/manager/UIManagerModel.h"
#include "features/manager/UIManagerView.h"
#include "input/InputHandler.h"
#include "input/KeyPad.h"
#include "input/Dial.h"
#include "peripheral/WallClock.h"
#include "peripheral/WallClockListener.h"
#include "TickableTest.h"
#include "ui/FeatureBundle.h"

#define ADC_SOFT_PRESCALER_MAX 128

U8G2_ST7920_128X64_F_HW_SPI u8g2(U8G2_R0, 12, U8X8_PIN_NONE);

uint8_t tempref = 0;
uint8_t adcPrescaler = 0;

Configurations configurations = Configurations();

WallClock wallClock = WallClock();

SoftPWMOutput outputs[4] = {
		SoftPWMOutput(&PORTB, PORTB1, 100),
		SoftPWMOutput(&PORTD, PORTD6, 100),
		SoftPWMOutput(&PORTD, PORTD5, 100),
		SoftPWMOutput(&PORTD, PORTD3, 100)
};
SoftPWM softPWM = SoftPWM(outputs, 4);

SoftPWMOutput* lcdBacklightPwm = &outputs[0];
SoftPWMOutput* redLightPwm = &outputs[1];
SoftPWMOutput* greenLightPwm = &outputs[2];
SoftPWMOutput* blueLightPwm = &outputs[3];

RGBLed rgbLed = RGBLed(redLightPwm, greenLightPwm, blueLightPwm);

BWPrintingModel bwPrintingModel = BWPrintingModel(&rgbLed, &wallClock);
BWPrintingController bwPrintingController = BWPrintingController(&bwPrintingModel);
BWPrintingView bwPrintingView = BWPrintingView(&bwPrintingModel, &bwPrintingController);

FocusModel focusModel = FocusModel(&rgbLed);
FocusView focusView = FocusView(&focusModel);
FocusController focusController = FocusController(&focusModel);

LCD lcd = LCD(lcdBacklightPwm, &configurations);
LCDConfigModel lcdConfigModel = LCDConfigModel(&lcd);
LCDConfigView lcdConfigView = LCDConfigView(&lcdConfigModel);
LCDConfigController lcdConfigController = LCDConfigController(&lcdConfigModel);

FeatureBundle uiBundles[3] = {
		{ &bwPrintingModel, &bwPrintingView, &bwPrintingController },
		{ &focusModel, &focusView, &focusController},
		{ &lcdConfigModel, &lcdConfigView, &lcdConfigController }

};

UIManagerModel featureManagerModel = UIManagerModel(uiBundles, 3);
UIManagerView featureManagerView = UIManagerView();
UIManagerController featureManagerController = UIManagerController(&featureManagerModel, &featureManagerView);

InputHandler inputHandler = InputHandler(&featureManagerController);
KeyPad keyPad = KeyPad(&inputHandler);
Dial dial = Dial(&inputHandler);

void setup() {
	softPWM.setup();
	wallClock.Setup();
	keyPad.setup();
	dial.setup();
	u8g2.begin();

	sei();
}

void loop() {
	u8g2.clearBuffer();
	u8g2.setDrawColor(2);
	u8g2.setFontMode(1);

//	inputHandler.display(&u8g2);
//	tickableTest.display(&u8g2);
	featureManagerView.display(&u8g2);
//	rgbLed.display(&u8g2);

//	u8g2.setFontMode(1);
//	u8g2.setFont(u8g2_font_helvR08_tr);
//	u8g2.setCursor(1, 18);
//	u8g2.print(outputs[1]->getDutyCycle());

	u8g2.sendBuffer();
}


ISR(TIMER1_COMPA_vect) {
	wallClock.HandleTimerInterrupt();
	if (TCNT1 & 0x01) {
		dial.poll();
	}
}

ISR(TIMER2_COMPA_vect) {
	softPWM.handleTimerInterrupt();
}

ISR(ADC_vect) {
	adcPrescaler++;
	if (adcPrescaler == ADC_SOFT_PRESCALER_MAX) {
		keyPad.handleADCInterrupt();
		adcPrescaler = 0;
	}
}
