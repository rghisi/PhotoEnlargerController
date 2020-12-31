#include <avr/io.h>
#include <avr/interrupt.h>

#include <Arduino.h>
#include <U8g2lib.h>
#include <SPI.h>
#include <Wire.h>
#include <avr/io.h>

#include "features/bwprinting/BWPrinting.h"
#include "features/bwprinting/BWPrintingControl.h"
#include "features/bwprinting/BWPrintingUI.h"
#include "features/focus/FocusController.h"
#include "features/focus/FocusModel.h"
#include "features/focus/FocusView.h"
#include "features/manager/UIManagerController.h"
#include "features/manager/UIManagerModel.h"
#include "features/manager/UIManagerView.h"
#include "peripheral/SoftPWM.h"
#include "input/InputHandler.h"
#include "input/KeyPad.h"
#include "input/Dial.h"
#include "WallClock.h"
#include "WallClockTickable.h"
#include "TickableTest.h"
#include "ui/FeatureBundle.h"

#define ADC_SOFT_PRESCALER_MAX 128

U8G2_ST7920_128X64_F_HW_SPI u8g2(U8G2_R0, 12, U8X8_PIN_NONE);

uint8_t tempref = 0;
uint8_t adcPrescaler = 0;

RGBLed rgbLed = RGBLed();
WallClock wallClock = WallClock();
TickableTest tickableTest = TickableTest();

BWPrinting bwPrinting = BWPrinting(&rgbLed);
BWPrintingUI bwPrintingUI = BWPrintingUI();
BWPrintingControl bwPrintingControl = BWPrintingControl(&bwPrinting, &bwPrintingUI);

FocusModel focusModel = FocusModel(&rgbLed);
FocusView focusView = FocusView(&focusModel);
FocusController focusController = FocusController(&focusModel);

FeatureBundle uiBundles[2] = {
		{ &bwPrinting, &bwPrintingUI, &bwPrintingControl },
		{ &focusModel, &focusView, &focusController}
};

UIManagerModel featureManagerModel = UIManagerModel(uiBundles, 2);
UIManagerView featureManagerView = UIManagerView();
UIManagerController featureManagerController = UIManagerController(&featureManagerModel, &featureManagerView);

InputHandler inputHandler = InputHandler(&featureManagerController);
KeyPad keyPad = KeyPad(&inputHandler);
Dial dial = Dial(&inputHandler);

SoftPWMOutput lcdBacklightPwm = SoftPWMOutput(&PORTB, PORTB1, 100);
SoftPWMOutput* outputs = {&lcdBacklightPwm};
SoftPWM softPWM = SoftPWM(outputs, 1);

void setup() {
	softPWM.setup();
	wallClock.run((WallClockTickable*) &bwPrinting);
	wallClock.setup();
	keyPad.setup();
	dial.setup();
	u8g2.begin();

	sei();
}

void loop() {
	featureManagerController.readModel();

	u8g2.clearBuffer();
	u8g2.setDrawColor(2);

	inputHandler.display(&u8g2);
	tickableTest.display(&u8g2);
	featureManagerView.display(&u8g2);
	rgbLed.display(&u8g2);

//	u8g2.setFontMode(1);
//	u8g2.setFont(u8g2_font_helvR08_tf);
//	u8g2.setCursor(1, 18);
//	u8g2.print(tempref2);

	u8g2.sendBuffer();
}


ISR(TIMER1_COMPA_vect) {
	cli();
	wallClock.handleTimerInterrupt();
	sei();
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

ISR(PCINT1_vect) {
	dial.handleInterrupt();
}
