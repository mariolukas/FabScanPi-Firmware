// FabScan - http://hci.rwth-aachen.de/fabscan
//
//  Created by Mario Lukas on 04/08/14.
//  Copyright 2014 Media Computing Group, RWTH Aachen University. All rights reserved.
//

//#define VERBOSE 0

// You can use an online service to generate a random UUID. (eg http://www.uuidgenerator.net/version4)
//#define MACHINE_UUID "00000000-0000-0000-0000-000000000000"


#ifndef CONFIGURATION_H
#define CONFIGURATION_H

/*
 * The following define selects which electronics board you have.
 * Please choose the name from boards.h that matches your setup.
 * Some possible Values are:
 *
 * BOARD_FABSCANPI    - FabScanPi Hat for Raspberry Pi
 * BOARD_CYCLOP       - Cyclop Scanner ZUM Scan Board
 * BOARD_SANGUINOLOLU - Sanguinololu 3D Printer Board v 1.3
 * BOARD_CNCSHIELD - Arduino Uno with CNC shield V3.0 or newer (see grbl project for pinout)
 *
 */

#ifndef MOTHERBOARD
  #define MOTHERBOARD BOARD_FABSCANPI
#endif

#define BAUD_RATE 57600


#define TURN_BLOCKING 1
#define TURN_NON_BLOCKING 0

#define NUMPIXELS 16
#define MAX_FEEDRATE         (2000)
#define MIN_FEEDRATE         (1000)

#define MAX_BUF        64

#endif
