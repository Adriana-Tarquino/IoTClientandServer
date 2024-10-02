#ifndef CLIENTACTUATOR_H
#define CLIENTACTUATOR_H

#include <WiFi.h>

class ClientActuator {
  private:
    const char* ssid;
    const char* password;
    const char* serverIP;
    int serverPort;
    WiFiClient client;

  public:
    // Constructor
    ClientActuator(const char* wifiSSID, const char* wifiPassword, const char* ip, int port);

    // Method to connect to WiFi
    void connectWiFi();

    // Method to get the state from the server
    int getStateFromServer();
};

#endif
