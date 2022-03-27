#ifndef MOTOR_H_INCLUDED
#define MOTOR_H_INCLUDED
//-----------------------------------------------------------------------------
#include "../lib/avr-misc/avr-misc.h"
//-----------------------------------------------------------------------------
struct TB6612_config
{
    GPIO AIN1;
    GPIO AIN2;
    GPIO BIN1;
    GPIO BIN2;
    GPIO STBY;
    GPIO PWMA;
    GPIO PWMB;
};
//-----------------------------------------------------------------------------
class cTB6612
{
public:
    cTB6612(TB6612_config* config);
    void move(int16_t left_wheel, int16_t right_wheel);
    void freeze();
    void roll();
    void sleep();

private:
    TB6612_config m_config;
};
//-----------------------------------------------------------------------------
#endif
