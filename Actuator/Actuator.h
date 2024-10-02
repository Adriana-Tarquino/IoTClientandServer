#ifndef ACTUATOR_H
#define ACTUATOR_H

class Actuator {
  private:
    int ledPinRed;
    int ledPinGreen;
    int pumpPin;

  public:
    // Constructor
    Actuator(int redPin, int greenPin, int pumpPin);

    // Initialize actuators
    void begin();

    // Control actuators based on the received state
    void control(int state);
};

#endif
