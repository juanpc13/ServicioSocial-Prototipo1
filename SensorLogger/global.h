#include <SPI.h>
#include <SD.h>
#include <Wire.h>
#include <NMEAGPS.h>
#include <GPSport.h>
#include <SFE_BMP180.h>
#include "Adafruit_CCS811.h"
#include "ClosedCube_HDC1080.h"


NMEAGPS     gps;
SFE_BMP180 pressure;
Adafruit_CCS811 ccs;
ClosedCube_HDC1080 hdc1080;

#define motor 3
const int activeMotorTime = 5000; //5 segundos activo
unsigned long lastMotorTime = 0;
const int utc = -6;
const int chipSelect = 10;

double co2A;
double co2B;
double h2s;
double so2;
double presion;
double humedad;
double temperatura;
