#include "stdint.h"
#include <Arduino.h>
#include <IRremote.h>
#include "Ultrasonic.h"
#include "InfraredReceiverBtn.h"
#include "Wheel.h"


const uint8_t PIN_IR = 2;
const uint8_t PIN_TRIG = 3;
const uint8_t PIN_ECHO = 4;

const uint8_t PIN_PWM_A = 5;
const uint8_t PIN_IN_1 = 6;
const uint8_t PIN_IN_2 = 7;
const uint8_t PIN_IN_3 = 8;
const uint8_t PIN_IN_4 = 9;
const uint8_t PIN_PWM_B = 10;

const uint8_t SPEED = 200;


IRrecv irrecv(PIN_IR);
InfraredReceiverBtn ir;
Ultrasonic ultrasonic;

// init motors
Wheel wheelRight {PIN_IN_1, PIN_IN_2, PIN_PWM_A};
Wheel wheelLeft {PIN_IN_4, PIN_IN_3, PIN_PWM_B};


void setup() {
    Serial.begin(115200);

    irrecv.enableIRIn();
    ultrasonic.initPins(PIN_TRIG, PIN_ECHO);
}


void loop() {
    // detect IR signal
    decode_results results;
    if (irrecv.decode(&results)){
        ir.decodeBtn(results.value, results.isRepeat);
        irrecv.resume();
    }

    // get latest actual btn value
    Btn btn = ir.getBtn();

    if (btn == Btn::UNUSED) {
        wheelLeft.stop();
        wheelRight.stop();
    } else {
        if (btn == Btn::UP) {
            wheelLeft.setSpeed(SPEED);
            wheelRight.setSpeed(SPEED);
            wheelLeft.start();
            wheelRight.start();
        }
        if (btn == Btn::DOWN) {
            wheelLeft.setSpeed(-SPEED);
            wheelRight.setSpeed(-SPEED);
            wheelLeft.start();
            wheelRight.start();
        }
        if (btn == Btn::LEFT) {
            wheelLeft.setSpeed(-SPEED);
            wheelRight.setSpeed(SPEED);
            wheelLeft.start();
            wheelRight.start();
        }
        if (btn == Btn::RIGHT) {
            wheelLeft.setSpeed(SPEED);
            wheelRight.setSpeed(-SPEED);
            wheelLeft.start();
            wheelRight.start();
        }
    }

    // Serial.print("IR key: ");
    // Serial.println((int) btn);

    // Serial.print("Distance: ");
    // Serial.println(ultrasonic.getDistance());
}