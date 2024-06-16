#include <Arduino.h>
#include <math.h>
#include <XSpaceIoT.h>

// Sample interval in milliseconds
const int sampleInterval = 2;  
unsigned long previousSampleTime = 0;  // Stores the last sample time in microseconds

XSEthernet Ethernet;  // Instance of XSEthernet class for Ethernet and UDP communication

void setup() {
  Serial.begin(115200);  // Initialize serial communication at 115200 bps

  // Initialize Wi-Fi connection
  Ethernet.Wifi_init("Delta", "c9aa28ba93");
  
  // Establish UDP connection with specified IP and port
  Ethernet.UDP_Connect("192.168.31.150", 23);
}

void loop() {
  // Get the current time in microseconds
  unsigned long currentMicros = micros();
  
  // Check if the sample interval has passed
  if (currentMicros - previousSampleTime >= sampleInterval * 1000) {
    previousSampleTime = currentMicros;  // Update the last sample time

    // Calculate the angle for the sine function
    float timeInSeconds = currentMicros / 1000000.0;  // Convert microseconds to seconds
    float frequency = 0.5;  // Frequency of the sine wave in Hz
    float angle = 2 * PI * frequency * timeInSeconds;  // Angle in radians
    
    // Generate sine and cosine values
    float sineValue = 500 * sin(angle) + 500;  // Sine value scaled and offset
    float cosineValue = 500 * cos(angle) + 500;  // Cosine value scaled and offset

    // Prepare the message to send
    String message = String(sineValue) + " " + String(cosineValue);

    // Send the message via UDP and also print to serial for debugging
    Ethernet.println(message);
    Serial.println(message);
  }
}
