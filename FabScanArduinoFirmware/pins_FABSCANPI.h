#ifndef PINS_FABSCANPI_H
#define PINS_FABSCANPI_H

/*
 * Laser 
 */
#define RIGHT_LASER_PIN 9
#define LEFT_LASER_PIN 10

#define MICROSTEP   A5

/*
 * Turntable Stepper
 */
#define ENABLE_PIN_0  2
#define STEP_PIN_0    3
#define DIR_PIN_0     4

/**
 * WS2812 LED 
 */
#define LIGHT_PIN A1

/**
 * Optional Laser Stepper
 */

#define ENABLE_PIN_1  5
#define STEP_PIN_1    6
#define DIR_PIN_1     7

 /**
  * Optional Laser Servos
  */

#define RIGHT_SERVO_PIN 6
#define LEFT_SERVO_PIN 12

/**
 *  STEPPER DEFINES FOR SELECTION
 */
#define LASER_STEPPER        11  //0xb
#define TURNTABLE_STEPPER    10  //0xa

#endif
