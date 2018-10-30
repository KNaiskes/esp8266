#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <WiFiClient.h>
#include "page.h"

const int buzzer_pin = 5;
const int relay_pin = 4;

// ---network---
const char* ssid = "";
const char* passw = "";
const char* host_name = "esp8266";

// app
const char* app_name = "BuzzerRelay";
const char* app_passw = "secret";

const int port = 80;
ESP8266WebServer server(port);

void handlePage(){
	digitalWrite(relay_pin, !digitalRead(relay_pin));
	tone(buzzer_pin, 700, 700);
	server.send(200,"text/html",HTML_PAGE);
}


void setup() {
	pinMode(relay_pin, OUTPUT);
	digitalWrite(relay_pin, HIGH);

	WiFi.mode(WIFI_STA);
	WiFi.begin(ssid, passw);
	WiFi.softAP(app_name, app_passw); // default ip: 192.168.4.1
	WiFi.hostname(host_name);
	server.on("/",handlePage);
	server.begin();
}

void loop() {
	server.handleClient();
	/*
	tone(buzzer_pin, 700, 700);
	digitalWrite(relay_pin, LOW);
	delay(50000);
	digitalWrite(relay_pin, HIGH);
	delay(50000);
	*/
}
