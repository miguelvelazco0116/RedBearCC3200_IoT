# RedBearCC3200_IoT
The next sketch is an example how to connect the board ReadBear CC3200(TI) to upload data (temperature/humidity) to IBM Cloud - IoT Watson

# Hardware
 * Sensor DHT11 (https://hetpro-store.com/sensor-dht11/)
 * Red Bear CC3200 (http://redbearlab.com/)

# Libraries
 * #include <SPI.h>
 * #include <WiFi.h>
 * #include <dht.h>
 * #include <PubSubClient.h>
 * #include <aJSON.h>

# Pins
 - DHT11 - Pin 1 <==> CC3200 - Pin 8 (data)
 - DHT11 - Pin 2 <==> CC3200 - Pin VCC
 - DHT11 - Pin 3 <==> CC3200 - Pin GND
     
# Things to note:
 * We will use the sensor DHT11 to get the data 
 * The format to upload the data is in JSON
 * The protocol to transmit is MQTT and we will use the library PubSubClient modified to use with Energia TI and the WiFi CC3200
 * The tutorial was designed to connect with the IoT Watson platform (https://internetofthings.ibmcloud.com/#), consider having an account to replicate this sample
 
 # Script
 
* WIFI CONNECTION DATA, introduce your own WiFi data (SSID, Pwd)
* char ssid[] = "***";     ===> Network SSID
* char password[] = "***"; ===> Network password

* IoT Watson - Bluemix Data

* char broker_IBM[] = "***.messaging.internetofthings.ibmcloud.com"; ==> Add your organization 
* char client_IBM[] = "***"; ==> Add your Client Id (d:org:device:device Id)
* char username_IBM[] = "use-token-auth";
* char pwd_IBM[] = "***"; ==> Add your own pwd,
* int IoT_Port = 1883; ==> Bluemix allow you to connect with the port 1883 or 8883(SSL), during this example we'll use the MQTT port 1883
* char topic_MQTT[] = "iot-2/evt/***/fmt/json"; ==> Add your event (example: CC3200)
