// Parts of the follwing Code are from the 2 AXIS CNC Demo Code ( see info below)
//------------------------------------------------------------------------------
// 2 Axis CNC Demo v2 - supports Adafruit motor shields v1 and v2
// dan@marginallycelver.com 2013-08-30
//------------------------------------------------------------------------------
// Copyright at end of file.
// please see http://www.github.com/MarginallyClever/GcodeCNCDemo for more information.

#include "FabScanConfig.h"
#include "Interpreter.h"
#include "MotorDriver.h"
#include "LaserDriver.h"
#include "Adafruit_NeoPixel.h"

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, LIGHT_PIN, NEO_GRB + NEO_KHZ800);

void set_leds(int r, int g, int b){
  for(int i=0; i<NUMPIXELS; i++){
    pixels.setPixelColor(i,pixels.Color(r,g,b));
  }
  pixels.show();
  delay(100);
}


void initialize_led_driver(){
	pixels.begin();
  //set_leds(0,0,0);
}


char serialBuffer[MAX_BUF];  // where we store the message until we get a ';'
int sofar;  // how much is in the buffer
long line_number=0;


float px, py;  // location

// speeds
float fr=10000;  // human version
// machine version
long step_delay_ms;
long step_delay_us;
// settings
char mode_abs=0;  // absolute mode??

/**
 * Look for character /code/ in the buffer and read the float that immediately follows it.
 * @return the value found.  If nothing is found, /val/ is returned.
 * @input code the character to look for.
 * @input val the return value if /code/ is not found.
 **/
float parseNumber(char code,float val) {
  char *ptr=serialBuffer;  // start at the beginning of buffer
  while((long)ptr > 1 && (*ptr) && (long)ptr < (long)serialBuffer+sofar) {  // walk to the end
    if(*ptr==code) {  // if you find code on your walk,
      return atof(ptr+1);  // convert the digits that follow into a float and return it
    }
    ptr=strchr(ptr,' ')+1;  // take a step from here to the letter after the next space
  }
  return val;  // end reached, nothing found, return default val.
}


/**
 * write a string followed by a float to the serial line.  Convenient for debugging.
 * @input code the string.
 * @input val the float.
 */
void output(const char *code,float val) {
	Serial.print(code);
	Serial.println(val);
}

/**
 * display helpful information
 */
void help() {
	Serial.print(F("FabScan G-CODDE Interpreter Version: "));
	Serial.println(BUILD_VERSION);
	Serial.println(F("Commands:"));
	Serial.println(F("G00 [T(steps)]; - linear move"));
	Serial.println(F("G01 [T(steps)] [L(steps)] [F(feedrate)]; - move"));
	Serial.println(F("M17; - enable motors"));
	Serial.println(F("M18; - disable motors"));
	Serial.println(F("M19; - turn left laser on"));
	Serial.println(F("M20; - turn left laser off"));
	Serial.println(F("M21; - turn right laser on"));
	Serial.println(F("M22; - turn right laser off"));
	Serial.println(F("M100; - this help message"));
	Serial.println(F("M114; - report position and feedrate"));
}

void version(){
	Serial.println(BUILD_VERSION);
}

void board(){
  Serial.println(MOTHERBOARD);
}

void settingsmode(int state){
  if (state) {
      right_laser_on();
      start_turning();
  } else {
      right_laser_off();
      stop_turning();
  }
}

/**
 * Read the input buffer and find any recognized commands.  One G or M command per line.
 */
void processCommand() {
	// blank lines
	if(serialBuffer[0]==';') return;

	int cmd;

	// is there a line number?
	cmd = parseNumber('N',-1);
	if(cmd!=-1 && serialBuffer[0]=='N') {  // line number must appear first on the line
		if( cmd != line_number ) {
			// wrong line number error
			Serial.print(F("BADLINENUM "));
			Serial.println(line_number);
			return;
		}

		// is there a checksum?
		if(strchr(serialBuffer,'*')!=0) {
			// yes.  is it valid?
			char checksum=0;
			int c=0;
			while(serialBuffer[c]!='*') checksum ^= serialBuffer[c++];
			c++; // skip *
			int against = strtod(serialBuffer+c,NULL);
			if( checksum != against ) {
				Serial.print(F("BADCHECKSUM "));
				Serial.println(line_number);
				return;
			}
		} else {
			//Serial.print(F("NOCHECKSUM "));
			//Serial.println(line_number);
			return;
		}

		line_number++;
	}

	cmd = parseNumber('G',-1);
	switch(cmd) {
		case  0: // move linear
		case  1: // move linear
			//if (!laser_active()) right_laser_on();
			//delay(100);
			do_move(parseNumber('T',0), parseNumber('L',0), parseNumber('F',0), TURN_NON_BLOCKING);
			break;
    case 2:
      do_move(parseNumber('T',0), parseNumber('L',0), parseNumber('F',0), TURN_BLOCKING);
      break;
		case  4:
			do_move(parseNumber('T',0), parseNumber('L',0), parseNumber('F',0), TURN_NON_BLOCKING);
			break;

    case 5:
      // reserved for servo action
      break;
		case 6:
			start_turning();
			break;

		case 7:
			stop_turning();
			break;


		case 90: // mode_abs=1;  break;  // absolute mode
		case 91: // mode_abs=0;  break;  // relative mode
		case 92:  // set logical position
			/*position( parseNumber('X',0),
					parseNumber('Y',0) );*/
			break;
		default:  break;
	}

	cmd = parseNumber('M',-1);
	switch(cmd) {
		case 4:
			right_laser_off();
      left_laser_off();
			set_leds(parseNumber('R',0),parseNumber('G',0),parseNumber('B',0));
			break;
		case 5:
			set_leds(parseNumber('R',0),parseNumber('G',0),parseNumber('B',0));
			break;
    case 13: 
      turntable_motor_enable();
      break;
    case 14: 
      turntable_motor_release();
      break;
    case 15: 
      //laser_motor_enable();
      break;
    case 16: 
      //laser_motor_release();
      break;
		case 17:  // enable motors
			turntable_motor_enable();
			//laser_motor_enable();
			break;
		case 18:  // disable motors
			turntable_motor_release();
			//laser_motor_release();
			break;
		case 19:
			left_laser_on();
			break;
		case 20:
			left_laser_off();
			break;
		case 21:
			right_laser_on();
			break;
		case 22:
			right_laser_off();
			break;
		case 100:  help();  break;
		case 110:  line_number = parseNumber('N',line_number);  break;
		case 114:  where();  break;
		case 200:  version(); break;
    case 201:  board(); break;
		default:  break;
	}
}



/**
 * delay for the appropriate number of microseconds
 * @input ms how many milliseconds to wait
 */
void pause(long ms) {
	delay(ms/1000);
	delayMicroseconds(ms%1000);  // delayMicroseconds doesn't work for values > ~16k.
}


void tick() {
	delay(step_delay_ms);
	delayMicroseconds(step_delay_us);
}


/**
 * Set the feedrate (speed motors will move)
 * @input nfr the new speed in steps/second
 */
void feedrate(float nfr) {
	if(fr==nfr) return;  // same as last time?  quit now.

	if(nfr>MAX_FEEDRATE || nfr<MIN_FEEDRATE) {  // don't allow crazy feed rates
		Serial.print(F("New feedrate must be greater than "));
		Serial.print(MIN_FEEDRATE);
		Serial.print(F("steps/s and less than "));
		Serial.print(MAX_FEEDRATE);
		Serial.println(F("steps/s."));
		return;
	}

	long us_per_min = 60 * 1000l * 1000l;
	long x = us_per_min / nfr;
	step_delay_ms = x / 1000;
	step_delay_us = x % 1000;
	fr=nfr;
}


/**
 * Set the logical position
 * @input npx new position x
 * @input npy new position y
 */
void position(float npx,float npy) {
	// here is a good place to add sanity tests
	px=npx;
	py=npy;
}


/**
 * print the current position, feedrate, and absolute mode.
 */
void where() {
	output("T",px);
	output("L",py);
	output("F",fr);
	Serial.println(mode_abs?"ABS":"REL");
}

/**
 * prepares the input buffer to receive a new message and tells the serial connected device it is ready for more.
 */
void ready() {
	sofar=0;  // clear input buffer
	Serial.println(F(">"));  // signal ready to receive input
}
