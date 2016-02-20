#include "configuration.h"
#include "MotorDriver.h"
#include "AccelStepper.h"

AccelStepper laser(1,STEP_PIN_1, DIR_PIN_1);
AccelStepper turntable(2, STEP_PIN_0, DIR_PIN_0);


int currStepper = TURNTABLE_STEPPER;
boolean isTurning = false;


void turntable_motor_enable(){
   digitalWrite(ENABLE_PIN_0,HIGH);
}


void turntable_motor_release(){

  digitalWrite(ENABLE_PIN_0, LOW);
}

void laser_motor_enable(){
  digitalWrite(ENABLE_PIN_1, HIGH);
}

void laser_motor_release(){
  digitalWrite(ENABLE_PIN_1, LOW);
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
  digitalWrite(MICROSTEP,HIGH);

  //motors_release();
  laser.setMaxSpeed(2000.0);
  laser.setSpeed(700.0);
  
  turntable.setMaxSpeed(2000.0);
  turntable.setSpeed(700.0);
  
  turntable_motor_release();
  laser_motor_release();

    laser_motor_enable();
    turntable_motor_enable();

}


void step(int motor, float steps, float feedrate){
       
      AccelStepper stepper;
      if (motor == TURNTABLE_STEPPER ){
          stepper = turntable;
      }
      
      if (motor == LASER_STEPPER){  
          stepper = laser;
      }
  
      stepper.move(steps*SCALER);
      stepper.setSpeed(100);
      //motor.setAcceleration(acceleration);
      
      // Implementation without acceleration.
      while (stepper.distanceToGo() != 0)
        stepper.runSpeedToPosition();
        //motor.run();
     
}


void do_move(int t_steps, int l_steps, float feedrate){


  
  if (t_steps != 0){
    step(TURNTABLE_STEPPER, t_steps, feedrate); 
  }
  
  if (l_steps != 0){
    // do laser steps
     step(LASER_STEPPER, l_steps, feedrate);
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



