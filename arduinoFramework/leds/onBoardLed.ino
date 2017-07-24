#include <Arduino.h>

// testing the built-in led on esp8266 nodemcu, it may be a red or a blue led

const int timeD = 1000;

void setup()
{
	pinMode(LED_BUILTIN,OUTPUT);
}

void loop()
{
	digitalWrite(LED_BUILTIN,HIGH);
	delay(timeD);
	digitalWrite(LED_BUILTIN,LOW);
	delay(timeD);
}
