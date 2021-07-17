#include <Servo.h>

Servo myservo;
const int switch_pos = 0;
const int rocker_pos = 135;
const int min_wait = 0;    //in miliseconds
const int max_wait = 5000; //in miliseconds
int servo_speed = 15;    // large num is slow
int servo_min_speed = 50;    // large num is slow
int servo_max_speed = 10;    // large num is slow


void setup() {
  myservo.attach(3);  // attaches the servo on pin 9 to the servo object
}

void loop() {
  servo_speed = random(servo_min_speed,servo_max_speed);
  delay(random(min_wait, max_wait));
  go_to(switch_pos, servo_speed);
  delay(random(min_wait, max_wait));
  go_to(rocker_pos, servo_speed);
}

void go_to(int to_pos, int servo_speed){
  if (to_pos == switch_pos){
    for (int pos = switch_pos; pos <= rocker_pos; pos += 1) {
      myservo.write(pos);             
      delay(servo_speed);                       
    }
  }
  else { //pos == rocker_pos
    for (int pos = rocker_pos; pos >= switch_pos; pos -= 1) {
      myservo.write(pos);    
      delay(servo_speed);          
    }
  }
}
