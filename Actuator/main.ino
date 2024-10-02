#include "ESP32Actuator.h"

// Create an instance of ESP32Actuator
ESP32Actuator esp32Actuator("INVITADO", "", "192.168.41.16", 8080, 16, 17, 5);

void setup() {
    Serial.begin(115200);
    
    // Initialize WiFi and actuators
    esp32Actuator.begin();
}

void loop() {
    // Update actuators based on server response
    esp32Actuator.update();

    delay(500); // Wait before the next request
}
