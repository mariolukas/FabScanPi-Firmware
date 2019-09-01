#include "FabScanConfig.h"
#include "MotorDriver.h"
#include "AccelStepper.h"


AccelStepper turntable(2, STEP_PIN_0, DIR_PIN_0);
AccelStepper laser(1, STEP_PIN_1, DIR_PIN_1);


int currStepper = TURNTABLE_STEPPER;
boolean isTurning = false;


void turntable_motor_enable(){
	digitalWrite(ENABLE_PIN_0,LOW);
}

void turntable_motor_release(){
	digitalWrite(ENABLE_PIN_0, HIGH);
}

/*
void laser_motor_enable(){
	digitalWrite(ENABLE_PIN_1, LOW);
}

void laser_motor_release(){
	digitalWrite(ENABLE_PIN_1, HIGH);
}
*/

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

	//laser.setMaxSpeed(2000.0);
	//laser.setSpeed(700.0);
  //laser_motor_release();

	turntable.setMaxSpeed(2000.0);
	turntable.setSpeed(700.0);
	turntable_motor_release();

  // Laser Servos to initial position


}

void step_blocking(int motor, int steps, int feedrate){
   AccelStepper stepper;
   
   
   if (motor == TURNTABLE_STEPPER ){
      stepper = turntable;
   } 
   
   /*
   if (motor == LASER_STEPPER){
    stepper = laser;
  }
   */
   
   //stepper.move(steps);
   stepper.setSpeed(feedrate);
   stepper.setAcceleration(500); 

   //while (stepper.distanceToGo() != 0)
   stepper.runToNewPosition(steps);


}


void step(int motor, float steps, float feedrate){
	AccelStepper stepper;
	if (motor == TURNTABLE_STEPPER ){
		stepper = turntable;
	} 

	if (motor == LASER_STEPPER){
		stepper = laser;
	}

	stepper.move(steps);
	stepper.setSpeed(feedrate);
 // stepper.setAcceleration(500); 
	//motor.setAcceleration(acceleration);

	// Implementation without acceleration.
	while (stepper.distanceToGo() != 0)
		stepper.runSpeedToPosition();
	//motor.run();
}


void do_move(int t_steps, int l_steps, float feedrate, boolean block){
  if (block) {
      if (t_steps > 0){
        step_blocking(TURNTABLE_STEPPER, t_steps, feedrate);
      }
    /*
      if (l_steps > 0){
        // do laser steps
        step_blocking(LASER_STEPPER, l_steps, feedrate);
      }
      */
  } else {
    	if (t_steps > 0){
    		step(TURNTABLE_STEPPER, t_steps, feedrate);
    	}

    /*
    	if (l_steps > 0){
    		// do laser steps
    		step(LASER_STEPPER, l_steps, feedrate);
    	}
     */
  }
}

void turn(){
	if(isTurning){
		turntable.setSpeed(1000);
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
