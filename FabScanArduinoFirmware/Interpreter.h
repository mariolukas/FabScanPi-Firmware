#ifndef INTERPRETER_H
#define INTERPRETER_H


#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif


extern char serialBuffer[MAX_BUF];  // where we store the message until we get a ';'
extern int sofar;  // how much is in the buffer

void feedrate(float nfr);
void line(float newx,float newy);
void help();
void version();
void board();
void ready();
void where();
void processCommand();
void initialize_led_driver();
void initialize_status_leds();
void initialize_fan();

#endif
