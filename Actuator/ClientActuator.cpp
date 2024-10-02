#include "ClientActuator.h"
#include <Arduino.h>

// Constructor
ClientActuator::ClientActuator(const char* wifiSSID, const char* wifiPassword, const char* ip, int port) {
    this->ssid = wifiSSID;
    this->password = wifiPassword;
    this->serverIP = ip;
    this->serverPort = port;
}

// Connect to WiFi
void ClientActuator::connectWiFi() {
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
        Serial.println("Connecting to WiFi...");
    }
    Serial.println("Connected to WiFi");
}

// Get the state from the server
int ClientActuator::getStateFromServer() {
    if (client.connect(serverIP, serverPort)) {
        client.println("GET");  // Request state from server

        // Read the server response
        String response = client.readStringUntil('\n');
        Serial.println("Server response: " + response);  // Print full response

        // Handle response and extract the state
        if (response.startsWith("humidity=")) {
            int receivedState = response.substring(9).toInt(); // Extract the state
            client.stop();  // Close connection with server
            return receivedState;
        } else {
            Serial.println("Unrecognized response format.");
            client.stop();  // Close connection
            return -1;
        }
    } else {
        Serial.println("Failed to connect to the server.");
        return -1;
    }
}
