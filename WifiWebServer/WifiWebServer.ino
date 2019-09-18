#include <ESP8266WiFi.h>
#include <ArduinoJson.h>
#include <FS.h>
#include <ESPAsyncTCP.h>
#include <ESPAsyncWebServer.h>

AsyncWebServer server(80);

const char *ssid = "SensorLogger";
const char *password = "87654321";

String serialText = "";
int serialTimeOut = 750;//retener ultimo dato en segundos

void setup() {
  //Puerto Serial
  Serial.begin(9600);
  Serial.setTimeout(serialTimeOut);
  Serial.println();
  //Memoria SPIFFS
  SPIFFS.begin();
  //Iniciamos un punto de acceso
  WiFi.softAP(ssid, password);

  //Eventos del Servidor
  server.serveStatic("/", SPIFFS, "/www/").setDefaultFile("index.html");

  //Servidor GET Request
  server.on("/data", HTTP_GET, [](AsyncWebServerRequest *request) {
    request->send(200, "text/plain", serialText);
  });


  //DefaultHeaders::Instance().addHeader("Access-Control-Allow-Origin", "*");
  server.begin();
}

void loop() {
  
  serialText = Serial.readString();  

}
