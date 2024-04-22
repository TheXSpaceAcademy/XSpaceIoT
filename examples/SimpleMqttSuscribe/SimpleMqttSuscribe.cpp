#include <Arduino.h>
#include <XSpaceIoT.h>

// Constants for Wi-Fi SSID, Wifi password and MQTT id
const char* WIFI_SSID = "redpucp";
const char* WIFI_PASSWORD = "C9AA28BA93";
const char* MQTT_ID = "the_xspacer"; // MQTT client identifier (MUST BE UNIQUE to prevent connection issues)

// Object creation
XSThing Thing;

// Callback to handle incoming data from subscribed topics
void Mqtt_Callback(char* topicx, byte* Data, unsigned int DataLen){
  
  // Convert received data and topic to strings
  String ReceivedData = String((char*)Data, DataLen);
  String Topic = String((char*)topicx);

  // Check if the received data is from the topic "xspaceserver/current_time"
  if(Topic == "xspaceserver/current_time"){
    // Print the received data to the serial monitor
    Serial.println(ReceivedData);    
  }
}

void setup(){
  // Initialize serial communication
  Serial.begin(115200);

  // Enable serial information output
  Thing.SerialInfo(true); 

  // Initialize MQTT connection with server "www.xspace.pe" on port 1883, using the specified callback function
  Thing.Mqtt_init("www.xspace.pe",1883,Mqtt_Callback);

  // Connect to MQTT broker with the provided credentials
  Thing.Mqtt_Connect(WIFI_SSID, WIFI_PASSWORD, MQTT_ID);

  // Subscribe to the topic "xspaceserver/current_time"
  Thing.Mqtt_Suscribe("xspaceserver/current_time");
}

void loop() {
  // Check the incoming buffer for MQTT messages every 100ms
  Thing.Mqtt_CheckBuffer(); 
  delay(100);
}