#ifndef PINS_CNCSHIELD_H
#define PINS_CNCSHIELD_H

/*
 * Laser 
 */
//LIMIT SWITCH Z AXIS ON CNC SHIELD
#define RIGHT_LASER_PIN 11
//SPINDLE ENABLE PIN ON CNC SHIELD
#define LEFT_LASER_PIN 12

//NOT USED ON CNC SHIELD
#define MICROSTEP   A5

/*
 * Turntable Stepper
 */
//X AXIS ON CNC SHIELD
#define ENABLE_PIN_0  8
#define STEP_PIN_0    2
#define DIR_PIN_0     5

/**
 * WS2812 LED 
 */
// FEED HOLD PIN ON CNC SHIELD
#define LIGHT_PIN A1


/**
 * Optional Laser Stepper
 */
//Y AXIS ON CNC SHIELD
#define ENABLE_PIN_1  8
#define STEP_PIN_1    3
#define DIR_PIN_1     6

 /**
  * Optional Laser Servos
  */
//LIMIT SWITCH X AXIS ON CNC SHIELD
#define RIGHT_SERVO_PIN 9

//LIMIT SWITCH Y AXIS ON CNC SHIELD
#define LEFT_SERVO_PIN 10

/**
 *  STEPPER DEFINES FOR SELECTION
 */
#define LASER_STEPPER        11  //0xb
#define TURNTABLE_STEPPER    10  //0xa

#endif
