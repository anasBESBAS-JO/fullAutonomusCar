void speedFMax(){
  motor.writeMicroseconds(forwardSpeedMax);
}


void speedFMin(){
  motor.writeMicroseconds(forwardSpeed);
}


void slowDownSpeed(){ // goes from max till min forward speed 
  for (int i = forwardSpeedMax; i < forwardSpeed; ++i) { 
    motor.writeMicroseconds(i);
    delay(30);
  }
}


void breaking(){ // Function called to stop the car 
  motor.writeMicroseconds(reverseSpeed);
  delay(500);
  speedCenterN(); 
  Serial.println("Breaking done ! ");
}

void speedBMax(){
  motor.writeMicroseconds(reverseSpeed);
}


void speedBMin(){
  motor.writeMicroseconds(reverseSpeedMin);
}

void speedCenterN(){
  motor.writeMicroseconds(speedCenter);
}
