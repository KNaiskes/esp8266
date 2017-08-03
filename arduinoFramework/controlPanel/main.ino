#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <WiFiClient.h>
#include "index.h"
#include "ledPanel.h"
#include "led.h"

// network
const char* ssid = "";
const char* passw = "";

const char* setHostname = "LED controller";

const int port = 80;


// app
const char* appName = "";
const char* appPasw = "";

ESP8266WebServer server(port);

void handleIndex(){
	server.send(200,"text/html",HTML_INDEX);
}
void handleLogin(){
	// if credentails match go to led(s) page 
	if(server.arg("username") == "user1" && server.arg("password")=="test"){
		server.send(200,"text/html",HTML_ledsPanel);
	}
}
void handleLed(){
	digitalWrite(LED_BUILTIN,!digitalRead(LED_BUILTIN));
	server.send(200,"text/html",HTML_BACKMENU);
}

void setup(){
	pinMode(LED_BUILTIN,OUTPUT);
	WiFi.mode(WIFI_STA);
	WiFi.begin(ssid,passw);
	WiFi.softAP(appName,appPasw); // default ip: 192.168.4.1
	WiFi.hostname(setHostname);
	server.on("/",handleIndex);
	server.on("/dashboard",HTTP_POST,handleLogin);
	server.on("/status",HTTP_POST, handleLed);
	server.begin();
}
void loop(){
	server.handleClient();
}

