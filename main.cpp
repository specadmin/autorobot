//-----------------------------------------------------------------------------
#include "motor.h"
//-----------------------------------------------------------------------------
int main()
{
    TB6612_config cfg;
    cfg.STBY = { PORTD, 4, OUTPUT };
    cfg.PWMB = { PORTD, 5, OUTPUT };
    cfg.PWMA = { PORTD, 6, OUTPUT };
    cfg.AIN1 = { PORTC, 0, OUTPUT };
    cfg.AIN2 = { PORTC, 1, OUTPUT };
    cfg.BIN1 = { PORTC, 2, OUTPUT };
    cfg.BIN2 = { PORTC, 3, OUTPUT };
    cTB6612 motor(&cfg);


    while(1)
    {
        motor.move(80, 80);
        mdelay(800);
        motor.move(150, -150);
        mdelay(400);
    }

    return 0;
}
//-----------------------------------------------------------------------------
