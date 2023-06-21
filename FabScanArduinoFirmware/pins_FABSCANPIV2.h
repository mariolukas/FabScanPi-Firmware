#ifndef PINS_FABSCANPIHATV2_H
#define PINS_FABSCANPIHATV2_H

/*
 * Laser 
 */
#define RIGHT_LASER_PIN 12 //Bed (1284p=p18
#define LEFT_LASER_PIN 13  //Hotend (1284p=p19)


/*
 * Turntable 
 */
#define ENABLE_PIN_0  14
#define STEP_PIN_0    15
#define DIR_PIN_0     21


/**
 * WS2812 LED 
 */
#define LIGHT_PIN A1

/*
 * Optional Laser Stepper
 */
#define ENABLE_PIN_1  26
#define STEP_PIN_1    3
#define DIR_PIN_1     2


/* 
 *  Onboard FAN
 */
#define FAN_PIN 8

/*
 * Debug LED's
 */

#define GREEN_STATUS_LED  19
#define YELLOW_STATUS_LED 16
#define RED_STATUS_LED    17


 /**
  * Optional Laser Servos
  */

//#define RIGHT_SERVO_PIN 6
//#define LEFT_SERVO_PIN 12

/**
 *  STEPPER DEFINES FOR SELECTION
 */
#define LASER_STEPPER        11  //0xb
#define TURNTABLE_STEPPER    10  //0xa
#endif
