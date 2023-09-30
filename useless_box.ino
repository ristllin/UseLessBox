#include <Servo.h>

Servo myservo;
const int rocker_pos = 150;
const int switch_pos = 25;
const int min_wait = 0;    //in miliseconds
const int max_wait = 1500; //in miliseconds
int rand_wait = 0;    // large num is slow
int servo_speed = 15;    // large num is slow
int servo_min_speed = 50;    // large num is slow
int servo_max_speed = 0;    // large num is slow


void setup() {
  Serial.begin(9600);
  myservo.attach(3); 
  myservo.write(35);  
}

void loop() {
  servo_speed = random(servo_max_speed, servo_min_speed);
  Serial.println(servo_speed);
  rand_wait = random(min_wait, max_wait);
  Serial.println(rand_wait);
  delay(rand_wait);
  for (int pos = switch_pos; pos <= rocker_pos; pos += 1) {
    myservo.write(pos);             
    delay(servo_speed);                       
  }
  Serial.println(servo_speed);
  rand_wait = random(min_wait, max_wait);
  Serial.println(rand_wait);
  for (int pos = rocker_pos; pos > switch_pos; pos -= 1) {
    myservo.write(pos);             
    delay(servo_speed);                       
  }
}
