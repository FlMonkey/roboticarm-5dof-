#include <Servo.h>



Servo base;
Servo shoulder;
Servo elbow;
Servo wrist;
Servo grip;
Servo spin;


const int BASE_PIN = 5;
const int SHOULDER_PIN = 6;
const int ELBOW_PIN = 7;
const int WRIST_PIN = 8;
const int SPIN_PIN = 9; 
const int GRIP_PIN = 10;


void setup() {
  base.attach(BASE_PIN);
  shoulder.attach(SHOULDER_PIN);
  elbow.attach(ELBOW_PIN);
  wrist.attach(WRIST_PIN);
  grip.attach(GRIP_PIN);
  spin.attach(SPIN_PIN);

  Serial.begin(9600);
}

void stall(int moveto, Servo &servo, int speed = 20) {
  int pos = servo.read();
  int increment = 1;
  if (moveto < pos) {
    increment = -1;
  }
  
  while (pos != moveto) {
    pos += increment;
    servo.write(pos);
    delay(speed);
  }
}

void reset() {
  
  stall(97, shoulder);
  
  stall(85, elbow);

  stall(98, wrist);

  stall(95, base);

  stall(180, grip);

  stall(90, spin);
}

void test(){
  stall(150, shoulder);
  stall(97, shoulder);
  
  stall(150, elbow);
  stall(85, elbow);
  
  stall(150, wrist);
  stall(98, wrist);
  
  stall(150, base);
  stall(95, base);

  stall(150, spin);
  stall(90, spin);
}

void readpos() {
  Serial.println(shoulder.read());
  Serial.println(wrist.read());
  Serial.println(base.read());
  Serial.println(elbow.read());
  Serial.println(grip.read());
  Serial.println(spin.read());
}


void wave() {
  
  stall(125, shoulder);

  // Repeat the loop 3 times
  for (int repetition = 0; repetition < 3; repetition++) {
    // Move the servo from 90 to 135 degrees
    stall(135, wrist);
    // Move the servo back from 135 to 90 degrees
    stall(90, wrist);
  }
}

void variabletest(){
  stall(150, shoulder);
  delay(20);
  stall(150, base);
  delay(12000);
}

void loop() {
  delay(10);
  Serial.println("Which move would you like to do? (Options: Wave (1), ...)");

  // Read input for the selected option
  Serial.println("Enter the option number:");
  while (!Serial.available());
  int choice = Serial.parseInt();
  
  switch(choice) {
  case 0:
    reset();
    break;

  case 1:
    wave();
    delay(300);
    reset();
    break;

  case 2:
    stall(100, wrist);
    delay(300);
    reset();
    break;

  case 3:
    test();
    delay(300);
    reset();
    break;
  
  case 4:
    variabletest();
    delay(300);
    reset();
    break;
  
  case 5:
    readpos();

  default:
    Serial.println("invalid option");
    break;
  
}


}
