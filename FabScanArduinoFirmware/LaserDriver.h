#ifndef LASERDRIVER_H
#define LASERDRIVER_H

#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif
 
void initialize_laser_driver();
void left_laser_on();
void left_laser_off();
void right_laser_on();
void right_laser_off();
boolean laser_active();

#endif

