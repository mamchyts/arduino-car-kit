#ifndef  PID_H
#define  PID_H

class PID
{
    public:
        PID(float kp, float ki, float kd, float dt);
        float calculate(float inputValue, float destinationValue);
        void reset();

    private:
        float m_kp, m_ki, m_kd, m_dt;
        float m_previousErrorValue = 0;
        float m_integralErrorValue = 0;
};

#endif
