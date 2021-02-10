#include "stdint.h"
#include <Arduino.h>
#include <IRremote.h>
#include "Ultrasonic.h"
#include "InfraredReceiverBtn.h"
#include "Wheel.h"
#include "PID.h"


const uint8_t PIN_IR = 13;
const uint8_t PIN_TRIG = 11;
const uint8_t PIN_ECHO = 12;

const uint8_t PIN_PWM_A = 5;
const uint8_t PIN_IN_1 = 6;
const uint8_t PIN_IN_2 = 7;
const uint8_t PIN_IN_3 = 8;
const uint8_t PIN_IN_4 = 9;
const uint8_t PIN_PWM_B = 10;

const float SPEED = 200.0;


IRrecv irrecv(PIN_IR);
InfraredReceiverBtn ir;
Ultrasonic ultrasonic;

// init interrupt speed
volatile int32_t wheelLeftSpeed = 0;
volatile int32_t wheelRightSpeed = 0;


void wheelLeftInterrupt()
{
    wheelLeftSpeed++;
}


void wheelRightInterrupt()
{
    wheelRightSpeed++;
}


void setup()
{
    Serial.begin(115200);

    irrecv.enableIRIn();
    ultrasonic.initPins(PIN_TRIG, PIN_ECHO);

    // speed sensor
    attachInterrupt(0, wheelLeftInterrupt, RISING);
    attachInterrupt(1, wheelRightInterrupt, RISING);

    // for PWM frequency of 3921.16 Hz
    TCCR2B &= B11111000 | B00000010;
}


// init motors
Wheel wheelRight {PIN_IN_1, PIN_IN_2, PIN_PWM_A};
Wheel wheelLeft {PIN_IN_4, PIN_IN_3, PIN_PWM_B};

// init PIDs
PID pidLeft {0.2, 1.2, 0.005, 0.08};
PID pidRight {0.2, 1.2, 0.005, 0.08};

float newSpeedLeft = 0;
float newSpeedRight = 0;

// used for PID
unsigned long millisPrevious = 0;


void loop()
{
    unsigned long millisNow = millis();
    if ((millisNow - millisPrevious) >= 100) {
        millisPrevious = millisNow;
        newSpeedLeft = pidLeft.calculate(map(wheelLeftSpeed, 0, 25, 0, 255), SPEED);
        newSpeedLeft = constrain(newSpeedLeft, 0, 255);
        newSpeedRight = pidRight.calculate(map(wheelRightSpeed, 0, 25, 0, 255), SPEED);
        newSpeedRight = constrain(newSpeedRight, 0, 255);

        // reset interrupt speed values
        wheelLeftSpeed  = 0;
        wheelRightSpeed = 0;
    }

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
        pidLeft.reset();
        pidRight.reset();
    } else {
        if (btn == Btn::UP) {
            wheelLeft.setSpeed(newSpeedLeft);
            wheelRight.setSpeed(newSpeedRight);
            wheelLeft.start();
            wheelRight.start();
        }
        if (btn == Btn::DOWN) {
            wheelLeft.setSpeed(-newSpeedLeft);
            wheelRight.setSpeed(-newSpeedRight);
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

    Serial.print("IR key: ");
    // Serial.println(newSpeedLeft);

    // Serial.print("Distance: ");
    // Serial.println(ultrasonic.getDistance());
}

