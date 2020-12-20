#include "stdint.h"
#include <Arduino.h>
#include "Wheel.h"


Wheel::Wheel(uint8_t pinIn1, uint8_t pinIn2, uint8_t pinPwm): in1{pinIn1}, in2{pinIn2}, pwm{pinPwm}
{
    pinMode(pwm, OUTPUT);
    pinMode(in1, OUTPUT);
    pinMode(in2, OUTPUT);

    // turn off motors - Initial state
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
}


void Wheel::start()
{
    if (speed >= 0) {
        digitalWrite(in2, HIGH);
        digitalWrite(in1, LOW);
    } else {
        digitalWrite(in2, LOW);
        digitalWrite(in1, HIGH);
    }

    analogWrite(pwm, abs(speed));
}


void Wheel::stop()
{
    speed = 0;

    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
}


void Wheel::setSpeed(int16_t value)
{
    speed = value;
}

