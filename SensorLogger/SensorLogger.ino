#include "global.h"
#include "setup.h"
#include "rwGlobalData.h"
#include "gpsEventLoop.h"
#include "motor.h"

void setup() {  
  callSetup();
}

void loop() {
  motorLoop();
  gpsEventLoop();   //Esto metodo produce un pequeño delay debido al GPS
}
