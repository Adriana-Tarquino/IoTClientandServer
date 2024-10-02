#ifndef MOISTURESENSOR_H
#define MOISTURESENSOR_H

class MoistureSensor {
  private:
    int pin;
    
  public:
    // Constructor
    MoistureSensor(int sensorPin);

    // Método para inicializar el sensor
    void begin();

    // Método para leer el porcentaje de humedad
    int readMoisture();

    // Método para determinar el estado según la humedad
    int getState(int humedad);
};

#endif
