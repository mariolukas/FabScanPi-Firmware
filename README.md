# FabScanPi-Firmware
Firmware of FabScanPi 3D Laser Scanner

## Supported G-Codes

    G01 [T(steps)]; Move the Turntable for number of steps
    M4 [R(value) G(value) B(value)]; Turn on LED Ring for given RGB-Vlaues
    M17; Enable Motors
    M18; Disable Motors
    M19: Turn On Laser 0
    M20; Turn Off Laser 0
    M21; Turn On Laser 1
    M22; Turn Off Laser 1
    M100; Show Help Message
    
## Supported Boards

The firmware can be extended by adding new board files. 
Board files are used to define the pinout for a board. 

Currently supported boards: 

- FabScanPi HAT ( original FabScanPi )
- ZUM Arduino Shield ( used by cyclop 3D Scanner and clones )
- Sanguinololu ( 3D-Printer board )
