// FabScan - http://hci.rwth-aachen.de/fabscan
//
//  Created by Francis Engelmann on 7/1/11.
//  Copyright 2011 Media Computing Group, RWTH Aachen University. All rights reserved.
//
//  Chngelog:
//  R. Bohne 29.01.2013: changed pin mapping to Watterott FabScan Arduino Shield
//  R. Bohne 30.12.2013: added pin definitions for stepper 4 --> this firmware supports the new FabScan Shield V1.1, minor syntax changes. Steppers are now disabled at startup.
//  M. Lukas 05.08.2014: refactored Code, added second laser option

#include "FabScanConfig.h"
#include "Interpreter.h"
#include "LaserDriver.h"
#include "MotorDriver.h"


void setup()
{
  // initialize the serial port
  Serial.begin(BAUD_RATE);

  initialize_laser_driver();
  initialize_motor_driver();
  initialize_led_driver();
  turntable_motor_release();
  laser_motor_release();

  currStepper = TURNTABLE_STEPPER;  //turntable is default stepper
  //version();
  //ready();
}

void loop() {
  // listen for serial commands
  while (Serial.available() > 0) { // if something is available
    char c = Serial.read(); // get it
    //if(c=='\r') continue;  // skip it
    Serial.print(c);  // repeat it back so I know you got the message
    if (sofar < MAX_BUF - 1) buffer[sofar++] = c; // store it
    if ((c == '\n') || (c == '\r')) { // entire message received
      // we got a message and it ends with a semicolon
      buffer[sofar] = 0; // end the buffer so string functions work right
      processCommand();  // do something with the command
      ready();
    }
  }
  turn();
}
