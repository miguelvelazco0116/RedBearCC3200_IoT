# RedBearCC3200_IoT
The next sketch is an example how to connect the board ReadBear CC3200(TI) to upload data (temperature) to IBM Cloud - IoT Watson

# Hardware
 * Sensor DHT11
 * Red Bear CC3200 (http://redbearlab.com/)

# Libraries
 * #include <SPI.h>
 * #include <WiFi.h>
 * #include <dht.h>
 * #include <PubSubClient.h>
 * #include <aJSON.h>

# Pins
 - DHT11 - Pin 2 <==> CC3200 - Pin 8 (data)
 - 1 <==> VCC
 - 3 <==> gnd
     
# Things to note:
 * We will use the sensor DHT11 to get the data 
 * The format to upload the data is in JSON
 * The protocol to transmit is MQTT and we will use the library PubSubClient modified to use with Energia TI and the WiFi CC3200

