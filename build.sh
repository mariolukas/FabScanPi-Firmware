#!/bin/bash
docker build --platform linux/amd64 -t firmware-build .
docker run --platform linux/amd64 -it -v $(pwd):/home/build firmware-build make
