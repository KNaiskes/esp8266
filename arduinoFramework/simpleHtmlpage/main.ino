#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <WiFiClient.h>
#include "index.h"

const char* ssid = "";
const char* passw = "";

const int port = 80;

ESP8266WebServer server(port);

void handleIndex(){
	server.send(200,"text/html",HTML_INDEX);
}

void setup(){
	WiFi.begin(ssid,passw);
	server.on("/",handleIndex);
	server.begin();
}
void loop(){
	server.handleClient();
}

