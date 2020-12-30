#include <SPI.h>
#include <SD.h>
#include <Wire.h>
#include <NMEAGPS.h>
#include <GPSport.h>
#include "Adafruit_CCS811.h"
#include "SparkFun_Si7021_Breakout_Library.h"
#include "SparkFunBME280.h"


NMEAGPS     gps;
Adafruit_CCS811 ccs;
BME280 mySensor;
Weather sensor;
#define motor 3
const int activeMotorTime = 5000; //5 segundos activo
unsigned long lastMotorTime = 0;
const int utc = -6;
const int chipSelect = 10;

double co2A;
double co2B;
double h2s;
double so2;
double presion; // ARREGLAR LA PRESION Calcularla segun la altura del GPS
double humedad;
double temperatura;
