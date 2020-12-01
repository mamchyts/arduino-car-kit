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
