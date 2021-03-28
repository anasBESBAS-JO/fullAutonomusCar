// ---------------- Sonar Sensor functions  -----------------

float sonarFront() {
  turnOffLED();
  turnOnLED(LEDF);
  float a = fSonic.dist(); //return current distance (cm)
  float b = fSonic.dist(); //return current distance (cm)
  if (a < b){
    return a;
  }
  return b;
}

float sonarBack() {
  turnOffLED();
  turnOnLED(LEDB);
  float a = fSonic.dist(); //return current distance (cm)
  float b = fSonic.dist(); //return current distance (cm)
  if (a < b){
    return a;
  }
  return b;
}

float sonarFR() {
  turnOffLED();
  turnOnLED(LEDFR);
  float a = fSonic.dist(); //return current distance (cm)
  float b = fSonic.dist(); //return current distance (cm)
  if (a < b){
    return a;
  }
  return b;
}

float sonarFL() {
  turnOffLED();
  turnOnLED(LEDFL);
  float a = fSonic.dist(); //return current distance (cm)
  float b = fSonic.dist(); //return current distance (cm)
  if (a < b){
    return a;
  }
  return b;
}


//-------------------Infarad sensor-----------------

//Necessary vars for sonar readings, setting speeds, etc.
int valR = 0;  // used to stock the distance from the Front right infarad sensor
int valL = 0;  // used to stock the distance from the front  left infarad sensor
int valBR = 0; // used to stock the distance from the back  right infarad sensor
int valBL = 0; // used to stock the distance from the back   left infarad sensor

float mesureDisInfarad(int sensor){
  float volts = analogRead(sensor)*0.0048828125;  // value from sensor * (5/1024)
  return 13*pow(volts, -1); // worked out from datasheet graph
}
int sonarR() {
  turnOffLED();
  turnOnLED(LEDR);
  valR = mesureDisInfarad(Right);   // reads the value of the sharp sensor FrontRight
  Serial.println(valR);            // prints the value of the sensor to the serial monitor
  return valR;
}

int sonarL() {
  turnOffLED();
  turnOnLED(LEDL);
  valL = mesureDisInfarad(Left);       // reads the value of the sharp sensor FrontLeft
  Serial.println(valL);            // prints the value of the sensor to the serial monitor
  return valL;
}

int sonarBR() {
  valBR = mesureDisInfarad(BackRight);       // reads the value of the sharp sensor BackRight
  Serial.println(valBR);            // prints the value of the sensor to the serial monitor
  return valBR;
}

int sonarFRSide() {
  valBL = mesureDisInfarad(InfaradFRight);       // reads the value of the sharp sensor BackLeft
  Serial.println(valBL);            // prints the value of the sensor to the serial monitor
  return valBL;
}

float getTMP(){
  float t = dht.readTemperature();
  if (isnan(t) ) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return t;
  }
  return t;
}
