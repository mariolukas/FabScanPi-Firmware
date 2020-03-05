#ifndef MOTORDRIVER_H
#define MOTORDRIVER_H

#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

extern int currStepper;

void turn();
void start_turning();
void stop_turning();
void initialize_motor_driver();
void do_move(long laser_distance, long turntable_distance, float feedrate, boolean block);
void turntable_motor_enable();
void turntable_motor_release();

#endif
