void callSetup() {
  Serial.print(F("GPS NEO..............."));
  gpsPort.begin(9600);
  Serial.println(F("Ok"));

  Serial.print(F("MicroSD..............."));
  if (!SD.begin(chipSelect)) {
    Serial.println(F("Fail"));
    while (1);
  }
  Serial.println(F("Ok"));

  Serial.print(F("BMP180................"));
  if (!pressure.begin()) {
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

  Serial.print("ClosedCube HDC1080....");
  hdc1080.begin(0x40);
  Serial.println(F("Ok"));

  Serial.print(F("Motor................."));
  pinMode(motor, OUTPUT);
  Serial.println(F("Ok"));
}
