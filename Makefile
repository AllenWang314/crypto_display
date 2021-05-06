SHELL := /bin/bash
ARDUINO := arduino-cli
PORT := /dev/cu.SLAB_USBtoUART

DEFAULT_DIR := crypto
DIR := $(DEFAULT_DIR)


compile:
	$(ARDUINO) compile --fqbn esp32:esp32:esp32 $(DIR).ino

upload:
	- killall screen
	$(ARDUINO) upload -p $(PORT) --fqbn esp32:esp32:esp32 $(DIR).ino

test: compile upload
	screen $(PORT) 115200

all:
	$(ARDUINO) compile --fqbn esp32:esp32:esp32 crypto.ino
	- killall screen
	$(ARDUINO) upload -p $(PORT) --fqbn esp32:esp32:esp32 crypto.ino
	screen $(PORT) 115200