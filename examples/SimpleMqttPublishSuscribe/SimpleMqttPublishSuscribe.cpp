#include <Arduino.h>
#include <XSpaceIoT.h> // Make sure to install the XSpaceIoT library

// Constants for WiFi credentials
const char* WIFI_SSID = "Delta"; 
const char* WIFI_PASSWORD = "c9aa28ba93"; 
// Unique MQTT client ID (MUST BE UNIQUE to avoid connection issues)
const char* MQTT_ID = "the_xspacer"; 

XSThing Thing; // Create a Thing object
int counter = 0;

void Mqtt_Callback(char* topicx, byte* Data, unsigned int DataLen){
    // Convert the received topic and data into strings
    String ReceivedData = String((char*)Data, DataLen);
    String Topic = String((char*)topicx);

    // Check if the received data is from the topic "xspaceserver/current_time"
    if(Topic == "xspaceserver/current_time"){
        Serial.println(ReceivedData);    // Print the received data to the serial monitor
    }
}

void setup() {
    Serial.begin(115200); // Start serial communication
    Thing.Mqtt_SerialInfo(true); // Enable serial information output
    // Initialize MQTT connection with server on port 1883 using the specified callback function
    // The last parameter sets the interval in milliseconds to check the incoming data buffer automatically
    Thing.Mqtt_init("www.xspace.pe", 1883, Mqtt_Callback, 100); 
    // Connect to MQTT broker using provided credentials
    Thing.Mqtt_Connect(WIFI_SSID, WIFI_PASSWORD, MQTT_ID); 

    // Subscribe to the topic "xspaceserver/current_time"
    Thing.Mqtt_Suscribe("xspaceserver/current_time"); 
}

void loop() {
  counter++;
  // Publish counter value every 1000ms
  Thing.Mqtt_Publish("the_xspacer/myvalue", counter);
  delay(1000); // Wait for 1000 milliseconds
}