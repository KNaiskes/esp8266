#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <WiFiClient.h>
#include "index.h"
#include "relayPanel.h"
#include "backPage.h"


const int channel = 5;
// network
const char* ssid = "";
const char* passw = "";

const char* setHostname = "Lamp";

const int port = 80;

//login page credentials
const char* username = "";
const char* password = "";


// app
const char* appName = "Lamp";
const char* appPasw = "funnyPass";

ESP8266WebServer server(port);

void handleIndex(){
	server.send(200,"text/html",HTML_INDEX);
}
void handleLogin(){
	// if credentails match go to relay status page 
	if(server.arg("username") == username && server.arg("password")== password){
		server.send(200,"text/html",HTML_ledsPanel);
	}
}
void handleLed(){
	digitalWrite(channel,!digitalRead(channel));
	server.send(200,"text/html",HTML_BACKMENU);
}

void setup(){
	pinMode(channel,OUTPUT);
	WiFi.mode(WIFI_STA);
	WiFi.begin(ssid,passw);
	WiFi.softAP(appName,appPasw); // default ip: 192.168.4.1
	WiFi.hostname(setHostname);
	server.on("/",handleIndex);
	server.on("/dashboard",HTTP_POST,handleLogin);
	server.on("/status",HTTP_POST, handleLed);
	server.begin();
	digitalWrite(channel, HIGH);	
}
void loop(){
	server.handleClient();
}

