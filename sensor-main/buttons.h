#ifndef BUTTONS_H
#define BUTTONS_H

#include <Arduino.h>
class buttons
{
private:
    /* data */
    int _pin;

public:
    buttons(int pin);
    void test();
    // ~buttons();
};

#endif