from machine import Pin # for testing purpose - will be removed some time later
import network

def connect(ssid,passw):
	led = Pin(2,Pin.OUT)
	netw = network.WLAN(network.STA_IF)
	if not netw.isconnected():
		led.on() # while it is not connected led will be off
		print("Trying to connect to network:",ssid)
		netw.active(True)
		netw.connect(ssid,passw)
		while not netw.isconnected():
			pass
		led.off() # turn led on when it is connected to the network
	
def setupAP(ssid,passw,channel):
	espAP = network.WLAN(network.AP_IF)
	espAP.config(essid = ssid, password = passw, channel = channel)
	print("Access point name:",ssid," ,channel:",channel)

