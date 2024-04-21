#include <Arduino.h>
#include <XSpaceIoT.h>

// Constants for Wi-Fi SSID, Wifi password and MQTT id
const char* WIFI_SSID = "Delta";
const char* WIFI_PASSWORD = "c9aa28ba93";
const char* MQTT_ID = "the_xspacer"; // MQTT client identifier (MUST BE UNIQUE to prevent connection issues)

int counter = 0;

// Object creation
XSthing Thing;

void setup(){
  // Initialize serial communication
  Serial.begin(115200);

  // Enable serial information output
  Thing.SerialInfo(true); 

  // Initialize MQTT connection with server "www.xspace.pe" on port 1883, callback function is not used (NULL)
  Thing.Mqtt_init("www.xspace.pe",1883,NULL);

  // Connect to MQTT broker with the provided credentials
  Thing.Mqtt_Connect(WIFI_SSID, WIFI_PASSWORD, MQTT_ID);
}

void loop() {
  counter++;

  // Publish counter value every 1000ms
  Thing.Mqtt_Publish("the_xspacer/myvalue", counter);
  delay(1000);
}