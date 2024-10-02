#include <Arduino.h>
#include "ClientSensor.h"

// Constructor
ClientSensor::ClientSensor(const char* wifiSSID, const char* wifiPassword, const char* ip, int port) {
    ssid = wifiSSID;
    password = wifiPassword;
    serverIP = ip;
    serverPort = port;
}

// Conectarse a la red WiFi
void ClientSensor::connectWiFi() {
    WiFi.begin(ssid, password);
    Serial.print("Conectando a WiFi");
    while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
        Serial.print(".");
    }
    Serial.println("\nConectado a WiFi");
}

// Enviar el estado de humedad al servidor
void ClientSensor::sendHumidityState(int estado) {
    if (client.connect(serverIP, serverPort)) {
        String mensaje = "humidity=" + String(estado) + "\n";
        client.print(mensaje);
        Serial.println("Estado enviado: " + mensaje);
        client.stop();  // Cerrar la conexión
    } else {
        Serial.println("No se pudo conectar al servidor.");
    }
}
