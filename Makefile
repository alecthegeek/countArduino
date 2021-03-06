ARDUINO_DIR  := /usr/share/arduino
#
TARGET       := count
ARDUINO_LIBS := ${shell echo $(ARDUINO_DIR)/libraries/*}
#
MCU          := atmega328p
F_CPU        := 16000000L
ARDUINO_PORT := /dev/ttyUSB0
AVRDUDE_ARD_BAUDRATE :=  57600
U_DEFINES    :=-DAVRDUDE_ARD_BAUDRATE=$(AVRDUDE_ARD_BAUDRATE)

ifdef DEBUG
U_DEFINES:= $(U_DEFINES) -DDEBUG
endif

include $(ARDUINO_DIR)/Arduino.mk
