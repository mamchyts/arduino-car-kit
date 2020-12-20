/*
    Ultrasonic Ranging Module HC - SR04

    The Timing diagram is shown below. You only need to supply a short 10uS
    pulse to the trigger input to start the ranging, and then the module will send out
    an 8 cycle burst of ultrasound at 40 kHz and raise its echo. The Echo is a
    distance object that is pulse width and the range in proportion .You can
    calculate the range through the time interval between sending trigger signal and
    receiving echo signal. Formula: uS / 58 = centimeters or uS / 148 =inch; or: the
    range = high level time * velocity (340M/S) / 2; we suggest to use over 60ms
    measurement cycle, in order to prevent trigger signal to the echo signal.
*/
#ifndef ULTRASONIC_H
#define ULTRASONIC_H


#include "stdint.h"


class Ultrasonic
{
    private:
        uint8_t pinTrig;
        uint8_t pinEcho;

    public:
        void initPins(uint8_t trig, uint8_t echo);
        float getDistance();
};

#endif
