# RedBearCC3200_IoT
The next script is an example how to connect the board ReadBear CC3200(TI) to upload data (temperature) to IBM Cloud - IoT Watson

The libraries for the sketch are the next:

#include <SPI.h>
#include <WiFi.h>
#include <dht.h> ===> library to get the data from the sensor 
#include <PubSubClient.h> ==> library to transmit to the cloud 
#include <aJSON.h> ==> 

# Things to note:
 * We will use the sensor DHT11 to get the data 
 * The format to uoload the data is in JSON
 * The protocol to transmit is MQTT and we will use the library PubSubClient modified to use with Energia TI and the WiFi CC3200
