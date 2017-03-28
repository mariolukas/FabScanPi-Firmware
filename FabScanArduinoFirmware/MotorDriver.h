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
void step_blocking(int motor, int turntable_distance, int feedrate);
void do_move(int laser_distance, int turntable_distance, float feedrate, boolean block);
void move_right_servo_to_position(byte pos);
void turntable_motor_enable();
void laser_motor_enable();
void turntable_motor_release();
void laser_motor_release();

#endif

