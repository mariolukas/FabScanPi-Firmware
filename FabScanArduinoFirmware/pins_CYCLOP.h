

#ifndef PINS_CYCLOPE_H
#define PINS_CYCLOPE_H

#ifndef BOARD_NAME
  #define BOARD_NAME "Cylcop ZUM Shield"
#endif

/*
 * Laser 
 */
#define RIGHT_LASER_PIN 2
#define LEFT_LASER_PIN 3

#define MICROSTEP   A5

/*
 * Turntable Stepper
 */
#define ENABLE_PIN_0  9
#define STEP_PIN_0    12
#define DIR_PIN_0     13


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

#define RIGHT_SERVO_PIN 1
#define LEFT_SERVO_PIN 0

/**
 *  STEPPER DEFINES FOR SELECTION
 */
#define LASER_STEPPER        11  //0xb
#define TURNTABLE_STEPPER    10  //0xa

#endif
