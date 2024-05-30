BUILD_DIR=build
SOURCE_TARGET=FabScanArduinoFirmware/FabScanArduinoFirmware.ino
DATE=$(shell date +%Y%m%d)
BUILD_VERSION=v.$(DATE)
OUTPUT_FILE_POSTFIX=$(BUILD_VERSION)

#$(shell mkdir -p $(DIRS))

all: fabscanpi fabscanpiv2 ciclop sanguinololu cncshield

# original FabScanPi HAT
fabscanpi: EXTRA_FLAGS = "-DMOTHERBOARD=1 -DBAUDRATE=115200"
	PLATFORM = arduino:avr:uno
fabscanpi: 
	arduino-cli compile -b $(PLATFORM) --build-properties build.extra_flags=$(EXTRA_FLAGS) --build-properties build.project_name=fabscanpi_$(OUTPUT_FILE_POSTFIX) \
	--output-dir=$(BUILD_DIR) $(SOURCE_TARGET) --verbose

fabscanpiv2: EXTRA_FLAGS = "-DMOTHERBOARD=5 -DBAUDRATE=115200"
	PLATFORM = arduino:avr:uno
fabscanpiv2: 
	arduino-cli compile -b $(PLATFORM) --build-properties build.extra_flags=$(EXTRA_FLAGS) --build-properties build.project_name=fabscanpiv2_$(OUTPUT_FILE_POSTFIX)  \
	--output-dir=$(BUILD_DIR) $(SOURCE_TARGET) --verbose

# ciclop ZUM Board
ciclop: EXTRA_FLAGS = "-DMOTHERBOARD=2 -DBAUDRATE=14400"
	PLATFORM = arduino:avr:uno
ciclop:
	arduino-cli compile -b $(PLATFORM) --build-properties build.extra_flags=$(EXTRA_FLAGS) --build-properties build.project_name=ciclop_$(OUTPUT_FILE_POSTFIX) \
	--output-dir=$(BUILD_DIR) $(SOURCE_TARGET) --verbose

# Sanguinololu Board
sanguinololu: EXTRA_FLAGS = "-DMOTHERBOARD=3  -DBAUDRATE=115200"
	PLATFORM = arduino:avr:uno
sanguinololu:
	arduino-cli compile -b $(PLATFORM) --build-properties build.extra_flags=$(EXTRA_FLAGS) --build-properties build.project_name=sanguinololu_$(OUTPUT_FILE_POSTFIX) \
	--output-dir=$(BUILD_DIR) $(SOURCE_TARGET) --verbose

# CNC Shield 
cncshield: EXTRA_FLAGS = "-DMOTHERBOARD=4 -DBAUDRATE=115200"
	PLATFORM = arduino:avr:uno
cncshield:
	arduino-cli compile -b $(PLATFORM) --build-properties build.extra_flags=$(EXTRA_FLAGS) --build-properties build.project_name=cncshield_$(OUTPUT_FILE_POSTFIX) \
	--output-dir=$(BUILD_DIR) $(SOURCE_TARGET) --verbose

version: 
	 @echo $(BUILD_VERSION)

.PHONY: clean

clean:
	rm -rf build/*
	rm -f *.hex *.elf
	rm -r arduino
	rm -r arduino-core-cache
	rm -r arduino-sketch*

display:
	echo ${TMP}
