#include "configuration.h"
#include "LaserDriver.h"

boolean laser_is_active = false;

void initialize_laser_driver(){

  pinMode(RIGHT_LASER_PIN, OUTPUT);
  pinMode(LEFT_LASER_PIN, OUTPUT);
  pinMode(LIGHT_PIN, OUTPUT);
  
  digitalWrite(LIGHT_PIN, LOW); //turn light off
  digitalWrite(RIGHT_LASER_PIN, LOW); //turn right laser off
  digitalWrite(LEFT_LASER_PIN, LOW); //turn left laser off
}

void left_laser_on(){
   digitalWrite(LEFT_LASER_PIN, HIGH);
   laser_is_active = true;
}

void left_laser_off(){
  digitalWrite(LEFT_LASER_PIN, LOW);
  laser_is_active = false;
}

void right_laser_on(){
   digitalWrite(RIGHT_LASER_PIN, HIGH);
   laser_is_active = true;
}

void right_laser_off(){
  digitalWrite(RIGHT_LASER_PIN, LOW);
  laser_is_active = false;
}

boolean laser_active(){
    return laser_is_active;
}

