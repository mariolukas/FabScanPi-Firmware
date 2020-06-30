#!/bin/bash
docker build -t firmware-build .
docker run -it -v $(pwd):/home/arduino/Arduino/Projects/ firmware-build make
