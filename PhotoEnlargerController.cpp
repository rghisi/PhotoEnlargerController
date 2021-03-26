#include <avr/io.h>
#include <avr/interrupt.h>

#include <Arduino.h>
#include <U8g2lib.h>
#include <SPI.h>
#include <Wire.h>
#include <avr/io.h>

#include "peripheral/Configurations.h"
#include "peripheral/SoftPWM.h"
#include "features/bwprintingev/bw_printing_ev_controller.h"
#include "features/bwprintingev/bw_printing_ev_model.h"
#include "features/bwprintingev/bw_printing_ev_view.h"
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
#include "ui/FeatureBundle.h"

U8G2_ST7920_128X64_2_HW_SPI u8g2(U8G2_R0, 12, U8X8_PIN_NONE);
uint8_t gui_page = 0;

Configurations configurations = Configurations();

WallClock wallClock = WallClock();

SoftPWMOutput outputs[4] = {
		SoftPWMOutput(&PORTB, PORTB1, 100),
		SoftPWMOutput(&PORTD, PORTD6, 255),
		SoftPWMOutput(&PORTD, PORTD5, 255),
		SoftPWMOutput(&PORTD, PORTD3, 255)
};
SoftPWM softPWM = SoftPWM(outputs, 4);

SoftPWMOutput* lcdBacklightPwm = &outputs[0];
SoftPWMOutput* redLightPwm = &outputs[1];
SoftPWMOutput* greenLightPwm = &outputs[2];
SoftPWMOutput* blueLightPwm = &outputs[3];

RGBLed rgbLed = RGBLed(redLightPwm, greenLightPwm, blueLightPwm);

BWPrintingEVModel bwPrintingEvModel = BWPrintingEVModel(&rgbLed, &wallClock);
BWPrintingEVController bwPrintingEvController = BWPrintingEVController(&bwPrintingEvModel);
BWPrintingEVView bwPrintingEvView = BWPrintingEVView(&bwPrintingEvModel, &bwPrintingEvController);

FocusModel focusModel = FocusModel(&rgbLed);
FocusView focusView = FocusView(&focusModel);
FocusController focusController = FocusController(&focusModel);

LCD lcd = LCD(lcdBacklightPwm, &configurations);
LCDConfigModel lcdConfigModel = LCDConfigModel(&lcd);
LCDConfigView lcdConfigView = LCDConfigView(&lcdConfigModel);
LCDConfigController lcdConfigController = LCDConfigController(&lcdConfigModel);

FeatureBundle uiBundles[4] = {
    { &bwPrintingEvModel, &bwPrintingEvView, &bwPrintingEvController },
//		{ &bwPrintingModel, &bwPrintingView, &bwPrintingController },
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
	inputHandler.ProcessQueue();

	if (gui_page == 0) {
    u8g2.firstPage();
	}

  u8g2.setDrawColor(2);
  u8g2.setFontMode(1);
  featureManagerView.display(&u8g2);
//	inputHandler.display(&u8g2);
//	rgbLed.display(&u8g2);

//	u8g2.setFontMode(1);
//	u8g2.setFont(u8g2_font_helvR08_tr);
//	u8g2.setCursor(1, 18);
//	u8g2.print(outputs[1]->getDutyCycle());
  gui_page = u8g2.nextPage();
}


ISR(TIMER1_COMPA_vect) {
	wallClock.HandleTimerInterrupt();
	dial.poll();
	keyPad.poll();
}

ISR(TIMER2_COMPA_vect) {
	softPWM.handleTimerInterrupt();
}
