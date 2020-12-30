void callSetup() {
  Serial.begin(9600);
  Serial.print(F("GPS NEO..............."));
  gpsPort.begin(9600);
  Serial.println(F("Ok"));

  Serial.print(F("MicroSD..............."));
  if (!SD.begin(chipSelect)) {
    Serial.println(F("Fail"));
    while (1);
  }
  Serial.println(F("Ok"));

  Serial.print(F("CCS811 Sensor........."));
  if (!ccs.begin()) {
    Serial.println(F("Failed to start sensor! Please check your wiring."));
    while (1);
  }
  while (!ccs.available());   //Calibrar
  Serial.println(F("Ok"));

  // Init Sensor de temperatura y humedad y presion
  Serial.print(F("BMP280 Sensor........."));
  mySensor.setI2CAddress(0x76);
  if(mySensor.beginI2C() == false){
    Serial.println(F("Fail"));
    while (1);
  }
  Serial.println(F("Ok"));

  // Init Sensor de temperatura y humedad y presion
  Serial.print(F("Si7021 Sensor........."));
  sensor.begin();  
  sensor.heaterOff();
  Serial.println(F("Ok"));

  Serial.print(F("Motor................."));
  pinMode(motor, OUTPUT);
  Serial.println(F("Ok"));
}
