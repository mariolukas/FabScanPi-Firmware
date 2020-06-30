FROM logankennelly/arduino-cli-esp8266:latest
USER root

RUN apt-get update &&\
    apt-get install -y build-essential 

USER arduino
RUN arduino-cli core install arduino:avr &&\
    arduino-cli lib install AccelStepper &&\
    arduino-cli lib install "Adafruit NeoPixel"
