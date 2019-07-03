BUILD_DIR=build
SOURCE_TARGET=FabScanArduinoFirmware/FabScanArduinoFirmware.ino
DATE=$(shell date +%Y%m%d)
BUILD_VERSION=v.$(DATE)
OUTPUT_FILE_POSTFIX=$(BUILD_VERSION)

$(shell mkdir -p $(DIRS))

all: fabscanpi ciclop 

fabscanpi: EXTRA_FLAGS = "-DMOTHERBOARD=1 -DBUILD_VERSION='$(BUILD_VERSION)'"
	PLATFORM = arduino:avr:uno
fabscanpi: 
	arduino-cli compile --fqbn $(PLATFORM) --build-properties build.extra_flags=$(EXTRA_FLAGS) \
	--output=$(BUILD_DIR)/fabscanpi_$(OUTPUT_FILE_POSTFIX).hex $(SOURCE_TARGET) --verbose

# ciclop ZUM Board
ciclop: EXTRA_FLAGS = "-DMOTHERBOARD=2 -DBUILD_VERSION='$(BUILD_VERSION)'"
	PLATFORM = arduino:avr:uno
ciclop:
	arduino-cli compile --fqbn $(PLATFORM) --build-properties build.extra_flags=$(EXTRA_FLAGS) \
	--output=$(BUILD_DIR)/ciclop_$(OUTPUT_FILE_POSTFIX).hex $(SOURCE_TARGET) --verbose

.PHONY: clean

clean:
	rm -rf build/*
	rm -f *.hex *.elf

display:
	echo ${TMP}
