#include <Servo.h>

Servo myservo;
const int switch_pos = 0;
const int rocker_pos = 180;
const int min_wait = 0;    //in miliseconds
const int max_wait = 5000; //in miliseconds
int servo_speed = 15;    // large num is slow
int servo_min_speed = 30;    // large num is slow
int servo_max_speed = 1;    // large num is slow


void setup() {
  myservo.attach(3);  // attaches the servo on pin 9 to the servo object
}

void loop() {
  servo_speed = random(servo_min_speed,servo_max_speed);
  delay(random(min_wait, max_wait));
  goto(switch_pos, servo_speed);
  delay(random(min_wait, max_wait));
  goto(rocker_pos, servo_speed);
}

void go_to(int to_pos, int servo_speed){
  if (to_pos == switch_pos){
    for (pos = switch_pos; pos <= rocker_pos; pos += 1) {
      myservo.write(pos);             
      delay(servo_speed);                       
    }
  }
  else { //pos == rocker_pos
    for (to_pos = rocker_pos; pos >= switch_pos; pos -= 1) {
      myservo.write(pos);    
      delay(servo_speed);          
    }
  }
}
