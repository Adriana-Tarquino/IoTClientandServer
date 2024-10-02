#include "Actuator.h"
#include <Arduino.h>

// Constructor
Actuator::Actuator(int redPin, int greenPin, int pumpPin) {
    this->ledPinRed = redPin;
    this->ledPinGreen = greenPin;
    this->pumpPin = pumpPin;
}

// Initialize actuators
void Actuator::begin() {
    pinMode(ledPinRed, OUTPUT);
    pinMode(ledPinGreen, OUTPUT);
    pinMode(pumpPin, OUTPUT);
}

// Control actuators based on the received state
void Actuator::control(int state) {
    if (state == 1) {  // Dry
        Serial.println("State: Dry. Turning on Red LED and water pump.");
        digitalWrite(ledPinRed, HIGH);   // Turn on Red LED
        digitalWrite(ledPinGreen, LOW);  // Turn off Green LED
        digitalWrite(pumpPin, HIGH);     // Turn on water pump
        delay(2000);
    } else if (state == 2) {  // Moderately moist
        Serial.println("State: Moderately moist. Turning on Green LED.");
        digitalWrite(ledPinRed, LOW);    // Turn off Red LED
        digitalWrite(ledPinGreen, HIGH); // Turn on Green LED
        digitalWrite(pumpPin, LOW);      // Turn off water pump
    } else {
        Serial.println("Unrecognized state. Turning off all actuators.");
        digitalWrite(ledPinRed, LOW);    // Turn off Red LED
        digitalWrite(ledPinGreen, LOW);  // Turn off Green LED
        digitalWrite(pumpPin, LOW);      // Turn off water pump
    }
}
