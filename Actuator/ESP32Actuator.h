#ifndef ESP32ACTUATOR_H
#define ESP32ACTUATOR_H

#include "ClientActuator.h"
#include "Actuator.h"

class ESP32Actuator {
  private:
    ClientActuator clientActuator;
    Actuator actuator;
    
  public:
    // Constructor
    ESP32Actuator(const char* ssid, const char* password, const char* serverIP, int serverPort, int ledPinRed, int ledPinGreen, int pumpPin);

    // Initialize WiFi and actuators
    void begin();

    // Update the actuator's state based on server response
    void update();
};

#endif
