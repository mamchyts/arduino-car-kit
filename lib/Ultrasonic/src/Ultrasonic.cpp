#include "stdint.h"
#include <Arduino.h>
#include "Ultrasonic.h"


void Ultrasonic::initPins(uint8_t trig, uint8_t echo)
{
    pinTrig = trig;
    pinEcho = echo;

    pinMode(pinTrig, OUTPUT);
    digitalWrite(pinTrig, LOW);
    pinMode(pinEcho, INPUT);
}


float Ultrasonic::getDistance()
{
    // send signal
    digitalWrite(pinTrig, HIGH);
    delayMicroseconds(10);
    digitalWrite(pinTrig, LOW);

    // calculate distance in centimeters
    return pulseIn(pinEcho, HIGH) / 58.2;
}
