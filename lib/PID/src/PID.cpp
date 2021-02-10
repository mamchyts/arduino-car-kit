#include <Arduino.h>
#include "PID.h"


PID::PID(float kp, float ki, float kd, float dt): m_kp{kp}, m_ki{ki}, m_kd{kd}, m_dt{dt}
{
}


float PID::calculate(float inputValue, float destinationValue)
{
    float errorValue = destinationValue - inputValue;
    m_integralErrorValue += errorValue * m_dt;
    float derivative = (errorValue - m_previousErrorValue) / m_dt;
    m_previousErrorValue = errorValue;

    return m_kp * errorValue + m_ki * m_integralErrorValue + m_kd * derivative;
}


void PID::reset()
{
    m_integralErrorValue = 0;
    m_previousErrorValue = 0;
}
