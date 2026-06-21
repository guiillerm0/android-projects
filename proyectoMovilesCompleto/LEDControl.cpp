#include "LEDControl.h"
#include <Arduino.h>

LEDControl::LEDControl(int pin) {
    _pin = pin;
}

void LEDControl::begin() {
    pinMode(_pin, OUTPUT);
}

void LEDControl::on() {
    digitalWrite(_pin, HIGH);
}

void LEDControl::off() {
    digitalWrite(_pin, LOW);
}

void LEDControl::setBrightness(int brightness) {
    analogWrite(_pin, brightness);
}
