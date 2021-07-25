#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include "Adafruit_CCS811.h"

Adafruit_CCS811 ccs;

// Update these with values suitable for your network.
const char* ssid = "Modem 4G Wi-Fi_B764";
const char* password = "57270632";
const char* mqtt_server = "192.168.1.130"; 
const char* mqtt_user = "guest";
const char* mqtt_pass= "guest";


WiFiClient espClient;
PubSubClient client(espClient);

void setup_wifi() {
  // Connecting to a WiFi network
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void reconnect() {
  // Loop until we're reconnected
  Serial.println("In reconnect...");
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    // Attempt to connect
    if (client.connect("Arduino_Gas", mqtt_user, mqtt_pass)) {
      Serial.println("connected");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      delay(5000);
    }
  }
}

void setup() {
  Serial.begin(9600);
  setup_wifi();
  client.setServer(mqtt_server, 1883);
   if(!ccs.begin()){
    Serial.println("Failed to start sensor! Please check your wiring.");
    while(1);
  }

  // Wait for the sensor to be ready
  while(!ccs.available());
}


void loop() {
  char msg1[16];
  char msg2[16];
  if (!client.connected()) {
    reconnect();
  }

Serial.print("TVOC value:");
  Serial.println(msg2);
   if(ccs.available()){
    if(!ccs.readData()){
      Serial.print("CO2: ");
      Serial.print(ccs.geteCO2());
      Serial.print("ppm, TVOC: ");
      Serial.println(ccs.getTVOC());
      sprintf(msg1,"CO2 %i",ccs.geteCO2());
  client.publish("iot/sensors/co2", msg1);
  sprintf(msg2,"TVOC %i",ccs.getTVOC());
  client.publish("iot/sensors/co2", msg2);
    }
    else{
      Serial.println("ERROR!");
      while(1);
    }
  }
  

  delay(5000);
}
