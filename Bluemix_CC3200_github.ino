// *********************************************************
// *********************************************************
//                 LIBRARIES

#include <SPI.h>
#include <WiFi.h>
#include <dht.h>
#include <PubSubClient.h>
#include <aJSON.h>

// ************************************************************************************************************************
// ************************************************************************************************************************

// DEFINE FUNCTIONS 

float DTH11_sensor_temp();
void  connect_Bluemix();

// ************************************************************************************************************************
// ************************************************************************************************************************

// DATA FOR CONNECTION

#define LED RED_LED

// *********************************************************

// WIFI CONNECTION DATA

char ssid[] = "TOTALPLAY";            // Network SSID
char password[] = "7226253410a";      // Network password

// *********************************************************

char printbuf[100];
int arrivedcount = 0;

// ************************************************************************************************************************
// ************************************************************************************************************************

void callback(char* topic, byte* payload, unsigned int length) {
  // handle message arrived
}

// ************************************************************************************************************************
// ************************************************************************************************************************
// Global values

float   Temperature;
float   Humidity;
char    Source00[] = "TemperaturaZona01";
char    Source01[] = "HumedadZona01";

// ************************************************************************************************************************
// ************************************************************************************************************************

// IBM BLUEMIX CONNECTION DATA
// Bluemix organization: wcgnjx
// Bluemix device type: IIoT
// Bluemix device Id: IIoTD000001

char broker_IBM[] = "************.messaging.internetofthings.ibmcloud.com";
char client_IBM[] = "*****************";
char username_IBM[] = "use-token-auth";
char pwd_IBM[] = "***************";
int IoT_Port = 1883;
char topic_MQTT[] = "iot-2/evt/**********/fmt/json";

// ************************************************************************************************************************
// ************************************************************************************************************************

WiFiClient WClient;
PubSubClient client(broker_IBM, IoT_Port, callback, WClient);

// ************************************************************************************************************************
// ************************************************************************************************************************

void setup()
{

Humidity = 0.0;
Temperature = 0.0;

  pinMode(LED, OUTPUT);
  WiFi.begin(ssid, password);                               // Connect to WPA/WPA2 network. Change this line if using open or WEP network:
  
  while ( WiFi.status() != WL_CONNECTED) {                  // Print dots while we wait to connect
    
    delay(300);
  }
  
  while (WiFi.localIP() == INADDR_NONE) {                  //  Print dots while we wait for an ip addresss
        
    delay(300);
  }

  connect_Bluemix();
  delay(3000);
}

// ************************************************************************************************************************
// ************************************************************************************************************************

void loop()
{                  
           
  if(!client.connected())
  {      
      connect_Bluemix();         
  }

  dht::readFloatData(8, &Temperature, &Humidity, false) == 0;       
  createJSON(Temperature, Source00, Humidity, Source01);         
      
  delay(20000);
  digitalWrite(LED, HIGH);   
      
}


