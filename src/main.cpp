#include "stdint.h"
#include <Arduino.h>
#include <Ultrasonic.h>

const uint8_t PIN_TRIG = 9;
const uint8_t PIN_ECHO = 10;
const uint8_t PIN_LED = 13;

Ultrasonic ultrasonic;

void setup() {
    Serial.begin(9600);

    ultrasonic.initPins(PIN_TRIG, PIN_ECHO);
}

void loop() {
    delay(3000);
    digitalWrite(PIN_LED, LOW);
    delay(1000);
    digitalWrite(PIN_LED, HIGH);
    delay(1000);

    digitalWrite(PIN_TRIG, HIGH);
    delayMicroseconds(10);
    digitalWrite(PIN_TRIG, LOW);

    long duration, distance;
    duration = pulseIn(PIN_ECHO, HIGH);
    distance = (duration/2) / 29.1;

    Serial.print("duration: ");
    Serial.print(duration);
    Serial.print(" distance: ");
    Serial.println(distance);



    Serial.print("Distance: ");
    Serial.println(ultrasonic.getDistance());


}