#include "stdint.h"
#include <Arduino.h>
#include <IRremote.h>
#include "InfraredReceiver.h"

void InfraredReceiver::decodeBtn(int32_t code)
{
    switch (code)
    {
        case 0xFF629D:
            btn = Btn::UP;
            break;
        case 0xFF22DD:
            btn = Btn::LEFT;
            break;
        case 0xFFC23D:
            btn = Btn::RIGHT;
            break;
        case 0xFFA857:
            btn = Btn::DOWN;
            break;
        case 0xFF02FD:
            btn = Btn::OK;
            break;
        case 0xFF6897:
            btn = Btn::KEY_1;
            break;
        case 0xFF9867:
            btn = Btn::KEY_2;
            break;
        case 0xFF30CF:
            btn = Btn::KEY_4;
            break;
        case 0xFF18E7:
            btn = Btn::KEY_5;
            break;
        case 0xFF7A85:
            btn = Btn::KEY_6;
            break;
        case 0xFF10EF:
            btn = Btn::KEY_7;
            break;
        case 0xFF38C7:
            btn = Btn::KEY_8;
            break;
        case 0xFF5AA5:
            btn = Btn::KEY_9;
            break;
        case 0xFF4AB5:
            btn = Btn::KEY_0;
            break;
        case 0xFF42BD:
            btn = Btn::ASTERISK;
            break;
        case 0xFF52AD:
            btn = Btn::HASH;
            break;

        // special case
        case REPEAT:
            break;

        default:
            Serial.print("Unknown code: ");
            Serial.println(code, HEX);
            break;
    }
}

Btn InfraredReceiver::getBtn()
{
    return btn;
}