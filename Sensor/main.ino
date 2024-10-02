#include "ESP32Sensor.h"

// Crear instancia del ESP32Sensor
ESP32Sensor sensor(32, "INVITADO", "", "192.168.41.16", 8080);

void setup() {
    Serial.begin(115200);
    
    // Inicializar sensor y WiFi
    sensor.begin();
}

void loop() {
    // Leer la humedad y enviar el estado al servidor
    sensor.update();
    
    delay(2000);  // Esperar antes de la próxima lectura y envío
}
