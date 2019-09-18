int readCo2A() {
  int result = 0;
  while (!ccs.available()) {
    delay(10);
  }
  if (!ccs.readData()) {
    result = ccs.geteCO2();
    if (result == 0) {     //Si co2 es 0 leer todo otra vez
      return readCo2A();
    }
  } else {
    Serial.println(F("CCS811 Error"));
  }
  return result;
}

void ReadAllData() {
  if (pressure.getPressure(presion, temperatura) == 0) {
    Serial.println(F("BMP180 Error"));
  }

  temperatura = hdc1080.readTemperature();
  humedad = hdc1080.readHumidity();

  co2A = readCo2A();
  co2A += readCo2A();
  co2A = co2A / 2.0;

  co2B = constrain(map(analogRead(A0), 186, 930, 0, 3000),0, 3000);
  co2B += constrain(map(analogRead(A0), 186, 930, 0, 3000),0, 3000);
  co2B = co2B / 2.0;

  h2s = map(analogRead(A2), 0, 1023, 0, 200);
  h2s += map(analogRead(A2), 0, 1023, 0, 200);
  h2s = h2s / 2.0;

  so2 = map(analogRead(A3), 0, 1023, 0, 200);
  so2 += map(analogRead(A3), 0, 1023, 0, 200);
  so2 = so2 / 2.0;
}

void saveData(gps_fix & fix) {
  String dataString = "";
  dataString += fix.dateTime.date;
  dataString += "/";
  dataString += fix.dateTime.month;
  dataString += "/";
  dataString += fix.dateTime.year;
  dataString += ",";

  dataString += fix.dateTime.hours;
  dataString += ":";
  dataString += fix.dateTime.minutes;
  dataString += ":";
  dataString += fix.dateTime.seconds;
  dataString += ",";

  dataString += String(fix.latitude(), 6);
  dataString += ",";
  dataString += String(fix.longitude(), 6);
  dataString += ",";
  dataString += String(fix.altitude(), 2);
  dataString += ",";

  dataString += String(presion, 2);
  dataString += ",";
  dataString += String(humedad, 2);
  dataString += ",";
  dataString += String(temperatura, 2);
  dataString += ",";
  dataString += String(co2A, 2);
  dataString += ",";
  dataString += String(co2B, 2);
  dataString += ",";
  dataString += String(h2s, 2);
  dataString += ",";
  dataString += String(so2, 2);

  File dataFile = SD.open("datalog.txt", FILE_WRITE);
  if (dataFile) {
    dataFile.println(dataString);
    dataFile.close();
    lastMotorTime = millis();
    Serial.println(dataString);
  } else {
    Serial.println(F("error opening datalog.txt"));
  }

}
