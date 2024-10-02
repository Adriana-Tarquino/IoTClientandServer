#ifndef CLIENTSENSOR_H
#define CLIENTSENSOR_H

#include <WiFi.h>

class ClientSensor {
  private:
    const char* ssid;
    const char* password;
    const char* serverIP;
    int serverPort;
    WiFiClient client;
    
  public:
    // Constructor
    ClientSensor(const char* wifiSSID, const char* wifiPassword, const char* ip, int port);

    // Método para conectarse a la red WiFi
    void connectWiFi();

    // Método para enviar el estado de humedad al servidor
    void sendHumidityState(int estado);
};

#endif
