#include "motor.h"
#include <string.h>
//-----------------------------------------------------------------------------
cTB6612::cTB6612(TB6612_config* config)
{
    memcpy(&m_config, config, sizeof(TB6612_config));
    set_bits(TCCR0A, WGM00, WGM01, COM0A1, COM0B1);
    set_bits(TCCR0B, CS01);
}
//-----------------------------------------------------------------------------
void cTB6612::move(int16_t left_wheel, int16_t right_wheel)
{
    if(left_wheel == 0)
    {
        m_config.BIN1.set(1);
        m_config.BIN2.set(1);
    }
    else
    {
        if(left_wheel > 0)
        {
            m_config.BIN1.set(1);
            m_config.BIN2.set(0);
        }
        else
        {
            m_config.BIN1.set(0);
            m_config.BIN2.set(1);
        }
        // setup PWM
        OCR0B = abs(left_wheel);
    }

    if(right_wheel == 0)
    {
        m_config.AIN1.set(1);
        m_config.AIN2.set(1);
    }
    else
    {
        if(right_wheel > 0)
        {
            m_config.AIN1.set(1);
            m_config.AIN2.set(0);
        }
        else
        {
            m_config.AIN1.set(0);
            m_config.AIN2.set(1);
        }
        // setup PWM
        OCR0A = abs(right_wheel);
    }

    m_config.STBY.set(1);
}
//-----------------------------------------------------------------------------
void cTB6612::freeze()
{
    m_config.AIN1.set(1);
    m_config.AIN2.set(1);
    m_config.BIN1.set(1);
    m_config.BIN2.set(1);
    m_config.STBY.set(1);
}
//-----------------------------------------------------------------------------
void cTB6612::roll()
{
    m_config.AIN1.set(0);
    m_config.AIN2.set(0);
    m_config.BIN1.set(0);
    m_config.BIN2.set(0);
    m_config.STBY.set(1);
}
//-----------------------------------------------------------------------------
void cTB6612::sleep()
{
    m_config.STBY.set(0);
}
//-----------------------------------------------------------------------------
