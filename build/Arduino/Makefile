ifeq ($(OS),Windows_NT)
SHELL = cmd
RMDIR = rmdir /s /q
RM = del /q
mymkdir = if not exist "$1" mkdir "$1"
else
RMDIR = rm -fr
RM = rm -f
mymkdir = mkdir -p $1
endif

PROJECT_OBJS = \
	project/PhotoEnlargerController.cpp.o \
	project/TickableTest.cpp.o \
	project/features/bwprinting/BWPrintingController.cpp.o \
	project/features/bwprinting/BWPrintingModel.cpp.o \
	project/features/bwprinting/BWPrintingView.cpp.o \
	project/features/focus/FocusController.cpp.o \
	project/features/focus/FocusModel.cpp.o \
	project/features/focus/FocusView.cpp.o \
	project/features/lcd-config/LCDConfigController.cpp.o \
	project/features/lcd-config/LCDConfigModel.cpp.o \
	project/features/lcd-config/LCDConfigView.cpp.o \
	project/features/manager/UIManagerController.cpp.o \
	project/features/manager/UIManagerModel.cpp.o \
	project/features/manager/UIManagerView.cpp.o \
	project/input/Dial.cpp.o \
	project/input/InputHandler.cpp.o \
	project/input/KeyPad.cpp.o \
	project/peripheral/Configurations.cpp.o \
	project/peripheral/LCD.cpp.o \
	project/peripheral/RGBLed.cpp.o \
	project/peripheral/SoftPWM.cpp.o \
	project/peripheral/SoftPWMOutput.cpp.o \
	project/peripheral/WallClock.cpp.o \

PLATFORM_CORE_OBJS = \
	core/PluggableUSB.cpp.o \
	core/WMath.cpp.o \
	core/WInterrupts.c.o \
	core/USBCore.cpp.o \
	core/HardwareSerial2.cpp.o \
	core/Stream.cpp.o \
	core/HardwareSerial1.cpp.o \
	core/HardwareSerial.cpp.o \
	core/Print.cpp.o \
	core/wiring_digital.c.o \
	core/wiring_pulse.c.o \
	core/Tone.cpp.o \
	core/wiring_pulse.S.o \
	core/hooks.c.o \
	core/main.cpp.o \
	core/CDC.cpp.o \
	core/HardwareSerial3.cpp.o \
	core/IPAddress.cpp.o \
	core/HardwareSerial0.cpp.o \
	core/abi.cpp.o \
	core/wiring.c.o \
	core/wiring_analog.c.o \
	core/new.cpp.o \
	core/wiring_shift.c.o \
	core/WString.cpp.o \

PLATFORM_VARIANT_OBJS = \

LIBRARIES_OBJS = \
	libraries/Wire/src/utility/twi.c.o \
	libraries/Wire/src/Wire.cpp.o \
	libraries/U8g2/2.28.10/src/U8x8lib.cpp.o \
	libraries/U8g2/2.28.10/src/clib/u8g2_hvline.c.o \
	libraries/U8g2/2.28.10/src/clib/u8x8_d_ls013b7dh03.c.o \
	libraries/U8g2/2.28.10/src/clib/u8x8_debounce.c.o \
	libraries/U8g2/2.28.10/src/clib/u8x8_d_ssd1326.c.o \
	libraries/U8g2/2.28.10/src/clib/u8x8_d_st7528.c.o \
	libraries/U8g2/2.28.10/src/clib/u8x8_u8toa.c.o \
	libraries/U8g2/2.28.10/src/clib/u8x8_message.c.o \
	libraries/U8g2/2.28.10/src/clib/u8x8_d_st7571.c.o \
	libraries/U8g2/2.28.10/src/clib/u8x8_capture.c.o \
	libraries/U8g2/2.28.10/src/clib/u8log.c.o \
	libraries/U8g2/2.28.10/src/clib/u8g2_input_value.c.o \
	libraries/U8g2/2.28.10/src/clib/u8x8_d_ssd1305.c.o \
	libraries/U8g2/2.28.10/src/clib/u8x8_d_ssd1306_96x16.c.o \
	libraries/U8g2/2.28.10/src/clib/u8x8_input_value.c.o \
	libraries/U8g2/2.28.10/src/clib/u8x8_d_sh1107.c.o \
	libraries/U8g2/2.28.10/src/clib/u8x8_d_ssd1306_128x32.c.o \
	libraries/U8g2/2.28.10/src/clib/u8x8_d_uc1608.c.o \
	libraries/U8g2/2.28.10/src/clib/u8x8_d_max7219.c.o \
	libraries/U8g2/2.28.10/src/clib/u8x8_d_ssd1309.c.o \
	libraries/U8g2/2.28.10/src/clib/u8x8_d_st7565.c.o \
	libraries/U8g2/2.28.10/src/clib/u8x8_d_ssd1318.c.o \
	libraries/U8g2/2.28.10/src/clib/u8g2_d_setup.c.o \
	libraries/U8g2/2.28.10/src/clib/u8x8_d_sed1330.c.o \
	libraries/U8g2/2.28.10/src/clib/u8x8_d_lc7981.c.o \
	libraries/U8g2/2.28.10/src/clib/u8g2_cleardisplay.c.o \
	libraries/U8g2/2.28.10/src/clib/u8x8_d_uc1701_mini12864.c.o \
	libraries/U8g2/2.28.10/src/clib/u8x8_d_ssd1322.c.o \
	libraries/U8g2/2.28.10/src/clib/u8x8_d_uc1638.c.o \
	libraries/U8g2/2.28.10/src/clib/u8x8_d_pcd8544_84x48.c.o \
	libraries/U8g2/2.28.10/src/clib/u8g2_font.c.o \
	libraries/U8g2/2.28.10/src/clib/u8x8_d_st7567.c.o \
	libraries/U8g2/2.28.10/src/clib/u8x8_d_uc1610.c.o \
	libraries/U8g2/2.28.10/src/clib/u8x8_selection_list.c.o \
	libraries/U8g2/2.28.10/src/clib/u8g2_selection_list.c.o \
	libraries/U8g2/2.28.10/src/clib/u8x8_d_st75320.c.o \
	libraries/U8g2/2.28.10/src/clib/u8g2_message.c.o \
	libraries/U8g2/2.28.10/src/clib/u8x8_d_st7920.c.o \
	libraries/U8g2/2.28.10/src/clib/u8g2_box.c.o \
	libraries/U8g2/2.28.10/src/clib/u8x8_d_sh1106_72x40.c.o \
	libraries/U8g2/2.28.10/src/clib/u8x8_d_uc1617.c.o \
	libraries/U8g2/2.28.10/src/clib/u8x8_display.c.o \
	libraries/U8g2/2.28.10/src/clib/u8x8_d_ssd1317.c.o \
	libraries/U8g2/2.28.10/src/clib/u8x8_d_ist3020.c.o \
	libraries/U8g2/2.28.10/src/clib/u8g2_kerning.c.o \
	libraries/U8g2/2.28.10/src/clib/u8x8_d_ssd1325.c.o \
	libraries/U8g2/2.28.10/src/clib/u8x8_d_t6963.c.o \
	libraries/U8g2/2.28.10/src/clib/u8x8_d_ssd1316.c.o \
	libraries/U8g2/2.28.10/src/clib/u8x8_d_uc1611.c.o \
	libraries/U8g2/2.28.10/src/clib/u8g2_ll_hvline.c.o \
	libraries/U8g2/2.28.10/src/clib/u8x8_cad.c.o \
	libraries/U8g2/2.28.10/src/clib/u8x8_d_ld7032_60x32.c.o \
	libraries/U8g2/2.28.10/src/clib/u8g2_fonts.c.o \
	libraries/U8g2/2.28.10/src/clib/u8x8_d_st7586s_erc240160.c.o \
	libraries/U8g2/2.28.10/src/clib/u8x8_d_ssd1607_200x200.c.o \
	libraries/U8g2/2.28.10/src/clib/u8x8_d_ssd1306_2040x16.c.o \
	libraries/U8g2/2.28.10/src/clib/u8x8_d_ssd1606_172x72.c.o \
	libraries/U8g2/2.28.10/src/clib/u8g2_setup.c.o \
	libraries/U8g2/2.28.10/src/clib/u8x8_d_s1d15e06.c.o \
	libraries/U8g2/2.28.10/src/clib/u8x8_d_uc1701_dogs102.c.o \
	libraries/U8g2/2.28.10/src/clib/u8x8_d_st7586s_ymc240160.c.o \
	libraries/U8g2/2.28.10/src/clib/u8x8_d_st7588.c.o \
	libraries/U8g2/2.28.10/src/clib/u8x8_byte.c.o \
	libraries/U8g2/2.28.10/src/clib/u8x8_setup.c.o \
	libraries/U8g2/2.28.10/src/clib/u8x8_d_sh1122.c.o \
	libraries/U8g2/2.28.10/src/clib/u8x8_d_uc1601.c.o \
	libraries/U8g2/2.28.10/src/clib/u8g2_d_memory.c.o \
	libraries/U8g2/2.28.10/src/clib/u8g2_polygon.c.o \
	libraries/U8g2/2.28.10/src/clib/u8x8_u16toa.c.o \
	libraries/U8g2/2.28.10/src/clib/u8x8_d_ssd1306_72x40.c.o \
	libraries/U8g2/2.28.10/src/clib/u8x8_d_a2printer.c.o \
	libraries/U8g2/2.28.10/src/clib/u8x8_d_il3820_296x128.c.o \
	libraries/U8g2/2.28.10/src/clib/u8log_u8g2.c.o \
	libraries/U8g2/2.28.10/src/clib/u8x8_d_pcf8812.c.o \
	libraries/U8g2/2.28.10/src/clib/u8x8_d_sh1106_64x32.c.o \
	libraries/U8g2/2.28.10/src/clib/u8x8_d_ssd1306_64x48.c.o \
	libraries/U8g2/2.28.10/src/clib/u8x8_d_st7511.c.o \
	libraries/U8g2/2.28.10/src/clib/u8g2_line.c.o \
	libraries/U8g2/2.28.10/src/clib/u8x8_d_ssd1329.c.o \
	libraries/U8g2/2.28.10/src/clib/u8g2_intersection.c.o \
	libraries/U8g2/2.28.10/src/clib/u8x8_gpio.c.o \
	libraries/U8g2/2.28.10/src/clib/u8x8_d_ssd1306_48x64.c.o \
	libraries/U8g2/2.28.10/src/clib/u8x8_d_st75256.c.o \
	libraries/U8g2/2.28.10/src/clib/u8x8_d_st7586s_s028hn118a.c.o \
	libraries/U8g2/2.28.10/src/clib/u8log_u8x8.c.o \
	libraries/U8g2/2.28.10/src/clib/u8g2_bitmap.c.o \
	libraries/U8g2/2.28.10/src/clib/u8x8_8x8.c.o \
	libraries/U8g2/2.28.10/src/clib/u8x8_d_ks0108.c.o \
	libraries/U8g2/2.28.10/src/clib/u8g2_circle.c.o \
	libraries/U8g2/2.28.10/src/clib/u8x8_string.c.o \
	libraries/U8g2/2.28.10/src/clib/u8x8_d_ssd1327.c.o \
	libraries/U8g2/2.28.10/src/clib/u8x8_d_uc1604.c.o \
	libraries/U8g2/2.28.10/src/clib/u8x8_d_sh1108.c.o \
	libraries/U8g2/2.28.10/src/clib/u8x8_d_ssd1306_128x64_noname.c.o \
	libraries/U8g2/2.28.10/src/clib/u8g2_buffer.c.o \
	libraries/U8g2/2.28.10/src/clib/u8x8_d_ist7920.c.o \
	libraries/U8g2/2.28.10/src/clib/u8x8_fonts.c.o \
	libraries/U8g2/2.28.10/src/clib/u8x8_d_ssd1306_64x32.c.o \
	libraries/U8g2/2.28.10/src/clib/u8x8_d_sbn1661.c.o \
	libraries/U8g2/2.28.10/src/clib/u8x8_d_pcf8814_hx1230.c.o \
	libraries/U8g2/2.28.10/src/U8g2lib.cpp.o \
	libraries/SPI/src/SPI.cpp.o \

TARGETS = \
	PhotoEnlargerController.hex \
	PhotoEnlargerController.eep \

all: $(TARGETS)

PhotoEnlargerController.hex: PhotoEnlargerController.elf
	"/home/ghisi/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-objcopy" -O ihex -R .eeprom  "./PhotoEnlargerController.elf" "./PhotoEnlargerController.hex"

PhotoEnlargerController.eep: PhotoEnlargerController.elf
	"/home/ghisi/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-objcopy" -O ihex -j .eeprom --set-section-flags=.eeprom=alloc,load --no-change-warnings --change-section-lma .eeprom=0  "./PhotoEnlargerController.elf" "./PhotoEnlargerController.eep"

PhotoEnlargerController.elf: $(PROJECT_OBJS) $(LIBRARIES_OBJS) core.a
	"/home/ghisi/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-gcc" -w -Os -g -flto -fuse-linker-plugin -Wl,--gc-sections -mmcu=atmega328p   -o "./PhotoEnlargerController.elf" $(PROJECT_OBJS) $(LIBRARIES_OBJS)  "./core.a" "-L." -lm

core.a:	$(PLATFORM_CORE_OBJS) $(PLATFORM_VARIANT_OBJS)

clean:
	-$(RMDIR) project core variant libraries
	-$(RM) *.hex *.eep *.bin *.elf *.a *.ar *.d

size:
	"/home/ghisi/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-size" -A "./PhotoEnlargerController.elf"

project/PhotoEnlargerController.cpp.o: ../../PhotoEnlargerController.cpp project/PhotoEnlargerController.cpp.d
	@$(call mymkdir,$(dir $@))
	"/home/ghisi/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_DUEMILANOVE -DARDUINO_ARCH_AVR   -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/variants/standard" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/Wire/src" -I"/home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/EEPROM/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/SPI/src" "$<" -o "$@"

project/PhotoEnlargerController.cpp.d: ;

-include project/PhotoEnlargerController.cpp.d 

project/TickableTest.cpp.o: ../../TickableTest.cpp project/TickableTest.cpp.d
	@$(call mymkdir,$(dir $@))
	"/home/ghisi/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_DUEMILANOVE -DARDUINO_ARCH_AVR   -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/variants/standard" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/Wire/src" -I"/home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/EEPROM/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/SPI/src" "$<" -o "$@"

project/TickableTest.cpp.d: ;

-include project/TickableTest.cpp.d 

project/features/bwprinting/BWPrintingController.cpp.o: ../../features/bwprinting/BWPrintingController.cpp project/features/bwprinting/BWPrintingController.cpp.d
	@$(call mymkdir,$(dir $@))
	"/home/ghisi/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_DUEMILANOVE -DARDUINO_ARCH_AVR   -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/variants/standard" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/Wire/src" -I"/home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/EEPROM/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/SPI/src" "$<" -o "$@"

project/features/bwprinting/BWPrintingController.cpp.d: ;

-include project/features/bwprinting/BWPrintingController.cpp.d 

project/features/bwprinting/BWPrintingModel.cpp.o: ../../features/bwprinting/BWPrintingModel.cpp project/features/bwprinting/BWPrintingModel.cpp.d
	@$(call mymkdir,$(dir $@))
	"/home/ghisi/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_DUEMILANOVE -DARDUINO_ARCH_AVR   -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/variants/standard" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/Wire/src" -I"/home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/EEPROM/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/SPI/src" "$<" -o "$@"

project/features/bwprinting/BWPrintingModel.cpp.d: ;

-include project/features/bwprinting/BWPrintingModel.cpp.d 

project/features/bwprinting/BWPrintingView.cpp.o: ../../features/bwprinting/BWPrintingView.cpp project/features/bwprinting/BWPrintingView.cpp.d
	@$(call mymkdir,$(dir $@))
	"/home/ghisi/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_DUEMILANOVE -DARDUINO_ARCH_AVR   -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/variants/standard" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/Wire/src" -I"/home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/EEPROM/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/SPI/src" "$<" -o "$@"

project/features/bwprinting/BWPrintingView.cpp.d: ;

-include project/features/bwprinting/BWPrintingView.cpp.d 

project/features/focus/FocusController.cpp.o: ../../features/focus/FocusController.cpp project/features/focus/FocusController.cpp.d
	@$(call mymkdir,$(dir $@))
	"/home/ghisi/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_DUEMILANOVE -DARDUINO_ARCH_AVR   -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/variants/standard" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/Wire/src" -I"/home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/EEPROM/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/SPI/src" "$<" -o "$@"

project/features/focus/FocusController.cpp.d: ;

-include project/features/focus/FocusController.cpp.d 

project/features/focus/FocusModel.cpp.o: ../../features/focus/FocusModel.cpp project/features/focus/FocusModel.cpp.d
	@$(call mymkdir,$(dir $@))
	"/home/ghisi/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_DUEMILANOVE -DARDUINO_ARCH_AVR   -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/variants/standard" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/Wire/src" -I"/home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/EEPROM/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/SPI/src" "$<" -o "$@"

project/features/focus/FocusModel.cpp.d: ;

-include project/features/focus/FocusModel.cpp.d 

project/features/focus/FocusView.cpp.o: ../../features/focus/FocusView.cpp project/features/focus/FocusView.cpp.d
	@$(call mymkdir,$(dir $@))
	"/home/ghisi/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_DUEMILANOVE -DARDUINO_ARCH_AVR   -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/variants/standard" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/Wire/src" -I"/home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/EEPROM/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/SPI/src" "$<" -o "$@"

project/features/focus/FocusView.cpp.d: ;

-include project/features/focus/FocusView.cpp.d 

project/features/lcd-config/LCDConfigController.cpp.o: ../../features/lcd-config/LCDConfigController.cpp project/features/lcd-config/LCDConfigController.cpp.d
	@$(call mymkdir,$(dir $@))
	"/home/ghisi/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_DUEMILANOVE -DARDUINO_ARCH_AVR   -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/variants/standard" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/Wire/src" -I"/home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/EEPROM/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/SPI/src" "$<" -o "$@"

project/features/lcd-config/LCDConfigController.cpp.d: ;

-include project/features/lcd-config/LCDConfigController.cpp.d 

project/features/lcd-config/LCDConfigModel.cpp.o: ../../features/lcd-config/LCDConfigModel.cpp project/features/lcd-config/LCDConfigModel.cpp.d
	@$(call mymkdir,$(dir $@))
	"/home/ghisi/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_DUEMILANOVE -DARDUINO_ARCH_AVR   -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/variants/standard" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/Wire/src" -I"/home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/EEPROM/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/SPI/src" "$<" -o "$@"

project/features/lcd-config/LCDConfigModel.cpp.d: ;

-include project/features/lcd-config/LCDConfigModel.cpp.d 

project/features/lcd-config/LCDConfigView.cpp.o: ../../features/lcd-config/LCDConfigView.cpp project/features/lcd-config/LCDConfigView.cpp.d
	@$(call mymkdir,$(dir $@))
	"/home/ghisi/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_DUEMILANOVE -DARDUINO_ARCH_AVR   -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/variants/standard" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/Wire/src" -I"/home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/EEPROM/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/SPI/src" "$<" -o "$@"

project/features/lcd-config/LCDConfigView.cpp.d: ;

-include project/features/lcd-config/LCDConfigView.cpp.d 

project/features/manager/UIManagerController.cpp.o: ../../features/manager/UIManagerController.cpp project/features/manager/UIManagerController.cpp.d
	@$(call mymkdir,$(dir $@))
	"/home/ghisi/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_DUEMILANOVE -DARDUINO_ARCH_AVR   -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/variants/standard" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/Wire/src" -I"/home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/EEPROM/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/SPI/src" "$<" -o "$@"

project/features/manager/UIManagerController.cpp.d: ;

-include project/features/manager/UIManagerController.cpp.d 

project/features/manager/UIManagerModel.cpp.o: ../../features/manager/UIManagerModel.cpp project/features/manager/UIManagerModel.cpp.d
	@$(call mymkdir,$(dir $@))
	"/home/ghisi/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_DUEMILANOVE -DARDUINO_ARCH_AVR   -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/variants/standard" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/Wire/src" -I"/home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/EEPROM/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/SPI/src" "$<" -o "$@"

project/features/manager/UIManagerModel.cpp.d: ;

-include project/features/manager/UIManagerModel.cpp.d 

project/features/manager/UIManagerView.cpp.o: ../../features/manager/UIManagerView.cpp project/features/manager/UIManagerView.cpp.d
	@$(call mymkdir,$(dir $@))
	"/home/ghisi/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_DUEMILANOVE -DARDUINO_ARCH_AVR   -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/variants/standard" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/Wire/src" -I"/home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/EEPROM/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/SPI/src" "$<" -o "$@"

project/features/manager/UIManagerView.cpp.d: ;

-include project/features/manager/UIManagerView.cpp.d 

project/input/Dial.cpp.o: ../../input/Dial.cpp project/input/Dial.cpp.d
	@$(call mymkdir,$(dir $@))
	"/home/ghisi/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_DUEMILANOVE -DARDUINO_ARCH_AVR   -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/variants/standard" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/Wire/src" -I"/home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/EEPROM/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/SPI/src" "$<" -o "$@"

project/input/Dial.cpp.d: ;

-include project/input/Dial.cpp.d 

project/input/InputHandler.cpp.o: ../../input/InputHandler.cpp project/input/InputHandler.cpp.d
	@$(call mymkdir,$(dir $@))
	"/home/ghisi/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_DUEMILANOVE -DARDUINO_ARCH_AVR   -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/variants/standard" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/Wire/src" -I"/home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/EEPROM/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/SPI/src" "$<" -o "$@"

project/input/InputHandler.cpp.d: ;

-include project/input/InputHandler.cpp.d 

project/input/KeyPad.cpp.o: ../../input/KeyPad.cpp project/input/KeyPad.cpp.d
	@$(call mymkdir,$(dir $@))
	"/home/ghisi/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_DUEMILANOVE -DARDUINO_ARCH_AVR   -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/variants/standard" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/Wire/src" -I"/home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/EEPROM/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/SPI/src" "$<" -o "$@"

project/input/KeyPad.cpp.d: ;

-include project/input/KeyPad.cpp.d 

project/peripheral/Configurations.cpp.o: ../../peripheral/Configurations.cpp project/peripheral/Configurations.cpp.d
	@$(call mymkdir,$(dir $@))
	"/home/ghisi/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_DUEMILANOVE -DARDUINO_ARCH_AVR   -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/variants/standard" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/Wire/src" -I"/home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/EEPROM/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/SPI/src" "$<" -o "$@"

project/peripheral/Configurations.cpp.d: ;

-include project/peripheral/Configurations.cpp.d 

project/peripheral/LCD.cpp.o: ../../peripheral/LCD.cpp project/peripheral/LCD.cpp.d
	@$(call mymkdir,$(dir $@))
	"/home/ghisi/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_DUEMILANOVE -DARDUINO_ARCH_AVR   -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/variants/standard" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/Wire/src" -I"/home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/EEPROM/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/SPI/src" "$<" -o "$@"

project/peripheral/LCD.cpp.d: ;

-include project/peripheral/LCD.cpp.d 

project/peripheral/RGBLed.cpp.o: ../../peripheral/RGBLed.cpp project/peripheral/RGBLed.cpp.d
	@$(call mymkdir,$(dir $@))
	"/home/ghisi/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_DUEMILANOVE -DARDUINO_ARCH_AVR   -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/variants/standard" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/Wire/src" -I"/home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/EEPROM/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/SPI/src" "$<" -o "$@"

project/peripheral/RGBLed.cpp.d: ;

-include project/peripheral/RGBLed.cpp.d 

project/peripheral/SoftPWM.cpp.o: ../../peripheral/SoftPWM.cpp project/peripheral/SoftPWM.cpp.d
	@$(call mymkdir,$(dir $@))
	"/home/ghisi/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_DUEMILANOVE -DARDUINO_ARCH_AVR   -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/variants/standard" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/Wire/src" -I"/home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/EEPROM/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/SPI/src" "$<" -o "$@"

project/peripheral/SoftPWM.cpp.d: ;

-include project/peripheral/SoftPWM.cpp.d 

project/peripheral/SoftPWMOutput.cpp.o: ../../peripheral/SoftPWMOutput.cpp project/peripheral/SoftPWMOutput.cpp.d
	@$(call mymkdir,$(dir $@))
	"/home/ghisi/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_DUEMILANOVE -DARDUINO_ARCH_AVR   -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/variants/standard" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/Wire/src" -I"/home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/EEPROM/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/SPI/src" "$<" -o "$@"

project/peripheral/SoftPWMOutput.cpp.d: ;

-include project/peripheral/SoftPWMOutput.cpp.d 

project/peripheral/WallClock.cpp.o: ../../peripheral/WallClock.cpp project/peripheral/WallClock.cpp.d
	@$(call mymkdir,$(dir $@))
	"/home/ghisi/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_DUEMILANOVE -DARDUINO_ARCH_AVR   -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/variants/standard" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/Wire/src" -I"/home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/EEPROM/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/SPI/src" "$<" -o "$@"

project/peripheral/WallClock.cpp.d: ;

-include project/peripheral/WallClock.cpp.d 


core/PluggableUSB.cpp.o: /home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino/PluggableUSB.cpp core/PluggableUSB.cpp.d
	@$(call mymkdir,$(dir $@))
	"/home/ghisi/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_DUEMILANOVE -DARDUINO_ARCH_AVR   -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/variants/standard" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/Wire/src" -I"/home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/EEPROM/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/SPI/src" "$<" -o "$@"
	"/home/ghisi/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/PluggableUSB.cpp.d: ;

-include core/PluggableUSB.cpp.d

core/WMath.cpp.o: /home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino/WMath.cpp core/WMath.cpp.d
	@$(call mymkdir,$(dir $@))
	"/home/ghisi/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_DUEMILANOVE -DARDUINO_ARCH_AVR   -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/variants/standard" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/Wire/src" -I"/home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/EEPROM/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/SPI/src" "$<" -o "$@"
	"/home/ghisi/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/WMath.cpp.d: ;

-include core/WMath.cpp.d

core/WInterrupts.c.o: /home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino/WInterrupts.c core/WInterrupts.c.d
	@$(call mymkdir,$(dir $@))
	"/home/ghisi/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_DUEMILANOVE -DARDUINO_ARCH_AVR   -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/variants/standard" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/Wire/src" -I"/home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/EEPROM/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/SPI/src" "$<" -o "$@"
	"/home/ghisi/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-gcc-ar" rcs  "./core.a" "$@"
	
core/WInterrupts.c.d: ;

-include core/WInterrupts.c.d

core/USBCore.cpp.o: /home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino/USBCore.cpp core/USBCore.cpp.d
	@$(call mymkdir,$(dir $@))
	"/home/ghisi/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_DUEMILANOVE -DARDUINO_ARCH_AVR   -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/variants/standard" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/Wire/src" -I"/home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/EEPROM/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/SPI/src" "$<" -o "$@"
	"/home/ghisi/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/USBCore.cpp.d: ;

-include core/USBCore.cpp.d

core/HardwareSerial2.cpp.o: /home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino/HardwareSerial2.cpp core/HardwareSerial2.cpp.d
	@$(call mymkdir,$(dir $@))
	"/home/ghisi/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_DUEMILANOVE -DARDUINO_ARCH_AVR   -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/variants/standard" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/Wire/src" -I"/home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/EEPROM/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/SPI/src" "$<" -o "$@"
	"/home/ghisi/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/HardwareSerial2.cpp.d: ;

-include core/HardwareSerial2.cpp.d

core/Stream.cpp.o: /home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino/Stream.cpp core/Stream.cpp.d
	@$(call mymkdir,$(dir $@))
	"/home/ghisi/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_DUEMILANOVE -DARDUINO_ARCH_AVR   -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/variants/standard" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/Wire/src" -I"/home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/EEPROM/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/SPI/src" "$<" -o "$@"
	"/home/ghisi/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/Stream.cpp.d: ;

-include core/Stream.cpp.d

core/HardwareSerial1.cpp.o: /home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino/HardwareSerial1.cpp core/HardwareSerial1.cpp.d
	@$(call mymkdir,$(dir $@))
	"/home/ghisi/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_DUEMILANOVE -DARDUINO_ARCH_AVR   -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/variants/standard" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/Wire/src" -I"/home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/EEPROM/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/SPI/src" "$<" -o "$@"
	"/home/ghisi/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/HardwareSerial1.cpp.d: ;

-include core/HardwareSerial1.cpp.d

core/HardwareSerial.cpp.o: /home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino/HardwareSerial.cpp core/HardwareSerial.cpp.d
	@$(call mymkdir,$(dir $@))
	"/home/ghisi/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_DUEMILANOVE -DARDUINO_ARCH_AVR   -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/variants/standard" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/Wire/src" -I"/home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/EEPROM/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/SPI/src" "$<" -o "$@"
	"/home/ghisi/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/HardwareSerial.cpp.d: ;

-include core/HardwareSerial.cpp.d

core/Print.cpp.o: /home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino/Print.cpp core/Print.cpp.d
	@$(call mymkdir,$(dir $@))
	"/home/ghisi/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_DUEMILANOVE -DARDUINO_ARCH_AVR   -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/variants/standard" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/Wire/src" -I"/home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/EEPROM/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/SPI/src" "$<" -o "$@"
	"/home/ghisi/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/Print.cpp.d: ;

-include core/Print.cpp.d

core/wiring_digital.c.o: /home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino/wiring_digital.c core/wiring_digital.c.d
	@$(call mymkdir,$(dir $@))
	"/home/ghisi/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_DUEMILANOVE -DARDUINO_ARCH_AVR   -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/variants/standard" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/Wire/src" -I"/home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/EEPROM/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/SPI/src" "$<" -o "$@"
	"/home/ghisi/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-gcc-ar" rcs  "./core.a" "$@"
	
core/wiring_digital.c.d: ;

-include core/wiring_digital.c.d

core/wiring_pulse.c.o: /home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino/wiring_pulse.c core/wiring_pulse.c.d
	@$(call mymkdir,$(dir $@))
	"/home/ghisi/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_DUEMILANOVE -DARDUINO_ARCH_AVR   -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/variants/standard" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/Wire/src" -I"/home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/EEPROM/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/SPI/src" "$<" -o "$@"
	"/home/ghisi/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-gcc-ar" rcs  "./core.a" "$@"
	
core/wiring_pulse.c.d: ;

-include core/wiring_pulse.c.d

core/Tone.cpp.o: /home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino/Tone.cpp core/Tone.cpp.d
	@$(call mymkdir,$(dir $@))
	"/home/ghisi/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_DUEMILANOVE -DARDUINO_ARCH_AVR   -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/variants/standard" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/Wire/src" -I"/home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/EEPROM/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/SPI/src" "$<" -o "$@"
	"/home/ghisi/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/Tone.cpp.d: ;

-include core/Tone.cpp.d

core/wiring_pulse.S.o: /home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino/wiring_pulse.S
	@$(call mymkdir,$(dir $@))
	"/home/ghisi/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-gcc" -c -g -x assembler-with-cpp -flto -MMD -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_DUEMILANOVE -DARDUINO_ARCH_AVR   -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/variants/standard" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/Wire/src" -I"/home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/EEPROM/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/SPI/src" "$<" -o "$@"
	"/home/ghisi/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/hooks.c.o: /home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino/hooks.c core/hooks.c.d
	@$(call mymkdir,$(dir $@))
	"/home/ghisi/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_DUEMILANOVE -DARDUINO_ARCH_AVR   -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/variants/standard" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/Wire/src" -I"/home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/EEPROM/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/SPI/src" "$<" -o "$@"
	"/home/ghisi/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-gcc-ar" rcs  "./core.a" "$@"
	
core/hooks.c.d: ;

-include core/hooks.c.d

core/main.cpp.o: /home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino/main.cpp core/main.cpp.d
	@$(call mymkdir,$(dir $@))
	"/home/ghisi/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_DUEMILANOVE -DARDUINO_ARCH_AVR   -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/variants/standard" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/Wire/src" -I"/home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/EEPROM/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/SPI/src" "$<" -o "$@"
	"/home/ghisi/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/main.cpp.d: ;

-include core/main.cpp.d

core/CDC.cpp.o: /home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino/CDC.cpp core/CDC.cpp.d
	@$(call mymkdir,$(dir $@))
	"/home/ghisi/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_DUEMILANOVE -DARDUINO_ARCH_AVR   -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/variants/standard" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/Wire/src" -I"/home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/EEPROM/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/SPI/src" "$<" -o "$@"
	"/home/ghisi/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/CDC.cpp.d: ;

-include core/CDC.cpp.d

core/HardwareSerial3.cpp.o: /home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino/HardwareSerial3.cpp core/HardwareSerial3.cpp.d
	@$(call mymkdir,$(dir $@))
	"/home/ghisi/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_DUEMILANOVE -DARDUINO_ARCH_AVR   -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/variants/standard" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/Wire/src" -I"/home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/EEPROM/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/SPI/src" "$<" -o "$@"
	"/home/ghisi/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/HardwareSerial3.cpp.d: ;

-include core/HardwareSerial3.cpp.d

core/IPAddress.cpp.o: /home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino/IPAddress.cpp core/IPAddress.cpp.d
	@$(call mymkdir,$(dir $@))
	"/home/ghisi/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_DUEMILANOVE -DARDUINO_ARCH_AVR   -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/variants/standard" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/Wire/src" -I"/home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/EEPROM/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/SPI/src" "$<" -o "$@"
	"/home/ghisi/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/IPAddress.cpp.d: ;

-include core/IPAddress.cpp.d

core/HardwareSerial0.cpp.o: /home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino/HardwareSerial0.cpp core/HardwareSerial0.cpp.d
	@$(call mymkdir,$(dir $@))
	"/home/ghisi/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_DUEMILANOVE -DARDUINO_ARCH_AVR   -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/variants/standard" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/Wire/src" -I"/home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/EEPROM/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/SPI/src" "$<" -o "$@"
	"/home/ghisi/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/HardwareSerial0.cpp.d: ;

-include core/HardwareSerial0.cpp.d

core/abi.cpp.o: /home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino/abi.cpp core/abi.cpp.d
	@$(call mymkdir,$(dir $@))
	"/home/ghisi/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_DUEMILANOVE -DARDUINO_ARCH_AVR   -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/variants/standard" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/Wire/src" -I"/home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/EEPROM/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/SPI/src" "$<" -o "$@"
	"/home/ghisi/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/abi.cpp.d: ;

-include core/abi.cpp.d

core/wiring.c.o: /home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino/wiring.c core/wiring.c.d
	@$(call mymkdir,$(dir $@))
	"/home/ghisi/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_DUEMILANOVE -DARDUINO_ARCH_AVR   -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/variants/standard" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/Wire/src" -I"/home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/EEPROM/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/SPI/src" "$<" -o "$@"
	"/home/ghisi/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-gcc-ar" rcs  "./core.a" "$@"
	
core/wiring.c.d: ;

-include core/wiring.c.d

core/wiring_analog.c.o: /home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino/wiring_analog.c core/wiring_analog.c.d
	@$(call mymkdir,$(dir $@))
	"/home/ghisi/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_DUEMILANOVE -DARDUINO_ARCH_AVR   -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/variants/standard" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/Wire/src" -I"/home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/EEPROM/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/SPI/src" "$<" -o "$@"
	"/home/ghisi/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-gcc-ar" rcs  "./core.a" "$@"
	
core/wiring_analog.c.d: ;

-include core/wiring_analog.c.d

core/new.cpp.o: /home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino/new.cpp core/new.cpp.d
	@$(call mymkdir,$(dir $@))
	"/home/ghisi/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_DUEMILANOVE -DARDUINO_ARCH_AVR   -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/variants/standard" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/Wire/src" -I"/home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/EEPROM/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/SPI/src" "$<" -o "$@"
	"/home/ghisi/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/new.cpp.d: ;

-include core/new.cpp.d

core/wiring_shift.c.o: /home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino/wiring_shift.c core/wiring_shift.c.d
	@$(call mymkdir,$(dir $@))
	"/home/ghisi/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_DUEMILANOVE -DARDUINO_ARCH_AVR   -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/variants/standard" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/Wire/src" -I"/home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/EEPROM/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/SPI/src" "$<" -o "$@"
	"/home/ghisi/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-gcc-ar" rcs  "./core.a" "$@"
	
core/wiring_shift.c.d: ;

-include core/wiring_shift.c.d

core/WString.cpp.o: /home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino/WString.cpp core/WString.cpp.d
	@$(call mymkdir,$(dir $@))
	"/home/ghisi/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_DUEMILANOVE -DARDUINO_ARCH_AVR   -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/variants/standard" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/Wire/src" -I"/home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/EEPROM/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/SPI/src" "$<" -o "$@"
	"/home/ghisi/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-gcc-ar" rcs  "./core.a" "$@"

core/WString.cpp.d: ;

-include core/WString.cpp.d



libraries/Wire/src/utility/twi.c.o: /home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/Wire/src/utility/twi.c libraries/Wire/src/utility/twi.c.d
	@$(call mymkdir,$(dir $@))
	"/home/ghisi/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_DUEMILANOVE -DARDUINO_ARCH_AVR   -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/variants/standard" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/Wire/src" -I"/home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/EEPROM/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/SPI/src" "$<" -o "$@"

libraries/Wire/src/utility/twi.c.d: ;

-include libraries/Wire/src/utility/twi.c.d

libraries/Wire/src/Wire.cpp.o: /home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/Wire/src/Wire.cpp libraries/Wire/src/Wire.cpp.d
	@$(call mymkdir,$(dir $@))
	"/home/ghisi/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_DUEMILANOVE -DARDUINO_ARCH_AVR   -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/variants/standard" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/Wire/src" -I"/home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/EEPROM/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/SPI/src" "$<" -o "$@"

libraries/Wire/src/Wire.cpp.d: ;

-include libraries/Wire/src/Wire.cpp.d

libraries/U8g2/2.28.10/src/U8x8lib.cpp.o: /home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src/U8x8lib.cpp libraries/U8g2/2.28.10/src/U8x8lib.cpp.d
	@$(call mymkdir,$(dir $@))
	"/home/ghisi/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_DUEMILANOVE -DARDUINO_ARCH_AVR   -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/variants/standard" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/Wire/src" -I"/home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/EEPROM/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/SPI/src" "$<" -o "$@"

libraries/U8g2/2.28.10/src/U8x8lib.cpp.d: ;

-include libraries/U8g2/2.28.10/src/U8x8lib.cpp.d

libraries/U8g2/2.28.10/src/clib/u8g2_hvline.c.o: /home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src/clib/u8g2_hvline.c libraries/U8g2/2.28.10/src/clib/u8g2_hvline.c.d
	@$(call mymkdir,$(dir $@))
	"/home/ghisi/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_DUEMILANOVE -DARDUINO_ARCH_AVR   -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/variants/standard" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/Wire/src" -I"/home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/EEPROM/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/SPI/src" "$<" -o "$@"

libraries/U8g2/2.28.10/src/clib/u8g2_hvline.c.d: ;

-include libraries/U8g2/2.28.10/src/clib/u8g2_hvline.c.d

libraries/U8g2/2.28.10/src/clib/u8x8_d_ls013b7dh03.c.o: /home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src/clib/u8x8_d_ls013b7dh03.c libraries/U8g2/2.28.10/src/clib/u8x8_d_ls013b7dh03.c.d
	@$(call mymkdir,$(dir $@))
	"/home/ghisi/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_DUEMILANOVE -DARDUINO_ARCH_AVR   -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/variants/standard" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/Wire/src" -I"/home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/EEPROM/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/SPI/src" "$<" -o "$@"

libraries/U8g2/2.28.10/src/clib/u8x8_d_ls013b7dh03.c.d: ;

-include libraries/U8g2/2.28.10/src/clib/u8x8_d_ls013b7dh03.c.d

libraries/U8g2/2.28.10/src/clib/u8x8_debounce.c.o: /home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src/clib/u8x8_debounce.c libraries/U8g2/2.28.10/src/clib/u8x8_debounce.c.d
	@$(call mymkdir,$(dir $@))
	"/home/ghisi/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_DUEMILANOVE -DARDUINO_ARCH_AVR   -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/variants/standard" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/Wire/src" -I"/home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/EEPROM/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/SPI/src" "$<" -o "$@"

libraries/U8g2/2.28.10/src/clib/u8x8_debounce.c.d: ;

-include libraries/U8g2/2.28.10/src/clib/u8x8_debounce.c.d

libraries/U8g2/2.28.10/src/clib/u8x8_d_ssd1326.c.o: /home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src/clib/u8x8_d_ssd1326.c libraries/U8g2/2.28.10/src/clib/u8x8_d_ssd1326.c.d
	@$(call mymkdir,$(dir $@))
	"/home/ghisi/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_DUEMILANOVE -DARDUINO_ARCH_AVR   -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/variants/standard" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/Wire/src" -I"/home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/EEPROM/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/SPI/src" "$<" -o "$@"

libraries/U8g2/2.28.10/src/clib/u8x8_d_ssd1326.c.d: ;

-include libraries/U8g2/2.28.10/src/clib/u8x8_d_ssd1326.c.d

libraries/U8g2/2.28.10/src/clib/u8x8_d_st7528.c.o: /home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src/clib/u8x8_d_st7528.c libraries/U8g2/2.28.10/src/clib/u8x8_d_st7528.c.d
	@$(call mymkdir,$(dir $@))
	"/home/ghisi/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_DUEMILANOVE -DARDUINO_ARCH_AVR   -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/variants/standard" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/Wire/src" -I"/home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/EEPROM/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/SPI/src" "$<" -o "$@"

libraries/U8g2/2.28.10/src/clib/u8x8_d_st7528.c.d: ;

-include libraries/U8g2/2.28.10/src/clib/u8x8_d_st7528.c.d

libraries/U8g2/2.28.10/src/clib/u8x8_u8toa.c.o: /home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src/clib/u8x8_u8toa.c libraries/U8g2/2.28.10/src/clib/u8x8_u8toa.c.d
	@$(call mymkdir,$(dir $@))
	"/home/ghisi/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_DUEMILANOVE -DARDUINO_ARCH_AVR   -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/variants/standard" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/Wire/src" -I"/home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/EEPROM/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/SPI/src" "$<" -o "$@"

libraries/U8g2/2.28.10/src/clib/u8x8_u8toa.c.d: ;

-include libraries/U8g2/2.28.10/src/clib/u8x8_u8toa.c.d

libraries/U8g2/2.28.10/src/clib/u8x8_message.c.o: /home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src/clib/u8x8_message.c libraries/U8g2/2.28.10/src/clib/u8x8_message.c.d
	@$(call mymkdir,$(dir $@))
	"/home/ghisi/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_DUEMILANOVE -DARDUINO_ARCH_AVR   -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/variants/standard" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/Wire/src" -I"/home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/EEPROM/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/SPI/src" "$<" -o "$@"

libraries/U8g2/2.28.10/src/clib/u8x8_message.c.d: ;

-include libraries/U8g2/2.28.10/src/clib/u8x8_message.c.d

libraries/U8g2/2.28.10/src/clib/u8x8_d_st7571.c.o: /home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src/clib/u8x8_d_st7571.c libraries/U8g2/2.28.10/src/clib/u8x8_d_st7571.c.d
	@$(call mymkdir,$(dir $@))
	"/home/ghisi/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_DUEMILANOVE -DARDUINO_ARCH_AVR   -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/variants/standard" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/Wire/src" -I"/home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/EEPROM/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/SPI/src" "$<" -o "$@"

libraries/U8g2/2.28.10/src/clib/u8x8_d_st7571.c.d: ;

-include libraries/U8g2/2.28.10/src/clib/u8x8_d_st7571.c.d

libraries/U8g2/2.28.10/src/clib/u8x8_capture.c.o: /home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src/clib/u8x8_capture.c libraries/U8g2/2.28.10/src/clib/u8x8_capture.c.d
	@$(call mymkdir,$(dir $@))
	"/home/ghisi/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_DUEMILANOVE -DARDUINO_ARCH_AVR   -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/variants/standard" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/Wire/src" -I"/home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/EEPROM/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/SPI/src" "$<" -o "$@"

libraries/U8g2/2.28.10/src/clib/u8x8_capture.c.d: ;

-include libraries/U8g2/2.28.10/src/clib/u8x8_capture.c.d

libraries/U8g2/2.28.10/src/clib/u8log.c.o: /home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src/clib/u8log.c libraries/U8g2/2.28.10/src/clib/u8log.c.d
	@$(call mymkdir,$(dir $@))
	"/home/ghisi/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_DUEMILANOVE -DARDUINO_ARCH_AVR   -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/variants/standard" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/Wire/src" -I"/home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/EEPROM/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/SPI/src" "$<" -o "$@"

libraries/U8g2/2.28.10/src/clib/u8log.c.d: ;

-include libraries/U8g2/2.28.10/src/clib/u8log.c.d

libraries/U8g2/2.28.10/src/clib/u8g2_input_value.c.o: /home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src/clib/u8g2_input_value.c libraries/U8g2/2.28.10/src/clib/u8g2_input_value.c.d
	@$(call mymkdir,$(dir $@))
	"/home/ghisi/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_DUEMILANOVE -DARDUINO_ARCH_AVR   -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/variants/standard" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/Wire/src" -I"/home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/EEPROM/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/SPI/src" "$<" -o "$@"

libraries/U8g2/2.28.10/src/clib/u8g2_input_value.c.d: ;

-include libraries/U8g2/2.28.10/src/clib/u8g2_input_value.c.d

libraries/U8g2/2.28.10/src/clib/u8x8_d_ssd1305.c.o: /home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src/clib/u8x8_d_ssd1305.c libraries/U8g2/2.28.10/src/clib/u8x8_d_ssd1305.c.d
	@$(call mymkdir,$(dir $@))
	"/home/ghisi/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_DUEMILANOVE -DARDUINO_ARCH_AVR   -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/variants/standard" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/Wire/src" -I"/home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/EEPROM/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/SPI/src" "$<" -o "$@"

libraries/U8g2/2.28.10/src/clib/u8x8_d_ssd1305.c.d: ;

-include libraries/U8g2/2.28.10/src/clib/u8x8_d_ssd1305.c.d

libraries/U8g2/2.28.10/src/clib/u8x8_d_ssd1306_96x16.c.o: /home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src/clib/u8x8_d_ssd1306_96x16.c libraries/U8g2/2.28.10/src/clib/u8x8_d_ssd1306_96x16.c.d
	@$(call mymkdir,$(dir $@))
	"/home/ghisi/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_DUEMILANOVE -DARDUINO_ARCH_AVR   -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/variants/standard" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/Wire/src" -I"/home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/EEPROM/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/SPI/src" "$<" -o "$@"

libraries/U8g2/2.28.10/src/clib/u8x8_d_ssd1306_96x16.c.d: ;

-include libraries/U8g2/2.28.10/src/clib/u8x8_d_ssd1306_96x16.c.d

libraries/U8g2/2.28.10/src/clib/u8x8_input_value.c.o: /home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src/clib/u8x8_input_value.c libraries/U8g2/2.28.10/src/clib/u8x8_input_value.c.d
	@$(call mymkdir,$(dir $@))
	"/home/ghisi/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_DUEMILANOVE -DARDUINO_ARCH_AVR   -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/variants/standard" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/Wire/src" -I"/home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/EEPROM/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/SPI/src" "$<" -o "$@"

libraries/U8g2/2.28.10/src/clib/u8x8_input_value.c.d: ;

-include libraries/U8g2/2.28.10/src/clib/u8x8_input_value.c.d

libraries/U8g2/2.28.10/src/clib/u8x8_d_sh1107.c.o: /home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src/clib/u8x8_d_sh1107.c libraries/U8g2/2.28.10/src/clib/u8x8_d_sh1107.c.d
	@$(call mymkdir,$(dir $@))
	"/home/ghisi/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_DUEMILANOVE -DARDUINO_ARCH_AVR   -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/variants/standard" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/Wire/src" -I"/home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/EEPROM/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/SPI/src" "$<" -o "$@"

libraries/U8g2/2.28.10/src/clib/u8x8_d_sh1107.c.d: ;

-include libraries/U8g2/2.28.10/src/clib/u8x8_d_sh1107.c.d

libraries/U8g2/2.28.10/src/clib/u8x8_d_ssd1306_128x32.c.o: /home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src/clib/u8x8_d_ssd1306_128x32.c libraries/U8g2/2.28.10/src/clib/u8x8_d_ssd1306_128x32.c.d
	@$(call mymkdir,$(dir $@))
	"/home/ghisi/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_DUEMILANOVE -DARDUINO_ARCH_AVR   -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/variants/standard" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/Wire/src" -I"/home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/EEPROM/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/SPI/src" "$<" -o "$@"

libraries/U8g2/2.28.10/src/clib/u8x8_d_ssd1306_128x32.c.d: ;

-include libraries/U8g2/2.28.10/src/clib/u8x8_d_ssd1306_128x32.c.d

libraries/U8g2/2.28.10/src/clib/u8x8_d_uc1608.c.o: /home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src/clib/u8x8_d_uc1608.c libraries/U8g2/2.28.10/src/clib/u8x8_d_uc1608.c.d
	@$(call mymkdir,$(dir $@))
	"/home/ghisi/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_DUEMILANOVE -DARDUINO_ARCH_AVR   -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/variants/standard" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/Wire/src" -I"/home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/EEPROM/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/SPI/src" "$<" -o "$@"

libraries/U8g2/2.28.10/src/clib/u8x8_d_uc1608.c.d: ;

-include libraries/U8g2/2.28.10/src/clib/u8x8_d_uc1608.c.d

libraries/U8g2/2.28.10/src/clib/u8x8_d_max7219.c.o: /home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src/clib/u8x8_d_max7219.c libraries/U8g2/2.28.10/src/clib/u8x8_d_max7219.c.d
	@$(call mymkdir,$(dir $@))
	"/home/ghisi/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_DUEMILANOVE -DARDUINO_ARCH_AVR   -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/variants/standard" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/Wire/src" -I"/home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/EEPROM/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/SPI/src" "$<" -o "$@"

libraries/U8g2/2.28.10/src/clib/u8x8_d_max7219.c.d: ;

-include libraries/U8g2/2.28.10/src/clib/u8x8_d_max7219.c.d

libraries/U8g2/2.28.10/src/clib/u8x8_d_ssd1309.c.o: /home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src/clib/u8x8_d_ssd1309.c libraries/U8g2/2.28.10/src/clib/u8x8_d_ssd1309.c.d
	@$(call mymkdir,$(dir $@))
	"/home/ghisi/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_DUEMILANOVE -DARDUINO_ARCH_AVR   -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/variants/standard" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/Wire/src" -I"/home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/EEPROM/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/SPI/src" "$<" -o "$@"

libraries/U8g2/2.28.10/src/clib/u8x8_d_ssd1309.c.d: ;

-include libraries/U8g2/2.28.10/src/clib/u8x8_d_ssd1309.c.d

libraries/U8g2/2.28.10/src/clib/u8x8_d_st7565.c.o: /home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src/clib/u8x8_d_st7565.c libraries/U8g2/2.28.10/src/clib/u8x8_d_st7565.c.d
	@$(call mymkdir,$(dir $@))
	"/home/ghisi/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_DUEMILANOVE -DARDUINO_ARCH_AVR   -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/variants/standard" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/Wire/src" -I"/home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/EEPROM/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/SPI/src" "$<" -o "$@"

libraries/U8g2/2.28.10/src/clib/u8x8_d_st7565.c.d: ;

-include libraries/U8g2/2.28.10/src/clib/u8x8_d_st7565.c.d

libraries/U8g2/2.28.10/src/clib/u8x8_d_ssd1318.c.o: /home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src/clib/u8x8_d_ssd1318.c libraries/U8g2/2.28.10/src/clib/u8x8_d_ssd1318.c.d
	@$(call mymkdir,$(dir $@))
	"/home/ghisi/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_DUEMILANOVE -DARDUINO_ARCH_AVR   -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/variants/standard" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/Wire/src" -I"/home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/EEPROM/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/SPI/src" "$<" -o "$@"

libraries/U8g2/2.28.10/src/clib/u8x8_d_ssd1318.c.d: ;

-include libraries/U8g2/2.28.10/src/clib/u8x8_d_ssd1318.c.d

libraries/U8g2/2.28.10/src/clib/u8g2_d_setup.c.o: /home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src/clib/u8g2_d_setup.c libraries/U8g2/2.28.10/src/clib/u8g2_d_setup.c.d
	@$(call mymkdir,$(dir $@))
	"/home/ghisi/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_DUEMILANOVE -DARDUINO_ARCH_AVR   -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/variants/standard" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/Wire/src" -I"/home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/EEPROM/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/SPI/src" "$<" -o "$@"

libraries/U8g2/2.28.10/src/clib/u8g2_d_setup.c.d: ;

-include libraries/U8g2/2.28.10/src/clib/u8g2_d_setup.c.d

libraries/U8g2/2.28.10/src/clib/u8x8_d_sed1330.c.o: /home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src/clib/u8x8_d_sed1330.c libraries/U8g2/2.28.10/src/clib/u8x8_d_sed1330.c.d
	@$(call mymkdir,$(dir $@))
	"/home/ghisi/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_DUEMILANOVE -DARDUINO_ARCH_AVR   -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/variants/standard" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/Wire/src" -I"/home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/EEPROM/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/SPI/src" "$<" -o "$@"

libraries/U8g2/2.28.10/src/clib/u8x8_d_sed1330.c.d: ;

-include libraries/U8g2/2.28.10/src/clib/u8x8_d_sed1330.c.d

libraries/U8g2/2.28.10/src/clib/u8x8_d_lc7981.c.o: /home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src/clib/u8x8_d_lc7981.c libraries/U8g2/2.28.10/src/clib/u8x8_d_lc7981.c.d
	@$(call mymkdir,$(dir $@))
	"/home/ghisi/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_DUEMILANOVE -DARDUINO_ARCH_AVR   -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/variants/standard" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/Wire/src" -I"/home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/EEPROM/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/SPI/src" "$<" -o "$@"

libraries/U8g2/2.28.10/src/clib/u8x8_d_lc7981.c.d: ;

-include libraries/U8g2/2.28.10/src/clib/u8x8_d_lc7981.c.d

libraries/U8g2/2.28.10/src/clib/u8g2_cleardisplay.c.o: /home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src/clib/u8g2_cleardisplay.c libraries/U8g2/2.28.10/src/clib/u8g2_cleardisplay.c.d
	@$(call mymkdir,$(dir $@))
	"/home/ghisi/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_DUEMILANOVE -DARDUINO_ARCH_AVR   -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/variants/standard" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/Wire/src" -I"/home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/EEPROM/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/SPI/src" "$<" -o "$@"

libraries/U8g2/2.28.10/src/clib/u8g2_cleardisplay.c.d: ;

-include libraries/U8g2/2.28.10/src/clib/u8g2_cleardisplay.c.d

libraries/U8g2/2.28.10/src/clib/u8x8_d_uc1701_mini12864.c.o: /home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src/clib/u8x8_d_uc1701_mini12864.c libraries/U8g2/2.28.10/src/clib/u8x8_d_uc1701_mini12864.c.d
	@$(call mymkdir,$(dir $@))
	"/home/ghisi/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_DUEMILANOVE -DARDUINO_ARCH_AVR   -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/variants/standard" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/Wire/src" -I"/home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/EEPROM/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/SPI/src" "$<" -o "$@"

libraries/U8g2/2.28.10/src/clib/u8x8_d_uc1701_mini12864.c.d: ;

-include libraries/U8g2/2.28.10/src/clib/u8x8_d_uc1701_mini12864.c.d

libraries/U8g2/2.28.10/src/clib/u8x8_d_ssd1322.c.o: /home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src/clib/u8x8_d_ssd1322.c libraries/U8g2/2.28.10/src/clib/u8x8_d_ssd1322.c.d
	@$(call mymkdir,$(dir $@))
	"/home/ghisi/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_DUEMILANOVE -DARDUINO_ARCH_AVR   -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/variants/standard" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/Wire/src" -I"/home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/EEPROM/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/SPI/src" "$<" -o "$@"

libraries/U8g2/2.28.10/src/clib/u8x8_d_ssd1322.c.d: ;

-include libraries/U8g2/2.28.10/src/clib/u8x8_d_ssd1322.c.d

libraries/U8g2/2.28.10/src/clib/u8x8_d_uc1638.c.o: /home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src/clib/u8x8_d_uc1638.c libraries/U8g2/2.28.10/src/clib/u8x8_d_uc1638.c.d
	@$(call mymkdir,$(dir $@))
	"/home/ghisi/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_DUEMILANOVE -DARDUINO_ARCH_AVR   -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/variants/standard" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/Wire/src" -I"/home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/EEPROM/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/SPI/src" "$<" -o "$@"

libraries/U8g2/2.28.10/src/clib/u8x8_d_uc1638.c.d: ;

-include libraries/U8g2/2.28.10/src/clib/u8x8_d_uc1638.c.d

libraries/U8g2/2.28.10/src/clib/u8x8_d_pcd8544_84x48.c.o: /home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src/clib/u8x8_d_pcd8544_84x48.c libraries/U8g2/2.28.10/src/clib/u8x8_d_pcd8544_84x48.c.d
	@$(call mymkdir,$(dir $@))
	"/home/ghisi/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_DUEMILANOVE -DARDUINO_ARCH_AVR   -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/variants/standard" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/Wire/src" -I"/home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/EEPROM/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/SPI/src" "$<" -o "$@"

libraries/U8g2/2.28.10/src/clib/u8x8_d_pcd8544_84x48.c.d: ;

-include libraries/U8g2/2.28.10/src/clib/u8x8_d_pcd8544_84x48.c.d

libraries/U8g2/2.28.10/src/clib/u8g2_font.c.o: /home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src/clib/u8g2_font.c libraries/U8g2/2.28.10/src/clib/u8g2_font.c.d
	@$(call mymkdir,$(dir $@))
	"/home/ghisi/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_DUEMILANOVE -DARDUINO_ARCH_AVR   -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/variants/standard" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/Wire/src" -I"/home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/EEPROM/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/SPI/src" "$<" -o "$@"

libraries/U8g2/2.28.10/src/clib/u8g2_font.c.d: ;

-include libraries/U8g2/2.28.10/src/clib/u8g2_font.c.d

libraries/U8g2/2.28.10/src/clib/u8x8_d_st7567.c.o: /home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src/clib/u8x8_d_st7567.c libraries/U8g2/2.28.10/src/clib/u8x8_d_st7567.c.d
	@$(call mymkdir,$(dir $@))
	"/home/ghisi/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_DUEMILANOVE -DARDUINO_ARCH_AVR   -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/variants/standard" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/Wire/src" -I"/home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/EEPROM/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/SPI/src" "$<" -o "$@"

libraries/U8g2/2.28.10/src/clib/u8x8_d_st7567.c.d: ;

-include libraries/U8g2/2.28.10/src/clib/u8x8_d_st7567.c.d

libraries/U8g2/2.28.10/src/clib/u8x8_d_uc1610.c.o: /home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src/clib/u8x8_d_uc1610.c libraries/U8g2/2.28.10/src/clib/u8x8_d_uc1610.c.d
	@$(call mymkdir,$(dir $@))
	"/home/ghisi/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_DUEMILANOVE -DARDUINO_ARCH_AVR   -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/variants/standard" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/Wire/src" -I"/home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/EEPROM/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/SPI/src" "$<" -o "$@"

libraries/U8g2/2.28.10/src/clib/u8x8_d_uc1610.c.d: ;

-include libraries/U8g2/2.28.10/src/clib/u8x8_d_uc1610.c.d

libraries/U8g2/2.28.10/src/clib/u8x8_selection_list.c.o: /home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src/clib/u8x8_selection_list.c libraries/U8g2/2.28.10/src/clib/u8x8_selection_list.c.d
	@$(call mymkdir,$(dir $@))
	"/home/ghisi/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_DUEMILANOVE -DARDUINO_ARCH_AVR   -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/variants/standard" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/Wire/src" -I"/home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/EEPROM/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/SPI/src" "$<" -o "$@"

libraries/U8g2/2.28.10/src/clib/u8x8_selection_list.c.d: ;

-include libraries/U8g2/2.28.10/src/clib/u8x8_selection_list.c.d

libraries/U8g2/2.28.10/src/clib/u8g2_selection_list.c.o: /home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src/clib/u8g2_selection_list.c libraries/U8g2/2.28.10/src/clib/u8g2_selection_list.c.d
	@$(call mymkdir,$(dir $@))
	"/home/ghisi/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_DUEMILANOVE -DARDUINO_ARCH_AVR   -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/variants/standard" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/Wire/src" -I"/home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/EEPROM/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/SPI/src" "$<" -o "$@"

libraries/U8g2/2.28.10/src/clib/u8g2_selection_list.c.d: ;

-include libraries/U8g2/2.28.10/src/clib/u8g2_selection_list.c.d

libraries/U8g2/2.28.10/src/clib/u8x8_d_st75320.c.o: /home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src/clib/u8x8_d_st75320.c libraries/U8g2/2.28.10/src/clib/u8x8_d_st75320.c.d
	@$(call mymkdir,$(dir $@))
	"/home/ghisi/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_DUEMILANOVE -DARDUINO_ARCH_AVR   -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/variants/standard" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/Wire/src" -I"/home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/EEPROM/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/SPI/src" "$<" -o "$@"

libraries/U8g2/2.28.10/src/clib/u8x8_d_st75320.c.d: ;

-include libraries/U8g2/2.28.10/src/clib/u8x8_d_st75320.c.d

libraries/U8g2/2.28.10/src/clib/u8g2_message.c.o: /home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src/clib/u8g2_message.c libraries/U8g2/2.28.10/src/clib/u8g2_message.c.d
	@$(call mymkdir,$(dir $@))
	"/home/ghisi/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_DUEMILANOVE -DARDUINO_ARCH_AVR   -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/variants/standard" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/Wire/src" -I"/home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/EEPROM/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/SPI/src" "$<" -o "$@"

libraries/U8g2/2.28.10/src/clib/u8g2_message.c.d: ;

-include libraries/U8g2/2.28.10/src/clib/u8g2_message.c.d

libraries/U8g2/2.28.10/src/clib/u8x8_d_st7920.c.o: /home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src/clib/u8x8_d_st7920.c libraries/U8g2/2.28.10/src/clib/u8x8_d_st7920.c.d
	@$(call mymkdir,$(dir $@))
	"/home/ghisi/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_DUEMILANOVE -DARDUINO_ARCH_AVR   -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/variants/standard" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/Wire/src" -I"/home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/EEPROM/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/SPI/src" "$<" -o "$@"

libraries/U8g2/2.28.10/src/clib/u8x8_d_st7920.c.d: ;

-include libraries/U8g2/2.28.10/src/clib/u8x8_d_st7920.c.d

libraries/U8g2/2.28.10/src/clib/u8g2_box.c.o: /home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src/clib/u8g2_box.c libraries/U8g2/2.28.10/src/clib/u8g2_box.c.d
	@$(call mymkdir,$(dir $@))
	"/home/ghisi/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_DUEMILANOVE -DARDUINO_ARCH_AVR   -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/variants/standard" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/Wire/src" -I"/home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/EEPROM/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/SPI/src" "$<" -o "$@"

libraries/U8g2/2.28.10/src/clib/u8g2_box.c.d: ;

-include libraries/U8g2/2.28.10/src/clib/u8g2_box.c.d

libraries/U8g2/2.28.10/src/clib/u8x8_d_sh1106_72x40.c.o: /home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src/clib/u8x8_d_sh1106_72x40.c libraries/U8g2/2.28.10/src/clib/u8x8_d_sh1106_72x40.c.d
	@$(call mymkdir,$(dir $@))
	"/home/ghisi/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_DUEMILANOVE -DARDUINO_ARCH_AVR   -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/variants/standard" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/Wire/src" -I"/home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/EEPROM/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/SPI/src" "$<" -o "$@"

libraries/U8g2/2.28.10/src/clib/u8x8_d_sh1106_72x40.c.d: ;

-include libraries/U8g2/2.28.10/src/clib/u8x8_d_sh1106_72x40.c.d

libraries/U8g2/2.28.10/src/clib/u8x8_d_uc1617.c.o: /home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src/clib/u8x8_d_uc1617.c libraries/U8g2/2.28.10/src/clib/u8x8_d_uc1617.c.d
	@$(call mymkdir,$(dir $@))
	"/home/ghisi/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_DUEMILANOVE -DARDUINO_ARCH_AVR   -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/variants/standard" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/Wire/src" -I"/home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/EEPROM/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/SPI/src" "$<" -o "$@"

libraries/U8g2/2.28.10/src/clib/u8x8_d_uc1617.c.d: ;

-include libraries/U8g2/2.28.10/src/clib/u8x8_d_uc1617.c.d

libraries/U8g2/2.28.10/src/clib/u8x8_display.c.o: /home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src/clib/u8x8_display.c libraries/U8g2/2.28.10/src/clib/u8x8_display.c.d
	@$(call mymkdir,$(dir $@))
	"/home/ghisi/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_DUEMILANOVE -DARDUINO_ARCH_AVR   -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/variants/standard" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/Wire/src" -I"/home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/EEPROM/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/SPI/src" "$<" -o "$@"

libraries/U8g2/2.28.10/src/clib/u8x8_display.c.d: ;

-include libraries/U8g2/2.28.10/src/clib/u8x8_display.c.d

libraries/U8g2/2.28.10/src/clib/u8x8_d_ssd1317.c.o: /home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src/clib/u8x8_d_ssd1317.c libraries/U8g2/2.28.10/src/clib/u8x8_d_ssd1317.c.d
	@$(call mymkdir,$(dir $@))
	"/home/ghisi/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_DUEMILANOVE -DARDUINO_ARCH_AVR   -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/variants/standard" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/Wire/src" -I"/home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/EEPROM/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/SPI/src" "$<" -o "$@"

libraries/U8g2/2.28.10/src/clib/u8x8_d_ssd1317.c.d: ;

-include libraries/U8g2/2.28.10/src/clib/u8x8_d_ssd1317.c.d

libraries/U8g2/2.28.10/src/clib/u8x8_d_ist3020.c.o: /home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src/clib/u8x8_d_ist3020.c libraries/U8g2/2.28.10/src/clib/u8x8_d_ist3020.c.d
	@$(call mymkdir,$(dir $@))
	"/home/ghisi/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_DUEMILANOVE -DARDUINO_ARCH_AVR   -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/variants/standard" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/Wire/src" -I"/home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/EEPROM/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/SPI/src" "$<" -o "$@"

libraries/U8g2/2.28.10/src/clib/u8x8_d_ist3020.c.d: ;

-include libraries/U8g2/2.28.10/src/clib/u8x8_d_ist3020.c.d

libraries/U8g2/2.28.10/src/clib/u8g2_kerning.c.o: /home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src/clib/u8g2_kerning.c libraries/U8g2/2.28.10/src/clib/u8g2_kerning.c.d
	@$(call mymkdir,$(dir $@))
	"/home/ghisi/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_DUEMILANOVE -DARDUINO_ARCH_AVR   -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/variants/standard" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/Wire/src" -I"/home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/EEPROM/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/SPI/src" "$<" -o "$@"

libraries/U8g2/2.28.10/src/clib/u8g2_kerning.c.d: ;

-include libraries/U8g2/2.28.10/src/clib/u8g2_kerning.c.d

libraries/U8g2/2.28.10/src/clib/u8x8_d_ssd1325.c.o: /home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src/clib/u8x8_d_ssd1325.c libraries/U8g2/2.28.10/src/clib/u8x8_d_ssd1325.c.d
	@$(call mymkdir,$(dir $@))
	"/home/ghisi/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_DUEMILANOVE -DARDUINO_ARCH_AVR   -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/variants/standard" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/Wire/src" -I"/home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/EEPROM/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/SPI/src" "$<" -o "$@"

libraries/U8g2/2.28.10/src/clib/u8x8_d_ssd1325.c.d: ;

-include libraries/U8g2/2.28.10/src/clib/u8x8_d_ssd1325.c.d

libraries/U8g2/2.28.10/src/clib/u8x8_d_t6963.c.o: /home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src/clib/u8x8_d_t6963.c libraries/U8g2/2.28.10/src/clib/u8x8_d_t6963.c.d
	@$(call mymkdir,$(dir $@))
	"/home/ghisi/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_DUEMILANOVE -DARDUINO_ARCH_AVR   -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/variants/standard" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/Wire/src" -I"/home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/EEPROM/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/SPI/src" "$<" -o "$@"

libraries/U8g2/2.28.10/src/clib/u8x8_d_t6963.c.d: ;

-include libraries/U8g2/2.28.10/src/clib/u8x8_d_t6963.c.d

libraries/U8g2/2.28.10/src/clib/u8x8_d_ssd1316.c.o: /home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src/clib/u8x8_d_ssd1316.c libraries/U8g2/2.28.10/src/clib/u8x8_d_ssd1316.c.d
	@$(call mymkdir,$(dir $@))
	"/home/ghisi/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_DUEMILANOVE -DARDUINO_ARCH_AVR   -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/variants/standard" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/Wire/src" -I"/home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/EEPROM/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/SPI/src" "$<" -o "$@"

libraries/U8g2/2.28.10/src/clib/u8x8_d_ssd1316.c.d: ;

-include libraries/U8g2/2.28.10/src/clib/u8x8_d_ssd1316.c.d

libraries/U8g2/2.28.10/src/clib/u8x8_d_uc1611.c.o: /home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src/clib/u8x8_d_uc1611.c libraries/U8g2/2.28.10/src/clib/u8x8_d_uc1611.c.d
	@$(call mymkdir,$(dir $@))
	"/home/ghisi/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_DUEMILANOVE -DARDUINO_ARCH_AVR   -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/variants/standard" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/Wire/src" -I"/home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/EEPROM/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/SPI/src" "$<" -o "$@"

libraries/U8g2/2.28.10/src/clib/u8x8_d_uc1611.c.d: ;

-include libraries/U8g2/2.28.10/src/clib/u8x8_d_uc1611.c.d

libraries/U8g2/2.28.10/src/clib/u8g2_ll_hvline.c.o: /home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src/clib/u8g2_ll_hvline.c libraries/U8g2/2.28.10/src/clib/u8g2_ll_hvline.c.d
	@$(call mymkdir,$(dir $@))
	"/home/ghisi/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_DUEMILANOVE -DARDUINO_ARCH_AVR   -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/variants/standard" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/Wire/src" -I"/home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/EEPROM/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/SPI/src" "$<" -o "$@"

libraries/U8g2/2.28.10/src/clib/u8g2_ll_hvline.c.d: ;

-include libraries/U8g2/2.28.10/src/clib/u8g2_ll_hvline.c.d

libraries/U8g2/2.28.10/src/clib/u8x8_cad.c.o: /home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src/clib/u8x8_cad.c libraries/U8g2/2.28.10/src/clib/u8x8_cad.c.d
	@$(call mymkdir,$(dir $@))
	"/home/ghisi/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_DUEMILANOVE -DARDUINO_ARCH_AVR   -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/variants/standard" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/Wire/src" -I"/home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/EEPROM/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/SPI/src" "$<" -o "$@"

libraries/U8g2/2.28.10/src/clib/u8x8_cad.c.d: ;

-include libraries/U8g2/2.28.10/src/clib/u8x8_cad.c.d

libraries/U8g2/2.28.10/src/clib/u8x8_d_ld7032_60x32.c.o: /home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src/clib/u8x8_d_ld7032_60x32.c libraries/U8g2/2.28.10/src/clib/u8x8_d_ld7032_60x32.c.d
	@$(call mymkdir,$(dir $@))
	"/home/ghisi/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_DUEMILANOVE -DARDUINO_ARCH_AVR   -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/variants/standard" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/Wire/src" -I"/home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/EEPROM/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/SPI/src" "$<" -o "$@"

libraries/U8g2/2.28.10/src/clib/u8x8_d_ld7032_60x32.c.d: ;

-include libraries/U8g2/2.28.10/src/clib/u8x8_d_ld7032_60x32.c.d

libraries/U8g2/2.28.10/src/clib/u8g2_fonts.c.o: /home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src/clib/u8g2_fonts.c libraries/U8g2/2.28.10/src/clib/u8g2_fonts.c.d
	@$(call mymkdir,$(dir $@))
	"/home/ghisi/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_DUEMILANOVE -DARDUINO_ARCH_AVR   -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/variants/standard" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/Wire/src" -I"/home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/EEPROM/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/SPI/src" "$<" -o "$@"

libraries/U8g2/2.28.10/src/clib/u8g2_fonts.c.d: ;

-include libraries/U8g2/2.28.10/src/clib/u8g2_fonts.c.d

libraries/U8g2/2.28.10/src/clib/u8x8_d_st7586s_erc240160.c.o: /home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src/clib/u8x8_d_st7586s_erc240160.c libraries/U8g2/2.28.10/src/clib/u8x8_d_st7586s_erc240160.c.d
	@$(call mymkdir,$(dir $@))
	"/home/ghisi/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_DUEMILANOVE -DARDUINO_ARCH_AVR   -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/variants/standard" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/Wire/src" -I"/home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/EEPROM/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/SPI/src" "$<" -o "$@"

libraries/U8g2/2.28.10/src/clib/u8x8_d_st7586s_erc240160.c.d: ;

-include libraries/U8g2/2.28.10/src/clib/u8x8_d_st7586s_erc240160.c.d

libraries/U8g2/2.28.10/src/clib/u8x8_d_ssd1607_200x200.c.o: /home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src/clib/u8x8_d_ssd1607_200x200.c libraries/U8g2/2.28.10/src/clib/u8x8_d_ssd1607_200x200.c.d
	@$(call mymkdir,$(dir $@))
	"/home/ghisi/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_DUEMILANOVE -DARDUINO_ARCH_AVR   -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/variants/standard" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/Wire/src" -I"/home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/EEPROM/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/SPI/src" "$<" -o "$@"

libraries/U8g2/2.28.10/src/clib/u8x8_d_ssd1607_200x200.c.d: ;

-include libraries/U8g2/2.28.10/src/clib/u8x8_d_ssd1607_200x200.c.d

libraries/U8g2/2.28.10/src/clib/u8x8_d_ssd1306_2040x16.c.o: /home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src/clib/u8x8_d_ssd1306_2040x16.c libraries/U8g2/2.28.10/src/clib/u8x8_d_ssd1306_2040x16.c.d
	@$(call mymkdir,$(dir $@))
	"/home/ghisi/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_DUEMILANOVE -DARDUINO_ARCH_AVR   -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/variants/standard" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/Wire/src" -I"/home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/EEPROM/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/SPI/src" "$<" -o "$@"

libraries/U8g2/2.28.10/src/clib/u8x8_d_ssd1306_2040x16.c.d: ;

-include libraries/U8g2/2.28.10/src/clib/u8x8_d_ssd1306_2040x16.c.d

libraries/U8g2/2.28.10/src/clib/u8x8_d_ssd1606_172x72.c.o: /home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src/clib/u8x8_d_ssd1606_172x72.c libraries/U8g2/2.28.10/src/clib/u8x8_d_ssd1606_172x72.c.d
	@$(call mymkdir,$(dir $@))
	"/home/ghisi/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_DUEMILANOVE -DARDUINO_ARCH_AVR   -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/variants/standard" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/Wire/src" -I"/home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/EEPROM/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/SPI/src" "$<" -o "$@"

libraries/U8g2/2.28.10/src/clib/u8x8_d_ssd1606_172x72.c.d: ;

-include libraries/U8g2/2.28.10/src/clib/u8x8_d_ssd1606_172x72.c.d

libraries/U8g2/2.28.10/src/clib/u8g2_setup.c.o: /home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src/clib/u8g2_setup.c libraries/U8g2/2.28.10/src/clib/u8g2_setup.c.d
	@$(call mymkdir,$(dir $@))
	"/home/ghisi/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_DUEMILANOVE -DARDUINO_ARCH_AVR   -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/variants/standard" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/Wire/src" -I"/home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/EEPROM/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/SPI/src" "$<" -o "$@"

libraries/U8g2/2.28.10/src/clib/u8g2_setup.c.d: ;

-include libraries/U8g2/2.28.10/src/clib/u8g2_setup.c.d

libraries/U8g2/2.28.10/src/clib/u8x8_d_s1d15e06.c.o: /home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src/clib/u8x8_d_s1d15e06.c libraries/U8g2/2.28.10/src/clib/u8x8_d_s1d15e06.c.d
	@$(call mymkdir,$(dir $@))
	"/home/ghisi/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_DUEMILANOVE -DARDUINO_ARCH_AVR   -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/variants/standard" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/Wire/src" -I"/home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/EEPROM/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/SPI/src" "$<" -o "$@"

libraries/U8g2/2.28.10/src/clib/u8x8_d_s1d15e06.c.d: ;

-include libraries/U8g2/2.28.10/src/clib/u8x8_d_s1d15e06.c.d

libraries/U8g2/2.28.10/src/clib/u8x8_d_uc1701_dogs102.c.o: /home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src/clib/u8x8_d_uc1701_dogs102.c libraries/U8g2/2.28.10/src/clib/u8x8_d_uc1701_dogs102.c.d
	@$(call mymkdir,$(dir $@))
	"/home/ghisi/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_DUEMILANOVE -DARDUINO_ARCH_AVR   -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/variants/standard" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/Wire/src" -I"/home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/EEPROM/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/SPI/src" "$<" -o "$@"

libraries/U8g2/2.28.10/src/clib/u8x8_d_uc1701_dogs102.c.d: ;

-include libraries/U8g2/2.28.10/src/clib/u8x8_d_uc1701_dogs102.c.d

libraries/U8g2/2.28.10/src/clib/u8x8_d_st7586s_ymc240160.c.o: /home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src/clib/u8x8_d_st7586s_ymc240160.c libraries/U8g2/2.28.10/src/clib/u8x8_d_st7586s_ymc240160.c.d
	@$(call mymkdir,$(dir $@))
	"/home/ghisi/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_DUEMILANOVE -DARDUINO_ARCH_AVR   -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/variants/standard" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/Wire/src" -I"/home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/EEPROM/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/SPI/src" "$<" -o "$@"

libraries/U8g2/2.28.10/src/clib/u8x8_d_st7586s_ymc240160.c.d: ;

-include libraries/U8g2/2.28.10/src/clib/u8x8_d_st7586s_ymc240160.c.d

libraries/U8g2/2.28.10/src/clib/u8x8_d_st7588.c.o: /home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src/clib/u8x8_d_st7588.c libraries/U8g2/2.28.10/src/clib/u8x8_d_st7588.c.d
	@$(call mymkdir,$(dir $@))
	"/home/ghisi/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_DUEMILANOVE -DARDUINO_ARCH_AVR   -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/variants/standard" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/Wire/src" -I"/home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/EEPROM/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/SPI/src" "$<" -o "$@"

libraries/U8g2/2.28.10/src/clib/u8x8_d_st7588.c.d: ;

-include libraries/U8g2/2.28.10/src/clib/u8x8_d_st7588.c.d

libraries/U8g2/2.28.10/src/clib/u8x8_byte.c.o: /home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src/clib/u8x8_byte.c libraries/U8g2/2.28.10/src/clib/u8x8_byte.c.d
	@$(call mymkdir,$(dir $@))
	"/home/ghisi/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_DUEMILANOVE -DARDUINO_ARCH_AVR   -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/variants/standard" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/Wire/src" -I"/home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/EEPROM/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/SPI/src" "$<" -o "$@"

libraries/U8g2/2.28.10/src/clib/u8x8_byte.c.d: ;

-include libraries/U8g2/2.28.10/src/clib/u8x8_byte.c.d

libraries/U8g2/2.28.10/src/clib/u8x8_setup.c.o: /home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src/clib/u8x8_setup.c libraries/U8g2/2.28.10/src/clib/u8x8_setup.c.d
	@$(call mymkdir,$(dir $@))
	"/home/ghisi/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_DUEMILANOVE -DARDUINO_ARCH_AVR   -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/variants/standard" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/Wire/src" -I"/home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/EEPROM/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/SPI/src" "$<" -o "$@"

libraries/U8g2/2.28.10/src/clib/u8x8_setup.c.d: ;

-include libraries/U8g2/2.28.10/src/clib/u8x8_setup.c.d

libraries/U8g2/2.28.10/src/clib/u8x8_d_sh1122.c.o: /home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src/clib/u8x8_d_sh1122.c libraries/U8g2/2.28.10/src/clib/u8x8_d_sh1122.c.d
	@$(call mymkdir,$(dir $@))
	"/home/ghisi/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_DUEMILANOVE -DARDUINO_ARCH_AVR   -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/variants/standard" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/Wire/src" -I"/home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/EEPROM/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/SPI/src" "$<" -o "$@"

libraries/U8g2/2.28.10/src/clib/u8x8_d_sh1122.c.d: ;

-include libraries/U8g2/2.28.10/src/clib/u8x8_d_sh1122.c.d

libraries/U8g2/2.28.10/src/clib/u8x8_d_uc1601.c.o: /home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src/clib/u8x8_d_uc1601.c libraries/U8g2/2.28.10/src/clib/u8x8_d_uc1601.c.d
	@$(call mymkdir,$(dir $@))
	"/home/ghisi/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_DUEMILANOVE -DARDUINO_ARCH_AVR   -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/variants/standard" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/Wire/src" -I"/home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/EEPROM/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/SPI/src" "$<" -o "$@"

libraries/U8g2/2.28.10/src/clib/u8x8_d_uc1601.c.d: ;

-include libraries/U8g2/2.28.10/src/clib/u8x8_d_uc1601.c.d

libraries/U8g2/2.28.10/src/clib/u8g2_d_memory.c.o: /home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src/clib/u8g2_d_memory.c libraries/U8g2/2.28.10/src/clib/u8g2_d_memory.c.d
	@$(call mymkdir,$(dir $@))
	"/home/ghisi/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_DUEMILANOVE -DARDUINO_ARCH_AVR   -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/variants/standard" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/Wire/src" -I"/home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/EEPROM/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/SPI/src" "$<" -o "$@"

libraries/U8g2/2.28.10/src/clib/u8g2_d_memory.c.d: ;

-include libraries/U8g2/2.28.10/src/clib/u8g2_d_memory.c.d

libraries/U8g2/2.28.10/src/clib/u8g2_polygon.c.o: /home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src/clib/u8g2_polygon.c libraries/U8g2/2.28.10/src/clib/u8g2_polygon.c.d
	@$(call mymkdir,$(dir $@))
	"/home/ghisi/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_DUEMILANOVE -DARDUINO_ARCH_AVR   -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/variants/standard" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/Wire/src" -I"/home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/EEPROM/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/SPI/src" "$<" -o "$@"

libraries/U8g2/2.28.10/src/clib/u8g2_polygon.c.d: ;

-include libraries/U8g2/2.28.10/src/clib/u8g2_polygon.c.d

libraries/U8g2/2.28.10/src/clib/u8x8_u16toa.c.o: /home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src/clib/u8x8_u16toa.c libraries/U8g2/2.28.10/src/clib/u8x8_u16toa.c.d
	@$(call mymkdir,$(dir $@))
	"/home/ghisi/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_DUEMILANOVE -DARDUINO_ARCH_AVR   -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/variants/standard" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/Wire/src" -I"/home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/EEPROM/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/SPI/src" "$<" -o "$@"

libraries/U8g2/2.28.10/src/clib/u8x8_u16toa.c.d: ;

-include libraries/U8g2/2.28.10/src/clib/u8x8_u16toa.c.d

libraries/U8g2/2.28.10/src/clib/u8x8_d_ssd1306_72x40.c.o: /home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src/clib/u8x8_d_ssd1306_72x40.c libraries/U8g2/2.28.10/src/clib/u8x8_d_ssd1306_72x40.c.d
	@$(call mymkdir,$(dir $@))
	"/home/ghisi/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_DUEMILANOVE -DARDUINO_ARCH_AVR   -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/variants/standard" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/Wire/src" -I"/home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/EEPROM/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/SPI/src" "$<" -o "$@"

libraries/U8g2/2.28.10/src/clib/u8x8_d_ssd1306_72x40.c.d: ;

-include libraries/U8g2/2.28.10/src/clib/u8x8_d_ssd1306_72x40.c.d

libraries/U8g2/2.28.10/src/clib/u8x8_d_a2printer.c.o: /home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src/clib/u8x8_d_a2printer.c libraries/U8g2/2.28.10/src/clib/u8x8_d_a2printer.c.d
	@$(call mymkdir,$(dir $@))
	"/home/ghisi/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_DUEMILANOVE -DARDUINO_ARCH_AVR   -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/variants/standard" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/Wire/src" -I"/home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/EEPROM/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/SPI/src" "$<" -o "$@"

libraries/U8g2/2.28.10/src/clib/u8x8_d_a2printer.c.d: ;

-include libraries/U8g2/2.28.10/src/clib/u8x8_d_a2printer.c.d

libraries/U8g2/2.28.10/src/clib/u8x8_d_il3820_296x128.c.o: /home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src/clib/u8x8_d_il3820_296x128.c libraries/U8g2/2.28.10/src/clib/u8x8_d_il3820_296x128.c.d
	@$(call mymkdir,$(dir $@))
	"/home/ghisi/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_DUEMILANOVE -DARDUINO_ARCH_AVR   -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/variants/standard" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/Wire/src" -I"/home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/EEPROM/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/SPI/src" "$<" -o "$@"

libraries/U8g2/2.28.10/src/clib/u8x8_d_il3820_296x128.c.d: ;

-include libraries/U8g2/2.28.10/src/clib/u8x8_d_il3820_296x128.c.d

libraries/U8g2/2.28.10/src/clib/u8log_u8g2.c.o: /home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src/clib/u8log_u8g2.c libraries/U8g2/2.28.10/src/clib/u8log_u8g2.c.d
	@$(call mymkdir,$(dir $@))
	"/home/ghisi/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_DUEMILANOVE -DARDUINO_ARCH_AVR   -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/variants/standard" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/Wire/src" -I"/home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/EEPROM/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/SPI/src" "$<" -o "$@"

libraries/U8g2/2.28.10/src/clib/u8log_u8g2.c.d: ;

-include libraries/U8g2/2.28.10/src/clib/u8log_u8g2.c.d

libraries/U8g2/2.28.10/src/clib/u8x8_d_pcf8812.c.o: /home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src/clib/u8x8_d_pcf8812.c libraries/U8g2/2.28.10/src/clib/u8x8_d_pcf8812.c.d
	@$(call mymkdir,$(dir $@))
	"/home/ghisi/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_DUEMILANOVE -DARDUINO_ARCH_AVR   -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/variants/standard" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/Wire/src" -I"/home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/EEPROM/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/SPI/src" "$<" -o "$@"

libraries/U8g2/2.28.10/src/clib/u8x8_d_pcf8812.c.d: ;

-include libraries/U8g2/2.28.10/src/clib/u8x8_d_pcf8812.c.d

libraries/U8g2/2.28.10/src/clib/u8x8_d_sh1106_64x32.c.o: /home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src/clib/u8x8_d_sh1106_64x32.c libraries/U8g2/2.28.10/src/clib/u8x8_d_sh1106_64x32.c.d
	@$(call mymkdir,$(dir $@))
	"/home/ghisi/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_DUEMILANOVE -DARDUINO_ARCH_AVR   -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/variants/standard" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/Wire/src" -I"/home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/EEPROM/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/SPI/src" "$<" -o "$@"

libraries/U8g2/2.28.10/src/clib/u8x8_d_sh1106_64x32.c.d: ;

-include libraries/U8g2/2.28.10/src/clib/u8x8_d_sh1106_64x32.c.d

libraries/U8g2/2.28.10/src/clib/u8x8_d_ssd1306_64x48.c.o: /home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src/clib/u8x8_d_ssd1306_64x48.c libraries/U8g2/2.28.10/src/clib/u8x8_d_ssd1306_64x48.c.d
	@$(call mymkdir,$(dir $@))
	"/home/ghisi/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_DUEMILANOVE -DARDUINO_ARCH_AVR   -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/variants/standard" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/Wire/src" -I"/home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/EEPROM/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/SPI/src" "$<" -o "$@"

libraries/U8g2/2.28.10/src/clib/u8x8_d_ssd1306_64x48.c.d: ;

-include libraries/U8g2/2.28.10/src/clib/u8x8_d_ssd1306_64x48.c.d

libraries/U8g2/2.28.10/src/clib/u8x8_d_st7511.c.o: /home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src/clib/u8x8_d_st7511.c libraries/U8g2/2.28.10/src/clib/u8x8_d_st7511.c.d
	@$(call mymkdir,$(dir $@))
	"/home/ghisi/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_DUEMILANOVE -DARDUINO_ARCH_AVR   -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/variants/standard" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/Wire/src" -I"/home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/EEPROM/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/SPI/src" "$<" -o "$@"

libraries/U8g2/2.28.10/src/clib/u8x8_d_st7511.c.d: ;

-include libraries/U8g2/2.28.10/src/clib/u8x8_d_st7511.c.d

libraries/U8g2/2.28.10/src/clib/u8g2_line.c.o: /home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src/clib/u8g2_line.c libraries/U8g2/2.28.10/src/clib/u8g2_line.c.d
	@$(call mymkdir,$(dir $@))
	"/home/ghisi/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_DUEMILANOVE -DARDUINO_ARCH_AVR   -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/variants/standard" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/Wire/src" -I"/home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/EEPROM/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/SPI/src" "$<" -o "$@"

libraries/U8g2/2.28.10/src/clib/u8g2_line.c.d: ;

-include libraries/U8g2/2.28.10/src/clib/u8g2_line.c.d

libraries/U8g2/2.28.10/src/clib/u8x8_d_ssd1329.c.o: /home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src/clib/u8x8_d_ssd1329.c libraries/U8g2/2.28.10/src/clib/u8x8_d_ssd1329.c.d
	@$(call mymkdir,$(dir $@))
	"/home/ghisi/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_DUEMILANOVE -DARDUINO_ARCH_AVR   -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/variants/standard" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/Wire/src" -I"/home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/EEPROM/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/SPI/src" "$<" -o "$@"

libraries/U8g2/2.28.10/src/clib/u8x8_d_ssd1329.c.d: ;

-include libraries/U8g2/2.28.10/src/clib/u8x8_d_ssd1329.c.d

libraries/U8g2/2.28.10/src/clib/u8g2_intersection.c.o: /home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src/clib/u8g2_intersection.c libraries/U8g2/2.28.10/src/clib/u8g2_intersection.c.d
	@$(call mymkdir,$(dir $@))
	"/home/ghisi/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_DUEMILANOVE -DARDUINO_ARCH_AVR   -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/variants/standard" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/Wire/src" -I"/home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/EEPROM/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/SPI/src" "$<" -o "$@"

libraries/U8g2/2.28.10/src/clib/u8g2_intersection.c.d: ;

-include libraries/U8g2/2.28.10/src/clib/u8g2_intersection.c.d

libraries/U8g2/2.28.10/src/clib/u8x8_gpio.c.o: /home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src/clib/u8x8_gpio.c libraries/U8g2/2.28.10/src/clib/u8x8_gpio.c.d
	@$(call mymkdir,$(dir $@))
	"/home/ghisi/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_DUEMILANOVE -DARDUINO_ARCH_AVR   -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/variants/standard" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/Wire/src" -I"/home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/EEPROM/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/SPI/src" "$<" -o "$@"

libraries/U8g2/2.28.10/src/clib/u8x8_gpio.c.d: ;

-include libraries/U8g2/2.28.10/src/clib/u8x8_gpio.c.d

libraries/U8g2/2.28.10/src/clib/u8x8_d_ssd1306_48x64.c.o: /home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src/clib/u8x8_d_ssd1306_48x64.c libraries/U8g2/2.28.10/src/clib/u8x8_d_ssd1306_48x64.c.d
	@$(call mymkdir,$(dir $@))
	"/home/ghisi/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_DUEMILANOVE -DARDUINO_ARCH_AVR   -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/variants/standard" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/Wire/src" -I"/home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/EEPROM/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/SPI/src" "$<" -o "$@"

libraries/U8g2/2.28.10/src/clib/u8x8_d_ssd1306_48x64.c.d: ;

-include libraries/U8g2/2.28.10/src/clib/u8x8_d_ssd1306_48x64.c.d

libraries/U8g2/2.28.10/src/clib/u8x8_d_st75256.c.o: /home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src/clib/u8x8_d_st75256.c libraries/U8g2/2.28.10/src/clib/u8x8_d_st75256.c.d
	@$(call mymkdir,$(dir $@))
	"/home/ghisi/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_DUEMILANOVE -DARDUINO_ARCH_AVR   -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/variants/standard" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/Wire/src" -I"/home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/EEPROM/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/SPI/src" "$<" -o "$@"

libraries/U8g2/2.28.10/src/clib/u8x8_d_st75256.c.d: ;

-include libraries/U8g2/2.28.10/src/clib/u8x8_d_st75256.c.d

libraries/U8g2/2.28.10/src/clib/u8x8_d_st7586s_s028hn118a.c.o: /home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src/clib/u8x8_d_st7586s_s028hn118a.c libraries/U8g2/2.28.10/src/clib/u8x8_d_st7586s_s028hn118a.c.d
	@$(call mymkdir,$(dir $@))
	"/home/ghisi/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_DUEMILANOVE -DARDUINO_ARCH_AVR   -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/variants/standard" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/Wire/src" -I"/home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/EEPROM/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/SPI/src" "$<" -o "$@"

libraries/U8g2/2.28.10/src/clib/u8x8_d_st7586s_s028hn118a.c.d: ;

-include libraries/U8g2/2.28.10/src/clib/u8x8_d_st7586s_s028hn118a.c.d

libraries/U8g2/2.28.10/src/clib/u8log_u8x8.c.o: /home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src/clib/u8log_u8x8.c libraries/U8g2/2.28.10/src/clib/u8log_u8x8.c.d
	@$(call mymkdir,$(dir $@))
	"/home/ghisi/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_DUEMILANOVE -DARDUINO_ARCH_AVR   -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/variants/standard" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/Wire/src" -I"/home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/EEPROM/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/SPI/src" "$<" -o "$@"

libraries/U8g2/2.28.10/src/clib/u8log_u8x8.c.d: ;

-include libraries/U8g2/2.28.10/src/clib/u8log_u8x8.c.d

libraries/U8g2/2.28.10/src/clib/u8g2_bitmap.c.o: /home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src/clib/u8g2_bitmap.c libraries/U8g2/2.28.10/src/clib/u8g2_bitmap.c.d
	@$(call mymkdir,$(dir $@))
	"/home/ghisi/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_DUEMILANOVE -DARDUINO_ARCH_AVR   -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/variants/standard" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/Wire/src" -I"/home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/EEPROM/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/SPI/src" "$<" -o "$@"

libraries/U8g2/2.28.10/src/clib/u8g2_bitmap.c.d: ;

-include libraries/U8g2/2.28.10/src/clib/u8g2_bitmap.c.d

libraries/U8g2/2.28.10/src/clib/u8x8_8x8.c.o: /home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src/clib/u8x8_8x8.c libraries/U8g2/2.28.10/src/clib/u8x8_8x8.c.d
	@$(call mymkdir,$(dir $@))
	"/home/ghisi/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_DUEMILANOVE -DARDUINO_ARCH_AVR   -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/variants/standard" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/Wire/src" -I"/home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/EEPROM/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/SPI/src" "$<" -o "$@"

libraries/U8g2/2.28.10/src/clib/u8x8_8x8.c.d: ;

-include libraries/U8g2/2.28.10/src/clib/u8x8_8x8.c.d

libraries/U8g2/2.28.10/src/clib/u8x8_d_ks0108.c.o: /home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src/clib/u8x8_d_ks0108.c libraries/U8g2/2.28.10/src/clib/u8x8_d_ks0108.c.d
	@$(call mymkdir,$(dir $@))
	"/home/ghisi/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_DUEMILANOVE -DARDUINO_ARCH_AVR   -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/variants/standard" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/Wire/src" -I"/home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/EEPROM/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/SPI/src" "$<" -o "$@"

libraries/U8g2/2.28.10/src/clib/u8x8_d_ks0108.c.d: ;

-include libraries/U8g2/2.28.10/src/clib/u8x8_d_ks0108.c.d

libraries/U8g2/2.28.10/src/clib/u8g2_circle.c.o: /home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src/clib/u8g2_circle.c libraries/U8g2/2.28.10/src/clib/u8g2_circle.c.d
	@$(call mymkdir,$(dir $@))
	"/home/ghisi/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_DUEMILANOVE -DARDUINO_ARCH_AVR   -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/variants/standard" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/Wire/src" -I"/home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/EEPROM/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/SPI/src" "$<" -o "$@"

libraries/U8g2/2.28.10/src/clib/u8g2_circle.c.d: ;

-include libraries/U8g2/2.28.10/src/clib/u8g2_circle.c.d

libraries/U8g2/2.28.10/src/clib/u8x8_string.c.o: /home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src/clib/u8x8_string.c libraries/U8g2/2.28.10/src/clib/u8x8_string.c.d
	@$(call mymkdir,$(dir $@))
	"/home/ghisi/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_DUEMILANOVE -DARDUINO_ARCH_AVR   -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/variants/standard" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/Wire/src" -I"/home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/EEPROM/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/SPI/src" "$<" -o "$@"

libraries/U8g2/2.28.10/src/clib/u8x8_string.c.d: ;

-include libraries/U8g2/2.28.10/src/clib/u8x8_string.c.d

libraries/U8g2/2.28.10/src/clib/u8x8_d_ssd1327.c.o: /home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src/clib/u8x8_d_ssd1327.c libraries/U8g2/2.28.10/src/clib/u8x8_d_ssd1327.c.d
	@$(call mymkdir,$(dir $@))
	"/home/ghisi/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_DUEMILANOVE -DARDUINO_ARCH_AVR   -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/variants/standard" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/Wire/src" -I"/home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/EEPROM/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/SPI/src" "$<" -o "$@"

libraries/U8g2/2.28.10/src/clib/u8x8_d_ssd1327.c.d: ;

-include libraries/U8g2/2.28.10/src/clib/u8x8_d_ssd1327.c.d

libraries/U8g2/2.28.10/src/clib/u8x8_d_uc1604.c.o: /home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src/clib/u8x8_d_uc1604.c libraries/U8g2/2.28.10/src/clib/u8x8_d_uc1604.c.d
	@$(call mymkdir,$(dir $@))
	"/home/ghisi/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_DUEMILANOVE -DARDUINO_ARCH_AVR   -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/variants/standard" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/Wire/src" -I"/home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/EEPROM/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/SPI/src" "$<" -o "$@"

libraries/U8g2/2.28.10/src/clib/u8x8_d_uc1604.c.d: ;

-include libraries/U8g2/2.28.10/src/clib/u8x8_d_uc1604.c.d

libraries/U8g2/2.28.10/src/clib/u8x8_d_sh1108.c.o: /home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src/clib/u8x8_d_sh1108.c libraries/U8g2/2.28.10/src/clib/u8x8_d_sh1108.c.d
	@$(call mymkdir,$(dir $@))
	"/home/ghisi/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_DUEMILANOVE -DARDUINO_ARCH_AVR   -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/variants/standard" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/Wire/src" -I"/home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/EEPROM/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/SPI/src" "$<" -o "$@"

libraries/U8g2/2.28.10/src/clib/u8x8_d_sh1108.c.d: ;

-include libraries/U8g2/2.28.10/src/clib/u8x8_d_sh1108.c.d

libraries/U8g2/2.28.10/src/clib/u8x8_d_ssd1306_128x64_noname.c.o: /home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src/clib/u8x8_d_ssd1306_128x64_noname.c libraries/U8g2/2.28.10/src/clib/u8x8_d_ssd1306_128x64_noname.c.d
	@$(call mymkdir,$(dir $@))
	"/home/ghisi/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_DUEMILANOVE -DARDUINO_ARCH_AVR   -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/variants/standard" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/Wire/src" -I"/home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/EEPROM/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/SPI/src" "$<" -o "$@"

libraries/U8g2/2.28.10/src/clib/u8x8_d_ssd1306_128x64_noname.c.d: ;

-include libraries/U8g2/2.28.10/src/clib/u8x8_d_ssd1306_128x64_noname.c.d

libraries/U8g2/2.28.10/src/clib/u8g2_buffer.c.o: /home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src/clib/u8g2_buffer.c libraries/U8g2/2.28.10/src/clib/u8g2_buffer.c.d
	@$(call mymkdir,$(dir $@))
	"/home/ghisi/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_DUEMILANOVE -DARDUINO_ARCH_AVR   -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/variants/standard" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/Wire/src" -I"/home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/EEPROM/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/SPI/src" "$<" -o "$@"

libraries/U8g2/2.28.10/src/clib/u8g2_buffer.c.d: ;

-include libraries/U8g2/2.28.10/src/clib/u8g2_buffer.c.d

libraries/U8g2/2.28.10/src/clib/u8x8_d_ist7920.c.o: /home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src/clib/u8x8_d_ist7920.c libraries/U8g2/2.28.10/src/clib/u8x8_d_ist7920.c.d
	@$(call mymkdir,$(dir $@))
	"/home/ghisi/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_DUEMILANOVE -DARDUINO_ARCH_AVR   -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/variants/standard" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/Wire/src" -I"/home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/EEPROM/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/SPI/src" "$<" -o "$@"

libraries/U8g2/2.28.10/src/clib/u8x8_d_ist7920.c.d: ;

-include libraries/U8g2/2.28.10/src/clib/u8x8_d_ist7920.c.d

libraries/U8g2/2.28.10/src/clib/u8x8_fonts.c.o: /home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src/clib/u8x8_fonts.c libraries/U8g2/2.28.10/src/clib/u8x8_fonts.c.d
	@$(call mymkdir,$(dir $@))
	"/home/ghisi/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_DUEMILANOVE -DARDUINO_ARCH_AVR   -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/variants/standard" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/Wire/src" -I"/home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/EEPROM/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/SPI/src" "$<" -o "$@"

libraries/U8g2/2.28.10/src/clib/u8x8_fonts.c.d: ;

-include libraries/U8g2/2.28.10/src/clib/u8x8_fonts.c.d

libraries/U8g2/2.28.10/src/clib/u8x8_d_ssd1306_64x32.c.o: /home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src/clib/u8x8_d_ssd1306_64x32.c libraries/U8g2/2.28.10/src/clib/u8x8_d_ssd1306_64x32.c.d
	@$(call mymkdir,$(dir $@))
	"/home/ghisi/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_DUEMILANOVE -DARDUINO_ARCH_AVR   -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/variants/standard" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/Wire/src" -I"/home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/EEPROM/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/SPI/src" "$<" -o "$@"

libraries/U8g2/2.28.10/src/clib/u8x8_d_ssd1306_64x32.c.d: ;

-include libraries/U8g2/2.28.10/src/clib/u8x8_d_ssd1306_64x32.c.d

libraries/U8g2/2.28.10/src/clib/u8x8_d_sbn1661.c.o: /home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src/clib/u8x8_d_sbn1661.c libraries/U8g2/2.28.10/src/clib/u8x8_d_sbn1661.c.d
	@$(call mymkdir,$(dir $@))
	"/home/ghisi/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_DUEMILANOVE -DARDUINO_ARCH_AVR   -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/variants/standard" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/Wire/src" -I"/home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/EEPROM/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/SPI/src" "$<" -o "$@"

libraries/U8g2/2.28.10/src/clib/u8x8_d_sbn1661.c.d: ;

-include libraries/U8g2/2.28.10/src/clib/u8x8_d_sbn1661.c.d

libraries/U8g2/2.28.10/src/clib/u8x8_d_pcf8814_hx1230.c.o: /home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src/clib/u8x8_d_pcf8814_hx1230.c libraries/U8g2/2.28.10/src/clib/u8x8_d_pcf8814_hx1230.c.d
	@$(call mymkdir,$(dir $@))
	"/home/ghisi/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_DUEMILANOVE -DARDUINO_ARCH_AVR   -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/variants/standard" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/Wire/src" -I"/home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/EEPROM/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/SPI/src" "$<" -o "$@"

libraries/U8g2/2.28.10/src/clib/u8x8_d_pcf8814_hx1230.c.d: ;

-include libraries/U8g2/2.28.10/src/clib/u8x8_d_pcf8814_hx1230.c.d

libraries/U8g2/2.28.10/src/U8g2lib.cpp.o: /home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src/U8g2lib.cpp libraries/U8g2/2.28.10/src/U8g2lib.cpp.d
	@$(call mymkdir,$(dir $@))
	"/home/ghisi/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_DUEMILANOVE -DARDUINO_ARCH_AVR   -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/variants/standard" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/Wire/src" -I"/home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/EEPROM/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/SPI/src" "$<" -o "$@"

libraries/U8g2/2.28.10/src/U8g2lib.cpp.d: ;

-include libraries/U8g2/2.28.10/src/U8g2lib.cpp.d

libraries/SPI/src/SPI.cpp.o: /home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/SPI/src/SPI.cpp libraries/SPI/src/SPI.cpp.d
	@$(call mymkdir,$(dir $@))
	"/home/ghisi/.arduinocdt/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10608 -DARDUINO_AVR_DUEMILANOVE -DARDUINO_ARCH_AVR   -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/cores/arduino" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/variants/standard" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/Wire/src" -I"/home/ghisi/.arduinocdt/libraries/U8g2/2.28.10/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/EEPROM/src" -I"/home/ghisi/.arduinocdt/packages/arduino/hardware/avr/1.8.3/libraries/SPI/src" "$<" -o "$@"

libraries/SPI/src/SPI.cpp.d: ;

-include libraries/SPI/src/SPI.cpp.d

