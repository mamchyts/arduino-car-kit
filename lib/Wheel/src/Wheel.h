/*
    L298N Dual H-Bridge Motor Driver

    This dual bidirectional motor driver, is based on the very popular L298 Dual H-Bridge Motor Driver
    Integrated Circuit. The circuit will allow you to easily and independently control two motors of up to 2A
    each in both directions.It is ideal for robotic applications and well suited for connection to a microcontroller
    requiring just a couple of control lines per motor. It can also be interfaced with simple manual switches,
    TTL logic gates, relays, etc. This board equipped with power LED indicators, on-board +5V regulator and
    protection diodes.
*/
#ifndef WHEEL_H
#define WHEEL_H


#include "stdint.h"


class Wheel
{
    private:
        uint8_t in1;
        uint8_t in2;
        uint8_t pwm;
        int16_t speed {0};

    public:
        Wheel(uint8_t in1, uint8_t in2, uint8_t pwm);
        void start();
        void stop();
        void setSpeed(int16_t speed);
};

#endif
