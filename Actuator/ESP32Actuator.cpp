#include "ESP32Actuator.h"

// Constructor
ESP32Actuator::ESP32Actuator(const char* ssid, const char* password, const char* serverIP, int serverPort, int ledPinRed, int ledPinGreen, int pumpPin)
: clientActuator(ssid, password, serverIP, serverPort), actuator(ledPinRed, ledPinGreen, pumpPin) {
}

// Initialize WiFi and actuators
void ESP32Actuator::begin() {
    clientActuator.connectWiFi();
    actuator.begin();
}

// Update the actuator's state based on server response
void ESP32Actuator::update() {
    // Get state from server
    int state = clientActuator.getStateFromServer();

    // If the state is valid, control the actuators
    if (state != -1) {
        actuator.control(state);
    }
}
