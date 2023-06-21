FROM amotzek/arduino-cli

USER root

RUN apt-get update &&\
    apt-get install -y build-essential &&\
    mkdir /home/build

RUN arduino-cli core install arduino:avr &&\
    arduino-cli lib install AccelStepper &&\
    arduino-cli lib install "Adafruit NeoPixel"

WORKDIR /home/build