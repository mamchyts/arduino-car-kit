#include "stdint.h"
#include <Arduino.h>
#include <IRremote.h>
#include "Ultrasonic.h"
#include "InfraredReceiver.h"

const uint8_t PIN_IR = 7;
const uint8_t PIN_TRIG = 9;
const uint8_t PIN_ECHO = 10;
const uint8_t PIN_LED = 13;

// Ultrasonic ultrasonic;
IRrecv irrecv(PIN_IR);
InfraredReceiver ir;

void setup() {
    Serial.begin(9600);
    // ultrasonic.initPins(PIN_TRIG, PIN_ECHO);

    irrecv.enableIRIn();
}

void loop() {
    // detect IR signal
    decode_results results;
    if (irrecv.decode(&results)){
        ir.decodeBtn(results.value);
        irrecv.resume();
    }

    if (ir.getBtn() != Btn::UNUSED) {
        Serial.print("IR key: ");
        Serial.println((int) ir.getBtn());
    }


    // Serial.print("Distance: ");
    // Serial.println(ultrasonic.getDistance());

}