#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <WiFiClient.h>
#include <ESP8266WiFiMulti.h>
#include "index.h"
#include "ledPanel.h"

// network
const char* ssid = "";
const char* passw = "";
// credentials of the second network that I usually use 
const char* ssid2 = "";
const char* passw2 = "";

const char* setHostname = "";

const int port = 80;

// app
const char* appName = "";
const char* appPasw = "";

ESP8266WebServer server(port);
ESP8266WiFiMulti multinetw;

void handleIndex(){
	server.send(200,"text/html",HTML_INDEX);
}
void handleLogin(){
	// if credentails match go to led(s) page 
	if(server.arg("username") == "user1" && server.arg("password")=="test"){
		server.send(200,"text/html",HTML_ledsPanel);
	}
}


void setup(){
	//WiFi.begin(ssid,passw);
	multinetw.addAP(ssid,passw);
	WiFi.softAP(appName,appPasw); // default ip: 192.168.4.1
	WiFi.hostname(setHostname);
	server.on("/",handleIndex);
	server.on("/connect",HTTP_POST,handleLogin);
	server.begin();
}
void loop(){
	server.handleClient();
}

