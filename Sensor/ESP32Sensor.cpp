#include "ESP32Sensor.h"

// Constructor
ESP32Sensor::ESP32Sensor(int sensorPin, const char* ssid, const char* password, const char* ip, int port)
: moistureSensor(sensorPin), clientSensor(ssid, password, ip, port) {
}

// Inicializar sensor y WiFi
void ESP32Sensor::begin() {
    moistureSensor.begin();
    clientSensor.connectWiFi();
}

// Leer la humedad y enviar el estado
void ESP32Sensor::update() {
    // Leer humedad
    int humidity = moistureSensor.readMoisture();
    
    // Obtener estado según la humedad
    int state = moistureSensor.getState(humidity);

    // Enviar estado al servidor
    clientSensor.sendHumidityState(state);
}
