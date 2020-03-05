#include "FabScanConfig.h"
#include "MotorDriver.h"
#include <AccelStepper.h>

AccelStepper turntable(2, STEP_PIN_0, DIR_PIN_0);

int currStepper = TURNTABLE_STEPPER;
boolean isTurning = false;

void turntable_motor_enable(){
	digitalWrite(ENABLE_PIN_0,LOW);
}

void turntable_motor_release(){
	digitalWrite(ENABLE_PIN_0, HIGH);
}

int direction(long distance){
	if (distance < 0){
		return HIGH;
	}else{
		return LOW;
	}
}

void initialize_motor_driver(){
	pinMode(MICROSTEP, OUTPUT);
	digitalWrite(MICROSTEP,LOW);
  
	pinMode(ENABLE_PIN_0, OUTPUT);
	pinMode(ENABLE_PIN_1, OUTPUT);
  
	pinMode(STEP_PIN_0, OUTPUT);
	pinMode(STEP_PIN_1, OUTPUT);
  
	digitalWrite(MICROSTEP,HIGH);

	turntable.setMaxSpeed(300.0);
	turntable.setSpeed(200.0);
	turntable_motor_release();

}

void step_blocking(long motor, long steps, float feedrate){
   AccelStepper stepper;
   stepper = turntable;

   stepper.setSpeed(feedrate);
   stepper.setAcceleration(800.0); 

   //while (stepper.distanceToGo() != 0)
   stepper.runToNewPosition(steps);


}


void step(int motor, int steps, int feedrate){
	AccelStepper stepper;
	stepper = turntable;

	stepper.move(steps);
	stepper.setSpeed(feedrate);

	// Implementation without acceleration.
	while (stepper.distanceToGo() != 0)
		stepper.runSpeedToPosition();

}


void do_move(long t_steps, long l_steps, float feedrate, boolean block){

 if (block) {
      if (t_steps > 0){
        step_blocking(TURNTABLE_STEPPER, t_steps, feedrate);
      }

  } else {
    	if (t_steps > 0){
    		step(TURNTABLE_STEPPER, t_steps, feedrate);
    	}

  }
}

void turn(){
	if(isTurning){
		turntable.setSpeed(1000.0);
		turntable.move(10);
		turntable.runSpeed();
	}
}

void start_turning(){
	isTurning = true;
}

void stop_turning(){
	isTurning = false;
}
