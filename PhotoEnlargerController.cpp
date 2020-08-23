#include <avr/io.h>
#include <avr/interrupt.h>

#include <Arduino.h>
#include <U8g2lib.h>
#include <SPI.h>
#include <Wire.h>
#include <avr/io.h>

#include "input/InputHandler.h"
#include "modes/focus/Focus.h"
#include "WallClock.h"
#include "WallClockTickable.h"
#include "TickableTest.h"
#include "modes/bwprinting/BWPrinting.h"
#include "modes/bwprinting/BWPrintingUI.h"
#include "modes/bwprinting/BWPrintingControl.h"

U8G2_ST7920_128X64_F_HW_SPI u8g2(U8G2_R0, 12, U8X8_PIN_NONE);

uint16_t start = 0;
uint16_t end = 0;
uint16_t total = 0;
uint8_t seconds = 30;
uint16_t elapsed = 0;

RGBLed rgbLed = RGBLed();
WallClock wallClock = WallClock();
TickableTest tickableTest = TickableTest();
BWPrinting bwPrinting = BWPrinting(&rgbLed);
BWPrintingUI bwPrintingUI = BWPrintingUI();
BWPrintingControl bwPrintingControl = BWPrintingControl(&bwPrinting, &bwPrintingUI);

InputHandler controls = InputHandler(&u8g2);

void setup() {
	sei();
	wallClock.run((WallClockTickable*) &tickableTest);
	wallClock.setup();
	controls.setup();
	controls.addListener(&bwPrintingControl);
	u8g2.begin();
}

void loop() {
	start = millis();
	u8g2.clearBuffer();

	u8g2.setDrawColor(2);

	u8g2.setFont(u8g2_font_open_iconic_play_4x_t);
	u8g2.drawGlyph(5, 48, 0x045);
//	controls.notify();
	tickableTest.display(&u8g2);
	bwPrintingUI.display(&u8g2);

//	u8g2.setFontMode(1);
//	u8g2.setFont(u8g2_font_helvR08_tf);
//	u8g2.setCursor(1, 9);
//	u8g2.print(SPCR);

	u8g2.sendBuffer();

	end = millis();
	total = end - start;
	elapsed += total;
	if (elapsed >= 1000) {
		elapsed = 0;
		seconds--;
	}
}


ISR(TIMER1_COMPA_vect) {
	cli();
	wallClock.handleTimerInterruption();
	controls.poll();
	sei();
}
