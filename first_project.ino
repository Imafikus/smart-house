#include "Arduino.h"
#include "ESP8266WiFi.h"
#include "ESP8266WebServer.h"


ESP8266WebServer server(80);

void red_on()
{
	digitalWrite(4, HIGH);
	digitalWrite(5, LOW);
	server.send(200, "text/plain", "Upaljena crvena");
}

void green_on()
{
	digitalWrite(5, HIGH);
	digitalWrite(4, LOW);
	server.send(200, "text/plain", "Upaljena zelena");
}

void setup()
{
	pinMode(4, OUTPUT);//crveni
	pinMode(5, OUTPUT);//zeleni
	
	WiFi.begin("AndroidAP", "imafikus");
	while (WiFi.status() != WL_CONNECTED) delay(500);
	
	Serial.begin(115200);
	Serial.println(WiFi.localIP() );

	server.on("/red",red_on);
	server.on("/green",green_on);
	server.begin();
}

char parsed_packet[1024];

void loop()
{
	server.handleClient();
	// if (udp_start.parsePacket())
	// {
	// 	int len = udp_start.read(parsed_packet, 1024);
	// 	parsed_packet[len] = 0;
	// 	Serial.println(parsed_packet);

	// 	if(parsed_packet[0] == 'a')
	// 	{
	// 		digitalWrite(4, HIGH);
	// 		digitalWrite(5, LOW);
	// 	}
	// 	else
	// 	{
	// 		digitalWrite(5, HIGH);
	// 		digitalWrite(4, LOW);
	// 	}
	// }

}
