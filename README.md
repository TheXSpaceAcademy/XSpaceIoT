# XSpaceIoT Library

Welcome to the XSpaceIoT library, designed to simplify the development of IoT projects using XSpace boards and ESP32-WROOM-based devices. This library provides an easy-to-use interface for connecting to MQTT brokers, making it ideal for building IoT applications, sensor networks, and more.

## Features

- Easy integration with IoT services using the PubSubClient library for MQTT
- Supports XSpace boards and any ESP32-WROOM-based devices
- Easy integration with IoT services using PubSubClient for MQTT
- Simple example for PlatformIO with Visual Studio Code

## Installation

### PlatformIO

To use XSpaceIoT with PlatformIO, add the following line to your platformio.ini file under the lib_deps section:

```ini
lib_deps =
  https://github.com/TheXSpaceAcademy/XSpaceIoT.git#main
```

### Arduino IDE

For Arduino IDE, you can clone this repository and place it in your Arduino libraries folder, or you can download the zip and import it directly into the Arduino IDE.

## Quick Start

Here's a simple example to get you started with the XSpaceIoT library. This example connects to an MQTT broker and publishes a counter value every second:

```cpp
#include <Arduino.h>
#include <XSpaceIoT.h>

// Constants for Wi-Fi SSID, WiFi password, and MQTT ID
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
  Thing.Mqtt_init("www.xspace.pe", 1883, NULL);

  // Connect to MQTT broker with the provided credentials
  Thing.Mqtt_Connect(WIFI_SSID, WIFI_PASSWORD, MQTT_ID);
}

void loop() {
  counter++;

  // Publish counter value every 1000ms
  Thing.Mqtt_Publish("the_xspacer/myvalue", counter);
  delay(1000);
}
```

## Documentation

For detailed documentation, including setup instructions, API reference, and examples, please visit our [GitHub repository](https://github.com/TheXSpaceAcademy/XSpaceIoT).

## Contributing

We welcome contributions to the `XSpaceIoT` library! If you have suggestions, bug reports, or contributions, please submit them as issues or pull requests on GitHub.

## License

`XSpaceIoT` is licensed under the MIT License. See the [LICENSE](https://github.com/TheXSpaceAcademy/XSpaceIoT/blob/main/LICENSE) file for more details.

## Acknowledgments

A big thank you to everyone who has contributed to this project. Your support helps make `XSpaceIoT` better for everyone.
