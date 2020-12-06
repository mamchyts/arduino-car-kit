/*
    TL1838 Infrared Receiver Datasheet

    The Timing diagram is shown below. You only need to supply a short 10uS
    pulse to the trigger input to start the ranging, and then the module will send out
    an 8 cycle burst of ultrasound at 40 kHz and raise its echo. The Echo is a
    distance object that is pulse width and the range in proportion .You can
    calculate the range through the time interval between sending trigger signal and
    receiving echo signal. Formula: uS / 58 = centimeters or uS / 148 =inch; or: the
    range = high level time * velocity (340M/S) / 2; we suggest to use over 60ms
    measurement cycle, in order to prevent trigger signal to the echo signal.
*/

#ifndef  INFRAREDRECEIVER_H
#define  INFRAREDRECEIVER_H

#include "stdint.h"

enum class Btn
{
    UNUSED = 0,

    KEY_1,
    KEY_2,
    KEY_3,
    KEY_4,
    KEY_5,
    KEY_6,
    KEY_7,
    KEY_8,
    KEY_9,
    KEY_0,

    UP,
    DOWN,
    LEFT,
    RIGHT,
    OK,

    ASTERISK,
    HASH,
};

class  InfraredReceiver
{
    private:
        Btn btn;

    public:
        void decodeBtn(int32_t code);
        Btn getBtn();
};

#endif
