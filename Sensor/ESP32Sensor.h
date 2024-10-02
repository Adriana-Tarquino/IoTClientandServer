#ifndef ESP32SENSOR_H
#define ESP32SENSOR_H

#include "MoistureSensor.h"
#include "ClientSensor.h"

class ESP32Sensor {
  private:
    MoistureSensor moistureSensor;
    ClientSensor clientSensor;
    
  public:
    // Constructor
    ESP32Sensor(int sensorPin, const char* ssid, const char* password, const char* ip, int port);

    // Método para inicializar el sensor y WiFi
    void begin();

    // Método principal para leer la humedad y enviar el estado al servidor
    void update();
};

#endif
