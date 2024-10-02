#include <Arduino.h>
#include "MoistureSensor.h"

// Constructor
MoistureSensor::MoistureSensor(int sensorPin) {
    pin = sensorPin;
}

// Inicializar el sensor
void MoistureSensor::begin() {
    pinMode(pin, INPUT);
}

// Leer el porcentaje de humedad
int MoistureSensor::readMoisture() {
    int valorHumedad = analogRead(pin);  
    int percentageHumidity = map(valorHumedad, 0, 4095, 100, 0);  // Convertir a porcentaje
    Serial.print("Humedad del suelo: ");
    Serial.print(percentageHumidity);
    Serial.println("%");
    return percentageHumidity;
}

// Determinar el estado según la humedad
int MoistureSensor::getState(int humedad) {
    if (humedad >= 30) {
        return 2;  // Moderadamente húmedo
    } else {
        return 1;  // Seco
    }
}
