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
const int GRIP_PIN = 11;


void setup() {
  base.attach(BASE_PIN);
  shoulder.attach(SHOULDER_PIN);
  elbow.attach(ELBOW_PIN);
  wrist.attach(WRIST_PIN);
  grip.attach(GRIP_PIN);
  spin.attach(SPIN_PIN);

  delay(500);
  Serial.begin(9600);
  delay(500);
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
  delay(1000);

  stall(97, shoulder);
  
  stall(85, elbow);

  stall(98, wrist);

  stall(95, base);

  stall(200, grip);

  stall(60, spin);
}


void test(){
  //stall(0, grip);
  
  stall(35, shoulder, 35);
  stall(97, shoulder);
  
  stall(150, elbow);
  stall(85, elbow);
  
  stall(150, wrist);
  stall(98, wrist);
  
  stall(30, base);
  stall(95, base);

  stall(180, spin, 8);
  stall(0, spin, 8);


}

void hailJeff(){
  stall(115, shoulder);
  delay(2000);

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
  
  stall(180, base);

  stall(200, spin);

  stall(110, shoulder);

  stall(60, wrist);

  // Repeat the loop 3 times
  for (int repetition = 0; repetition < 2; repetition++) {
    // Move the servo from 90 to 135 degrees
    stall(120, wrist, 15);
    // Move the servo back from 135 to 90 degrees
    stall(45, wrist, 15);
  }
}

void sus(){
  stall(165, shoulder);
  for (int repetition = 0; repetition < 5; repetition++) {
    stall(130, wrist, 13);
    stall(100, wrist, 13);
  }
}

void shake(){
  //stall(160, elbow);
  stall(120, elbow);
  stall(150, shoulder, 35);
  stall(180, spin, 5);
  
  for (int repetition = 0; repetition < 3; repetition++) {
    stall(160, wrist, 25);
    stall(130, wrist, 25);
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
    break;
  case 6:
    stall(20, grip);
    break;
  case 7:
    sus();
    break;
  case 8:
    shake();
    break;
  case 9:
  hailJeff();
  default:
    Serial.println("invalid option");
    break;
  
}
}
