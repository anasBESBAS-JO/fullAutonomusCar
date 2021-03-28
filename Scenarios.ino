// ------------ Motor Demo ------------------

void forwardReverseDemo() { //Function called to execute speeding with acceleration
  blinking();
  steer.write(neutral);
  motor.writeMicroseconds(forwardSpeed);
  delay(20000);
  breaking();
  motor.writeMicroseconds(reverseSpeed);
  delay(20000);
  breaking();
}

// ------------ Steer Demo ------------------

void SteerDemo() { //  Function called to execute a multiple turn
  motor.writeMicroseconds(forwardSpeed);
  rightTurn();
  delay(500);
  leftTurn();
  delay(500);
  longLeftTurn();
  delay(500);
  longRightTurn();
  breaking();
}


// ------------ autoParking Demo ------------------

void autoParking() {
  blinking();
  delay(5000); //wait 5 seconds
  steer.write(steerLeft);
  motor.writeMicroseconds(forwardSpeed);
}

// ------------ autoDrive Demo ------------------

void autoDrive() {
  steer.write(neutral);
  speedFMax();
  delay(300);
  slowDownSpeed();
  delay(300);
  leftTurn();
  speedCenterN();
  turnSpeedDirTime(steerRight, reverseSpeed, 66);
  speedCenterN();
  turnSpeedDirTime(steerLeft, forwardSpeed, 66);
  speedFMax();
  delay(300);
  speedCenterN();
}

// --------------- overTaking Demo -------------------

int opsticalDetection() { // Helper function used to mesure destance if obstical
                          // is detected return 1 or 2 or 3 espectly from front, left,
                          // right if obstical is detected and 0 if not.
  float distance1 = sonarFront();
  float distance2 = sonarFL();
  float distance3 = sonarFR();
  if (distance1 <= 50) {
    return 1;
  } else if (distance2 <= 35){ // check if left is detected 
    return 2;
  } else if (distance3 <= 35){ // check if right is detected
    return 3;
  }
  return 0; // nothing is detected the path is clear 
}


int outOfRange(int sensor) { // sonarFL -> 1  sonarFR -> 2
  float i;
  if (sensor == 1) {
    i = sonarFL();
    return (i > 45);
  }
  i = sonarFR();
  return (i > 45);
}


void turnToOvertake() {
  int x = opsticalDetection();
  if ( x == 0 ){
    return;
  } 
  else if ( x == 1 ){
    float sf = sonarFront();
    while (sf > 35 && sf < 60){
      sf = sonarFront();
      // check for other sensors
    }
    if ( sf <= 35 ){ // overtake rotine now
      if (outOfRange(1)){
        steer.write(steerLeft);
        motor.writeMicroseconds(forwardSpeed);
        Serial.println("LEFT TURN");
        delay(200);
        steer.write(steerRight);
        Serial.println("Right a little");
        delay(60);
        steer.write(neutral);
        Serial.println("neutral -> checking right ...");
        int right = outOfRange(2); // check if right is available 
        while (right == 0){
          right = outOfRange(2);
        }
        int back = sonarBR();
        while (back <= 8){
          back = sonarBR();
        }
        delay(200);
        steer.write(steerRight);
        delay(200);
        steer.write(steerLeft);
        Serial.println("Left a little");
        delay(60);
        breaking(); // overtake done
        blinking();
        loop();
      } else {
        breaking(); // no way to overtake
        loop();
      }
      // if everything is good 
      // breaking();
      // blinking();
      // loop();
    }
  }
}


void overTaking() { // function used to preform an overtaking if an obstical is
                    // detected in front of the car this function calles
                    // multipel helper functions to take a dicesion. The function
                    // start by moving the car forword for 10s
  unsigned long counterMillis = 0;
  unsigned long currentMillis = millis(); // get current time
  const long interval = 10000; //timer for 10 senconds
  while (counterMillis < interval) {
    steer.write(neutral);
    motor.writeMicroseconds(forwardSpeed);
    opsticalDetection();
    counterMillis += millis() - currentMillis;
  }
  breaking();
}
